# stm32F072RB_HFY_FST_Sender
stm32F072RB_HFY_FST_Sender

## First milestone: Nucleo LED blink

`Core/Src/main.c` toggles the Nucleo-F072RB user LED (PA5) with direct register
access; it does not use HAL and does not transmit RF. The project includes a
local reset/vector startup file and is configured for the STM32F072RBTx.

Open `stm32F072RB_HFY_FST_Sender.uvprojx` in Keil µVision, build, and flash the
Nucleo-F072RB. The user LED should blink. Select ST-Link Debugger in the Keil
Debug settings if it is not selected automatically. The project targets the
STM32F072RBTx and uses the installed `Keil.STM32F0xx_DFP` pack for device and
flash programming support; no HAL is used.

The HFY-FST `DATA` input is assigned to Arduino D15 (PB8) and is initialized
LOW. Connect module `DATA` to D15, module `-` to Nucleo GND, and module `+` to
3V3 after confirming the rating of the exact module. The RF protocol is not
implemented yet, so a LOW output does not transmit a useful message.
