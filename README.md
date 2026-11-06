# stm32F072RB_HFY_FST_Sender
stm32F072RB_HFY_FST_Sender

## First milestone: Nucleo LED blink

`Core/Src/main.c` uses CMSIS device definitions for the STM32F072RBTx. It
toggles the Nucleo-F072RB user LED (PA5), initializes Arduino D15/PB8 as a LOW
output, does not use HAL, and does not transmit RF. The project includes a
local reset/vector startup file.

Open `stm32F072RB_HFY_FST_Sender.uvprojx` in Keil µVision, build, and flash the
Nucleo-F072RB. The user LED should blink. Select ST-Link Debugger in the Keil
Debug settings if it is not selected automatically. The project targets the
STM32F072RBTx and uses the installed `Keil.STM32F0xx_DFP` pack for device and
flash programming support; no HAL is used. The µVision C include paths use
CMSIS-Core 6.3.0 and the STM32F0 device headers from NUCLEO-F072RB_BSP 1.1.0.
If those packs are installed in a different location, update the C/C++ include
paths in the project options.

The HFY-FST `DATA` input is assigned to Arduino D15 (PB8) and is initialized
LOW. Connect module `DATA` to D15, module `-` to Nucleo GND, and module `+` to
3V3 after confirming the rating of the exact module. The RF protocol is not
implemented yet, so a LOW output does not transmit a useful message.
