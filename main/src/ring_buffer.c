/** @file ring_buffer.c
 *
 * @brief This module contains interrupt-safe ring buffers for handling various
 * data types for general purpose use. Derived from from the "Bare Metal Series"
 * of tutorials by Francis Stokes, see:
 * https://github.com/lowbyteproductions/bare-metal-series
 *
 */

#include "ring_buffer.h"

/*!
 * @brief Set up a new ringbuffer structure to handle elements of type uint8_t.
 *
 * @attention The `size` parameter MUST BE a power of 2.
 *
 * @param[in] rb  Pointer to a new ring buffer structure to initialize.
 * @param[in] buffer  Pointer to a uint8_t buffer to be used as the backing
 * storage of the ring buffer.
 * @param[in] uint32_t  The size of the buffer in terms of number of uint8_t
 * elements. Must be a power of 2.
 */
void
ring_buffer_u8_setup (ring_buffer_u8_t *rb, uint8_t *buffer, uint32_t size)
{
    rb->buffer      = buffer;
    rb->read_index  = 0;
    rb->write_index = 0;
    rb->mask        = size - 1;
}

/*!
 * @brief Check if the given ring buffer is empty.
 *
 * @param[in] rb  A pointer to an initialized ringbuffer structure.
 *
 * @return Returns true if elements are available in the ringbuffer.
 */
bool
ring_buffer_u8_is_empty (ring_buffer_u8_t *rb)
{
    return rb->read_index == rb->write_index;
}

/*!
 * @brief Pop an element from the head of the ring buffer.
 *
 * @param[in] rb  A pointer to an initialized ringbuffer structure.
 * @param[out] element_dest  A pointer to some destination to copy the element
 * into.
 *
 * @return Returns true if an element was available and it was copied into the
 * destination location.
 */
bool
ring_buffer_u8_pop (ring_buffer_u8_t *rb, uint8_t *element_dest)
{
    uint32_t local_read_index  = rb->read_index;
    uint32_t local_write_index = rb->write_index;

    if (local_read_index == local_write_index)
    {
        return false;
    }

    *element_dest    = rb->buffer[local_read_index];
    local_read_index = (local_read_index + 1) & rb->mask;
    rb->read_index   = local_read_index;

    return true;
}

/*!
 * @brief Push a new element into the ringbuffer.
 *
 * @param[in] rb  A pointer to an initialized ringbuffer structure.
 * @param[in] element  A value to be copied into the ring buffer.
 *
 * @return Returns true if the va was written, otherwise returns false.
 */
bool
ring_buffer_u8_push (ring_buffer_u8_t *rb, uint8_t element)
{
    uint32_t local_write_index = rb->write_index;
    uint32_t local_read_index  = rb->read_index;

    uint32_t next_write_index = (local_write_index + 1) & rb->mask;

    if (next_write_index == local_read_index)
    {
        return false;
    }

    rb->buffer[local_write_index] = element;
    rb->write_index               = next_write_index;
    return true;
}

void
ring_buffer_u32_setup (ring_buffer_u32_t *rb, uint32_t *buffer, uint32_t size)
{
    rb->buffer      = buffer;
    rb->read_index  = 0;
    rb->write_index = 0;
    rb->mask        = size - 1;
}

bool
ring_buffer_u32_is_empty (ring_buffer_u32_t *rb)
{
    return rb->read_index == rb->write_index;
}

bool
ring_buffer_u32_push (ring_buffer_u32_t *rb, uint32_t element)
{
    uint32_t local_write_index = rb->write_index;
    uint32_t local_read_index  = rb->read_index;

    uint32_t next_write_index = (local_write_index + 1) & rb->mask;

    if (next_write_index == local_read_index)
    {
        return false;
    }

    rb->buffer[local_write_index] = element;
    rb->write_index               = next_write_index;
    return true;
}

bool
ring_buffer_u32_pop (ring_buffer_u32_t *rb, uint32_t *element_dest)
{
    uint32_t local_read_index  = rb->read_index;
    uint32_t local_write_index = rb->write_index;

    if (local_read_index == local_write_index)
    {
        return false;
    }

    *element_dest    = rb->buffer[local_read_index];
    local_read_index = (local_read_index + 1) & rb->mask;
    rb->read_index   = local_read_index;

    return true;
}

void
ring_buffer_ptr_setup (ring_buffer_ptr_t *rb, void **buffer, uint32_t size)
{
    rb->buffer      = buffer;
    rb->read_index  = 0;
    rb->write_index = 0;
    rb->mask        = size - 1;
}

bool
ring_buffer_ptr_push (ring_buffer_ptr_t *rb, void *element)
{
    uint32_t local_write_index = rb->write_index;
    uint32_t local_read_index  = rb->read_index;

    uint32_t next_write_index = (local_write_index + 1) & rb->mask;

    if (next_write_index == local_read_index)
    {
        return false;
    }

    rb->buffer[local_write_index] = element;
    rb->write_index               = next_write_index;
    return true;
}

bool
ring_buffer_ptr_pop (ring_buffer_ptr_t *rb, void **element_dest)
{
    uint32_t local_read_index  = rb->read_index;
    uint32_t local_write_index = rb->write_index;

    if (local_read_index == local_write_index)
    {
        return false;
    }

    *element_dest    = rb->buffer[local_read_index];
    local_read_index = (local_read_index + 1) & rb->mask;
    rb->read_index   = local_read_index;

    return true;
}

bool
ring_buffer_ptr_is_empty (ring_buffer_ptr_t *rb)
{
    return rb->read_index == rb->write_index;
}