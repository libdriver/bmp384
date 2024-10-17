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
 * @file      driver_bmp384_fifo.h
 * @brief     driver bmp384 fifo header file
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

#ifndef DRIVER_BMP384_FIFO_H
#define DRIVER_BMP384_FIFO_H

#include "driver_bmp384_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @addtogroup bmp384_example_driver
 * @{
 */

/**
 * @brief bmp384 fifo example default definition
 */
#define BMP384_FIFO_DEFAULT_SPI_WIRE                 BMP384_SPI_WIRE_4                        /**< 4 wire spi */
#define BMP384_FIFO_DEFAULT_IIC_WATCHDOG_TIMER       BMP384_BOOL_TRUE                         /**< enable iic watchdog timer */
#define BMP384_FIFO_DEFAULT_IIC_WATCHDOG_PERIOD      BMP384_IIC_WATCHDOG_PERIOD_40_MS         /**< set watchdog timer period 40ms */
#define BMP384_FIFO_DEFAULT_FIFO_STOP_ON_FULL        BMP384_BOOL_FALSE                        /**< disable fifo stop on full */
#define BMP384_FIFO_DEFAULT_FIFO_WATERMARK           256                                      /**< 256 fifo watermark */
#define BMP384_FIFO_DEFAULT_FIFO_SENSORTIME_ON       BMP384_BOOL_TRUE                         /**< enable fifo sensor time on */
#define BMP384_FIFO_DEFAULT_FIFO_PRESSURE_ON         BMP384_BOOL_TRUE                         /**< enable fifo pressure on */
#define BMP384_FIFO_DEFAULT_FIFO_TEMPERATURE_ON      BMP384_BOOL_TRUE                         /**< enable fifo temperature on */
#define BMP384_FIFO_DEFAULT_FIFO_SUBSAMPLING         0                                        /**< fifo subsampling */
#define BMP384_FIFO_DEFAULT_FIFO_DATA_SOURCE         BMP384_FIFO_DATA_SOURCE_FILTERED         /**< fifo data source filtered */
#define BMP384_FIFO_DEFAULT_INTERRUPT_PIN_TYPE       BMP384_INTERRUPT_PIN_TYPE_PUSH_PULL      /**< interrupt pin type push pull */
#define BMP384_FIFO_DEFAULT_INTERRUPT_ACTIVE_LEVEL   BMP384_INTERRUPT_ACTIVE_LEVEL_HIGHER     /**< interrupt pin active level higher */
#define BMP384_FIFO_DEFAULT_INTERRUPT_WATERMARK      BMP384_BOOL_TRUE                         /**< enable interrupt watermark */
#define BMP384_FIFO_DEFAULT_INTERRUPT_FIFO_FULL      BMP384_BOOL_FALSE                        /**< disable interrupt fifo full */
#define BMP384_FIFO_DEFAULT_INTERRUPT_DATA_READY     BMP384_BOOL_FALSE                        /**< disable interrupt data ready */
#define BMP384_FIFO_DEFAULT_LATCH_INTERRUPT          BMP384_BOOL_FALSE                        /**< latch interrupt pin and interrupt status */
#define BMP384_FIFO_DEFAULT_PRESSURE                 BMP384_BOOL_TRUE                         /**< enable pressure */
#define BMP384_FIFO_DEFAULT_TEMPERATURE              BMP384_BOOL_TRUE                         /**< enable temperature */
#define BMP384_FIFO_DEFAULT_PRESSURE_OVERSAMPLING    BMP384_OVERSAMPLING_x32                  /**< pressure oversampling x32 */
#define BMP384_FIFO_DEFAULT_TEMPERATURE_OVERSAMPLING BMP384_OVERSAMPLING_x2                   /**< temperature oversampling x2 */
#define BMP384_FIFO_DEFAULT_ODR                      BMP384_ODR_12P5_HZ                       /**< output data rate 12.5Hz */
#define BMP384_FIFO_DEFAULT_FILTER_COEFFICIENT       BMP384_FILTER_COEFFICIENT_15             /**< set filter coefficient 15 */

/**
 * @brief  fifo example irq handler
 * @return status code
 *         - 0 success
 *         - 1 run failed
 * @note   none
 */
uint8_t bmp384_fifo_irq_handler(void);

/**
 * @brief     fifo example init
 * @param[in] interface is the chip interface
 * @param[in] addr_pin is the iic device address
 * @param[in] *fifo_receive_callback points to a fifo receive callback
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t bmp384_fifo_init(bmp384_interface_t interface, bmp384_address_t addr_pin,
                         void (*fifo_receive_callback)(uint8_t type));

/**
 * @brief  fifo example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t bmp384_fifo_deinit(void);

/**
 * @brief         fifo example read
 * @param[in]     *buf points a data buffer
 * @param[in]     buf_len is the data buffer
 * @param[out]    *frame points a frame structure
 * @param[in,out] *frame_len points a frame data buffer
 * @return        status code
 *                - 0 success
 *                - 1 read failed
 * @note          none
 */
uint8_t bmp384_fifo_read(uint8_t *buf, uint16_t buf_len, bmp384_frame_t *frame, uint16_t *frame_len);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
