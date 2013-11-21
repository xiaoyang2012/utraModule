/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2' in SOPC Builder design 'kernel'
 * SOPC Builder design path: E:/work/utraScan/code/utraSonic/utraModule/kernel/kernel.sopcinfo
 *
 * Generated: Thu Nov 21 10:40:03 CST 2013
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * AD_CNT configuration
 *
 */

#define AD_CNT_BASE 0x10041120
#define AD_CNT_BIT_CLEARING_EDGE_REGISTER 0
#define AD_CNT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define AD_CNT_CAPTURE 0
#define AD_CNT_DATA_WIDTH 16
#define AD_CNT_DO_TEST_BENCH_WIRING 0
#define AD_CNT_DRIVEN_SIM_VALUE 0x0
#define AD_CNT_EDGE_TYPE "NONE"
#define AD_CNT_FREQ 50000000u
#define AD_CNT_HAS_IN 0
#define AD_CNT_HAS_OUT 1
#define AD_CNT_HAS_TRI 0
#define AD_CNT_IRQ -1
#define AD_CNT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AD_CNT_IRQ_TYPE "NONE"
#define AD_CNT_NAME "/dev/AD_CNT"
#define AD_CNT_RESET_VALUE 0x0
#define AD_CNT_SPAN 16
#define AD_CNT_TYPE "altera_avalon_pio"
#define ALT_MODULE_CLASS_AD_CNT altera_avalon_pio


/*
 * AD_CTRL configuration
 *
 */

#define AD_CTRL_BASE 0x10041110
#define AD_CTRL_BIT_CLEARING_EDGE_REGISTER 0
#define AD_CTRL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define AD_CTRL_CAPTURE 0
#define AD_CTRL_DATA_WIDTH 8
#define AD_CTRL_DO_TEST_BENCH_WIRING 0
#define AD_CTRL_DRIVEN_SIM_VALUE 0x0
#define AD_CTRL_EDGE_TYPE "NONE"
#define AD_CTRL_FREQ 50000000u
#define AD_CTRL_HAS_IN 0
#define AD_CTRL_HAS_OUT 1
#define AD_CTRL_HAS_TRI 0
#define AD_CTRL_IRQ -1
#define AD_CTRL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AD_CTRL_IRQ_TYPE "NONE"
#define AD_CTRL_NAME "/dev/AD_CTRL"
#define AD_CTRL_RESET_VALUE 0x0
#define AD_CTRL_SPAN 16
#define AD_CTRL_TYPE "altera_avalon_pio"
#define ALT_MODULE_CLASS_AD_CTRL altera_avalon_pio


/*
 * AD_STATUS configuration
 *
 */

#define AD_STATUS_BASE 0x10041100
#define AD_STATUS_BIT_CLEARING_EDGE_REGISTER 0
#define AD_STATUS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define AD_STATUS_CAPTURE 0
#define AD_STATUS_DATA_WIDTH 4
#define AD_STATUS_DO_TEST_BENCH_WIRING 0
#define AD_STATUS_DRIVEN_SIM_VALUE 0x0
#define AD_STATUS_EDGE_TYPE "NONE"
#define AD_STATUS_FREQ 50000000u
#define AD_STATUS_HAS_IN 1
#define AD_STATUS_HAS_OUT 0
#define AD_STATUS_HAS_TRI 0
#define AD_STATUS_IRQ -1
#define AD_STATUS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AD_STATUS_IRQ_TYPE "NONE"
#define AD_STATUS_NAME "/dev/AD_STATUS"
#define AD_STATUS_RESET_VALUE 0x0
#define AD_STATUS_SPAN 16
#define AD_STATUS_TYPE "altera_avalon_pio"
#define ALT_MODULE_CLASS_AD_STATUS altera_avalon_pio


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x10040820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x10020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1d
#define ALT_CPU_NAME "nios2"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x10020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x10040820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x10020020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1d
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x10020000


/*
 * DDR3_MEM configuration
 *
 */

#define ALT_MODULE_CLASS_DDR3_MEM altera_mem_if_ddr3_emif
#define DDR3_MEM_BASE 0x0
#define DDR3_MEM_IRQ -1
#define DDR3_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DDR3_MEM_NAME "/dev/DDR3_MEM"
#define DDR3_MEM_SPAN 268435456
#define DDR3_MEM_TYPE "altera_mem_if_ddr3_emif"


/*
 * DDR3_MEM configuration as viewed by DMA_READ_m_read
 *
 */

#define DMA_READ_M_READ_DDR3_MEM_BASE 0x0
#define DMA_READ_M_READ_DDR3_MEM_IRQ -1
#define DMA_READ_M_READ_DDR3_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_READ_M_READ_DDR3_MEM_NAME "/dev/DDR3_MEM"
#define DMA_READ_M_READ_DDR3_MEM_SPAN 268435456
#define DMA_READ_M_READ_DDR3_MEM_TYPE "altera_mem_if_ddr3_emif"


/*
 * DDR3_MEM configuration as viewed by DMA_WRITE_m_write
 *
 */

#define DMA_WRITE_M_WRITE_DDR3_MEM_BASE 0x0
#define DMA_WRITE_M_WRITE_DDR3_MEM_IRQ -1
#define DMA_WRITE_M_WRITE_DDR3_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DMA_WRITE_M_WRITE_DDR3_MEM_NAME "/dev/DDR3_MEM"
#define DMA_WRITE_M_WRITE_DDR3_MEM_SPAN 268435456
#define DMA_WRITE_M_WRITE_DDR3_MEM_TYPE "altera_mem_if_ddr3_emif"


/*
 * DMA_READ configuration
 *
 */

#define ALT_MODULE_CLASS_DMA_READ altera_avalon_sgdma
#define DMA_READ_ADDRESS_WIDTH 32
#define DMA_READ_ALWAYS_DO_MAX_BURST 1
#define DMA_READ_ATLANTIC_CHANNEL_DATA_WIDTH 4
#define DMA_READ_AVALON_MM_BYTE_REORDER_MODE 0
#define DMA_READ_BASE 0x10041000
#define DMA_READ_BURST_DATA_WIDTH 8
#define DMA_READ_BURST_TRANSFER 0
#define DMA_READ_BYTES_TO_TRANSFER_DATA_WIDTH 16
#define DMA_READ_CHAIN_WRITEBACK_DATA_WIDTH 32
#define DMA_READ_COMMAND_FIFO_DATA_WIDTH 104
#define DMA_READ_CONTROL_DATA_WIDTH 8
#define DMA_READ_CONTROL_SLAVE_ADDRESS_WIDTH 0x4
#define DMA_READ_CONTROL_SLAVE_DATA_WIDTH 32
#define DMA_READ_DESCRIPTOR_READ_BURST 0
#define DMA_READ_DESC_DATA_WIDTH 32
#define DMA_READ_HAS_READ_BLOCK 1
#define DMA_READ_HAS_WRITE_BLOCK 0
#define DMA_READ_IN_ERROR_WIDTH 0
#define DMA_READ_IRQ 2
#define DMA_READ_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_READ_NAME "/dev/DMA_READ"
#define DMA_READ_OUT_ERROR_WIDTH 0
#define DMA_READ_READ_BLOCK_DATA_WIDTH 32
#define DMA_READ_READ_BURSTCOUNT_WIDTH 4
#define DMA_READ_SPAN 64
#define DMA_READ_STATUS_TOKEN_DATA_WIDTH 24
#define DMA_READ_STREAM_DATA_WIDTH 32
#define DMA_READ_SYMBOLS_PER_BEAT 4
#define DMA_READ_TYPE "altera_avalon_sgdma"
#define DMA_READ_UNALIGNED_TRANSFER 0
#define DMA_READ_WRITE_BLOCK_DATA_WIDTH 32
#define DMA_READ_WRITE_BURSTCOUNT_WIDTH 4


/*
 * DMA_WRITE configuration
 *
 */

#define ALT_MODULE_CLASS_DMA_WRITE altera_avalon_sgdma
#define DMA_WRITE_ADDRESS_WIDTH 32
#define DMA_WRITE_ALWAYS_DO_MAX_BURST 1
#define DMA_WRITE_ATLANTIC_CHANNEL_DATA_WIDTH 4
#define DMA_WRITE_AVALON_MM_BYTE_REORDER_MODE 0
#define DMA_WRITE_BASE 0x10041040
#define DMA_WRITE_BURST_DATA_WIDTH 8
#define DMA_WRITE_BURST_TRANSFER 0
#define DMA_WRITE_BYTES_TO_TRANSFER_DATA_WIDTH 16
#define DMA_WRITE_CHAIN_WRITEBACK_DATA_WIDTH 32
#define DMA_WRITE_COMMAND_FIFO_DATA_WIDTH 104
#define DMA_WRITE_CONTROL_DATA_WIDTH 8
#define DMA_WRITE_CONTROL_SLAVE_ADDRESS_WIDTH 0x4
#define DMA_WRITE_CONTROL_SLAVE_DATA_WIDTH 32
#define DMA_WRITE_DESCRIPTOR_READ_BURST 0
#define DMA_WRITE_DESC_DATA_WIDTH 32
#define DMA_WRITE_HAS_READ_BLOCK 0
#define DMA_WRITE_HAS_WRITE_BLOCK 1
#define DMA_WRITE_IN_ERROR_WIDTH 0
#define DMA_WRITE_IRQ 1
#define DMA_WRITE_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DMA_WRITE_NAME "/dev/DMA_WRITE"
#define DMA_WRITE_OUT_ERROR_WIDTH 0
#define DMA_WRITE_READ_BLOCK_DATA_WIDTH 32
#define DMA_WRITE_READ_BURSTCOUNT_WIDTH 4
#define DMA_WRITE_SPAN 64
#define DMA_WRITE_STATUS_TOKEN_DATA_WIDTH 24
#define DMA_WRITE_STREAM_DATA_WIDTH 32
#define DMA_WRITE_SYMBOLS_PER_BEAT 4
#define DMA_WRITE_TYPE "altera_avalon_sgdma"
#define DMA_WRITE_UNALIGNED_TRANSFER 0
#define DMA_WRITE_WRITE_BLOCK_DATA_WIDTH 32
#define DMA_WRITE_WRITE_BURSTCOUNT_WIDTH 4


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SGDMA
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_UART
#define __ALTERA_MEM_IF_DDR3_EMIF
#define __ALTERA_NIOS2_QSYS


/*
 * MCU_PIO configuration
 *
 */

#define ALT_MODULE_CLASS_MCU_PIO altera_avalon_pio
#define MCU_PIO_BASE 0x10041130
#define MCU_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define MCU_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MCU_PIO_CAPTURE 0
#define MCU_PIO_DATA_WIDTH 7
#define MCU_PIO_DO_TEST_BENCH_WIRING 0
#define MCU_PIO_DRIVEN_SIM_VALUE 0x0
#define MCU_PIO_EDGE_TYPE "NONE"
#define MCU_PIO_FREQ 50000000u
#define MCU_PIO_HAS_IN 1
#define MCU_PIO_HAS_OUT 0
#define MCU_PIO_HAS_TRI 0
#define MCU_PIO_IRQ 7
#define MCU_PIO_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MCU_PIO_IRQ_TYPE "LEVEL"
#define MCU_PIO_NAME "/dev/MCU_PIO"
#define MCU_PIO_RESET_VALUE 0x0
#define MCU_PIO_SPAN 16
#define MCU_PIO_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x10041150
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x10041150
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x10041150
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "kernel"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x10041150
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x10041140
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 4
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0x0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000u
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0x0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * onchip_memory configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_BASE 0x10020000
#define ONCHIP_MEMORY_CONTENTS_INFO ""
#define ONCHIP_MEMORY_DUAL_PORT 0
#define ONCHIP_MEMORY_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEMORY_INIT_CONTENTS_FILE "onchip_memory"
#define ONCHIP_MEMORY_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_IRQ -1
#define ONCHIP_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_NAME "/dev/onchip_memory"
#define ONCHIP_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SIZE_VALUE 81920u
#define ONCHIP_MEMORY_SPAN 81920
#define ONCHIP_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_WRITABLE 1


/*
 * spi1 configuration
 *
 */

#define ALT_MODULE_CLASS_spi1 altera_avalon_spi
#define SPI1_BASE 0x100410a0
#define SPI1_CLOCKMULT 1
#define SPI1_CLOCKPHASE 0
#define SPI1_CLOCKPOLARITY 0
#define SPI1_CLOCKUNITS "Hz"
#define SPI1_DATABITS 8
#define SPI1_DATAWIDTH 16
#define SPI1_DELAYMULT "1.0E-9"
#define SPI1_DELAYUNITS "ns"
#define SPI1_EXTRADELAY 0
#define SPI1_INSERT_SYNC 0
#define SPI1_IRQ 5
#define SPI1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI1_ISMASTER 0
#define SPI1_LSBFIRST 0
#define SPI1_NAME "/dev/spi1"
#define SPI1_NUMSLAVES 1
#define SPI1_PREFIX "spi_"
#define SPI1_SPAN 32
#define SPI1_SYNC_REG_DEPTH 2
#define SPI1_TARGETCLOCK 128000u
#define SPI1_TARGETSSDELAY "0.0"
#define SPI1_TYPE "altera_avalon_spi"


/*
 * spi2 configuration
 *
 */

#define ALT_MODULE_CLASS_spi2 altera_avalon_spi
#define SPI2_BASE 0x10041080
#define SPI2_CLOCKMULT 1
#define SPI2_CLOCKPHASE 0
#define SPI2_CLOCKPOLARITY 0
#define SPI2_CLOCKUNITS "Hz"
#define SPI2_DATABITS 8
#define SPI2_DATAWIDTH 16
#define SPI2_DELAYMULT "1.0E-9"
#define SPI2_DELAYUNITS "ns"
#define SPI2_EXTRADELAY 0
#define SPI2_INSERT_SYNC 0
#define SPI2_IRQ 6
#define SPI2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI2_ISMASTER 0
#define SPI2_LSBFIRST 0
#define SPI2_NAME "/dev/spi2"
#define SPI2_NUMSLAVES 1
#define SPI2_PREFIX "spi_"
#define SPI2_SPAN 32
#define SPI2_SYNC_REG_DEPTH 2
#define SPI2_TARGETCLOCK 128000u
#define SPI2_TARGETSSDELAY "0.0"
#define SPI2_TYPE "altera_avalon_spi"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x10041158
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1385000072
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * uart1 configuration
 *
 */

#define ALT_MODULE_CLASS_uart1 altera_avalon_uart
#define UART1_BASE 0x100410c0
#define UART1_BAUD 9600
#define UART1_DATA_BITS 8
#define UART1_FIXED_BAUD 1
#define UART1_FREQ 50000000u
#define UART1_IRQ 3
#define UART1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART1_NAME "/dev/uart1"
#define UART1_PARITY 'N'
#define UART1_SIM_CHAR_STREAM ""
#define UART1_SIM_TRUE_BAUD 1
#define UART1_SPAN 32
#define UART1_STOP_BITS 1
#define UART1_SYNC_REG_DEPTH 2
#define UART1_TYPE "altera_avalon_uart"
#define UART1_USE_CTS_RTS 0
#define UART1_USE_EOP_REGISTER 0


/*
 * uart_test configuration
 *
 */

#define ALT_MODULE_CLASS_uart_test altera_avalon_uart
#define UART_TEST_BASE 0x100410e0
#define UART_TEST_BAUD 9600
#define UART_TEST_DATA_BITS 8
#define UART_TEST_FIXED_BAUD 1
#define UART_TEST_FREQ 50000000u
#define UART_TEST_IRQ 4
#define UART_TEST_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_TEST_NAME "/dev/uart_test"
#define UART_TEST_PARITY 'N'
#define UART_TEST_SIM_CHAR_STREAM ""
#define UART_TEST_SIM_TRUE_BAUD 1
#define UART_TEST_SPAN 32
#define UART_TEST_STOP_BITS 1
#define UART_TEST_SYNC_REG_DEPTH 2
#define UART_TEST_TYPE "altera_avalon_uart"
#define UART_TEST_USE_CTS_RTS 0
#define UART_TEST_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
