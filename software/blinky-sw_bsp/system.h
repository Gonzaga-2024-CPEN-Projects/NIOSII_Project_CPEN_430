/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'blinky'
 * SOPC Builder design path: ../../blinky.sopcinfo
 *
 * Generated: Wed Nov 29 13:31:11 PST 2023
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
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00010000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00010000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
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
#define ALT_STDERR_BASE 0x210d0
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x210d0
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x210d0
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "blinky"


/*
 * grn_leds configuration
 *
 */

#define ALT_MODULE_CLASS_grn_leds altera_avalon_pio
#define GRN_LEDS_BASE 0x21020
#define GRN_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define GRN_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GRN_LEDS_CAPTURE 0
#define GRN_LEDS_DATA_WIDTH 8
#define GRN_LEDS_DO_TEST_BENCH_WIRING 0
#define GRN_LEDS_DRIVEN_SIM_VALUE 0
#define GRN_LEDS_EDGE_TYPE "NONE"
#define GRN_LEDS_FREQ 50000000
#define GRN_LEDS_HAS_IN 0
#define GRN_LEDS_HAS_OUT 1
#define GRN_LEDS_HAS_TRI 0
#define GRN_LEDS_IRQ -1
#define GRN_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GRN_LEDS_IRQ_TYPE "NONE"
#define GRN_LEDS_NAME "/dev/grn_leds"
#define GRN_LEDS_RESET_VALUE 0
#define GRN_LEDS_SPAN 16
#define GRN_LEDS_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x210d0
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
 * keys configuration
 *
 */

#define ALT_MODULE_CLASS_keys altera_avalon_pio
#define KEYS_BASE 0x21000
#define KEYS_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_CAPTURE 0
#define KEYS_DATA_WIDTH 3
#define KEYS_DO_TEST_BENCH_WIRING 0
#define KEYS_DRIVEN_SIM_VALUE 0
#define KEYS_EDGE_TYPE "NONE"
#define KEYS_FREQ 50000000
#define KEYS_HAS_IN 1
#define KEYS_HAS_OUT 0
#define KEYS_HAS_TRI 0
#define KEYS_IRQ -1
#define KEYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEYS_IRQ_TYPE "NONE"
#define KEYS_NAME "/dev/keys"
#define KEYS_RESET_VALUE 0
#define KEYS_SPAN 16
#define KEYS_TYPE "altera_avalon_pio"


/*
 * onchip_ram configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_ram altera_avalon_onchip_memory2
#define ONCHIP_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_RAM_BASE 0x10000
#define ONCHIP_RAM_CONTENTS_INFO ""
#define ONCHIP_RAM_DUAL_PORT 0
#define ONCHIP_RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_INIT_CONTENTS_FILE "blinky_onchip_ram"
#define ONCHIP_RAM_INIT_MEM_CONTENT 0
#define ONCHIP_RAM_INSTANCE_ID "NONE"
#define ONCHIP_RAM_IRQ -1
#define ONCHIP_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_RAM_NAME "/dev/onchip_ram"
#define ONCHIP_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_RAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_RAM_SINGLE_CLOCK_OP 0
#define ONCHIP_RAM_SIZE_MULTIPLE 1
#define ONCHIP_RAM_SIZE_VALUE 65536
#define ONCHIP_RAM_SPAN 65536
#define ONCHIP_RAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_RAM_WRITABLE 1


/*
 * randoms configuration
 *
 */

#define ALT_MODULE_CLASS_randoms altera_avalon_pio
#define RANDOMS_BASE 0x210a0
#define RANDOMS_BIT_CLEARING_EDGE_REGISTER 0
#define RANDOMS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RANDOMS_CAPTURE 0
#define RANDOMS_DATA_WIDTH 32
#define RANDOMS_DO_TEST_BENCH_WIRING 0
#define RANDOMS_DRIVEN_SIM_VALUE 0
#define RANDOMS_EDGE_TYPE "NONE"
#define RANDOMS_FREQ 50000000
#define RANDOMS_HAS_IN 1
#define RANDOMS_HAS_OUT 0
#define RANDOMS_HAS_TRI 0
#define RANDOMS_IRQ -1
#define RANDOMS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RANDOMS_IRQ_TYPE "NONE"
#define RANDOMS_NAME "/dev/randoms"
#define RANDOMS_RESET_VALUE 0
#define RANDOMS_SPAN 16
#define RANDOMS_TYPE "altera_avalon_pio"


/*
 * red_leds configuration
 *
 */

#define ALT_MODULE_CLASS_red_leds altera_avalon_pio
#define RED_LEDS_BASE 0x21010
#define RED_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define RED_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RED_LEDS_CAPTURE 0
#define RED_LEDS_DATA_WIDTH 17
#define RED_LEDS_DO_TEST_BENCH_WIRING 0
#define RED_LEDS_DRIVEN_SIM_VALUE 0
#define RED_LEDS_EDGE_TYPE "NONE"
#define RED_LEDS_FREQ 50000000
#define RED_LEDS_HAS_IN 0
#define RED_LEDS_HAS_OUT 1
#define RED_LEDS_HAS_TRI 0
#define RED_LEDS_IRQ -1
#define RED_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RED_LEDS_IRQ_TYPE "NONE"
#define RED_LEDS_NAME "/dev/red_leds"
#define RED_LEDS_RESET_VALUE 0
#define RED_LEDS_SPAN 16
#define RED_LEDS_TYPE "altera_avalon_pio"


/*
 * sev_seg_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_0 altera_avalon_pio
#define SEV_SEG_0_BASE 0x210b0
#define SEV_SEG_0_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_0_CAPTURE 0
#define SEV_SEG_0_DATA_WIDTH 7
#define SEV_SEG_0_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_0_DRIVEN_SIM_VALUE 0
#define SEV_SEG_0_EDGE_TYPE "NONE"
#define SEV_SEG_0_FREQ 50000000
#define SEV_SEG_0_HAS_IN 0
#define SEV_SEG_0_HAS_OUT 1
#define SEV_SEG_0_HAS_TRI 0
#define SEV_SEG_0_IRQ -1
#define SEV_SEG_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_0_IRQ_TYPE "NONE"
#define SEV_SEG_0_NAME "/dev/sev_seg_0"
#define SEV_SEG_0_RESET_VALUE 0
#define SEV_SEG_0_SPAN 16
#define SEV_SEG_0_TYPE "altera_avalon_pio"


/*
 * sev_seg_1 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_1 altera_avalon_pio
#define SEV_SEG_1_BASE 0x21090
#define SEV_SEG_1_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_1_CAPTURE 0
#define SEV_SEG_1_DATA_WIDTH 7
#define SEV_SEG_1_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_1_DRIVEN_SIM_VALUE 0
#define SEV_SEG_1_EDGE_TYPE "NONE"
#define SEV_SEG_1_FREQ 50000000
#define SEV_SEG_1_HAS_IN 0
#define SEV_SEG_1_HAS_OUT 1
#define SEV_SEG_1_HAS_TRI 0
#define SEV_SEG_1_IRQ -1
#define SEV_SEG_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_1_IRQ_TYPE "NONE"
#define SEV_SEG_1_NAME "/dev/sev_seg_1"
#define SEV_SEG_1_RESET_VALUE 0
#define SEV_SEG_1_SPAN 16
#define SEV_SEG_1_TYPE "altera_avalon_pio"


/*
 * sev_seg_2 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_2 altera_avalon_pio
#define SEV_SEG_2_BASE 0x21080
#define SEV_SEG_2_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_2_CAPTURE 0
#define SEV_SEG_2_DATA_WIDTH 7
#define SEV_SEG_2_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_2_DRIVEN_SIM_VALUE 0
#define SEV_SEG_2_EDGE_TYPE "NONE"
#define SEV_SEG_2_FREQ 50000000
#define SEV_SEG_2_HAS_IN 0
#define SEV_SEG_2_HAS_OUT 1
#define SEV_SEG_2_HAS_TRI 0
#define SEV_SEG_2_IRQ -1
#define SEV_SEG_2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_2_IRQ_TYPE "NONE"
#define SEV_SEG_2_NAME "/dev/sev_seg_2"
#define SEV_SEG_2_RESET_VALUE 0
#define SEV_SEG_2_SPAN 16
#define SEV_SEG_2_TYPE "altera_avalon_pio"


/*
 * sev_seg_3 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_3 altera_avalon_pio
#define SEV_SEG_3_BASE 0x21070
#define SEV_SEG_3_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_3_CAPTURE 0
#define SEV_SEG_3_DATA_WIDTH 7
#define SEV_SEG_3_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_3_DRIVEN_SIM_VALUE 0
#define SEV_SEG_3_EDGE_TYPE "NONE"
#define SEV_SEG_3_FREQ 50000000
#define SEV_SEG_3_HAS_IN 0
#define SEV_SEG_3_HAS_OUT 1
#define SEV_SEG_3_HAS_TRI 0
#define SEV_SEG_3_IRQ -1
#define SEV_SEG_3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_3_IRQ_TYPE "NONE"
#define SEV_SEG_3_NAME "/dev/sev_seg_3"
#define SEV_SEG_3_RESET_VALUE 0
#define SEV_SEG_3_SPAN 16
#define SEV_SEG_3_TYPE "altera_avalon_pio"


/*
 * sev_seg_4 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_4 altera_avalon_pio
#define SEV_SEG_4_BASE 0x21060
#define SEV_SEG_4_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_4_CAPTURE 0
#define SEV_SEG_4_DATA_WIDTH 7
#define SEV_SEG_4_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_4_DRIVEN_SIM_VALUE 0
#define SEV_SEG_4_EDGE_TYPE "NONE"
#define SEV_SEG_4_FREQ 50000000
#define SEV_SEG_4_HAS_IN 0
#define SEV_SEG_4_HAS_OUT 1
#define SEV_SEG_4_HAS_TRI 0
#define SEV_SEG_4_IRQ -1
#define SEV_SEG_4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_4_IRQ_TYPE "NONE"
#define SEV_SEG_4_NAME "/dev/sev_seg_4"
#define SEV_SEG_4_RESET_VALUE 0
#define SEV_SEG_4_SPAN 16
#define SEV_SEG_4_TYPE "altera_avalon_pio"


/*
 * sev_seg_5 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_5 altera_avalon_pio
#define SEV_SEG_5_BASE 0x21050
#define SEV_SEG_5_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_5_CAPTURE 0
#define SEV_SEG_5_DATA_WIDTH 7
#define SEV_SEG_5_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_5_DRIVEN_SIM_VALUE 0
#define SEV_SEG_5_EDGE_TYPE "NONE"
#define SEV_SEG_5_FREQ 50000000
#define SEV_SEG_5_HAS_IN 0
#define SEV_SEG_5_HAS_OUT 1
#define SEV_SEG_5_HAS_TRI 0
#define SEV_SEG_5_IRQ -1
#define SEV_SEG_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_5_IRQ_TYPE "NONE"
#define SEV_SEG_5_NAME "/dev/sev_seg_5"
#define SEV_SEG_5_RESET_VALUE 0
#define SEV_SEG_5_SPAN 16
#define SEV_SEG_5_TYPE "altera_avalon_pio"


/*
 * sev_seg_6 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_6 altera_avalon_pio
#define SEV_SEG_6_BASE 0x21040
#define SEV_SEG_6_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_6_CAPTURE 0
#define SEV_SEG_6_DATA_WIDTH 7
#define SEV_SEG_6_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_6_DRIVEN_SIM_VALUE 0
#define SEV_SEG_6_EDGE_TYPE "NONE"
#define SEV_SEG_6_FREQ 50000000
#define SEV_SEG_6_HAS_IN 0
#define SEV_SEG_6_HAS_OUT 1
#define SEV_SEG_6_HAS_TRI 0
#define SEV_SEG_6_IRQ -1
#define SEV_SEG_6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_6_IRQ_TYPE "NONE"
#define SEV_SEG_6_NAME "/dev/sev_seg_6"
#define SEV_SEG_6_RESET_VALUE 0
#define SEV_SEG_6_SPAN 16
#define SEV_SEG_6_TYPE "altera_avalon_pio"


/*
 * sev_seg_7 configuration
 *
 */

#define ALT_MODULE_CLASS_sev_seg_7 altera_avalon_pio
#define SEV_SEG_7_BASE 0x21030
#define SEV_SEG_7_BIT_CLEARING_EDGE_REGISTER 0
#define SEV_SEG_7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEV_SEG_7_CAPTURE 0
#define SEV_SEG_7_DATA_WIDTH 7
#define SEV_SEG_7_DO_TEST_BENCH_WIRING 0
#define SEV_SEG_7_DRIVEN_SIM_VALUE 0
#define SEV_SEG_7_EDGE_TYPE "NONE"
#define SEV_SEG_7_FREQ 50000000
#define SEV_SEG_7_HAS_IN 0
#define SEV_SEG_7_HAS_OUT 1
#define SEV_SEG_7_HAS_TRI 0
#define SEV_SEG_7_IRQ -1
#define SEV_SEG_7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEV_SEG_7_IRQ_TYPE "NONE"
#define SEV_SEG_7_NAME "/dev/sev_seg_7"
#define SEV_SEG_7_RESET_VALUE 0
#define SEV_SEG_7_SPAN 16
#define SEV_SEG_7_TYPE "altera_avalon_pio"


/*
 * switches configuration
 *
 */

#define ALT_MODULE_CLASS_switches altera_avalon_pio
#define SWITCHES_BASE 0x210c0
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 0
#define SWITCHES_DATA_WIDTH 18
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "NONE"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ -1
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES_IRQ_TYPE "NONE"
#define SWITCHES_NAME "/dev/switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
