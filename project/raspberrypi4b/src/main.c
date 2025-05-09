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
 * @file      main.c
 * @brief     main source file
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

#include "driver_bmp384_basic.h"
#include "driver_bmp384_shot.h"
#include "driver_bmp384_interrupt.h"
#include "driver_bmp384_fifo.h"
#include "driver_bmp384_register_test.h"
#include "driver_bmp384_read_test.h"
#include "driver_bmp384_interrupt_test.h"
#include "driver_bmp384_fifo_test.h"
#include "gpio.h"
#include <getopt.h>
#include <stdlib.h>

/**
 * @brief global var definition
 */
static volatile uint8_t gs_data_ready_flag;         /**< data ready flag */
static float gs_temperature_c;                      /**< temperature data */
static float gs_pressure_pa;                        /**< pressure data */
static volatile uint8_t gs_fifo_full_flag;          /**< fifo full flag */
static volatile uint8_t gs_fifo_watermark_flag;     /**< fifo watermark flag */
static uint8_t gs_buf[512];                         /**< buffer */
static bmp384_frame_t gs_frame[256];                /**< frame buffer */
uint8_t (*g_gpio_irq)(void) = NULL;                 /**< irq function address */

/**
 * @brief     interface interrupt receive callback
 * @param[in] type interrupt type
 * @note      none
 */
void bmp384_interface_interrupt_receive_callback(uint8_t type)
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
            /* read temperature pressure */
            if (bmp384_interrupt_read((float *)&gs_temperature_c, (float *)&gs_pressure_pa) != 0)
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
 * @brief     interface fifo receive callback
 * @param[in] type interrupt type
 * @note      none
 */
void bmp384_interface_fifo_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP384_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp384_fifo_read(gs_buf, len, (bmp384_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp384_interface_debug_print("bmp384: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP384_FRAME_TYPE_TEMPERATURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensor time is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknown type.\n");
                }
            }
            gs_fifo_watermark_flag = 1;
            
            break;
        }
        case BMP384_INTERRUPT_STATUS_FIFO_FULL :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp384_fifo_read(gs_buf, len, (bmp384_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp384_interface_debug_print("bmp384: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP384_FRAME_TYPE_TEMPERATURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensor time is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i + 1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknown type.\n");
                }
            }
            gs_fifo_full_flag = 1;
            
            break;
        }
        case BMP384_INTERRUPT_STATUS_DATA_READY :
        {
            break;
        }
        default :
        {
            break;
        }
    }
}

/**
 * @brief     bmp384 full function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t bmp384(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"addr", required_argument, NULL, 1},
        {"interface", required_argument, NULL, 2},
        {"times", required_argument, NULL, 3},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    uint32_t times = 3;
    bmp384_address_t addr = BMP384_ADDRESS_ADO_LOW;
    bmp384_interface_t interface = BMP384_INTERFACE_IIC;
    
    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }
    
    /* init 0 */
    optind = 0;
    
    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);
        
        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");
                
                break;
            }
            
            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");
                
                break;
            }
            
            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");
                
                break;
            }
            
            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);
                
                break;
            }
            
            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);
                
                break;
            }
            
            /* addr */
            case 1 :
            {
                /* set the addr */
                if (strcmp("0", optarg) == 0)
                {
                    addr = BMP384_ADDRESS_ADO_LOW;
                }
                else if (strcmp("1", optarg) == 0)
                {
                    addr = BMP384_ADDRESS_ADO_HIGH;
                }
                else
                {
                    return 5;
                }
                
                break;
            }
            
            /* interface */
            case 2 :
            {
                /* set the interface */
                if (strcmp("iic", optarg) == 0)
                {
                    interface = BMP384_INTERFACE_IIC;
                }
                else if (strcmp("spi", optarg) == 0)
                {
                    interface = BMP384_INTERFACE_SPI;
                }
                else
                {
                    return 5;
                }
                
                break;
            }

            /* running times */
            case 3 :
            {
                /* set the times */
                times = atol(optarg);
                
                break;
            } 
            
            /* the end */
            case -1 :
            {
                break;
            }
            
            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run the function */
    if (strcmp("t_reg", type) == 0)
    {
        uint8_t res;
        
        /* run the reg test */
        res = bmp384_register_test(interface, addr);
        if (res != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp("t_read", type) == 0)
    {
        uint8_t res;
        
        /* run the read test */
        res = bmp384_read_test(interface, addr, times);
        if (res != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp("t_int", type) == 0)
    {
        uint8_t res;
        
        /* gpio init */
        res = gpio_interrupt_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* set the gpio irq */
        g_gpio_irq = bmp384_interrupt_test_irq_handler;
        
        /* run the interrupt test */
        res = bmp384_interrupt_test(interface, addr, times);
        if (res != 0)
        {
            g_gpio_irq = NULL;
            (void)gpio_interrupt_deinit();
            
            return 1;
        }
        
        /* gpio deinit */
        g_gpio_irq = NULL;
        (void)gpio_interrupt_deinit();
        
        return 0;
    }
    else if (strcmp("t_fifo", type) == 0)
    {
        uint8_t res;
        
        /* gpio init */
        res = gpio_interrupt_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* set the gpio irq */
        g_gpio_irq = bmp384_fifo_test_irq_handler;
        
        /* run the fifo test */
        res = bmp384_fifo_test(interface, addr, times);
        if (res != 0)
        {
            g_gpio_irq = NULL;
            (void)gpio_interrupt_deinit();
            
            return 1;
        }
        
        /* gpio deinit */
        g_gpio_irq = NULL;
        (void)gpio_interrupt_deinit();
        
        return 0;
    }
    else if (strcmp("e_read", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature_c;
        float pressure_pa;
        
        /* basic init */
        res = bmp384_basic_init(interface, addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            bmp384_interface_delay_ms(1000);
            
            /* read data */
            res = bmp384_basic_read((float *)&temperature_c, (float *)&pressure_pa);
            if (res != 0)
            {
                (void)bmp384_basic_deinit();
                
                return 1;
            }
            
            /* output */
            bmp384_interface_debug_print("bmp384: %d/%d.\n", i + 1, times);
            bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
            bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);
        }
        
        /* deinit */
        (void)bmp384_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_shot", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature_c;
        float pressure_pa;
        
        /* shot init */
        res = bmp384_shot_init(interface, addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            bmp384_interface_delay_ms(1000);
            
            /* read data */
            res = bmp384_shot_read((float *)&temperature_c, (float *)&pressure_pa);
            if (res != 0)
            {
                (void)bmp384_shot_deinit();
                
                return 1;
            }
            
            /* output */
            bmp384_interface_debug_print("bmp384: %d/%d.\n", i + 1, times);
            bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
            bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);
        }
        (void)bmp384_shot_deinit();
        
        return 0;
    }
    else if (strcmp("e_int", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        uint32_t timeout;
        
        /* set the gpio irq */
        g_gpio_irq = bmp384_interrupt_irq_handler;
        
        /* gpio init */
        res = gpio_interrupt_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* interrupt init */
        res = bmp384_interrupt_init(interface, addr, bmp384_interface_interrupt_receive_callback);
        if (res != 0)
        {
            g_gpio_irq = NULL;
            (void)gpio_interrupt_deinit();
            
            return 1;
        }
        
        /* param init */
        gs_data_ready_flag = 0;
        timeout = 5000;
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* check the timeout */
            while (timeout != 0)
            {
                /* delay 100ms */
                bmp384_interface_delay_ms(100);
                timeout--;
                
                /* check the ready flag */
                if (gs_data_ready_flag != 0)
                {
                    break;
                }
                
                /* check the timeout */
                if (timeout == 0)
                {
                    g_gpio_irq = NULL;
                    (void)gpio_interrupt_deinit();
                    (void)bmp384_interrupt_deinit();
                    
                    return 1;
                }
            }
            gs_data_ready_flag = 0;
            timeout = 5000;
            
            /* output */
            bmp384_interface_debug_print("bmp384: %d/%d.\n", i + 1, times);
            bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_temperature_c);
            bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_pressure_pa);
        }
        
        /* deinit */
        g_gpio_irq = NULL;
        (void)gpio_interrupt_deinit();
        (void)bmp384_interrupt_deinit();
        
        return 0;
    }
    else if (strcmp("e_fifo", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        uint32_t timeout;

        /* set the gpio irq */
        g_gpio_irq = bmp384_fifo_irq_handler;
        res = gpio_interrupt_init();
        if (res != 0)
        {
            return 1;
        }
        
        /* fifo init */
        res = bmp384_fifo_init(interface, addr, bmp384_interface_fifo_receive_callback);
        if (res != 0)
        {
            g_gpio_irq = NULL;
            (void)gpio_interrupt_deinit();
            
            return 1;
        }
        
        /* param init */
        gs_fifo_watermark_flag = 0;
        gs_fifo_full_flag = 0;
        timeout = 5000;
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* check the timeout */
            while (timeout != 0)
            {
                /* delay 100ms */
                bmp384_interface_delay_ms(100);
                timeout--;
                
                /* check the flag */
                if (gs_fifo_watermark_flag != 0 || gs_fifo_full_flag != 0)
                {
                    break;
                }
                
                /* check the timeout */
                if (timeout == 0)
                {
                    g_gpio_irq = NULL;
                    (void)gpio_interrupt_deinit();
                    (void)bmp384_fifo_deinit();
                    
                    return 1;
                }
            }
            
            /* param init */
            gs_fifo_watermark_flag = 0;
            gs_fifo_full_flag = 0;
            timeout = 5000;
        }
        bmp384_interface_debug_print("bmp384: finish fifo read.\n");
        
        /* gpio deinit */
        g_gpio_irq = NULL;
        (void)gpio_interrupt_deinit();
        (void)bmp384_fifo_deinit();
        
        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        bmp384_interface_debug_print("Usage:\n");
        bmp384_interface_debug_print("  bmp384 (-i | --information)\n");
        bmp384_interface_debug_print("  bmp384 (-h | --help)\n");
        bmp384_interface_debug_print("  bmp384 (-p | --port)\n");
        bmp384_interface_debug_print("  bmp384 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]\n");
        bmp384_interface_debug_print("  bmp384 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("  bmp384 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]\n");
        bmp384_interface_debug_print("\n");
        bmp384_interface_debug_print("Options:\n");
        bmp384_interface_debug_print("      --addr=<0 | 1>                 Set the chip iic address.([default: 0])\n");
        bmp384_interface_debug_print("  -e <read | shot | int | fifo>, --example=<read | shot | int | fifo>\n");
        bmp384_interface_debug_print("                                     Run the driver example.\n");
        bmp384_interface_debug_print("  -h, --help                         Show the help.\n");
        bmp384_interface_debug_print("  -i, --information                  Show the chip information.\n");
        bmp384_interface_debug_print("      --interface=<iic | spi>        Set the chip interface.([default: iic])\n");
        bmp384_interface_debug_print("  -p, --port                         Display the pin connections of the current board.\n");
        bmp384_interface_debug_print("  -t <reg | read | int | fifo>, --test=<reg | read | int | fifo>\n");
        bmp384_interface_debug_print("                                     Run the driver test.\n");
        bmp384_interface_debug_print("      --times=<num>                  Set the running times.([default: 3])\n");
        
        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        bmp384_info_t info;
        
        /* print bmp384 info */
        bmp384_info(&info);
        bmp384_interface_debug_print("bmp384: chip is %s.\n", info.chip_name);
        bmp384_interface_debug_print("bmp384: manufacturer is %s.\n", info.manufacturer_name);
        bmp384_interface_debug_print("bmp384: interface is %s.\n", info.interface);
        bmp384_interface_debug_print("bmp384: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        bmp384_interface_debug_print("bmp384: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        bmp384_interface_debug_print("bmp384: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        bmp384_interface_debug_print("bmp384: max current is %0.2fmA.\n", info.max_current_ma);
        bmp384_interface_debug_print("bmp384: max temperature is %0.1fC.\n", info.temperature_max);
        bmp384_interface_debug_print("bmp384: min temperature is %0.1fC.\n", info.temperature_min);
        
        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        bmp384_interface_debug_print("bmp384: SPI interface SCK connected to GPIO11(BCM).\n");
        bmp384_interface_debug_print("bmp384: SPI interface MISO connected to GPIO9(BCM).\n");
        bmp384_interface_debug_print("bmp384: SPI interface MOSI connected to GPIO10(BCM).\n");
        bmp384_interface_debug_print("bmp384: SPI interface CS connected to GPIO8(BCM).\n");
        bmp384_interface_debug_print("bmp384: IIC interface SCL connected to GPIO3(BCM).\n");
        bmp384_interface_debug_print("bmp384: IIC interface SDA connected to GPIO2(BCM).\n");
        bmp384_interface_debug_print("bmp384: INT connected to GPIO17(BCM).\n");
        
        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = bmp384(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        bmp384_interface_debug_print("bmp384: run failed.\n");
    }
    else if (res == 5)
    {
        bmp384_interface_debug_print("bmp384: param is invalid.\n");
    }
    else
    {
        bmp384_interface_debug_print("bmp384: unknown status code.\n");
    }

    return 0;
}
