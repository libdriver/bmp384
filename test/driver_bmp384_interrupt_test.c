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
 * @file      driver_bmp384_interrupt_test.h
 * @brief     driver bmp384 interrupt test header file
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

#include "driver_bmp384_interrupt_test.h"

static bmp384_handle_t gs_handle;                 /**< bmp384 handle */
static volatile uint8_t gs_data_ready_flag;       /**< data ready flag */
static float gs_temperature_c;                    /**< temperature */
static float gs_pressure_pa;                      /**< pressure */

/**
 * @brief  interrupt test irq handler
 * @return status code
 *         - 0 success
 *         - 1 run failed
 * @note   none
 */
uint8_t bmp384_interrupt_test_irq_handler(void)
{
    /* run irq handler */
    if (bmp384_irq_handler(&gs_handle) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief     interface test receive callback
 * @param[in] type interrupt type
 * @note      none
 */
static void a_bmp384_interface_test_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP384_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            break;
        }
        case BMP384_INTERRUPT_STATUS_FIFO_FULL :
        {
            break;
        }
        case BMP384_INTERRUPT_STATUS_DATA_READY :
        {
            uint32_t temperature_raw;
            uint32_t pressure_raw;
            
            /* read temperature pressure */
            if (bmp384_read_temperature_pressure(&gs_handle, (uint32_t *)&temperature_raw, (float *)&gs_temperature_c,
                                                (uint32_t *)&pressure_raw, (float *)&gs_pressure_pa) != 0)
            {
                bmp384_interface_debug_print("bmp384: read temperature and pressure failed.\n");
           
                return;
            }
            gs_data_ready_flag  = 1;
            
            break;
        }
        default :
        {
            break;
        }
    }
}

/**
 * @brief     interrupt test
 * @param[in] interface chip interface
 * @param[in] addr_pin iic device address
 * @param[in] times test times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t bmp384_interrupt_test(bmp384_interface_t interface, bmp384_address_t addr_pin, uint32_t times)
{
    uint8_t res;
    uint32_t i;
    bmp384_info_t info;
    
    /* link functions */
    DRIVER_BMP384_LINK_INIT(&gs_handle, bmp384_handle_t);
    DRIVER_BMP384_LINK_IIC_INIT(&gs_handle, bmp384_interface_iic_init);
    DRIVER_BMP384_LINK_IIC_DEINIT(&gs_handle, bmp384_interface_iic_deinit);
    DRIVER_BMP384_LINK_IIC_READ(&gs_handle, bmp384_interface_iic_read);
    DRIVER_BMP384_LINK_IIC_WRITE(&gs_handle, bmp384_interface_iic_write);
    DRIVER_BMP384_LINK_SPI_INIT(&gs_handle, bmp384_interface_spi_init);
    DRIVER_BMP384_LINK_SPI_DEINIT(&gs_handle, bmp384_interface_spi_deinit);
    DRIVER_BMP384_LINK_SPI_READ(&gs_handle, bmp384_interface_spi_read);
    DRIVER_BMP384_LINK_SPI_WRITE(&gs_handle, bmp384_interface_spi_write);
    DRIVER_BMP384_LINK_DELAY_MS(&gs_handle, bmp384_interface_delay_ms);
    DRIVER_BMP384_LINK_DEBUG_PRINT(&gs_handle, bmp384_interface_debug_print);
    DRIVER_BMP384_LINK_RECEIVE_CALLBACK(&gs_handle, a_bmp384_interface_test_receive_callback);
    
    /* bmp384 info */
    res = bmp384_info(&info);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        bmp384_interface_debug_print("bmp384: chip is %s.\n", info.chip_name);
        bmp384_interface_debug_print("bmp384: manufacturer is %s.\n", info.manufacturer_name);
        bmp384_interface_debug_print("bmp384: interface is %s.\n", info.interface);
        bmp384_interface_debug_print("bmp384: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        bmp384_interface_debug_print("bmp384: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        bmp384_interface_debug_print("bmp384: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        bmp384_interface_debug_print("bmp384: max current is %0.2fmA.\n", info.max_current_ma);
        bmp384_interface_debug_print("bmp384: max temperature is %0.1fC.\n", info.temperature_max);
        bmp384_interface_debug_print("bmp384: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start interrupt test */
    bmp384_interface_debug_print("bmp384: start interrupt test.\n");
    
    /* set interface */
    res = bmp384_set_interface(&gs_handle, interface);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interface failed.\n");
       
        return 1;
    }
    
    /* set addr pin */
    res = bmp384_set_addr_pin(&gs_handle, addr_pin);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set addr pin failed.\n");
       
        return 1;
    }
    
    /* bmp384 init */
    res = bmp384_init(&gs_handle);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: init failed.\n");
       
        return 1;
    }
    
    /* set spi wire 4 */
    res = bmp384_set_spi_wire(&gs_handle, BMP384_SPI_WIRE_4);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set spi wire failed.\n");
        (void)bmp384_deinit(&gs_handle);   
        
        return 1;
    }
    
    /* enable iic watchdog timer */
    res = bmp384_set_iic_watchdog_timer(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set iic watchdog timer failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set iic watchdog period */
    res = bmp384_set_iic_watchdog_period(&gs_handle, BMP384_IIC_WATCHDOG_PERIOD_40_MS);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set iic watchdog period failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* disable fifo */
    res = bmp384_set_fifo(&gs_handle, BMP384_BOOL_FALSE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* disable fifo stop on full */
    res = bmp384_set_fifo_stop_on_full(&gs_handle, BMP384_BOOL_FALSE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo stop on full failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set fifo watermark 256 */
    res = bmp384_set_fifo_watermark(&gs_handle, 256);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo watermark failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable fifo sensor time on */
    res = bmp384_set_fifo_sensortime_on(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo sensor time on failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable fifo sensor time on */
    res = bmp384_set_fifo_pressure_on(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo sensor time on failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set fifo temperature on */
    res = bmp384_set_fifo_temperature_on(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo temperature on failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set fifo subsampling 0 */
    res = bmp384_set_fifo_subsampling(&gs_handle, 0);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo subsampling failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set fifo data source filtered */
    res = bmp384_set_fifo_data_source(&gs_handle, BMP384_FIFO_DATA_SOURCE_FILTERED);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set fifo data source failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set interrupt pin type push pull */
    res = bmp384_set_interrupt_pin_type(&gs_handle, BMP384_INTERRUPT_PIN_TYPE_PUSH_PULL);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interrupt pin type failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set interrupt active level higher */
    res = bmp384_set_interrupt_active_level(&gs_handle, BMP384_INTERRUPT_ACTIVE_LEVEL_HIGHER);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interrupt active level failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* disable latch interrupt pin and interrupt status */
    res = bmp384_set_latch_interrupt_pin_and_interrupt_status(&gs_handle, BMP384_BOOL_FALSE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set set latch interrupt pin and interrupt status failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable interrupt fifo watermark */
    res = bmp384_set_interrupt_fifo_watermark(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interrupt fifo watermark failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable interrupt fifo full */
    res = bmp384_set_interrupt_fifo_full(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interrupt fifo full failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable interrupt data ready */
    res = bmp384_set_interrupt_data_ready(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set interrupt data ready failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable pressure */
    res = bmp384_set_pressure(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set pressure failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* enable temperature */
    res = bmp384_set_temperature(&gs_handle, BMP384_BOOL_TRUE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set temperature failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set pressure oversampling x32 */
    res = bmp384_set_pressure_oversampling(&gs_handle, BMP384_OVERSAMPLING_x32);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set pressure oversampling failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set temperature oversampling x2 */
    res = bmp384_set_temperature_oversampling(&gs_handle, BMP384_OVERSAMPLING_x2);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set temperature oversampling failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set odr 12.5Hz */
    res = bmp384_set_odr(&gs_handle, BMP384_ODR_12P5_HZ);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set odr failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set filter coefficient 15 */
    res = bmp384_set_filter_coefficient(&gs_handle, BMP384_FILTER_COEFFICIENT_15);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set filter coefficient failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set normal mode */
    res = bmp384_set_mode(&gs_handle, BMP384_MODE_NORMAL_MODE);
    if (res != 0)
    {
        bmp384_interface_debug_print("bmp384: set mode failed.\n");
        (void)bmp384_deinit(&gs_handle); 
        
        return 1;
    }
    for (i = 0; i < times; i++)
    {
        gs_data_ready_flag = 0;
        bmp384_interface_delay_ms(500);  
        bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_temperature_c);
        bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_pressure_pa);
    
        /* check data ready flag */
        if (gs_data_ready_flag == 0)
        {
            bmp384_interface_debug_print("bmp384: interrupt failed.\n");
            (void)bmp384_deinit(&gs_handle); 
            
            return 1;
        }
        bmp384_interface_delay_ms(1000);
    }

    /* finish interrupt test */
    bmp384_interface_debug_print("bmp384: finish interrupt test.\n");
    (void)bmp384_deinit(&gs_handle); 
    
    return 0;
}
