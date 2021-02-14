/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios_cpu' in SOPC Builder design 'polling_interrupt_cpu_system'
 * SOPC Builder design path: ../../polling_interrupt_cpu_system.sopcinfo
 *
 * Generated: Sat Feb 13 14:02:47 CET 2021
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
#define ALT_CPU_NAME "nios_cpu"
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
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_GEN2
#define __TIMER_HW_IP


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x21068
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x21068
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x21068
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "polling_interrupt_cpu_system"


/*
 * TIMER_HW_IP_0 configuration
 *
 */

#define ALT_MODULE_CLASS_TIMER_HW_IP_0 TIMER_HW_IP
#define TIMER_HW_IP_0_BASE 0x21050
#define TIMER_HW_IP_0_IRQ -1
#define TIMER_HW_IP_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMER_HW_IP_0_NAME "/dev/TIMER_HW_IP_0"
#define TIMER_HW_IP_0_SPAN 16
#define TIMER_HW_IP_0_TYPE "TIMER_HW_IP"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x21068
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * kicker_output configuration
 *
 */

#define ALT_MODULE_CLASS_kicker_output altera_avalon_pio
#define KICKER_OUTPUT_BASE 0x21020
#define KICKER_OUTPUT_BIT_CLEARING_EDGE_REGISTER 0
#define KICKER_OUTPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KICKER_OUTPUT_CAPTURE 0
#define KICKER_OUTPUT_DATA_WIDTH 1
#define KICKER_OUTPUT_DO_TEST_BENCH_WIRING 0
#define KICKER_OUTPUT_DRIVEN_SIM_VALUE 0
#define KICKER_OUTPUT_EDGE_TYPE "NONE"
#define KICKER_OUTPUT_FREQ 50000000
#define KICKER_OUTPUT_HAS_IN 0
#define KICKER_OUTPUT_HAS_OUT 1
#define KICKER_OUTPUT_HAS_TRI 0
#define KICKER_OUTPUT_IRQ -1
#define KICKER_OUTPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KICKER_OUTPUT_IRQ_TYPE "NONE"
#define KICKER_OUTPUT_NAME "/dev/kicker_output"
#define KICKER_OUTPUT_RESET_VALUE 0
#define KICKER_OUTPUT_SPAN 16
#define KICKER_OUTPUT_TYPE "altera_avalon_pio"


/*
 * led_diods configuration
 *
 */

#define ALT_MODULE_CLASS_led_diods altera_avalon_pio
#define LED_DIODS_BASE 0x21040
#define LED_DIODS_BIT_CLEARING_EDGE_REGISTER 0
#define LED_DIODS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_DIODS_CAPTURE 0
#define LED_DIODS_DATA_WIDTH 10
#define LED_DIODS_DO_TEST_BENCH_WIRING 0
#define LED_DIODS_DRIVEN_SIM_VALUE 0
#define LED_DIODS_EDGE_TYPE "NONE"
#define LED_DIODS_FREQ 50000000
#define LED_DIODS_HAS_IN 0
#define LED_DIODS_HAS_OUT 1
#define LED_DIODS_HAS_TRI 0
#define LED_DIODS_IRQ -1
#define LED_DIODS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_DIODS_IRQ_TYPE "NONE"
#define LED_DIODS_NAME "/dev/led_diods"
#define LED_DIODS_RESET_VALUE 0
#define LED_DIODS_SPAN 16
#define LED_DIODS_TYPE "altera_avalon_pio"


/*
 * onchip configuration
 *
 */

#define ALT_MODULE_CLASS_onchip altera_avalon_onchip_memory2
#define ONCHIP_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_BASE 0x10000
#define ONCHIP_CONTENTS_INFO ""
#define ONCHIP_DUAL_PORT 0
#define ONCHIP_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_INIT_CONTENTS_FILE "polling_interrupt_cpu_system_onchip"
#define ONCHIP_INIT_MEM_CONTENT 0
#define ONCHIP_INSTANCE_ID "NONE"
#define ONCHIP_IRQ -1
#define ONCHIP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_NAME "/dev/onchip"
#define ONCHIP_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_SINGLE_CLOCK_OP 0
#define ONCHIP_SIZE_MULTIPLE 1
#define ONCHIP_SIZE_VALUE 65536
#define ONCHIP_SPAN 65536
#define ONCHIP_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_WRITABLE 1


/*
 * push_button configuration
 *
 */

#define ALT_MODULE_CLASS_push_button altera_avalon_pio
#define PUSH_BUTTON_BASE 0x21030
#define PUSH_BUTTON_BIT_CLEARING_EDGE_REGISTER 0
#define PUSH_BUTTON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSH_BUTTON_CAPTURE 0
#define PUSH_BUTTON_DATA_WIDTH 1
#define PUSH_BUTTON_DO_TEST_BENCH_WIRING 0
#define PUSH_BUTTON_DRIVEN_SIM_VALUE 0
#define PUSH_BUTTON_EDGE_TYPE "NONE"
#define PUSH_BUTTON_FREQ 50000000
#define PUSH_BUTTON_HAS_IN 1
#define PUSH_BUTTON_HAS_OUT 0
#define PUSH_BUTTON_HAS_TRI 0
#define PUSH_BUTTON_IRQ -1
#define PUSH_BUTTON_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSH_BUTTON_IRQ_TYPE "NONE"
#define PUSH_BUTTON_NAME "/dev/push_button"
#define PUSH_BUTTON_RESET_VALUE 0
#define PUSH_BUTTON_SPAN 16
#define PUSH_BUTTON_TYPE "altera_avalon_pio"


/*
 * seven_seg_data_validate configuration
 *
 */

#define ALT_MODULE_CLASS_seven_seg_data_validate altera_avalon_pio
#define SEVEN_SEG_DATA_VALIDATE_BASE 0x21000
#define SEVEN_SEG_DATA_VALIDATE_BIT_CLEARING_EDGE_REGISTER 0
#define SEVEN_SEG_DATA_VALIDATE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVEN_SEG_DATA_VALIDATE_CAPTURE 0
#define SEVEN_SEG_DATA_VALIDATE_DATA_WIDTH 1
#define SEVEN_SEG_DATA_VALIDATE_DO_TEST_BENCH_WIRING 0
#define SEVEN_SEG_DATA_VALIDATE_DRIVEN_SIM_VALUE 0
#define SEVEN_SEG_DATA_VALIDATE_EDGE_TYPE "NONE"
#define SEVEN_SEG_DATA_VALIDATE_FREQ 50000000
#define SEVEN_SEG_DATA_VALIDATE_HAS_IN 0
#define SEVEN_SEG_DATA_VALIDATE_HAS_OUT 1
#define SEVEN_SEG_DATA_VALIDATE_HAS_TRI 0
#define SEVEN_SEG_DATA_VALIDATE_IRQ -1
#define SEVEN_SEG_DATA_VALIDATE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVEN_SEG_DATA_VALIDATE_IRQ_TYPE "NONE"
#define SEVEN_SEG_DATA_VALIDATE_NAME "/dev/seven_seg_data_validate"
#define SEVEN_SEG_DATA_VALIDATE_RESET_VALUE 0
#define SEVEN_SEG_DATA_VALIDATE_SPAN 16
#define SEVEN_SEG_DATA_VALIDATE_TYPE "altera_avalon_pio"


/*
 * seven_segment_leds configuration
 *
 */

#define ALT_MODULE_CLASS_seven_segment_leds altera_avalon_pio
#define SEVEN_SEGMENT_LEDS_BASE 0x21010
#define SEVEN_SEGMENT_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define SEVEN_SEGMENT_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVEN_SEGMENT_LEDS_CAPTURE 0
#define SEVEN_SEGMENT_LEDS_DATA_WIDTH 8
#define SEVEN_SEGMENT_LEDS_DO_TEST_BENCH_WIRING 0
#define SEVEN_SEGMENT_LEDS_DRIVEN_SIM_VALUE 0
#define SEVEN_SEGMENT_LEDS_EDGE_TYPE "NONE"
#define SEVEN_SEGMENT_LEDS_FREQ 50000000
#define SEVEN_SEGMENT_LEDS_HAS_IN 0
#define SEVEN_SEGMENT_LEDS_HAS_OUT 1
#define SEVEN_SEGMENT_LEDS_HAS_TRI 0
#define SEVEN_SEGMENT_LEDS_IRQ -1
#define SEVEN_SEGMENT_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVEN_SEGMENT_LEDS_IRQ_TYPE "NONE"
#define SEVEN_SEGMENT_LEDS_NAME "/dev/seven_segment_leds"
#define SEVEN_SEGMENT_LEDS_RESET_VALUE 0
#define SEVEN_SEGMENT_LEDS_SPAN 16
#define SEVEN_SEGMENT_LEDS_TYPE "altera_avalon_pio"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x21060
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1613218297
#define SYSID_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
