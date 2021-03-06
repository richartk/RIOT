/*
 * Copyright (C) 2017 Michel Rottleuthner <michel.rottleuthner@haw-hamburg.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     auto_init_sdcard_spi
 * @{
 *
 * @file
 * @brief       Auto initialization for sd-cards connected over spi
 *
 * @author      Michel Rottleuthner <michel.rottleuthner@haw-hamburg.de>
 */

#ifdef MODULE_SDCARD_SPI

#include "sdcard_spi.h"
#include "sdcard_spi_params.h"

#define ENABLE_DEBUG    (0)
#include "debug.h"

/**
 * @brief   number of used sd cards
 * @{
 */
#define SDCARD_SPI_NUM (sizeof(sdcard_spi_params) / sizeof(sdcard_spi_params[0]))
/** @} */

/**
 * @brief   Allocate memory for the device descriptors
 * @{
 */
sdcard_spi_t sdcard_spi_devs[SDCARD_SPI_NUM];
/** @} */

void auto_init_sdcard_spi(void)
{
    for (int i = 0; i < SDCARD_SPI_NUM; i++) {
        DEBUG("sdcard_spi_auto_init(): initializing device [%i]...\n", i);
        int resu = sdcard_spi_init(&sdcard_spi_devs[i], &sdcard_spi_params[i]);
        if(resu != 0){
            DEBUG("error initializing device [%i]\n", i);
        }
    }
}

#else
typedef int dont_be_pedantic;
#endif /* MODULE_SDCARD_SPI */
/** @} */
