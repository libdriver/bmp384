### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

SPI Pin: SCK/MISO/MOSI/CS  PA5/PA6/PA7/PA4.

GPIO Pin: INT PB0.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. BMP384

#### 3.1 Command Instruction

1. Show bmp384 chip and driver information.

   ```shell
   bmp384 (-i | --information)
   ```

2. Show bmp384 help.

   ```shell
   bmp384 (-h | --help)
   ```

3. Show bmp384 pin connections of the current board.

   ```shell
   bmp384 (-p | --port)
   ```

4. Run bmp384 register test.

   ```shell
   bmp384 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

5. Run bmp384 read test, num means the test times. 

   ```shell
   bmp384 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

6. Run bmp384 interrupt test, num means the test times.

   ```shell
   bmp384 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

7. Run bmp384 fifo test, num means the test times.

   ```shell
   bmp384 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

8. Run bmp384 read function, num means the read times. 

   ```shell
   bmp384 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

9. Run bmp384 shot function, num means the read times.

   ```shell
   bmp384 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

10. Run bmp384 interrupt function, num means the read times.

    ```shell
    bmp384 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
    ```

11. Run bmp384 fifo function, num means the read times.

    ```shell
    bmp384 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
    ```

#### 3.2 Command Example

```shell
bmp384 -i

bmp384: chip is Bosch BMP384.
bmp384: manufacturer is Bosch.
bmp384: interface is IIC SPI.
bmp384: driver version is 1.0.
bmp384: min supply voltage is 1.6V.
bmp384: max supply voltage is 3.6V.
bmp384: max current is 0.80mA.
bmp384: max temperature is 85.0C.
bmp384: min temperature is -40.0C.
```

```shell
bmp384 -p

bmp384: SPI interface SCK connected to GPIOA PIN5.
bmp384: SPI interface MISO connected to GPIOA PIN6.
bmp384: SPI interface MOSI connected to GPIOA PIN7.
bmp384: SPI interface CS connected to GPIOA PIN4.
bmp384: IIC interface SCL connected to GPIOB PIN8.
bmp384: IIC interface SDA connected to GPIOB PIN9.
bmp384: INT connected to GPIOB PIN0.
```

```shell
bmp384 -t reg --addr=0 --interface=iic

bmp384: chip is Bosch BMP384.
bmp384: manufacturer is Bosch.
bmp384: interface is IIC SPI.
bmp384: driver version is 1.0.
bmp384: min supply voltage is 1.6V.
bmp384: max supply voltage is 3.6V.
bmp384: max current is 0.80mA.
bmp384: max temperature is 85.0C.
bmp384: min temperature is -40.0C.
bmp384: start register test.
bmp384: bmp384_set_interface/bmp384_get_interface test.
bmp384: set interface iic.
bmp384: check interface ok.
bmp384: set interface spi.
bmp384: check interface ok.
bmp384: bmp384_set_addr_pin/bmp384_get_addr_pin test.
bmp384: set addr pin low.
bmp384: check addr pin ok.
bmp384: set addr pin high.
bmp384: check addr pin ok.
bmp384: bmp384_set_fifo_watermark/bmp384_get_fifo_watermark test.
bmp384: set fifo watermark 432.
bmp384: check fifo watermark ok.
bmp384: bmp384_set_fifo/bmp384_get_fifo test.
bmp384: set fifo enable.
bmp384: check fifo ok.
bmp384: set fifo disable.
bmp384: check fifo ok.
bmp384: bmp384_set_fifo_stop_on_full/bmp384_get_fifo_stop_on_full test.
bmp384: set fifo stop on full enable.
bmp384: check fifo stop on full ok.
bmp384: set fifo stop on full disable.
bmp384: check fifo stop on full ok.
bmp384: bmp384_set_fifo_sensortime_on/bmp384_get_fifo_sensortime_on test.
bmp384: set fifo sensor time on enable.
bmp384: check fifo sensor time on ok.
bmp384: set fifo sensor time on disable.
bmp384: check fifo sensor time on ok.
bmp384: bmp384_set_fifo_pressure_on/bmp384_get_fifo_pressure_on test.
bmp384: set fifo pressure on enable.
bmp384: check fifo pressure on ok.
bmp384: set fifo pressure on disable.
bmp384: check fifo pressure on ok.
bmp384: bmp384_set_fifo_temperature_on/bmp384_get_fifo_temperature_on test.
bmp384: set fifo temperature on enable.
bmp384: check fifo temperature on ok.
bmp384: set fifo temperature on disable.
bmp384: check fifo temperature on ok.
bmp384: bmp384_set_fifo_subsampling/bmp384_get_fifo_subsampling test.
bmp384: set fifo subsampling 4.
bmp384: check fifo subsampling on ok.
bmp384: bmp384_set_fifo_data_source/bmp384_get_fifo_data_source test.
bmp384: set fifo data source unfiltered.
bmp384: check fifo data source ok.
bmp384: set fifo data source filtered.
bmp384: check fifo data source ok.
bmp384: bmp384_set_interrupt_pin_type/bmp384_get_interrupt_pin_type test.
bmp384: set interrupt pin type push pull.
bmp384: check interrupt pin type ok.
bmp384: set interrupt pin type open drain.
bmp384: check interrupt pin type ok.
bmp384: bmp384_set_interrupt_active_level/bmp384_get_interrupt_active_level test.
bmp384: set interrupt active level lower.
bmp384: check interrupt active level ok.
bmp384: set interrupt active level higher.
bmp384: check interrupt active level ok.
bmp384: bmp384_set_latch_interrupt_pin_and_interrupt_status/bmp384_get_latch_interrupt_pin_and_interrupt_status test.
bmp384: set latch interrupt pin and interrupt status enable.
bmp384: check latch interrupt pin and interrupt status ok.
bmp384: set latch interrupt pin and interrupt status disable.
bmp384: check latch interrupt pin and interrupt status ok.
bmp384: bmp384_set_interrupt_fifo_watermark/bmp384_get_interrupt_fifo_watermark test.
bmp384: set interrupt fifo watermark enable.
bmp384: check interrupt fifo watermark ok.
bmp384: set interrupt fifo watermark disable.
bmp384: check interrupt fifo watermark ok.
bmp384: bmp384_set_interrupt_fifo_full/bmp384_get_interrupt_fifo_full test.
bmp384: set interrupt fifo full enable.
bmp384: check interrupt fifo full ok.
bmp384: set interrupt fifo full disable.
bmp384: check interrupt fifo full ok.
bmp384: bmp384_set_interrupt_data_ready/bmp384_get_interrupt_fifo_data_ready test.
bmp384: set interrupt data ready enable.
bmp384: check interrupt data ready ok.
bmp384: set interrupt data ready disable.
bmp384: check interrupt data ready ok.
bmp384: bmp384_set_spi_wire/bmp384_get_spi_wire test.
bmp384: set spi 4 wire.
bmp384: check spi wire ok.
bmp384: set spi 3 wire.
bmp384: check spi wire ok.
bmp384: bmp384_set_iic_watchdog_timer/bmp384_get_iic_watchdog_timer test.
bmp384: set iic watchdog timer enable.
bmp384: check iic watchdog timer ok.
bmp384: set iic watchdog timer disable.
bmp384: check iic watchdog timer ok.
bmp384: bmp384_set_iic_watchdog_period/bmp384_get_iic_watchdog_period test.
bmp384: set iic watchdog period 1.25ms.
bmp384: check iic watchdog period ok.
bmp384: set iic watchdog period 40ms.
bmp384: check iic watchdog period ok.
bmp384: bmp384_set_pressure/bmp384_get_pressure test.
bmp384: set pressure disable.
bmp384: check pressure ok.
bmp384: set pressure enable.
bmp384: check pressure ok.
bmp384: bmp384_set_temperature/bmp384_get_temperature test.
bmp384: set temperature disable.
bmp384: check temperature ok.
bmp384: set temperature enable.
bmp384: check temperature ok.
bmp384: bmp384_set_mode/bmp384_get_mode test.
bmp384: set mode sleep.
bmp384: check mode ok.
bmp384: set mode normal mode.
bmp384: check mode ok.
bmp384: set mode forced mode.
bmp384: check mode ok.
bmp384: bmp384_set_pressure_oversampling/bmp384_get_pressure_oversampling test.
bmp384: set pressure oversampling x1.
bmp384: check pressure oversampling ok.
bmp384: set pressure oversampling x2.
bmp384: check pressure oversampling ok.
bmp384: set pressure oversampling x4.
bmp384: check pressure oversampling ok.
bmp384: set pressure oversampling x8.
bmp384: check pressure oversampling ok.
bmp384: set pressure oversampling x16.
bmp384: check pressure oversampling ok.
bmp384: set pressure oversampling x32.
bmp384: check pressure oversampling ok.
bmp384: bmp384_set_temperature_oversampling/bmp384_get_temperature_oversampling test.
bmp384: set temperature oversampling x1.
bmp384: check temperature oversampling ok.
bmp384: set temperature oversampling x2.
bmp384: check temperature oversampling ok.
bmp384: set temperature oversampling x4.
bmp384: check temperature oversampling ok.
bmp384: set temperature oversampling x8.
bmp384: check temperature oversampling ok.
bmp384: set temperature oversampling x16.
bmp384: check temperature oversampling ok.
bmp384: set temperature oversampling x32.
bmp384: check temperature oversampling ok.
bmp384: bmp384_set_odr/bmp384_get_odr test.
bmp384: set odr 200Hz.
bmp384: check odr ok.
bmp384: set odr 100Hz.
bmp384: check odr ok.
bmp384: set odr 50Hz.
bmp384: check odr ok.
bmp384: set odr 25Hz.
bmp384: check odr ok.
bmp384: set odr 12.5Hz.
bmp384: check odr ok.
bmp384: set odr 6.25Hz.
bmp384: check odr ok.
bmp384: set odr 3.1Hz.
bmp384: check odr ok.
bmp384: set odr 1.5Hz.
bmp384: check odr ok.
bmp384: set odr 0.78Hz.
bmp384: check odr ok.
bmp384: set odr 0.39Hz.
bmp384: check odr ok.
bmp384: set odr 0.2Hz.
bmp384: check odr ok.
bmp384: set odr 0.1Hz.
bmp384: check odr ok.
bmp384: set odr 0.05Hz.
bmp384: check odr ok.
bmp384: set odr 0.02Hz.
bmp384: check odr ok.
bmp384: set odr 0.01Hz.
bmp384: check odr ok.
bmp384: set odr 0.006Hz.
bmp384: check odr ok.
bmp384: set odr 0.003Hz.
bmp384: check odr ok.
bmp384: set odr 0.0015Hz.
bmp384: check odr ok.
bmp384: bmp384_set_filter_coefficient/bmp384_get_filter_coefficient test.
bmp384: set filter coefficient 0.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 1.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 3.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 7.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 15.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 31.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 63.
bmp384: check filter coefficient ok.
bmp384: set filter coefficient 127.
bmp384: check filter coefficient ok.
bmp384: bmp384_get_error.
bmp384: err is 0x00.
bmp384: bmp384_get_status.
bmp384: status is 0x70.
bmp384: bmp384_get_sensortime.
bmp384: sensor time is 0x002A9F.
bmp384: bmp384_get_event.
bmp384: event is power up or softrest.
bmp384: bmp384_get_interrupt_status.
bmp384: interrupt status is 0x08.
bmp384: bmp384_get_fifo_length.
bmp384: get fifo length is 0x0000.
bmp384: bmp384_get_fifo_data.
bmp384: get fifo data is 0x0080.
bmp384: bmp384_flush_fifo.
bmp384: flush fifo ok.
bmp384: bmp384_extmode_en_middle.
bmp384: extmode en middle ok.
bmp384: bmp384_softreset.
bmp384: soft reset ok.
bmp384: finish register test.
```

```shell
bmp384 -t read --addr=0 --interface=iic --times=3

bmp384: chip is Bosch BMP384.
bmp384: manufacturer is Bosch.
bmp384: interface is IIC SPI.
bmp384: driver version is 1.0.
bmp384: min supply voltage is 1.6V.
bmp384: max supply voltage is 3.6V.
bmp384: max current is 0.80mA.
bmp384: max temperature is 85.0C.
bmp384: min temperature is -40.0C.
bmp384: start read test.
bmp384: forced mode read test.
bmp384: temperature is 26.08C.
bmp384: pressure is 101267.80Pa.
bmp384: temperature is 26.08C.
bmp384: pressure is 101267.65Pa.
bmp384: temperature is 26.07C.
bmp384: pressure is 101267.39Pa.
bmp384: normal mode read test.
bmp384: temperature is 26.10C.
bmp384: pressure is 101258.35Pa.
bmp384: temperature is 26.17C.
bmp384: pressure is 101254.11Pa.
bmp384: temperature is 26.20C.
bmp384: pressure is 101251.87Pa.
bmp384: finish read test.
```

```shell
bmp384 -t int --addr=0 --interface=iic --times=3

bmp384: chip is Bosch BMP384.
bmp384: manufacturer is Bosch.
bmp384: interface is IIC SPI.
bmp384: driver version is 1.0.
bmp384: min supply voltage is 1.6V.
bmp384: max supply voltage is 3.6V.
bmp384: max current is 0.80mA.
bmp384: max temperature is 85.0C.
bmp384: min temperature is -40.0C.
bmp384: start interrupt test.
bmp384: temperature is 24.36C.
bmp384: pressure is 101267.79Pa.
bmp384: temperature is 24.51C.
bmp384: pressure is 101262.07Pa.
bmp384: temperature is 24.57C.
bmp384: pressure is 101260.32Pa.
bmp384: finish interrupt test.
```

```shell
bmp384 -t fifo --addr=0 --interface=iic --times=3

bmp384: chip is Bosch BMP384.
bmp384: manufacturer is Bosch.
bmp384: interface is IIC SPI.
bmp384: driver version is 1.0.
bmp384: min supply voltage is 1.6V.
bmp384: max supply voltage is 3.6V.
bmp384: max current is 0.80mA.
bmp384: max temperature is 85.0C.
bmp384: min temperature is -40.0C.
bmp384: start fifo test.
bmp384: fifo watermark test.
bmp384: clear fifo with length 510.
bmp384: fifo parse success and total frame is 145.
bmp384: read fifo with length 4.
bmp384: clear fifo with length 508.
bmp384: fifo parse success and total frame is 145.
bmp384: read fifo with length 4.
bmp384: clear fifo with length 508.
bmp384: fifo parse success and total frame is 145.
bmp384: read fifo with length 4.
bmp384: fifo full test.
bmp384: clear fifo with length 508.
bmp384: fifo parse success and total frame is 145.
bmp384: clear fifo with length 508.
bmp384: fifo parse success and total frame is 145.
bmp384: clear fifo with length 508.
bmp384: fifo parse success and total frame is 145.
bmp384: finish fifo test.
```

```shell
bmp384 -e read --addr=0 --interface=iic --times=3

bmp384: 1/3.
bmp384: temperature is 24.11C.
bmp384: pressure is 101266.96Pa.
bmp384: 2/3.
bmp384: temperature is 24.19C.
bmp384: pressure is 101261.95Pa.
bmp384: 3/3.
bmp384: temperature is 24.24C.
bmp384: pressure is 101259.92Pa.
```

```shell
bmp384 -e shot --addr=0 --interface=iic --times=3

bmp384: 1/3.
bmp384: temperature is 24.03C.
bmp384: pressure is 101271.20Pa.
bmp384: 2/3.
bmp384: temperature is 24.03C.
bmp384: pressure is 101271.29Pa.
bmp384: 3/3.
bmp384: temperature is 24.03C.
bmp384: pressure is 101271.18Pa.
```

```shell
bmp384 -e int --addr=0 --interface=iic --times=3

bmp384: 1/3.
bmp384: temperature is 24.08C.
bmp384: pressure is 101271.62Pa.
bmp384: 2/3.
bmp384: temperature is 24.08C.
bmp384: pressure is 101271.16Pa.
bmp384: 3/3.
bmp384: temperature is 24.10C.
bmp384: pressure is 101270.09Pa.
```

```shell
bmp384 -e fifo --addr=0 --interface=iic --times=3

bmp384: fifo 1/75.
bmp384: temperature is 24.09C.
bmp384: fifo 2/75.
bmp384: pressure is 101272.29Pa.
bmp384: fifo 3/75.
bmp384: temperature is 24.09C.
bmp384: fifo 4/75.
bmp384: pressure is 101271.92Pa.
bmp384: fifo 5/75.
bmp384: temperature is 24.10C.
bmp384: fifo 6/75.
bmp384: pressure is 101271.47Pa.
bmp384: fifo 7/75.
bmp384: temperature is 24.11C.
bmp384: fifo 8/75.
bmp384: pressure is 101270.80Pa.
bmp384: fifo 9/75.
bmp384: temperature is 24.12C.
bmp384: fifo 10/75.
bmp384: pressure is 101270.26Pa.
bmp384: fifo 11/75.
bmp384: temperature is 24.13C.
bmp384: fifo 12/75.
bmp384: pressure is 101269.68Pa.
bmp384: fifo 13/75.
bmp384: temperature is 24.14C.
bmp384: fifo 14/75.
bmp384: pressure is 101269.06Pa.
bmp384: fifo 15/75.
bmp384: temperature is 24.15C.
bmp384: fifo 16/75.
bmp384: pressure is 101268.53Pa.
bmp384: fifo 17/75.
bmp384: temperature is 24.16C.
bmp384: fifo 18/75.
bmp384: pressure is 101268.03Pa.
bmp384: fifo 19/75.
bmp384: temperature is 24.17C.
bmp384: fifo 20/75.
bmp384: pressure is 101267.57Pa.
bmp384: fifo 21/75.
bmp384: temperature is 24.18C.
bmp384: fifo 22/75.
bmp384: pressure is 101267.08Pa.
bmp384: fifo 23/75.
bmp384: temperature is 24.19C.
bmp384: fifo 24/75.
bmp384: pressure is 101266.56Pa.
bmp384: fifo 25/75.
bmp384: temperature is 24.20C.
bmp384: fifo 26/75.
bmp384: pressure is 101266.20Pa.
bmp384: fifo 27/75.
bmp384: temperature is 24.20C.
bmp384: fifo 28/75.
bmp384: pressure is 101265.90Pa.
bmp384: fifo 29/75.
bmp384: temperature is 24.21C.
bmp384: fifo 30/75.
bmp384: pressure is 101265.57Pa.
bmp384: fifo 31/75.
bmp384: temperature is 24.22C.
bmp384: fifo 32/75.
bmp384: pressure is 101265.30Pa.
bmp384: fifo 33/75.
bmp384: temperature is 24.23C.
bmp384: fifo 34/75.
bmp384: pressure is 101265.10Pa.
bmp384: fifo 35/75.
bmp384: temperature is 24.23C.
bmp384: fifo 36/75.
bmp384: pressure is 101264.84Pa.
bmp384: fifo 37/75.
bmp384: temperature is 24.24C.
bmp384: fifo 38/75.
bmp384: pressure is 101264.61Pa.
bmp384: fifo 39/75.
bmp384: temperature is 24.25C.
bmp384: fifo 40/75.
bmp384: pressure is 101264.36Pa.
bmp384: fifo 41/75.
bmp384: temperature is 24.25C.
bmp384: fifo 42/75.
bmp384: pressure is 101264.11Pa.
bmp384: fifo 43/75.
bmp384: temperature is 24.26C.
bmp384: fifo 44/75.
bmp384: pressure is 101263.95Pa.
bmp384: fifo 45/75.
bmp384: temperature is 24.27C.
bmp384: fifo 46/75.
bmp384: pressure is 101263.71Pa.
bmp384: fifo 47/75.
bmp384: temperature is 24.27C.
bmp384: fifo 48/75.
bmp384: pressure is 101263.43Pa.
bmp384: fifo 49/75.
bmp384: temperature is 24.28C.
bmp384: fifo 50/75.
bmp384: pressure is 101263.24Pa.
bmp384: fifo 51/75.
bmp384: temperature is 24.28C.
bmp384: fifo 52/75.
bmp384: pressure is 101262.99Pa.
bmp384: fifo 53/75.
bmp384: temperature is 24.29C.
bmp384: fifo 54/75.
bmp384: pressure is 101262.89Pa.
bmp384: fifo 55/75.
bmp384: temperature is 24.29C.
bmp384: fifo 56/75.
bmp384: pressure is 101262.82Pa.
bmp384: fifo 57/75.
bmp384: temperature is 24.29C.
bmp384: fifo 58/75.
bmp384: pressure is 101262.69Pa.
bmp384: fifo 59/75.
bmp384: temperature is 24.30C.
bmp384: fifo 60/75.
bmp384: pressure is 101262.65Pa.
bmp384: fifo 61/75.
bmp384: temperature is 24.30C.
bmp384: fifo 62/75.
bmp384: pressure is 101262.59Pa.
bmp384: fifo 63/75.
bmp384: temperature is 24.31C.
bmp384: fifo 64/75.
bmp384: pressure is 101262.67Pa.
bmp384: fifo 65/75.
bmp384: temperature is 24.31C.
bmp384: fifo 66/75.
bmp384: pressure is 101262.49Pa.
bmp384: fifo 67/75.
bmp384: temperature is 24.31C.
bmp384: fifo 68/75.
bmp384: pressure is 101262.43Pa.
bmp384: fifo 69/75.
bmp384: temperature is 24.32C.
bmp384: fifo 70/75.
bmp384: pressure is 101262.33Pa.
bmp384: fifo 71/75.
bmp384: temperature is 24.32C.
bmp384: fifo 72/75.
bmp384: pressure is 101262.31Pa.
bmp384: fifo 73/75.
bmp384: temperature is 24.32C.
bmp384: fifo 74/75.
bmp384: pressure is 101262.35Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 73973.
bmp384: fifo 1/75.
bmp384: temperature is 24.33C.
bmp384: fifo 2/75.
bmp384: pressure is 101262.31Pa.
bmp384: fifo 3/75.
bmp384: temperature is 24.33C.
bmp384: fifo 4/75.
bmp384: pressure is 101262.17Pa.
bmp384: fifo 5/75.
bmp384: temperature is 24.33C.
bmp384: fifo 6/75.
bmp384: pressure is 101262.14Pa.
bmp384: fifo 7/75.
bmp384: temperature is 24.33C.
bmp384: fifo 8/75.
bmp384: pressure is 101262.14Pa.
bmp384: fifo 9/75.
bmp384: temperature is 24.34C.
bmp384: fifo 10/75.
bmp384: pressure is 101262.11Pa.
bmp384: fifo 11/75.
bmp384: temperature is 24.34C.
bmp384: fifo 12/75.
bmp384: pressure is 101262.11Pa.
bmp384: fifo 13/75.
bmp384: temperature is 24.34C.
bmp384: fifo 14/75.
bmp384: pressure is 101262.06Pa.
bmp384: fifo 15/75.
bmp384: temperature is 24.34C.
bmp384: fifo 16/75.
bmp384: pressure is 101262.13Pa.
bmp384: fifo 17/75.
bmp384: temperature is 24.34C.
bmp384: fifo 18/75.
bmp384: pressure is 101262.05Pa.
bmp384: fifo 19/75.
bmp384: temperature is 24.35C.
bmp384: fifo 20/75.
bmp384: pressure is 101262.10Pa.
bmp384: fifo 21/75.
bmp384: temperature is 24.35C.
bmp384: fifo 22/75.
bmp384: pressure is 101262.18Pa.
bmp384: fifo 23/75.
bmp384: temperature is 24.35C.
bmp384: fifo 24/75.
bmp384: pressure is 101262.11Pa.
bmp384: fifo 25/75.
bmp384: temperature is 24.35C.
bmp384: fifo 26/75.
bmp384: pressure is 101262.10Pa.
bmp384: fifo 27/75.
bmp384: temperature is 24.35C.
bmp384: fifo 28/75.
bmp384: pressure is 101262.03Pa.
bmp384: fifo 29/75.
bmp384: temperature is 24.35C.
bmp384: fifo 30/75.
bmp384: pressure is 101261.99Pa.
bmp384: fifo 31/75.
bmp384: temperature is 24.36C.
bmp384: fifo 32/75.
bmp384: pressure is 101262.04Pa.
bmp384: fifo 33/75.
bmp384: temperature is 24.36C.
bmp384: fifo 34/75.
bmp384: pressure is 101261.99Pa.
bmp384: fifo 35/75.
bmp384: temperature is 24.36C.
bmp384: fifo 36/75.
bmp384: pressure is 101262.04Pa.
bmp384: fifo 37/75.
bmp384: temperature is 24.36C.
bmp384: fifo 38/75.
bmp384: pressure is 101262.12Pa.
bmp384: fifo 39/75.
bmp384: temperature is 24.36C.
bmp384: fifo 40/75.
bmp384: pressure is 101262.06Pa.
bmp384: fifo 41/75.
bmp384: temperature is 24.36C.
bmp384: fifo 42/75.
bmp384: pressure is 101262.07Pa.
bmp384: fifo 43/75.
bmp384: temperature is 24.36C.
bmp384: fifo 44/75.
bmp384: pressure is 101262.07Pa.
bmp384: fifo 45/75.
bmp384: temperature is 24.36C.
bmp384: fifo 46/75.
bmp384: pressure is 101262.09Pa.
bmp384: fifo 47/75.
bmp384: temperature is 24.37C.
bmp384: fifo 48/75.
bmp384: pressure is 101262.06Pa.
bmp384: fifo 49/75.
bmp384: temperature is 24.37C.
bmp384: fifo 50/75.
bmp384: pressure is 101261.93Pa.
bmp384: fifo 51/75.
bmp384: temperature is 24.37C.
bmp384: fifo 52/75.
bmp384: pressure is 101261.96Pa.
bmp384: fifo 53/75.
bmp384: temperature is 24.37C.
bmp384: fifo 54/75.
bmp384: pressure is 101261.96Pa.
bmp384: fifo 55/75.
bmp384: temperature is 24.37C.
bmp384: fifo 56/75.
bmp384: pressure is 101261.78Pa.
bmp384: fifo 57/75.
bmp384: temperature is 24.37C.
bmp384: fifo 58/75.
bmp384: pressure is 101261.73Pa.
bmp384: fifo 59/75.
bmp384: temperature is 24.37C.
bmp384: fifo 60/75.
bmp384: pressure is 101261.70Pa.
bmp384: fifo 61/75.
bmp384: temperature is 24.37C.
bmp384: fifo 62/75.
bmp384: pressure is 101261.56Pa.
bmp384: fifo 63/75.
bmp384: temperature is 24.37C.
bmp384: fifo 64/75.
bmp384: pressure is 101261.64Pa.
bmp384: fifo 65/75.
bmp384: temperature is 24.37C.
bmp384: fifo 66/75.
bmp384: pressure is 101261.61Pa.
bmp384: fifo 67/75.
bmp384: temperature is 24.37C.
bmp384: fifo 68/75.
bmp384: pressure is 101261.68Pa.
bmp384: fifo 69/75.
bmp384: temperature is 24.37C.
bmp384: fifo 70/75.
bmp384: pressure is 101261.65Pa.
bmp384: fifo 71/75.
bmp384: temperature is 24.37C.
bmp384: fifo 72/75.
bmp384: pressure is 101261.66Pa.
bmp384: fifo 73/75.
bmp384: temperature is 24.37C.
bmp384: fifo 74/75.
bmp384: pressure is 101261.62Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 149747.
bmp384: fifo 1/75.
bmp384: temperature is 24.38C.
bmp384: fifo 2/75.
bmp384: pressure is 101261.72Pa.
bmp384: fifo 3/75.
bmp384: temperature is 24.38C.
bmp384: fifo 4/75.
bmp384: pressure is 101261.72Pa.
bmp384: fifo 5/75.
bmp384: temperature is 24.38C.
bmp384: fifo 6/75.
bmp384: pressure is 101261.75Pa.
bmp384: fifo 7/75.
bmp384: temperature is 24.38C.
bmp384: fifo 8/75.
bmp384: pressure is 101261.92Pa.
bmp384: fifo 9/75.
bmp384: temperature is 24.38C.
bmp384: fifo 10/75.
bmp384: pressure is 101261.90Pa.
bmp384: fifo 11/75.
bmp384: temperature is 24.38C.
bmp384: fifo 12/75.
bmp384: pressure is 101261.81Pa.
bmp384: fifo 13/75.
bmp384: temperature is 24.38C.
bmp384: fifo 14/75.
bmp384: pressure is 101261.84Pa.
bmp384: fifo 15/75.
bmp384: temperature is 24.38C.
bmp384: fifo 16/75.
bmp384: pressure is 101261.82Pa.
bmp384: fifo 17/75.
bmp384: temperature is 24.38C.
bmp384: fifo 18/75.
bmp384: pressure is 101261.82Pa.
bmp384: fifo 19/75.
bmp384: temperature is 24.38C.
bmp384: fifo 20/75.
bmp384: pressure is 101261.93Pa.
bmp384: fifo 21/75.
bmp384: temperature is 24.38C.
bmp384: fifo 22/75.
bmp384: pressure is 101261.95Pa.
bmp384: fifo 23/75.
bmp384: temperature is 24.38C.
bmp384: fifo 24/75.
bmp384: pressure is 101261.95Pa.
bmp384: fifo 25/75.
bmp384: temperature is 24.38C.
bmp384: fifo 26/75.
bmp384: pressure is 101262.03Pa.
bmp384: fifo 27/75.
bmp384: temperature is 24.38C.
bmp384: fifo 28/75.
bmp384: pressure is 101262.00Pa.
bmp384: fifo 29/75.
bmp384: temperature is 24.38C.
bmp384: fifo 30/75.
bmp384: pressure is 101261.93Pa.
bmp384: fifo 31/75.
bmp384: temperature is 24.38C.
bmp384: fifo 32/75.
bmp384: pressure is 101261.89Pa.
bmp384: fifo 33/75.
bmp384: temperature is 24.38C.
bmp384: fifo 34/75.
bmp384: pressure is 101261.94Pa.
bmp384: fifo 35/75.
bmp384: temperature is 24.38C.
bmp384: fifo 36/75.
bmp384: pressure is 101261.91Pa.
bmp384: fifo 37/75.
bmp384: temperature is 24.39C.
bmp384: fifo 38/75.
bmp384: pressure is 101261.89Pa.
bmp384: fifo 39/75.
bmp384: temperature is 24.39C.
bmp384: fifo 40/75.
bmp384: pressure is 101261.84Pa.
bmp384: fifo 41/75.
bmp384: temperature is 24.39C.
bmp384: fifo 42/75.
bmp384: pressure is 101261.72Pa.
bmp384: fifo 43/75.
bmp384: temperature is 24.39C.
bmp384: fifo 44/75.
bmp384: pressure is 101261.75Pa.
bmp384: fifo 45/75.
bmp384: temperature is 24.39C.
bmp384: fifo 46/75.
bmp384: pressure is 101261.67Pa.
bmp384: fifo 47/75.
bmp384: temperature is 24.39C.
bmp384: fifo 48/75.
bmp384: pressure is 101261.59Pa.
bmp384: fifo 49/75.
bmp384: temperature is 24.39C.
bmp384: fifo 50/75.
bmp384: pressure is 101261.59Pa.
bmp384: fifo 51/75.
bmp384: temperature is 24.39C.
bmp384: fifo 52/75.
bmp384: pressure is 101261.58Pa.
bmp384: fifo 53/75.
bmp384: temperature is 24.39C.
bmp384: fifo 54/75.
bmp384: pressure is 101261.46Pa.
bmp384: fifo 55/75.
bmp384: temperature is 24.39C.
bmp384: fifo 56/75.
bmp384: pressure is 101261.50Pa.
bmp384: fifo 57/75.
bmp384: temperature is 24.39C.
bmp384: fifo 58/75.
bmp384: pressure is 101261.46Pa.
bmp384: fifo 59/75.
bmp384: temperature is 24.39C.
bmp384: fifo 60/75.
bmp384: pressure is 101261.55Pa.
bmp384: fifo 61/75.
bmp384: temperature is 24.39C.
bmp384: fifo 62/75.
bmp384: pressure is 101261.45Pa.
bmp384: fifo 63/75.
bmp384: temperature is 24.39C.
bmp384: fifo 64/75.
bmp384: pressure is 101261.45Pa.
bmp384: fifo 65/75.
bmp384: temperature is 24.39C.
bmp384: fifo 66/75.
bmp384: pressure is 101261.45Pa.
bmp384: fifo 67/75.
bmp384: temperature is 24.39C.
bmp384: fifo 68/75.
bmp384: pressure is 101261.45Pa.
bmp384: fifo 69/75.
bmp384: temperature is 24.39C.
bmp384: fifo 70/75.
bmp384: pressure is 101261.42Pa.
bmp384: fifo 71/75.
bmp384: temperature is 24.39C.
bmp384: fifo 72/75.
bmp384: pressure is 101261.29Pa.
bmp384: fifo 73/75.
bmp384: temperature is 24.39C.
bmp384: fifo 74/75.
bmp384: pressure is 101261.08Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 225523.
bmp384: finish fifo read.
```

```shell
bmp384 -h

Usage:
  bmp384 (-i | --information)
  bmp384 (-h | --help)
  bmp384 (-p | --port)
  bmp384 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
  bmp384 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp384 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]

Options:
      --addr=<0 | 1>                 Set the chip iic address.([default: 0])
  -e <read | shot | int | fifo>, --example=<read | shot | int | fifo>
                                     Run the driver example.
  -h, --help                         Show the help.
  -i, --information                  Show the chip information.
      --interface=<iic | spi>        Set the chip interface.([default: iic])
  -p, --port                         Display the pin connections of the current board.
  -t <reg | read | int | fifo>, --test=<reg | read | int | fifo>
                                     Run the driver test.
      --times=<num>                  Set the running times.([default: 3])
```

