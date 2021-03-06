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

/*----------------------------------------------------------------------------*\
|										|
|			1. Device Family Constants				|
|										|
|			(followed by device family macros)			|
|										|
\*----------------------------------------------------------------------------*/

@ family
AT91_SAM3S	= 1			@ ATMEL AT91SAM3S family MCU

@ architecture
cortex		= 1
.cpu		cortex-m3

@ writing to on-chip flash (done from RAM, reserve space for flsRAM of initio.s)
EXTRA_FILE_RAM	= 0x60

@ interrupts
num_interrupts	= 64
uart0_int_num	= 14			@ USART0
uart1_int_num	= 15			@ USART1
timer0_int_num	= 23			@ TC0
timer1_int_num	= 24			@ TC1
i2c0_int_num	= 19			@ TWI0
i2c1_int_num	= 20			@ TWI1
usb_int_num	= 34			@ UDP

int_status	= int_stat__0__31	@ where to find the timer interrupts

uart0_int	= 1 << (uart0_int_num  % 32)
uart1_int	= 1 << (uart1_int_num  % 32)
timer0_int	= 1 << (timer0_int_num % 32)
timer1_int	= 1 << (timer1_int_num % 32)
i2c0_int	= 1 << (i2c0_int_num   % 32)
i2c1_int	= 1 << (i2c1_int_num   % 32)
usb_int		= 1 << (usb_int_num    % 32)

scminten__0__31 = timer0_int|timer1_int|i2c0_int|i2c1_int|uart0_int|uart1_int
scminten_32__63 = usb_int

@ gpio
pioa_base	= 0x400E0E00		@ PIOA_PER  -- PIO Enable Reg
piob_base	= 0x400E1000		@ PIOB_PER  -- PIO Enable Reg
pioc_base	= 0x400E1200		@ PIOC_PER  -- PIO Enable Reg
io_dir		= 0x10			@ PIOA_OER  -- Output Enable Reg
io_set		= 0x30			@ PIOA_SODR -- Set Output Data Reg
io_clear	= 0x34			@ PIOA_CODR -- Clear Output Data Reg
io_pdsr 	= 0x3C			@ PIOA_PDSR -- Pin Data Status Reg
io_state 	= 0x3C			@ PIOA_PDSR -- Pin Data Status Reg (alt)

@ usarts
uart0_base	= 0x40024000		@ US0_CR
uart1_base	= 0x40028000		@ US1_CR
uart_istat	= 0x10			@ offset of US_IMR
uart_status	= 0x14			@ offset of US_CSR - uart status reg.
uart_rhr	= 0x18			@ offset to uart rhr register
uart_thr	= 0x1C			@ offset to uart thr register
uart_txrdy	= 0x02			@ bit indicating uart THR empty
uart_ier	= 0x08			@ interrupt enable  reg offset
uart_idr	= 0x0c			@ interrupt disable reg offset
uart_iRx_ena	= 1			@ value to enable  interrupts
uart_iRx_dis	= 1			@ value to disable interrupts

@ timers
timer0_base	= 0x40010000		@ TC0_CCR
timer1_base	= 0x40010040		@ TC1_CCR
timer_istat	= 0x20			@ offset of TC_SR
timer_iset	= 0x24			@ offset of TC_IER
timer_ctrl	= 0x00			@ offset of TC_CCR

@ i2c
i2c0_base	= 0x40018000		@ TWI0_CR
i2c1_base	= 0x4001C000		@ TWI1_CR
i2c_ctrl	= 0x00			@ TWI_CR
i2c_mode	= 0x04			@ TWI_MMR
i2c_address	= 0x08			@ TWI_SMR
i2c_status	= 0x20			@ TWI_SR
i2c_ienable	= 0x24			@ TWI_IER
i2c_iclear	= 0x28			@ TWI_IDR
@i2c_cclear	= i2c_iclear	@ needs to be updated
i2c_imask	= 0x2C			@ TWI_IMR
i2c_rhr		= 0x30			@ TWI_RHR
i2c_thr		= 0x34			@ TWI_THR
@TWI_IADR	= i2c0_base + 0x0C	@ R/W
i2c_iadr	= 0x0C			@ TWI_IADR -- internal address bytes
i2c_irm_rcv	= 0x02
i2c_irs_rcv	= 0x02

@ adc
adc0_base	= 0x40038000

@ pwm
pwm0_base	= 0x40020000

@ SPI
spi0_base	= 0x40008000
spi_rhr		= 0x08
spi_thr		= 0x0c
spi_status	= 0x10
spi_rxrdy	= 0x01
spi_txrdy	= 0x02

@ usb
usb_per_id	= 34			@ USB peripheral ID
usb_base	= 0x40034000		@ UDP_NUM
usb_glbstate	= 0x04			@ UDP_GLBSTATE -- Global State Reg
usb_faddr	= 0x08			@ UDP_FADDR    -- Function Address Reg
usb_ier		= 0x10			@ UDP_IER      -- Interrupt Enable Reg
usb_istat_dv	= 0x1C			@ UDP_ISR      -- Interrupt Status Reg
usb_istat_ep	= 0x1C			@ UDP_ISR      -- Interrupt Status Reg
usb_iclear_dv	= 0x20			@ UDP_ICR      -- Interrupt Clear  Reg
usb_iclear_ep	= 0x20			@ UDP_ICR      -- Interrupt Clear  Reg
usb_csr0	= 0x30			@ UDP_CSR0    -- EP Control/Status Reg
usb_csr1	= 0x34			@ UDP_CSR1    -- EP Control/Status Reg
usb_csr2	= 0x38			@ UDP_CSR2    -- EP Control/Status Reg
usb_ibulkin	= 0x3C			@ UDP_CSR3 ctrl/stat of EP 3 (Bulk IN)
usb_fdr0	= 0x50			@ UDP_FDR0   -- Endpoint FIFO Data Reg
usb_fdr3	= 0x5C			@ UDP_FDR3   -- Endpoint FIFO Data Reg
usb_iep_mask	= 0x000F		@ mask for enpoint interrupt
usb_idv_mask	= 0xFF00		@ mask for device status interrupt
usb_busreset	= 0x1000		@ bus reset bit
usb_suspend	= 0x0100		@ suspend bit
usb_txrdy	= 0x10			@ Tx ready bit in usb_iBulk_IN
usb_itxendp	= 0x80			@ Tx end of packet interrupt bit
UsbControlOutEP	= 0x00			@ Control OUT Endpoint
UsbControlInEP	= 0x00			@ Control IN  Endpoint (same as ctl out)
UsbBulkOutEP	= 0x02			@ Bulk OUT EP
UsbBulkInEP	= 0x03			@ Bulk IN  EP
usbBulkINDescr	= 0x83			@ Bulk IN is EP 3 (for desc at end file)
usbCO_ibit	= 0x01			@ bit indic int for Control OUT Endpoint
usbCI_ibit	= 0x02			@ bit indic int for Control IN  Endpoint
usbBO_ibit	= 0x04			@ bit indic int for Bulk    OUT Endpoint
usbBI_ibit	= 0x08			@ bit indic int for Bulk    IN  Endpoint
usbCO_setupbit	= 0x04			@ EP stat bit if last tfer was SETUP pkt

@ Other Constants
PMC_base	= 0x400E0400		@ PMC  (power management controller) 

@ FLASH
EEFC_base    	= 0x400E0A00		@ EEFC Flash Controller
MC_FCR    	= 0x400E0A04		@ EEFC Flash Command Register
MC_FSR    	= 0x400E0A08		@ EEFC Flash Status Register
flash_erase_cmd	= 0x5A000003		@ flash erase then write CMD for page 0

/*----------------------------------------------------------------------------*\
|										|
|			2. Device Family Macros					|
|										|
\*----------------------------------------------------------------------------*/

.macro	clearUartInt	
	@ clear interrupt in uart with base address in rva
	read	cnt, rva, #uart_istat	@ cnt <- int status (clears UART int)
.endm


.macro	clearTimerInt	
	@ clear interrupt in timer peripheral block with base address in rva
	read	rvc, rva, #timer_istat	@ at91sam7
	write	rvc, rva, #timer_iset	@ lpc2000
	set	rvc, 0			@ rvc <- 0
	write	rvc, rva, #timer_iset	@ str711, STM32
.endm



