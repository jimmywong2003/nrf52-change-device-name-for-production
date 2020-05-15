/*
   Copyright (c) 2010 - 2017, Nordic Semiconductor ASA
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   2. Redistributions in binary form, except as embedded into a Nordic
     Semiconductor ASA integrated circuit in a product or a software update for
     such product, must reproduce the above copyright notice, this list of
     conditions and the following disclaimer in the documentation and/or other
     materials provided with the distribution.

   3. Neither the name of Nordic Semiconductor ASA nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   4. This software, with or without modification, must only be used with a
     Nordic Semiconductor ASA integrated circuit.

   5. Any software provided in binary form under this license must not be reverse
     engineered, decompiled, modified and/or disassembled.

   THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
   OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
   OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @file BLE configuration module
 *
 * @defgroup m_ble_flash BLE flash configuration
 * @{
 * @ingroup m_ble
 * @brief BLE handling module flash configuration.
 *
 */

#ifndef __DEVICE_CONFIG_FLASH_H__
#define __DEVICE_CONFIG_FLASH_H__

#include "ble.h"
#include "ble_srv_common.h"
#include "app_util_platform.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __GNUC__
    #ifdef PACKED
        #undef PACKED
    #endif
    #define PACKED(TYPE) TYPE __attribute__ ((packed))
#endif

#define DEVICE_NAME_LEN_MAX 10

typedef PACKED ( struct
{
        uint8_t name[DEVICE_NAME_LEN_MAX+1];
        uint8_t len;
}) ble_dev_name_t;

typedef struct
{
        ble_dev_name_t dev_name;
        ble_gap_addr_t device_addr;
} device_config_t;


uint32_t m_ble_flash_config_store(const device_config_t * p_config, bool gc_request);

uint32_t m_ble_flash_config_load(device_config_t ** p_config);

uint32_t m_ble_flash_init(const device_config_t * p_default_config, device_config_t ** p_config);


#endif
