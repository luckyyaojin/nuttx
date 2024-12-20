/****************************************************************************
 * arch/risc-v/src/esp32c3-legacy/hardware/esp32c3_cache_memory.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_RISCV_SRC_ESP32C3_LEGACY_HARDWARE_ESP32C3_CACHE_MEMORY_H
#define __ARCH_RISCV_SRC_ESP32C3_LEGACY_HARDWARE_ESP32C3_CACHE_MEMORY_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* IRAM0 is connected with Cache IBUS0 */

#define IRAM0_ADDRESS_LOW               0x40000000
#define IRAM0_ADDRESS_HIGH              0x44000000
#define IRAM0_CACHE_ADDRESS_LOW         0x42000000
#define IRAM0_CACHE_ADDRESS_HIGH        0x42800000

/* DRAM0 is connected with Cache DBUS0 */

#define DRAM0_ADDRESS_LOW               0x3c000000
#define DRAM0_ADDRESS_HIGH              0x40000000
#define DRAM0_CACHE_ADDRESS_LOW         0x3c000000
#define DRAM0_CACHE_ADDRESS_HIGH        0x3c800000
#define DRAM0_CACHE_OPERATION_HIGH      DRAM0_CACHE_ADDRESS_HIGH
#define ESP_CACHE_TEMP_ADDR             0x3c000000

#define BUS_SIZE(bus_name)              (bus_name##_ADDRESS_HIGH - \
                                            bus_name##_ADDRESS_LOW)
#define ADDRESS_IN_BUS(bus_name, vaddr) ((vaddr) >= bus_name##_ADDRESS_LOW \
                                            && (vaddr) < \
                                                bus_name##_ADDRESS_HIGH)

#define ADDRESS_IN_IRAM0(vaddr)         ADDRESS_IN_BUS(IRAM0, vaddr)
#define ADDRESS_IN_IRAM0_CACHE(vaddr)   ADDRESS_IN_BUS(IRAM0_CACHE, vaddr)
#define ADDRESS_IN_DRAM0(vaddr)         ADDRESS_IN_BUS(DRAM0, vaddr)
#define ADDRESS_IN_DRAM0_CACHE(vaddr)   ADDRESS_IN_BUS(DRAM0_CACHE, vaddr)

#define BUS_IRAM0_CACHE_SIZE    BUS_SIZE(IRAM0_CACHE)
#define BUS_DRAM0_CACHE_SIZE    BUS_SIZE(DRAM0_CACHE)

#define CACHE_IBUS              0
#define CACHE_IBUS_MMU_START    0
#define CACHE_IBUS_MMU_END      0x200

#define CACHE_DBUS              1
#define CACHE_DBUS_MMU_START    0
#define CACHE_DBUS_MMU_END      0x200

#define CACHE_IROM_MMU_START    0
#define CACHE_IROM_MMU_END      Cache_Get_IROM_MMU_End()
#define CACHE_IROM_MMU_SIZE     (CACHE_IROM_MMU_END - CACHE_IROM_MMU_START)

#define CACHE_DROM_MMU_START    CACHE_IROM_MMU_END
#define CACHE_DROM_MMU_END      Cache_Get_DROM_MMU_End()
#define CACHE_DROM_MMU_SIZE     (CACHE_DROM_MMU_END - CACHE_DROM_MMU_START)

#define CACHE_DROM_MMU_MAX_END  0x200

#define ICACHE_MMU_SIZE         0x200
#define DCACHE_MMU_SIZE         0x200

#define MMU_BUS_START(i)        0
#define MMU_BUS_SIZE(i)         0x200

#define MMU_INVALID             BIT(8)
#define MMU_TYPE                0
#define MMU_ACCESS_FLASH        0

#define CACHE_MAX_SYNC_NUM      0x400000
#define CACHE_MAX_LOCK_NUM      0x8000

#define FLASH_MMU_TABLE         ((volatile uint32_t*) DR_REG_MMU_TABLE)
#define FLASH_MMU_TABLE_SIZE    (ICACHE_MMU_SIZE/sizeof(uint32_t))

#define MMU_TABLE_INVALID_VAL   0x100
#define MMU_ADDRESS_MASK        0xff
#define MMU_PAGE_SIZE           0x10000
#define INVALID_PHY_PAGE        0xffff

#define BUS_ADDR_SIZE           0x800000
#define BUS_ADDR_MASK           (BUS_ADDR_SIZE - 1)

#define CACHE_ICACHE_LOW_SHIFT      0
#define CACHE_ICACHE_HIGH_SHIFT     2
#define CACHE_DCACHE_LOW_SHIFT      4
#define CACHE_DCACHE_HIGH_SHIFT     6

#define CACHE_MEMORY_IBANK0_ADDR    0x4037c000

#endif /* __ARCH_RISCV_SRC_ESP32C3_LEGACY_HARDWARE_ESP32C3_CACHE_MEMORY_H */
