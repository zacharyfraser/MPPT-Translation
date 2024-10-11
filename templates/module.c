/** @file module.c
 *
 * @brief A description of the module’s purpose.
 *
 */

#include "module.h"

// The current ammount of stuff this module has received.
int stuff_counter = 0;

/*!
 * @brief Module superloop function: Inrements the stuff counter once.
 */
void
module_superloop (void)
{
    // Increment the stuff
    stuff_counter++;
}

/*!
 * @brief Increment this module's stuff counter by some given ammount.
 *
 * @param[in] stuff  The ammount of stuff receivied.
 *
 * @return The current value of the stuff counter.
 */
uint32_t
module_add_stuff (uint32_t stuff)
{
    stuff_counter += stuff;
    return stuff_counter;
}