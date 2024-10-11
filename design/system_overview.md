# MPPT/BMS Translation

Forward BMS UART telemetry to Nautono board using single UART channel.  Decode MPPT status LED signals into UART telemetry.

## Hardware

ESP32-WROOM-32E

### Peripherals

- UART0 - Output to main PCB
- UART1 - BMS_1 UART input
- UART2 - BMS_2 UART input
- TIMG1_T1 - Main Timer for MPPT decoding.  Using four channels for input capture; one for each 'LED' signal

## Current Progress

Successful echoing of UART from channels 1 and 2 onto channel 0.  LED signal pulse width calculations complete.

## To Do

- Refactor UART echoing to push full messages into a buffer, to be handled periodically.  This will prevent an incoming transmission from both UART1 and UART2 overlapping resulting in garbage outputs.  I am waiting on a response from DALY BMS for details on their UART packet definitions so I can reliably define what the end of a message looks like.
- Create decoding state machine matrix.  Currently, only the pulse width of each signal is independantly being captured.  The widths should be fed into a state machine in order to determine the status code being emitted.d

## Timeline

Progress is currently paused in order to allow for a quick board spin using an STM32U073CC instead of the ESP32.  The STM will be significantly lower power, and much easier to finish implementing the firmware.

I expect that the firmware can be finished within 2 weeks of receiving the new boards.  Assuming a 2 week spin time, and a 2 week manufacturing lead time, this subsystem should be complete within 6 weeks.
