/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_bmp384_basic.h
 * @brief     driver bmp384 basic header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-09-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/09/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_BMP384_BASIC_H
#define DRIVER_BMP384_BASIC_H

#include "driver_bmp384_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup bmp384_example_driver bmp384 example driver function
 * @brief    bmp384 example driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief bmp384 basic example default definition
 */
#define BMP384_BASIC_DEFAULT_SPI_WIRE                 BMP384_SPI_WIRE_4                        /**< 4 wire spi */
#define BMP384_BASIC_DEFAULT_IIC_WATCHDOG_TIMER       BMP384_BOOL_TRUE                         /**< enable iic watchdog timer */
#define BMP384_BASIC_DEFAULT_IIC_WATCHDOG_PERIOD      BMP384_IIC_WATCHDOG_PERIOD_40_MS         /**< set watchdog timer period 40ms */
#define BMP384_BASIC_DEFAULT_PRESSURE                 BMP384_BOOL_TRUE                         /**< enable pressure **/
#define BMP384_BASIC_DEFAULT_TEMPERATURE              BMP384_BOOL_TRUE                         /**< enable temperature */
#define BMP384_BASIC_DEFAULT_PRESSURE_OVERSAMPLING    BMP384_OVERSAMPLING_x32                  /**< pressure oversampling x32 */
#define BMP384_BASIC_DEFAULT_TEMPERATURE_OVERSAMPLING BMP384_OVERSAMPLING_x2                   /**< temperature oversampling x2 */
#define BMP384_BASIC_DEFAULT_ODR                      BMP384_ODR_12P5_HZ                       /**< output data rate 12.5Hz */
#define BMP384_BASIC_DEFAULT_FILTER_COEFFICIENT       BMP384_FILTER_COEFFICIENT_15             /**< set filter coefficient 15 */

/**
 * @brief     basic example init
 * @param[in] interface is the chip interface
 * @param[in] addr_pin is the iic device address
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t bmp384_basic_init(bmp384_interface_t interface, bmp384_address_t addr_pin);

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t bmp384_basic_deinit(void);

/**
 * @brief      basic example read
 * @param[out] *temperature_c points a converted temperature data buffer
 * @param[out] *pressure_pa points a converted pressure data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t bmp384_basic_read(float *temperature_c, float *pressure_pa);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
