/*------------------------------------------------------------------------------
@
@  ARMPIT SCHEME Version 070
@
@  ARMPIT SCHEME is distributed under The MIT License.

@  Copyright (c) 2006-2014 Hubert Montas

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
@-----------------------------------------------------------------------------*/

@-------10--------20--------30--------40--------50--------60--------70--------80

/* =======  BOARD =========== */
GMX_OVERO_TIDE	= 1		@ Gumstix Overo Tide OMAP3530, 720MHz, 512MB RAM

/* ======= OPTIONS ========== */
live_SD 	= 1		@ live SD version (no flash on this board)
hardware_FPU	= 1		@ use the FPU (for floats)
enable_MPU	= 1		@ use the MPU (via MMU)
native_usb	= 1		@ include usb support
onboard_SDFT	= 1		@ include SD card file subsystem
@sdhc_on_sd_mmc	= 1		@ use SDHC cards on MMC interface (no normal SD)

/* ===== CONFIGURATION ====== */
@ ---- LEDs (Thumbo) -------
LEDIO		= io1_base	@ GPIO Port 1, control THUMBO board LED on/off
rled_pin	= 21		@ bit 21, GPIO 21 (Thumbo red LED)
yled_pin	= rled_pin	@ aliased
gled_pin	= 22		@ bit 22, GPIO 22 (Thumbo blue LED)
RLED_PDCNF_OFST	= 0x5ea		@ ofst frm SCM_base to gpio_21 CONTROL_PADCONF_
GLED_PDCNF_OFST	= 0x5ec		@ ofst frm SCM_base to gpio_22 CONTROL_PADCONF_
@ ----- BOOT OVERRIDE -------
BOOTOVERRID_PRT	= io1_base	@ Boot-override GPIO for button (gpio_14)
BOOTOVERRID_BUT	= 14		@ Boot-override button is gpio_14
@ --- Live SD / SD Card ----
sd_is_on_mci	= 1		@ SD card uses MCI interface
sd_mci		= mmc1_base	@ SD card is on mmc1
@ --------- FREQs -----------
@ Note: if the MPU is too hot at 720 MHz, use 600MHz for PLL1 below
@PLL1_parms	= 0x0012d00c	@ PLL1 fclk=corclk/2 M=0x2d0 N=0x0c => X1=720MHz
PLL1_parms	= 0x0012580c	@ PLL1 fclk=corclk/2 M=0x258 N=0x0c => X1=600MHz
PLL3_parms	= 0x094c0c00	@ PLL3 CORE M2=0x01 M=0x14c N=0x0c > M2X1=332MHz
PLL4_parms	= 0x0001b00c	@ PLL4 PER  M=0x1b0 N=0x0c > X1=432MHz X2=864MHz
@UART_DIVL	= 0x4e		@ low  div for  38400 baud, uart clk = 48 MHz
@UART_DIVL	= 0x34		@ low  div for  57600 baud, uart clk = 48 MHz
UART_DIVL	= 26		@ low  div for 115200 baud, uart clk = 48 MHz
UART_DIVH	= 0		@ high div with uart clk = 48 MHz
@ --------- RAM ------------
RAMBOTTOM	= 0x80000000	@ Bottom of SDRAM
RAMTOP		= 0xa0000000	@ 512MB
configure_CS1	= 256		@ configure CS1 and start it at 256 MB
SDRC_MCFG	= 0x03588099	@ RAS14,CAS10,256MB/bk,rwbkcl,32b,mobDDR,DpPwrDn
SDRC_ACTIM_A 	= 0x629db4c6	@ Micron MT46H128M32L2KQ-5 (D9LCH, 166 MHz)
SDRC_ACTIM_B 	= 0x00021213	@ (166 MHz)
SDRC_RFR_CTRL	= 0x0004dc01	@ 1294 (#x4dc + 50) -> 7.8 us / 6ns (166 MHz)
@ --------- BUFFERS --------
BUFFER_START	= RAMBOTTOM+0x020000+4	@ 128kb into SDRAM
RBF_size	= 0x10000	@ READBUFFER  size for tag as bytevector (64 KB)
WBF_size	= 0x10000	@ WRITEBUFFER size for tag as bytevector (64 KB)
heapbottom	= RAMBOTTOM + 0x100000	@ 1MB into SDRAM
I2C0ADR		= i2c0_base + i2c_address

@-------10--------20--------30--------40--------50--------60--------70--------80




