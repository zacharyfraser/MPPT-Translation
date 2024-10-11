/** @file uart_handler.c
 *
 * @brief Generic module for handling Interrupt-Driven UART Communications.
 *
 */

#define UART_0      UART_NUM_0
#define UART_1      UART_NUM_1
#define UART_2      UART_NUM_2

/* UART 0 is connected to CH340/USB */
#define UART_0_TX   GPIO_NUM_1
#define UART_0_RX   GPIO_NUM_3

#define UART_1_TX   GPIO_NUM_17
#define UART_1_RX   GPIO_NUM_16

#define UART_2_TX   GPIO_NUM_17
#define UART_2_RX   GPIO_NUM_16

#define UART_BAUD_RATE 115200
#define UART_DATA_BITS UART_DATA_8_BITS
#define UART_PARITY    UART_PARITY_DISABLE
#define UART_STOP_BITS UART_STOP_BITS_1

#define UART_QUEUE_SIZE 10
#define UART_BUFFER_SIZE 1024

/* Include Module Header */
#include "uart_handler.h"

/* Include ESP-IDF Drivers */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

uint8_t rxbuffer[256];

/**
 * @brief UART Handler Initialization and Configuration
 */
void
uart_handler_init (void)
{
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_BITS,
        .parity    = UART_PARITY,
        .stop_bits = UART_STOP_BITS,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB
    };


    const int uart_buffer_size = UART_BUFFER_SIZE;
    int intr_alloc_flags = 0;

    /* Setup UART Queue Handles */
    QueueHandle_t uart_0_queue;
    //QueueHandle_t uart_1_queue;
    //QueueHandle_t uart_2_queue;

    /* UART_0 */

    /* Install UART Driver - Input Buffer */
    ESP_ERROR_CHECK(uart_driver_install(UART_0, uart_buffer_size, 0, UART_QUEUE_SIZE, &uart_0_queue, intr_alloc_flags));
    /* Configure UART Parameters */
    ESP_ERROR_CHECK(uart_param_config(UART_0, &uart_config));
    /* Set UART Pins */
    ESP_ERROR_CHECK(uart_set_pin(UART_0, UART_0_TX, UART_0_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
}

