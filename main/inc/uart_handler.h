/** @file uart_handler.h
 *
 * @brief Generic module for handling Interrupt-Driven UART Communications.
 *
 */

#ifndef UART_HANDLER_H
#define UART_HANDLER_H

#include <stdint.h>

void uart_handler_init(void);
void uart_handler_superloop(void);

#endif /* UART_HANDLER_H */

/*** end of file ***/