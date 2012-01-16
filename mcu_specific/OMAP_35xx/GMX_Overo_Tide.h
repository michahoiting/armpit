@---------------------------------------------------------------------------------------------------
@
@  ARMPIT SCHEME Version 050
@
@  ARMPIT SCHEME is distributed under The MIT License.

@  Copyright (c) 2006-2012 Hubert Montas

@ Permission is hereby granted, free of charge, to any person obtaining
@ a copy of this software and associated documentation files (the "Software"),
@ to deal in the Software without restriction, including without limitation
@ the rights to use, copy, modify, merge, publish, distribute, sublicense,
@ and/or sell copies of the Software, and to permit persons to whom the
@ Software is furnished to do so, subject to the following conditions:
@
@ The above copyright notice and this permission notice shall be included
@ in all copies or substantial portions of the Software.
@
@ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
@ OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
@ FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
@ THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
@ OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
@ ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
@ OTHER DEALINGS IN THE SOFTWARE.
@
@---------------------------------------------------------------------------------------------------

@-------------------------------------------------------------------------------------
@ Gumstix Overo Tide / OMAP3530, 720MHz MPU, 512MB RAM at 166 MHz (live_SD config.)
@ ------- FAMILY -----------
OMAP_35xx	= 1			@ TI OMAP 35xx family MCU
@ ------ Native USB --------
native_usb	= 1			@ comment this line out to assemble without usb support
@ ----- VFPv3 / NEON -------
hardware_FPU	= 1			@ comment this to use soft float (no VFP use)
@ ---- LEDs (Thumbo) -------
LEDIO		= 0x48310000		@ GPIO Port 1, controlling THUMBO board LED on/off pins
REDLED		= 0x01 << 21		@ bit 21, GPIO 21 (Thumbo red LED)
YELLED		= REDLED		@ aliased to red led
GRNLED		= 0x01 << 22		@ bit 22, GPIO 22 (Thumbo blue LED)
@ --- Live SD / SD Card ----
live_SD 	= 1			@ live SD version (no flash on this board)
onboard_SDFT	= 1			@ comment this to exlcude interface to on-board SD card
sd_is_on_mci	= 1
sd_mci		= mmc1_base		@ SD card is on mmc1
@ --------- FREQs -----------
@ Note: if the MPU is too hot at 720 MHz, use 600MHz for PLL1 below
PLL1_parms	= 0x0012d00c		@ PLL1: fclk=corclk/2, M=0x2d0, N=0x0c =>         X1 = 720 MHz
@PLL1_parms	= 0x0012580c		@ PLL1: fclk=corclk/2, M=0x258, N=0x0c =>         X1 = 600 MHz
PLL3_parms	= 0x094c0c00		@ PLL3: CORE -- M2=0x01, M=0x14c, N=0x0c, =>    M2X1 = 332 MHz
PLL4_parms	= 0x0001b00c		@ PLL4: PER  -- M=0x1b0, N=0x0c, => X1 = 432 MHz, X2 = 864 MHz
UART_DIVL	= 0x1A			@ low  divisor for 115200 baud if uart clk = 48 mhz
UART_DIVH	= 0x00			@ high divisor for 115200 baud if uart clk = 48 mhz
@ --------- RAM ------------
RAMBOTTOM	= 0x80000000		@ Bottom of SDRAM
RAMTOP		= 0xa0000000		@ 512MB
configure_CS1	= 256			@ configure CS1 and start it at 256 MB
SDRC_MCFG	= 0x03588099		@ RAS=14,CAS=10,256MB/bank,row-bank-col,32bit,mobeDDR,DpPwrDn
SDRC_ACTIM_A 	= 0x629db4c6		@ Micron MT46H128M32L2KQ-5 (D9LCH, 166 MHz)
SDRC_ACTIM_B 	= 0x00021213		@ (166 MHz)
SDRC_RFR_CTRL	= 0x0004dc01		@ 1294 (#x4dc + 50) -> 7.8 us / 6ns (166 MHz)
@ --------- BUFFERS --------
BUFFER_START	= RAMBOTTOM + 0x020000	@ 128kb into SDRAM
RBF_size	= 0x10000		@ READBUFFER size for tag as bytevector (64 KBytes incl. 4-byte tag)
WBF_size	= 0x10000		@ WRITEBUFFER size for tag as bytevector (64 KBytes incl. 4-byte tag)
heapbottom	= RAMBOTTOM + 0x100000	@ 1MB into SDRAM
I2C0ADR		= i2c0_base + i2c_address
@-------------------------------------------------------------------------------------
