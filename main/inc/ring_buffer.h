/** @file ring_buffer.h
 *
 * @brief This module contains interrupt-safe ringbuffers handling various
 * data types for general purpose use. Derived from from the "Bare Metal Series"
 * of tutorials by Francis Stokes, see:
 * https://github.com/lowbyteproductions/bare-metal-series
 *
 */

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct ring_buffer_u8_t
{
    uint8_t *buffer;
    uint32_t mask;
    uint32_t read_index;
    uint32_t write_index;
} ring_buffer_u8_t;

typedef struct ring_buffer_u32_t
{
    uint32_t *buffer;
    uint32_t  mask;
    uint32_t  read_index;
    uint32_t  write_index;
} ring_buffer_u32_t;

typedef struct ring_buffer_ptr_t
{
    void   **buffer;
    uint32_t mask;
    uint32_t read_index;
    uint32_t write_index;
} ring_buffer_ptr_t;

void ring_buffer_u8_setup(ring_buffer_u8_t *rb, uint8_t *buffer, uint32_t size);
bool ring_buffer_u8_push(ring_buffer_u8_t *rb, uint8_t element);
bool ring_buffer_u8_pop(ring_buffer_u8_t *rb, uint8_t *element_dest);
bool ring_buffer_u8_is_empty(ring_buffer_u8_t *rb);

void ring_buffer_u32_setup(ring_buffer_u32_t *rb,
                           uint32_t          *buffer,
                           uint32_t           size);
bool ring_buffer_u32_push(ring_buffer_u32_t *rb, uint32_t element);
bool ring_buffer_u32_pop(ring_buffer_u32_t *rb, uint32_t *element_dest);
bool ring_buffer_u32_is_empty(ring_buffer_u32_t *rb);

void ring_buffer_ptr_setup(ring_buffer_ptr_t *rb, void **buffer, uint32_t size);
bool ring_buffer_ptr_push(ring_buffer_ptr_t *rb, void *element);
bool ring_buffer_ptr_pop(ring_buffer_ptr_t *rb, void **element_dest);
bool ring_buffer_ptr_is_empty(ring_buffer_ptr_t *rb);

#endif /* RING_BUFFER_H */

/*** end of file ***/