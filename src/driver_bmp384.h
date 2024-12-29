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
 * @file      driver_bmp384.h
 * @brief     driver bmp384 header file
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

#ifndef DRIVER_BMP384_H
#define DRIVER_BMP384_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup bmp384_driver bmp384 driver function
 * @brief    bmp384 driver modules
 * @{
 */

/**
 * @addtogroup bmp384_base_driver
 * @{
 */

/**
 * @brief bmp384 interface enumeration definition
 */
typedef enum
{
    BMP384_INTERFACE_IIC = 0x00,        /**< iic interface */
    BMP384_INTERFACE_SPI = 0x01,        /**< spi interface */
} bmp384_interface_t;

/**
 * @brief bmp384 address enumeration definition
 */
typedef enum
{
    BMP384_ADDRESS_ADO_LOW  = (0x76 << 1),        /**< ADO is low */
    BMP384_ADDRESS_ADO_HIGH = (0x77 << 1),        /**< ADO is HIGH */
} bmp384_address_t;

/**
 * @brief bmp384 bool enumeration definition
 */
typedef enum
{
    BMP384_BOOL_FALSE = 0x00,        /**< false */
    BMP384_BOOL_TRUE  = 0x01,        /**< true */
} bmp384_bool_t;

/**
 * @brief bmp384 error enumeration definition
 */
typedef enum
{
    BMP384_ERROR_FATAL = (1 << 0),        /**< fatal error */
    BMP384_ERROR_CMD   = (1 << 1),        /**< command error */
    BMP384_ERROR_CONF  = (1 << 2),        /**< conf error */
} bmp384_error_t;

/**
 * @brief bmp384 status enumeration definition
 */
typedef enum
{
    BMP384_STATUS_COMMAND_READY = (1 << 4),        /**< command ready status */
    BMP384_STATUS_PRESS_READY   = (1 << 5),        /**< press ready status */
    BMP384_STATUS_TEMP_READY    = (1 << 6),        /**< temp ready status */
} bmp384_status_t;

/**
 * @brief bmp384 event enumeration definition
 */
typedef enum
{
    BMP384_EVENT_NONE                  = (0 << 0),        /**< event none */
    BMP384_EVENT_POWER_UP_OR_SOFTRESET = (1 << 0),        /**< event power up or soft reset */
} bmp384_event_t;

/**
 * @brief bmp384 fifo data source enumeration definition
 */
typedef enum
{
    BMP384_FIFO_DATA_SOURCE_UNFILTERED  = 0,        /**< fifo data source unfiltered */
    BMP384_FIFO_DATA_SOURCE_FILTERED    = 1,        /**< fifo data source filtered */
} bmp384_fifo_data_source_t;

/**
 * @brief bmp384 interrupt status enumeration definition
 */
typedef enum
{
    BMP384_INTERRUPT_STATUS_FIFO_WATERMARK = (1 << 0),        /**< fifo watermark interrupt status */
    BMP384_INTERRUPT_STATUS_FIFO_FULL      = (1 << 1),        /**< fifo full interrupt status */
    BMP384_INTERRUPT_STATUS_DATA_READY     = (1 << 3),        /**< data ready interrupt status */
} bmp384_interrupt_status_t;

/**
 * @brief bmp384 interrupt active level enumeration definition
 */
typedef enum
{
    BMP384_INTERRUPT_ACTIVE_LEVEL_LOWER  = 0x00,        /**< active level lower */
    BMP384_INTERRUPT_ACTIVE_LEVEL_HIGHER = 0x01,        /**< active level higher */
} bmp384_interrupt_active_level_t;

/**
 * @brief bmp384 interrupt pin type enumeration definition
 */
typedef enum
{
    BMP384_INTERRUPT_PIN_TYPE_PUSH_PULL  = 0x00,        /**< push pull pin type */
    BMP384_INTERRUPT_PIN_TYPE_OPEN_DRAIN = 0x01,        /**< open drain pin type */
} bmp384_interrupt_pin_type_t;

/**
 * @brief bmp384 spi wire enumeration definition
 */
typedef enum
{
    BMP384_SPI_WIRE_4 = 0x00,        /**< 4 wire */
    BMP384_SPI_WIRE_3 = 0x01,        /**< 3 wire */
} bmp384_spi_wire_t;

/**
 * @brief bmp384 iic watchdog period enumeration definition
 */
typedef enum
{
    BMP384_IIC_WATCHDOG_PERIOD_1P25_MS = 0x00,        /**< iic watchdog period 1.25 ms */
    BMP384_IIC_WATCHDOG_PERIOD_40_MS   = 0x01,        /**< iic watchdog period 40 ms */
} bmp384_iic_watchdog_period_t;

/**
 * @brief bmp384 mode enumeration definition
 */
typedef enum
{
    BMP384_MODE_SLEEP_MODE  = 0x00,        /**< sleep mode */
    BMP384_MODE_FORCED_MODE = 0x01,        /**< forced mode */
    BMP384_MODE_NORMAL_MODE = 0x03,        /**< normal mode */
} bmp384_mode_t;

/**
 * @brief bmp384 oversampling enumeration definition
 */
typedef enum
{
    BMP384_OVERSAMPLING_x1  = 0x00,        /**< oversampling x1 */
    BMP384_OVERSAMPLING_x2  = 0x01,        /**< oversampling x2 */
    BMP384_OVERSAMPLING_x4  = 0x02,        /**< oversampling x4 */
    BMP384_OVERSAMPLING_x8  = 0x03,        /**< oversampling x8 */
    BMP384_OVERSAMPLING_x16 = 0x04,        /**< oversampling x16 */
    BMP384_OVERSAMPLING_x32 = 0x05,        /**< oversampling x32 */
} bmp384_oversampling_t;

/**
 * @brief bmp384 output data rate enumeration definition
 */
typedef enum
{
    BMP384_ODR_200_HZ    = 0x00,        /**< 200Hz */
    BMP384_ODR_100_HZ    = 0x01,        /**< 100Hz */
    BMP384_ODR_50_HZ     = 0x02,        /**< 50Hz */
    BMP384_ODR_25_HZ     = 0x03,        /**< 25Hz */
    BMP384_ODR_12P5_HZ   = 0x04,        /**< 12.5Hz */
    BMP384_ODR_6P25_HZ   = 0x05,        /**< 6.25Hz */
    BMP384_ODR_3P1_HZ    = 0x06,        /**< 3.1Hz */
    BMP384_ODR_1P5_HZ    = 0x07,        /**< 1.5Hz */
    BMP384_ODR_0P78_HZ   = 0x08,        /**< 0.78Hz */
    BMP384_ODR_0P39_HZ   = 0x09,        /**< 0.39Hz */ 
    BMP384_ODR_0P2_HZ    = 0x0A,        /**< 0.2Hz */ 
    BMP384_ODR_0P1_HZ    = 0x0B,        /**< 0.1Hz */ 
    BMP384_ODR_0P05_HZ   = 0x0C,        /**< 0.05Hz */
    BMP384_ODR_0P02_HZ   = 0x0D,        /**< 0.02Hz */
    BMP384_ODR_0P01_HZ   = 0x0E,        /**< 0.01Hz */
    BMP384_ODR_0P006_HZ  = 0x0F,        /**< 0.006Hz */
    BMP384_ODR_0P003_HZ  = 0x10,        /**< 0.003Hz */
    BMP384_ODR_0P0015_HZ = 0x11,        /**< 0.0015Hz */ 
} bmp384_odr_t;

/**
 * @brief bmp384 filter coefficient enumeration definition
 */
typedef enum
{
    BMP384_FILTER_COEFFICIENT_0   = 0x00,        /**< coefficient 0 */
    BMP384_FILTER_COEFFICIENT_1   = 0x01,        /**< coefficient 1 */
    BMP384_FILTER_COEFFICIENT_3   = 0x02,        /**< coefficient 3 */
    BMP384_FILTER_COEFFICIENT_7   = 0x03,        /**< coefficient 7 */
    BMP384_FILTER_COEFFICIENT_15  = 0x04,        /**< coefficient 15 */
    BMP384_FILTER_COEFFICIENT_31  = 0x05,        /**< coefficient 31 */
    BMP384_FILTER_COEFFICIENT_63  = 0x06,        /**< coefficient 63 */
    BMP384_FILTER_COEFFICIENT_127 = 0x07,        /**< coefficient 127 */
} bmp384_filter_coefficient_t;

/**
 * @brief bmp384 frame type enumeration definition
 */
typedef enum
{
    BMP384_FRAME_TYPE_TEMPERATURE = 0x01,        /**< temperature frame type */
    BMP384_FRAME_TYPE_PRESSURE    = 0x02,        /**< pressure frame type */
    BMP384_FRAME_TYPE_SENSORTIME  = 0x03,        /**< sensor time frame type */
} bmp384_frame_type_t;

/**
 * @brief bmp384 frame structure definition
 */
typedef struct bmp384_frame_s
{
    bmp384_frame_type_t type;        /**< frame type */
    uint32_t raw;                    /**< raw data */
    float data;                      /**< converted data */
} bmp384_frame_t;

/**
 * @brief bmp384 handle structure definition
 */
typedef struct bmp384_handle_s
{
    uint8_t iic_addr;                                                                   /**< iic device address */
    uint8_t buf[512 + 1];                                                               /**< inner buffer */
    uint8_t (*iic_init)(void);                                                          /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                        /**< point to an iic_deinit function address */
    uint8_t (*iic_read)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);         /**< point to an iic_read function address */
    uint8_t (*iic_write)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write function address */
    uint8_t (*spi_init)(void);                                                          /**< point to a spi_init function address */
    uint8_t (*spi_deinit)(void);                                                        /**< point to a spi_deinit function address */
    uint8_t (*spi_read)(uint8_t reg, uint8_t *buf, uint16_t len);                       /**< point to a spi_read function address */
    uint8_t (*spi_write)(uint8_t reg, uint8_t *buf, uint16_t len);                      /**< point to a spi_write function address */
    void (*receive_callback)(uint8_t type);                                             /**< point to a receive_callback function address */
    void (*delay_ms)(uint32_t ms);                                                      /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                    /**< point to a debug_print function address */
    uint8_t inited;                                                                     /**< inited flag */
    uint8_t iic_spi;                                                                    /**< iic spi interface */
    uint16_t t1;                                                                        /**< t1 register */
    uint16_t t2;                                                                        /**< t2 register */
    int8_t t3;                                                                          /**< t3 register */
    int16_t p1;                                                                         /**< p1 register */
    int16_t p2;                                                                         /**< p2 register */
    int8_t p3;                                                                          /**< p3 register */
    int8_t p4;                                                                          /**< p4 register */
    uint16_t p5;                                                                        /**< p5 register */
    uint16_t p6;                                                                        /**< p6 register */
    int8_t p7;                                                                          /**< p7 register */
    int8_t p8;                                                                          /**< p8 register */
    int16_t p9;                                                                         /**< p9 register */
    int8_t p10;                                                                         /**< p10 register */
    int8_t p11;                                                                         /**< p11 register */
    int64_t t_fine;                                                                     /**< t_fine register */
} bmp384_handle_t;

/**
 * @brief bmp384 information structure definition
 */
typedef struct bmp384_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} bmp384_info_t;

/**
 * @}
 */

/**
 * @defgroup bmp384_link_driver bmp384 link driver function
 * @brief    bmp384 link driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief     initialize bmp384_handle_t structure
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] STRUCTURE bmp384_handle_t
 * @note      none
 */
#define DRIVER_BMP384_LINK_INIT(HANDLE, STRUCTURE)        memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_IIC_INIT(HANDLE, FUC)         (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_IIC_DEINIT(HANDLE, FUC)       (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to an iic_read function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_IIC_READ(HANDLE, FUC)         (HANDLE)->iic_read = FUC

/**
 * @brief     link iic_write function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to an iic_write function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_IIC_WRITE(HANDLE, FUC)        (HANDLE)->iic_write = FUC

/**
 * @brief     link spi_init function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a spi_init function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_SPI_INIT(HANDLE, FUC)         (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a spi_deinit function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_SPI_DEINIT(HANDLE, FUC)       (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_read function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a spi_read function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_SPI_READ(HANDLE, FUC)         (HANDLE)->spi_read = FUC

/**
 * @brief     link spi_write function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a spi_write function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_SPI_WRITE(HANDLE, FUC)        (HANDLE)->spi_write = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_DELAY_MS(HANDLE, FUC)         (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_DEBUG_PRINT(HANDLE, FUC)      (HANDLE)->debug_print = FUC

/**
 * @brief     link receive_callback function
 * @param[in] HANDLE pointer to a bmp384 handle structure
 * @param[in] FUC pointer to a receive_callback function address
 * @note      none
 */
#define DRIVER_BMP384_LINK_RECEIVE_CALLBACK(HANDLE, FUC) (HANDLE)->receive_callback = FUC

/**
 * @}
 */

/**
 * @defgroup bmp384_base_driver bmp384 base driver function
 * @brief    bmp384 base driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to a bmp384 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp384_info(bmp384_info_t *info);

/**
 * @brief     set the iic address pin
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] addr_pin iic address pin
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t bmp384_set_addr_pin(bmp384_handle_t *handle, bmp384_address_t addr_pin);

/**
 * @brief      get the iic address pin
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *addr_pin pointer to an iic address pin buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp384_get_addr_pin(bmp384_handle_t *handle, bmp384_address_t *addr_pin);

/**
 * @brief     set the interface
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] interface chip interface
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t bmp384_set_interface(bmp384_handle_t *handle, bmp384_interface_t interface);

/**
 * @brief      get the interface
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *interface pointer to a chip interface buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp384_get_interface(bmp384_handle_t *handle, bmp384_interface_t *interface);

/**
 * @brief     irq handler
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_irq_handler(bmp384_handle_t *handle);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 id is invalid
 *            - 5 reset failed
 *            - 6 get calibration failed
 * @note      none
 */
uint8_t bmp384_init(bmp384_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or spi deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 power down failed
 * @note      none
 */
uint8_t bmp384_deinit(bmp384_handle_t *handle);

/**
 * @brief      read the temperature and pressure
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *temperature_raw pointer to a raw temperature buffer
 * @param[out] *temperature_c pointer to a converted temperature buffer
 * @param[out] *pressure_raw pointer to a raw pressure buffer
 * @param[out] *pressure_pa pointer to a converted pressure buffer
 * @return     status code
 *             - 0 success
 *             - 1 read temperature pressure failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_read_temperature_pressure(bmp384_handle_t *handle, uint32_t *temperature_raw, float *temperature_c, 
                                         uint32_t *pressure_raw, float *pressure_pa);

/**
 * @brief      read the temperature
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *raw pointer to a raw temperature buffer
 * @param[out] *c pointer to a converted temperature buffer
 * @return     status code
 *             - 0 success
 *             - 1 read temperature failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_read_temperature(bmp384_handle_t *handle, uint32_t *raw, float *c);

/**
 * @brief      read the pressure
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *raw pointer to a raw pressure buffer
 * @param[out] *pa pointer to a converted pressure buffer
 * @return     status code
 *             - 0 success
 *             - 1 read pressure failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_read_pressure(bmp384_handle_t *handle, uint32_t *raw, float *pa);

/**
 * @brief      get the error
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *err pointer to an error buffer
 * @return     status code
 *             - 0 success
 *             - 1 get error failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_error(bmp384_handle_t *handle, uint8_t *err);

/**
 * @brief      get the status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *status pointer to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_status(bmp384_handle_t *handle, uint8_t *status);

/**
 * @brief      get the sensor time
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *t pointer to a timestamp buffer
 * @return     status code
 *             - 0 success
 *             - 1 get sensor time failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_sensortime(bmp384_handle_t *handle, uint32_t *t);

/**
 * @brief      get the event
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *event pointer to an event buffer
 * @return     status code
 *             - 0 success
 *             - 1 get event failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_event(bmp384_handle_t *handle, bmp384_event_t *event);

/**
 * @brief     set the spi wire
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] wire spi wire
 * @return    status code
 *            - 0 success
 *            - 1 set spi wire failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_spi_wire(bmp384_handle_t *handle, bmp384_spi_wire_t wire);

/**
 * @brief      get the spi wire
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *wire pointer to a spi wire buffer
 * @return     status code
 *             - 0 success
 *             - 1 get spi wire failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_spi_wire(bmp384_handle_t *handle, bmp384_spi_wire_t *wire);

/**
 * @brief     enable or disable the iic watchdog timer
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set iic watchdog timer failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_iic_watchdog_timer(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the iic watchdog timer status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get iic watchdog timer failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_iic_watchdog_timer(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     set the iic watchdog period
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] period iic watchdog period
 * @return    status code
 *            - 0 success
 *            - 1 set iic watchdog period failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_iic_watchdog_period(bmp384_handle_t *handle, bmp384_iic_watchdog_period_t period);

/**
 * @brief      get the iic watchdog period
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *period pointer to an iic watchdog period buffer
 * @return     status code
 *             - 0 success
 *             - 1 get iic watchdog period failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_iic_watchdog_period(bmp384_handle_t *handle, bmp384_iic_watchdog_period_t *period);

/**
 * @brief     enable or disable the pressure
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set pressure failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_pressure(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the pressure status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get pressure failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_pressure(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the temperature
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set temperature failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_temperature(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the temperature status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get temperature failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_temperature(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     set the chip mode
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] mode chip mode
 * @return    status code
 *            - 0 success
 *            - 1 set mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_mode(bmp384_handle_t *handle, bmp384_mode_t mode);

/**
 * @brief      get the chip mode
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *mode pointer to a mode buffer
 * @return     status code
 *             - 0 success
 *             - 1 get mode failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_mode(bmp384_handle_t *handle, bmp384_mode_t *mode);

/**
 * @brief     set the pressure oversampling
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] oversampling pressure oversampling
 * @return    status code
 *            - 0 success
 *            - 1 set pressure oversampling failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_pressure_oversampling(bmp384_handle_t *handle, bmp384_oversampling_t oversampling);

/**
 * @brief      get the pressure oversampling
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *oversampling pointer to an oversampling buffer
 * @return     status code
 *             - 0 success
 *             - 1 get pressure oversampling failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_pressure_oversampling(bmp384_handle_t *handle, bmp384_oversampling_t *oversampling);

/**
 * @brief     set the temperature oversampling
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] oversampling temperature oversampling
 * @return    status code
 *            - 0 success
 *            - 1 set temperature oversampling failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_temperature_oversampling(bmp384_handle_t *handle, bmp384_oversampling_t oversampling);

/**
 * @brief      get the temperature oversampling
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *oversampling pointer to an oversampling buffer
 * @return     status code
 *             - 0 success
 *             - 1 get temperature oversampling failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_temperature_oversampling(bmp384_handle_t *handle, bmp384_oversampling_t *oversampling);

/**
 * @brief     set the output data rate
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] odr output data rate
 * @return    status code
 *            - 0 success
 *            - 1 set odr failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_odr(bmp384_handle_t *handle, bmp384_odr_t odr);

/**
 * @brief      get the output data rate
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *odr pointer to an output data rate buffer
 * @return     status code
 *             - 0 success
 *             - 1 get odr failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_odr(bmp384_handle_t *handle, bmp384_odr_t *odr);

/**
 * @brief     set the filter coefficient
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] coefficient filter coefficient
 * @return    status code
 *            - 0 success
 *            - 1 set filter coefficient failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_filter_coefficient(bmp384_handle_t *handle, bmp384_filter_coefficient_t coefficient);

/**
 * @brief      get the filter coefficient
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *coefficient pointer to a filter coefficient buffer
 * @return     status code
 *             - 0 success
 *             - 1 get filter coefficient failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_filter_coefficient(bmp384_handle_t *handle, bmp384_filter_coefficient_t *coefficient);

/**
 * @brief     soft reset
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 soft reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_softreset(bmp384_handle_t *handle);

/**
 * @brief     extmode enable middle
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 extmode enable middle failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_extmode_en_middle(bmp384_handle_t *handle);

/**
 * @}
 */

/**
 * @defgroup bmp384_interrupt_driver bmp384 interrupt driver function
 * @brief    bmp384 interrupt driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief      get the interrupt status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *status pointer to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_status(bmp384_handle_t *handle, uint8_t *status);

/**
 * @brief     set the interrupt pin type
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] pin_type interrupt pin type
 * @return    status code
 *            - 0 success
 *            - 1 set interrupt pin type failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_interrupt_pin_type(bmp384_handle_t *handle, bmp384_interrupt_pin_type_t pin_type);

/**
 * @brief      get the interrupt pin type
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *pin_type pointer to an interrupt pin type buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt pin type failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_pin_type(bmp384_handle_t *handle, bmp384_interrupt_pin_type_t *pin_type);

/**
 * @brief     set the interrupt active level
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] level interrupt active level
 * @return    status code
 *            - 0 success
 *            - 1 set interrupt active level failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_interrupt_active_level(bmp384_handle_t *handle, bmp384_interrupt_active_level_t level);

/**
 * @brief      get the interrupt active level
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *level pointer to an interrupt active level buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt active level failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_active_level(bmp384_handle_t *handle, bmp384_interrupt_active_level_t *level);

/**
 * @brief     enable or disable latching interrupt pin and interrupt status
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set latch interrupt pin and interrupt status failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_latch_interrupt_pin_and_interrupt_status(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get latching interrupt pin and interrupt status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get latch interrupt pin and interrupt status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_latch_interrupt_pin_and_interrupt_status(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo watermark interrupt
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set interrupt fifo watermark failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_interrupt_fifo_watermark(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the interrupt fifo watermark
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt fifo watermark failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_fifo_watermark(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo full interrupt
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set interrupt fifo full failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_interrupt_fifo_full(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the interrupt fifo full
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt fifo full failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_fifo_full(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the data ready interrupt
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set interrupt data ready failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_interrupt_data_ready(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the interrupt data ready status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get interrupt data ready failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_interrupt_data_ready(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @}
 */

/**
 * @defgroup bmp384_fifo_driver bmp384 fifo driver function
 * @brief    bmp384 fifo driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief      get the fifo length
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *length pointer to a fifo length buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo length failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_length(bmp384_handle_t *handle, uint16_t *length);

/**
 * @brief      get the fifo data
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *data pointer to a data buffer
 * @param[in]  length data buffer length
 * @return     status code
 *             - 0 success
 *             - 1 get fifo data failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_data(bmp384_handle_t *handle, uint8_t *data, uint16_t length);

/**
 * @brief     set the fifo watermark
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] watermark fifo watermark
 * @return    status code
 *            - 0 success
 *            - 1 set fifo watermark failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialize
 * @note      none
 */
uint8_t bmp384_set_fifo_watermark(bmp384_handle_t *handle, uint16_t watermark);

/**
 * @brief      get the fifo watermark
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *watermark pointer to a fifo watermark buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo watermark failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_watermark(bmp384_handle_t *handle, uint16_t *watermark);

/**
 * @brief     enable or disable the fifo
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set fifo failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the fifo status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo stopping on full
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set fifo stop on full failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo_stop_on_full(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the fifo stopping on full status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo stop on full failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_stop_on_full(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo sensor time on
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set fifo sensor time on failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo_sensortime_on(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the fifo sensor time on status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo sensor time on failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_sensortime_on(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo pressure on
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set fifo pressure on failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo_pressure_on(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the fifo pressure on status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo pressure on failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_pressure_on(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     enable or disable the fifo temperature on
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set fifo temperature on failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo_temperature_on(bmp384_handle_t *handle, bmp384_bool_t enable);

/**
 * @brief      get the fifo temperature on status
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *enable pointer to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo temperature on failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_temperature_on(bmp384_handle_t *handle, bmp384_bool_t *enable);

/**
 * @brief     set the fifo subsampling
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] subsample fifo subsample
 * @return    status code
 *            - 0 success
 *            - 1 set fifo subsampling failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      subsample <= 7
 */
uint8_t bmp384_set_fifo_subsampling(bmp384_handle_t *handle, uint8_t subsample);

/**
 * @brief      get the fifo subsampling
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *subsample pointer to subsample buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo subsampling failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_subsampling(bmp384_handle_t *handle, uint8_t *subsample);

/**
 * @brief     set the fifo data source
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] source fifo data source
 * @return    status code
 *            - 0 success
 *            - 1 set fifo data source failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_fifo_data_source(bmp384_handle_t *handle, bmp384_fifo_data_source_t source);

/**
 * @brief      get the fifo data source
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[out] *source pointer to fifo data source buffer
 * @return     status code
 *             - 0 success
 *             - 1 get fifo data source failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_fifo_data_source(bmp384_handle_t *handle, bmp384_fifo_data_source_t *source);

/**
 * @brief     flush the fifo
 * @param[in] *handle pointer to a bmp384 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 flush fifo failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_flush_fifo(bmp384_handle_t *handle);

/**
 * @brief         read the fifo
 * @param[in]     *handle pointer to a bmp384 handle structure
 * @param[in]     *buf pointer to a data buffer
 * @param[in,out] *len pointer to a data length buffer
 * @return        status code
 *                - 0 success
 *                - 1 read fifo failed
 *                - 2 handle is NULL
 *                - 3 handle is not initialized
 * @note          none
 */
uint8_t bmp384_read_fifo(bmp384_handle_t *handle, uint8_t *buf, uint16_t *len);

/**
 * @brief         parse the fifo data
 * @param[in]     *handle pointer to a bmp384 handle structure
 * @param[in]     *buf pointer to fifo data
 * @param[in]     buf_len fifo data length
 * @param[out]    *frame pointer to a frame buffer
 * @param[in,out] *frame_len pointer to a frame length buffer
 * @return        status code
 *                - 0 success
 *                - 1 fifo parse failed
 *                - 2 handle is NULL
 *                - 3 handle is not initialized
 * @note          none
 */
uint8_t bmp384_fifo_parse(bmp384_handle_t *handle, uint8_t *buf, uint16_t buf_len, bmp384_frame_t *frame, uint16_t *frame_len);

/**
 * @}
 */

/**
 * @defgroup bmp384_extern_driver bmp384 extern driver function
 * @brief    bmp384 extern driver modules
 * @ingroup  bmp384_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle pointer to a bmp384 handle structure
 * @param[in] reg iic register address
 * @param[in] value data written to the register
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp384_set_reg(bmp384_handle_t *handle, uint8_t reg, uint8_t value);

/**
 * @brief      get the chip register
 * @param[in]  *handle pointer to a bmp384 handle structure
 * @param[in]  reg iic register address
 * @param[out] *value pointer to a read data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp384_get_reg(bmp384_handle_t *handle, uint8_t reg, uint8_t *value);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
