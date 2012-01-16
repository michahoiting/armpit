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

@ startup
rst_direct_branch	= 1		@ use direct branch in reset vector for dataflash boot

@ interrupts
irq_direct_branch	= 1		@ branch to genisr diectly on interrupt (instead of VIC)
num_interrupts	= 32
uart0_int_num	= 1			@ DBGU uart
uart1_int_num	= 7
timer0_int_num	= 17
timer1_int_num	= 18
i2c0_int_num	= 11
i2c1_int_num	= 11
usb_int_num	= 10
int_voffset	= -0x0F20
int_base	= 0xFFFFF100		@ AIC_IVR
int_status	= 0x0C			@ AIC_IPR
int_enable	= 0x20			@ AIC_IECR
int_disable	= 0x24			@ AIC_IDCR
int_clear_vals	= 0x00
int_clear	= 0x30			@ AIC_EOICR
int_iccr  	= 0x28			@ AIC_ICCR -- Interrupt Clear Command Register
uart0_int	= 1 << uart0_int_num	@ bit
uart1_int	= 1 << uart1_int_num	@ bit
timer0_int	= 1 << timer0_int_num	@ bit
timer1_int	= 1 << timer1_int_num	@ bit
i2c0_int	= 1 << i2c0_int_num	@ bit
i2c1_int	= 1 << i2c1_int_num	@ bit
usb_int		= 1 << usb_int_num	@ bit
scheme_ints_enb	= timer0_int | timer1_int | i2c0_int | i2c1_int | uart0_int | uart1_int | usb_int

@ gpio -- APB Peripheral #2 -- Constants for PIOA
pioa_base	= 0xFFFFF400		@ PIOA_PER  -- PIO A Enable Register
piob_base	= 0xFFFFF600		@ PIOB_PER  -- PIO B Enable Register
pioc_base	= 0xFFFFF800		@ PIOC_PER  -- PIO C Enable Register

io_dir		= 0x10			@ PIOA_OER  -- Output Enable Register
io_set		= 0x30			@ PIOA_SODR -- Set Output Data Register
io_clear	= 0x34			@ PIOA_CODR -- Clear Output Data Register
io_pdsr 	= 0x3C			@ PIOA_PDSR -- Pin Data Status Register
io_state 	= 0x3C			@ PIOA_PDSR -- Pin Data Status Register (alternate name)

@ uarts -- APB Peripheral #6 
uart0_base	= 0xFFFFF200		@ DBGU_CR  uart in debug unit
uart1_base	= 0xFFFB4000		@ US1_CR

uart_istat	= 0x10			@ offset of US_IMR
uart_status	= 0x14			@ offset of US_CSR - uart status register
uart_rhr	= 0x18			@ offset to uart rhr register
uart_thr	= 0x1C			@ offset to uart thr register
uart_txrdy	= 0x02			@ bit indicating uart THR empty

@ timers
timer0_base	= 0xFFFA0000		@ TC0_CCR
timer1_base	= 0xFFFA0040		@ TC1_CCR

timer_istat	= 0x20			@ offset of TC_SR
timer_iset	= 0x24			@ offset of TC_IER
timer_ctrl	= 0x00			@ offset of TC_CCR

@ i2c
i2c0_base	= 0xFFFAC000		@ TWI_CR
i2c1_base	= i2c0_base

i2c_ctrl	= 0x00			@ TWI_CR
i2c_mode	= 0x04			@ TWI_MMR
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
@
@ no on-chip adc
@
adc0_base	= 0xfffd8000

@ pwm
@
@ no on-chip pwm (maybe use timer)
@
pwm0_base	= 0xfffcc000

@ SPI
spi0_base	= 0xfffc8000
spi1_base	= 0xfffcc000

spi_rhr		= 0x08
spi_thr		= 0x0c
spi_status	= 0x10
spi_rxrdy	= 0x01
spi_txrdy	= 0x02

@ usb -- APB Peripheral #11
usb_base	= 0xFFFA4000		@ UDP_NUM

usb_glbstate	= 0x04			@ UDP_GLBSTATE -- Global State Register
usb_faddr	= 0x08			@ UDP_FADDR    -- Function Address Register
usb_ier		= 0x10			@ UDP_IER -- Interrupt Enable Register
usb_istat_dv	= 0x1C			@ UDP_ISR
usb_istat_ep	= 0x1C			@ UDP_ISR
usb_iclear_dv	= 0x20			@ UDP_ICR
usb_iclear_ep	= 0x20			@ UDP_ICR
usb_csr0	= 0x30			@ UDP_CSR0 -- Endpoint Control and Status Register
usb_csr1	= 0x34			@ UDP_CSR1 -- Endpoint Control and Status Register
usb_csr2	= 0x38			@ UDP_CSR2 -- Endpoint Control and Status Register
usb_ibulkin	= 0x3C			@ UDP_CSR3 control and status of EP 3 (Bulk IN)
usb_fdr0	= 0x50			@ UDP_FDR0     -- Endpoint FIFO Data Register
usb_fdr3	= 0x5C			@ UDP_FDR3     -- Endpoint FIFO Data Register
usb_iep_mask	= 0x000F		@ mask for enpoint interrupt
usb_idv_mask	= 0xFF00		@ mask for device status interrupt
usb_busreset	= 0x1000		@ bus reset bit
usb_suspend	= 0x0100		@ suspend bit
usb_txrdy	= 0x10			@ Tx ready bit in usb_iBulk_IN
usb_itxendp	= 0x80			@ Tx end of packet interrupt bit
UsbControlOutEP	= 0x00			@ Control OUT Endpoint
UsbControlInEP	= 0x00			@ Control IN  Endpoint (same as control out)
UsbBulkOutEP	= 0x02			@ Bulk OUT EP
UsbBulkInEP	= 0x03			@ Bulk IN  EP
usbBulkINDescr	= 0x83			@ Bulk IN is EP 3 (for descriptor at end of file)
usbCO_ibit	= 0x01			@ bit indicating interrupt for Control OUT Endpoint
usbCI_ibit	= 0x02			@ bit indicating interrupt for Control IN  Endpoint
usbBO_ibit	= 0x04			@ bit indicating interrupt for Bulk    OUT Endpoint
usbBI_ibit	= 0x08			@ bit indicating interrupt for Bulk    IN  Endpoint
usbCO_setupbit	= 0x04			@ EP status bit indicating last transfer was a SETUP packet

@ APB Peripheral #0 -- Constants for AIC 
AIC_SMR   	= 0xFFFFF000		@ (AIC) Source Mode Register
AIC_SVR0	= 0xFFFFF080		@ (AIC) Source Vector Register
AIC_SVR1	= 0xFFFFF084		@ (AIC) Source Vector Register
AIC_SVR6	= 0xFFFFF098		@ (AIC) Source Vector Register
AIC_SVR7	= 0xFFFFF09C		@ (AIC) Source Vector Register
AIC_SVR9	= 0xFFFFF0A4		@ (AIC) Source Vector Register
AIC_SVR11	= 0xFFFFF0AC		@ (AIC) Source Vector Register
AIC_SVR12	= 0xFFFFF0B0		@ (AIC) Source Vector Register
AIC_SVR13	= 0xFFFFF0B4		@ (AIC) Source Vector Register
AIC_IVR   	= 0xFFFFF100		@ (AIC) IRQ Vector Register
AIC_FVR   	= 0xFFFFF104		@ (AIC) FIQ Vector Register
AIC_ISR   	= 0xFFFFF108		@ (AIC) Interrupt Status Register
AIC_IPR   	= 0xFFFFF10C		@ (AIC) Interrupt Pending Register
AIC_IMR   	= 0xFFFFF110		@ (AIC) Interrupt Mask Register
AIC_CISR  	= 0xFFFFF114		@ (AIC) Core Interrupt Status Register
AIC_IECR  	= 0xFFFFF120		@ (AIC) Interrupt Enable Command Register
AIC_IDCR  	= 0xFFFFF124		@ (AIC) Interrupt Disable Command Register
AIC_ICCR  	= 0xFFFFF128		@ (AIC) Interrupt Clear Command Register
AIC_ISCR  	= 0xFFFFF12C		@ (AIC) Interrupt Set Command Register
AIC_EOICR 	= 0xFFFFF130		@ (AIC) End of Interrupt Command Register
AIC_SPU   	= 0xFFFFF134		@ (AIC) Spurious Vector Register
AIC_DCR   	= 0xFFFFF138		@ (AIC) Debug Control Register (Protect)
AIC_FFER  	= 0xFFFFF140		@ (AIC) Fast Forcing Enable Register
AIC_FFDR  	= 0xFFFFF144		@ (AIC) Fast Forcing Disable Register
AIC_FFSR  	= 0xFFFFF148		@ (AIC) Fast Forcing Status Register

@ Constants for MC 
@
@  not used (no on-chip flash)
@
MC_FCR    	= 0xFFFFFF64		@ (MC) MC Flash Command Register
MC_FSR    	= 0xFFFFFF68		@ (MC) MC Flash Status Register

@ Power, Clocks
PMC_base	= 0xFFFFFC00
