[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP384

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp384/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

BMP384 にはゲル充填キャビティがあり、適切な統合コンセプトを使用すると、水、液体、その他の化学物質に対する堅牢性が向上します。BMP384 は、水位や詰まりの検出の用途に最適です。BMI088 を含む他の Bosch Sensortec センサーと互換性があり、パフォーマンス、堅牢性、安定性が向上します。フットプリントが小さい BMP384 は、優れた設計柔軟性を提供し、スマート ホーム、産業製品、ウェアラブル向けの既存および今後のデバイスに簡単に統合できる単一パッケージ ソリューションを提供します。

LibDriver BMP384は、LibDriverによって起動されたBMP384の全機能ドライバーであり、圧力と温度の連続読み取り、圧力と温度の単一読み取り、割り込み読み取り、FIFO取得およびその他の機能を提供します。 LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
    - [example interrupt](#example-interrupt)
    - [example fifo](#example-fifo)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver BMP384のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver BMP384用のプラットフォームに依存しないIIC, SPIバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver BMP384ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver BMP384プログラミング例が含まれています。

/ docディレクトリには、LibDriver BMP384オフラインドキュメントが含まれています。

/ datasheetディレクトリには、BMP384データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIIC, SPIバステンプレートを参照して、指定したプラットフォームのIIC, SPIバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

#### example basic

```C
#include "driver_bmp384_basic.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp384_basic_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp384_interface_delay_ms(1000);
    res = bmp384_basic_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp384_basic_deinit();

        return 1;
    }
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);

    ...
        
}

...

(void)bmp384_basic_deinit();

return 0;
```

#### example shot

```c
#include "driver_bmp384_shot.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp384_shot_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp384_interface_delay_ms(1000);
    res = bmp384_shot_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp384_shot_deinit();

        return 1;
    }
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
    
}

...

(void)bmp384_shot_deinit();

return 0;
```

#### example interrupt

```c
#include "driver_bmp384_interrupt.h"

uint8_t res;
uint16_t i, timeout;
uint8_t gs_data_ready_flag;
float gs_temperature_c;
float gs_pressure_pa;

void bmp384_interrupt_receive_callback(uint8_t type)
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

res = gpio_interrupt_init();
if (res != 0)
{
    return 1;
}
res = bmp384_interrupt_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW, bmp384_interrupt_receive_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();

    return 1;
}

...

gs_data_ready_flag = 0;
timeout = 5000;
for (i = 0; i < 3; i++)
{
    while (timeout != 0)
    {
        bmp384_interface_delay_ms(100);
        timeout--;
        if (gs_data_ready_flag != 0)
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp384_interrupt_deinit();

            return 1;
        }
    }
    gs_data_ready_flag = 0;
    timeout = 5000;
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_pressure_pa);
    
    ...
    
}

...

(void)gpio_interrupt_deinit();
(void)bmp384_interrupt_deinit();

return 0;
```

#### example fifo

```c
#include "driver_bmp384_fifo.h"

uint8_t gs_fifo_full_flag;
uint8_t gs_fifo_watermark_flag;
uint16_t i, timeout;
uint8_t gs_buf[512];
bmp384_frame_t gs_frame[256];

void bmp384_fifo_receive_callback(uint8_t type)
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
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknow type.\n");
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
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknow type.\n");
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

res = gpio_interrupt_init();
if (res != 0)
{
    return 1;
}
res = bmp384_fifo_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW, bmp384_fifo_receive_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();

    return 1;
}

...

gs_fifo_watermark_flag = 0;
gs_fifo_full_flag = 0;
timeout = 5000;
for (i = 0; i < 3; i++)
{
    while (timeout != 0)
    {
        bmp384_interface_delay_ms(100);
        timeout--;
        if ((gs_fifo_watermark_flag != 0) || (gs_fifo_full_flag != 0))
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp384_fifo_deinit();

            return 1;
        }
    }
    gs_fifo_watermark_flag = 0;
    gs_fifo_full_flag = 0;
    timeout = 5000;
    
    ...
    
}
(void)gpio_interrupt_deinit();
(void)bmp384_fifo_deinit();

...

return 0;
```

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/bmp384/index.html](https://www.libdriver.com/docs/bmp384/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。