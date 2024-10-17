### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

GPIO Pin: INT GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(bmp384 REQUIRED)
```

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
./bmp384 -i

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
./bmp384 -p

bmp384: SPI interface SCK connected to GPIO11(BCM).
bmp384: SPI interface MISO connected to GPIO9(BCM).
bmp384: SPI interface MOSI connected to GPIO10(BCM).
bmp384: SPI interface CS connected to GPIO8(BCM).
bmp384: IIC interface SCL connected to GPIO3(BCM).
bmp384: IIC interface SDA connected to GPIO2(BCM).
bmp384: INT connected to GPIO17(BCM).
```

```shell
./bmp384 -t reg --interface=spi

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
bmp384: set fifo watermark 359.
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
bmp384: sensor time is 0x000740.
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
./bmp384 -t read --interface=spi --times=3

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
bmp384: temperature is 29.30C.
bmp384: pressure is 101298.84Pa.
bmp384: temperature is 29.30C.
bmp384: pressure is 101298.68Pa.
bmp384: temperature is 29.30C.
bmp384: pressure is 101298.61Pa.
bmp384: normal mode read test.
bmp384: temperature is 29.28C.
bmp384: pressure is 101290.05Pa.
bmp384: temperature is 29.35C.
bmp384: pressure is 101286.68Pa.
bmp384: temperature is 29.36C.
bmp384: pressure is 101284.82Pa.
bmp384: finish read test.
```

```shell
./bmp384 -t int --interface=spi --times=3

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
bmp384: temperature is 28.47C.
bmp384: pressure is 101290.45Pa.
bmp384: temperature is 28.60C.
bmp384: pressure is 101284.75Pa.
bmp384: temperature is 28.64C.
bmp384: pressure is 101282.95Pa.
bmp384: finish interrupt test.
```

```shell
./bmp384 -t fifo --interface=spi --times=3

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
./bmp384 -e read --interface=spi --times=3

bmp384: 1/3.
bmp384: temperature is 27.43C.
bmp384: pressure is 101295.40Pa.
bmp384: 2/3.
bmp384: temperature is 27.52C.
bmp384: pressure is 101289.35Pa.
bmp384: 3/3.
bmp384: temperature is 27.56C.
bmp384: pressure is 101286.78Pa.
```

```shell
./bmp384 -e shot --interface=spi --times=3

bmp384: 1/3.
bmp384: temperature is 27.08C.
bmp384: pressure is 101303.51Pa.
bmp384: 2/3.
bmp384: temperature is 27.08C.
bmp384: pressure is 101303.45Pa.
bmp384: 3/3.
bmp384: temperature is 27.08C.
bmp384: pressure is 101303.54Pa.
```

```shell
./bmp384 -e int --interface=spi --times=3

bmp384: 1/3.
bmp384: temperature is 26.97C.
bmp384: pressure is 101303.76Pa.
bmp384: 2/3.
bmp384: temperature is 26.97C.
bmp384: pressure is 101303.38Pa.
bmp384: 3/3.
bmp384: temperature is 26.98C.
bmp384: pressure is 101302.79Pa.
```

```shell
./bmp384 -e fifo --interface=spi --times=3

bmp384: fifo 1/75.
bmp384: temperature is 26.88C.
bmp384: fifo 2/75.
bmp384: pressure is 101301.29Pa.
bmp384: fifo 3/75.
bmp384: temperature is 26.89C.
bmp384: fifo 4/75.
bmp384: pressure is 101300.99Pa.
bmp384: fifo 5/75.
bmp384: temperature is 26.89C.
bmp384: fifo 6/75.
bmp384: pressure is 101300.52Pa.
bmp384: fifo 7/75.
bmp384: temperature is 26.90C.
bmp384: fifo 8/75.
bmp384: pressure is 101299.93Pa.
bmp384: fifo 9/75.
bmp384: temperature is 26.91C.
bmp384: fifo 10/75.
bmp384: pressure is 101299.11Pa.
bmp384: fifo 11/75.
bmp384: temperature is 26.92C.
bmp384: fifo 12/75.
bmp384: pressure is 101298.39Pa.
bmp384: fifo 13/75.
bmp384: temperature is 26.93C.
bmp384: fifo 14/75.
bmp384: pressure is 101297.85Pa.
bmp384: fifo 15/75.
bmp384: temperature is 26.94C.
bmp384: fifo 16/75.
bmp384: pressure is 101297.19Pa.
bmp384: fifo 17/75.
bmp384: temperature is 26.95C.
bmp384: fifo 18/75.
bmp384: pressure is 101296.54Pa.
bmp384: fifo 19/75.
bmp384: temperature is 26.96C.
bmp384: fifo 20/75.
bmp384: pressure is 101296.02Pa.
bmp384: fifo 21/75.
bmp384: temperature is 26.97C.
bmp384: fifo 22/75.
bmp384: pressure is 101295.44Pa.
bmp384: fifo 23/75.
bmp384: temperature is 26.98C.
bmp384: fifo 24/75.
bmp384: pressure is 101294.95Pa.
bmp384: fifo 25/75.
bmp384: temperature is 26.99C.
bmp384: fifo 26/75.
bmp384: pressure is 101294.58Pa.
bmp384: fifo 27/75.
bmp384: temperature is 27.00C.
bmp384: fifo 28/75.
bmp384: pressure is 101294.09Pa.
bmp384: fifo 29/75.
bmp384: temperature is 27.01C.
bmp384: fifo 30/75.
bmp384: pressure is 101293.71Pa.
bmp384: fifo 31/75.
bmp384: temperature is 27.01C.
bmp384: fifo 32/75.
bmp384: pressure is 101293.37Pa.
bmp384: fifo 33/75.
bmp384: temperature is 27.02C.
bmp384: fifo 34/75.
bmp384: pressure is 101293.09Pa.
bmp384: fifo 35/75.
bmp384: temperature is 27.03C.
bmp384: fifo 36/75.
bmp384: pressure is 101292.79Pa.
bmp384: fifo 37/75.
bmp384: temperature is 27.03C.
bmp384: fifo 38/75.
bmp384: pressure is 101292.55Pa.
bmp384: fifo 39/75.
bmp384: temperature is 27.04C.
bmp384: fifo 40/75.
bmp384: pressure is 101292.45Pa.
bmp384: fifo 41/75.
bmp384: temperature is 27.05C.
bmp384: fifo 42/75.
bmp384: pressure is 101292.09Pa.
bmp384: fifo 43/75.
bmp384: temperature is 27.05C.
bmp384: fifo 44/75.
bmp384: pressure is 101291.93Pa.
bmp384: fifo 45/75.
bmp384: temperature is 27.06C.
bmp384: fifo 46/75.
bmp384: pressure is 101291.83Pa.
bmp384: fifo 47/75.
bmp384: temperature is 27.06C.
bmp384: fifo 48/75.
bmp384: pressure is 101291.49Pa.
bmp384: fifo 49/75.
bmp384: temperature is 27.07C.
bmp384: fifo 50/75.
bmp384: pressure is 101291.35Pa.
bmp384: fifo 51/75.
bmp384: temperature is 27.07C.
bmp384: fifo 52/75.
bmp384: pressure is 101291.26Pa.
bmp384: fifo 53/75.
bmp384: temperature is 27.08C.
bmp384: fifo 54/75.
bmp384: pressure is 101291.08Pa.
bmp384: fifo 55/75.
bmp384: temperature is 27.08C.
bmp384: fifo 56/75.
bmp384: pressure is 101290.85Pa.
bmp384: fifo 57/75.
bmp384: temperature is 27.09C.
bmp384: fifo 58/75.
bmp384: pressure is 101290.62Pa.
bmp384: fifo 59/75.
bmp384: temperature is 27.09C.
bmp384: fifo 60/75.
bmp384: pressure is 101290.54Pa.
bmp384: fifo 61/75.
bmp384: temperature is 27.09C.
bmp384: fifo 62/75.
bmp384: pressure is 101290.42Pa.
bmp384: fifo 63/75.
bmp384: temperature is 27.10C.
bmp384: fifo 64/75.
bmp384: pressure is 101290.27Pa.
bmp384: fifo 65/75.
bmp384: temperature is 27.10C.
bmp384: fifo 66/75.
bmp384: pressure is 101290.18Pa.
bmp384: fifo 67/75.
bmp384: temperature is 27.10C.
bmp384: fifo 68/75.
bmp384: pressure is 101289.99Pa.
bmp384: fifo 69/75.
bmp384: temperature is 27.10C.
bmp384: fifo 70/75.
bmp384: pressure is 101290.03Pa.
bmp384: fifo 71/75.
bmp384: temperature is 27.11C.
bmp384: fifo 72/75.
bmp384: pressure is 101290.08Pa.
bmp384: fifo 73/75.
bmp384: temperature is 27.11C.
bmp384: fifo 74/75.
bmp384: pressure is 101290.02Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 73759.
bmp384: fifo 1/75.
bmp384: temperature is 27.11C.
bmp384: fifo 2/75.
bmp384: pressure is 101289.96Pa.
bmp384: fifo 3/75.
bmp384: temperature is 27.11C.
bmp384: fifo 4/75.
bmp384: pressure is 101289.83Pa.
bmp384: fifo 5/75.
bmp384: temperature is 27.11C.
bmp384: fifo 6/75.
bmp384: pressure is 101289.83Pa.
bmp384: fifo 7/75.
bmp384: temperature is 27.12C.
bmp384: fifo 8/75.
bmp384: pressure is 101289.84Pa.
bmp384: fifo 9/75.
bmp384: temperature is 27.12C.
bmp384: fifo 10/75.
bmp384: pressure is 101289.69Pa.
bmp384: fifo 11/75.
bmp384: temperature is 27.12C.
bmp384: fifo 12/75.
bmp384: pressure is 101289.59Pa.
bmp384: fifo 13/75.
bmp384: temperature is 27.12C.
bmp384: fifo 14/75.
bmp384: pressure is 101289.36Pa.
bmp384: fifo 15/75.
bmp384: temperature is 27.12C.
bmp384: fifo 16/75.
bmp384: pressure is 101289.20Pa.
bmp384: fifo 17/75.
bmp384: temperature is 27.12C.
bmp384: fifo 18/75.
bmp384: pressure is 101289.16Pa.
bmp384: fifo 19/75.
bmp384: temperature is 27.12C.
bmp384: fifo 20/75.
bmp384: pressure is 101289.18Pa.
bmp384: fifo 21/75.
bmp384: temperature is 27.13C.
bmp384: fifo 22/75.
bmp384: pressure is 101289.09Pa.
bmp384: fifo 23/75.
bmp384: temperature is 27.13C.
bmp384: fifo 24/75.
bmp384: pressure is 101288.99Pa.
bmp384: fifo 25/75.
bmp384: temperature is 27.13C.
bmp384: fifo 26/75.
bmp384: pressure is 101288.90Pa.
bmp384: fifo 27/75.
bmp384: temperature is 27.13C.
bmp384: fifo 28/75.
bmp384: pressure is 101288.92Pa.
bmp384: fifo 29/75.
bmp384: temperature is 27.13C.
bmp384: fifo 30/75.
bmp384: pressure is 101289.00Pa.
bmp384: fifo 31/75.
bmp384: temperature is 27.13C.
bmp384: fifo 32/75.
bmp384: pressure is 101288.86Pa.
bmp384: fifo 33/75.
bmp384: temperature is 27.13C.
bmp384: fifo 34/75.
bmp384: pressure is 101288.73Pa.
bmp384: fifo 35/75.
bmp384: temperature is 27.13C.
bmp384: fifo 36/75.
bmp384: pressure is 101288.73Pa.
bmp384: fifo 37/75.
bmp384: temperature is 27.13C.
bmp384: fifo 38/75.
bmp384: pressure is 101288.76Pa.
bmp384: fifo 39/75.
bmp384: temperature is 27.13C.
bmp384: fifo 40/75.
bmp384: pressure is 101288.69Pa.
bmp384: fifo 41/75.
bmp384: temperature is 27.13C.
bmp384: fifo 42/75.
bmp384: pressure is 101288.80Pa.
bmp384: fifo 43/75.
bmp384: temperature is 27.13C.
bmp384: fifo 44/75.
bmp384: pressure is 101288.74Pa.
bmp384: fifo 45/75.
bmp384: temperature is 27.13C.
bmp384: fifo 46/75.
bmp384: pressure is 101288.73Pa.
bmp384: fifo 47/75.
bmp384: temperature is 27.13C.
bmp384: fifo 48/75.
bmp384: pressure is 101288.82Pa.
bmp384: fifo 49/75.
bmp384: temperature is 27.14C.
bmp384: fifo 50/75.
bmp384: pressure is 101288.78Pa.
bmp384: fifo 51/75.
bmp384: temperature is 27.14C.
bmp384: fifo 52/75.
bmp384: pressure is 101288.74Pa.
bmp384: fifo 53/75.
bmp384: temperature is 27.14C.
bmp384: fifo 54/75.
bmp384: pressure is 101288.59Pa.
bmp384: fifo 55/75.
bmp384: temperature is 27.14C.
bmp384: fifo 56/75.
bmp384: pressure is 101288.56Pa.
bmp384: fifo 57/75.
bmp384: temperature is 27.14C.
bmp384: fifo 58/75.
bmp384: pressure is 101288.56Pa.
bmp384: fifo 59/75.
bmp384: temperature is 27.14C.
bmp384: fifo 60/75.
bmp384: pressure is 101288.59Pa.
bmp384: fifo 61/75.
bmp384: temperature is 27.14C.
bmp384: fifo 62/75.
bmp384: pressure is 101288.52Pa.
bmp384: fifo 63/75.
bmp384: temperature is 27.14C.
bmp384: fifo 64/75.
bmp384: pressure is 101288.55Pa.
bmp384: fifo 65/75.
bmp384: temperature is 27.14C.
bmp384: fifo 66/75.
bmp384: pressure is 101288.43Pa.
bmp384: fifo 67/75.
bmp384: temperature is 27.14C.
bmp384: fifo 68/75.
bmp384: pressure is 101288.32Pa.
bmp384: fifo 69/75.
bmp384: temperature is 27.14C.
bmp384: fifo 70/75.
bmp384: pressure is 101288.29Pa.
bmp384: fifo 71/75.
bmp384: temperature is 27.14C.
bmp384: fifo 72/75.
bmp384: pressure is 101288.35Pa.
bmp384: fifo 73/75.
bmp384: temperature is 27.14C.
bmp384: fifo 74/75.
bmp384: pressure is 101288.36Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 149534.
bmp384: fifo 1/75.
bmp384: temperature is 27.14C.
bmp384: fifo 2/75.
bmp384: pressure is 101288.41Pa.
bmp384: fifo 3/75.
bmp384: temperature is 27.14C.
bmp384: fifo 4/75.
bmp384: pressure is 101288.37Pa.
bmp384: fifo 5/75.
bmp384: temperature is 27.14C.
bmp384: fifo 6/75.
bmp384: pressure is 101288.33Pa.
bmp384: fifo 7/75.
bmp384: temperature is 27.14C.
bmp384: fifo 8/75.
bmp384: pressure is 101288.29Pa.
bmp384: fifo 9/75.
bmp384: temperature is 27.14C.
bmp384: fifo 10/75.
bmp384: pressure is 101288.37Pa.
bmp384: fifo 11/75.
bmp384: temperature is 27.14C.
bmp384: fifo 12/75.
bmp384: pressure is 101288.31Pa.
bmp384: fifo 13/75.
bmp384: temperature is 27.14C.
bmp384: fifo 14/75.
bmp384: pressure is 101288.28Pa.
bmp384: fifo 15/75.
bmp384: temperature is 27.14C.
bmp384: fifo 16/75.
bmp384: pressure is 101288.16Pa.
bmp384: fifo 17/75.
bmp384: temperature is 27.14C.
bmp384: fifo 18/75.
bmp384: pressure is 101288.14Pa.
bmp384: fifo 19/75.
bmp384: temperature is 27.14C.
bmp384: fifo 20/75.
bmp384: pressure is 101288.10Pa.
bmp384: fifo 21/75.
bmp384: temperature is 27.14C.
bmp384: fifo 22/75.
bmp384: pressure is 101288.07Pa.
bmp384: fifo 23/75.
bmp384: temperature is 27.14C.
bmp384: fifo 24/75.
bmp384: pressure is 101288.01Pa.
bmp384: fifo 25/75.
bmp384: temperature is 27.14C.
bmp384: fifo 26/75.
bmp384: pressure is 101288.08Pa.
bmp384: fifo 27/75.
bmp384: temperature is 27.14C.
bmp384: fifo 28/75.
bmp384: pressure is 101288.07Pa.
bmp384: fifo 29/75.
bmp384: temperature is 27.14C.
bmp384: fifo 30/75.
bmp384: pressure is 101288.11Pa.
bmp384: fifo 31/75.
bmp384: temperature is 27.14C.
bmp384: fifo 32/75.
bmp384: pressure is 101288.23Pa.
bmp384: fifo 33/75.
bmp384: temperature is 27.14C.
bmp384: fifo 34/75.
bmp384: pressure is 101288.33Pa.
bmp384: fifo 35/75.
bmp384: temperature is 27.14C.
bmp384: fifo 36/75.
bmp384: pressure is 101288.47Pa.
bmp384: fifo 37/75.
bmp384: temperature is 27.14C.
bmp384: fifo 38/75.
bmp384: pressure is 101288.44Pa.
bmp384: fifo 39/75.
bmp384: temperature is 27.14C.
bmp384: fifo 40/75.
bmp384: pressure is 101288.54Pa.
bmp384: fifo 41/75.
bmp384: temperature is 27.14C.
bmp384: fifo 42/75.
bmp384: pressure is 101288.55Pa.
bmp384: fifo 43/75.
bmp384: temperature is 27.14C.
bmp384: fifo 44/75.
bmp384: pressure is 101288.56Pa.
bmp384: fifo 45/75.
bmp384: temperature is 27.14C.
bmp384: fifo 46/75.
bmp384: pressure is 101288.53Pa.
bmp384: fifo 47/75.
bmp384: temperature is 27.14C.
bmp384: fifo 48/75.
bmp384: pressure is 101288.45Pa.
bmp384: fifo 49/75.
bmp384: temperature is 27.14C.
bmp384: fifo 50/75.
bmp384: pressure is 101288.40Pa.
bmp384: fifo 51/75.
bmp384: temperature is 27.14C.
bmp384: fifo 52/75.
bmp384: pressure is 101288.31Pa.
bmp384: fifo 53/75.
bmp384: temperature is 27.14C.
bmp384: fifo 54/75.
bmp384: pressure is 101288.32Pa.
bmp384: fifo 55/75.
bmp384: temperature is 27.14C.
bmp384: fifo 56/75.
bmp384: pressure is 101288.31Pa.
bmp384: fifo 57/75.
bmp384: temperature is 27.14C.
bmp384: fifo 58/75.
bmp384: pressure is 101288.37Pa.
bmp384: fifo 59/75.
bmp384: temperature is 27.14C.
bmp384: fifo 60/75.
bmp384: pressure is 101288.43Pa.
bmp384: fifo 61/75.
bmp384: temperature is 27.14C.
bmp384: fifo 62/75.
bmp384: pressure is 101288.41Pa.
bmp384: fifo 63/75.
bmp384: temperature is 27.14C.
bmp384: fifo 64/75.
bmp384: pressure is 101288.48Pa.
bmp384: fifo 65/75.
bmp384: temperature is 27.14C.
bmp384: fifo 66/75.
bmp384: pressure is 101288.45Pa.
bmp384: fifo 67/75.
bmp384: temperature is 27.14C.
bmp384: fifo 68/75.
bmp384: pressure is 101288.40Pa.
bmp384: fifo 69/75.
bmp384: temperature is 27.14C.
bmp384: fifo 70/75.
bmp384: pressure is 101288.26Pa.
bmp384: fifo 71/75.
bmp384: temperature is 27.14C.
bmp384: fifo 72/75.
bmp384: pressure is 101288.34Pa.
bmp384: fifo 73/75.
bmp384: temperature is 27.14C.
bmp384: fifo 74/75.
bmp384: pressure is 101288.32Pa.
bmp384: fifo 75/75.
bmp384: sensor time is 225313.
bmp384: finish fifo read.
```

```shell
./bmp384 -h

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
