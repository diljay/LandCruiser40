# LVGL Demo v9.5.0

This project runs on an ESP32-P4 Development Board with a 7-inch LCD TouchScreen and onboard ESP32-C6, using LVGL v9.5.0 and ESP-IDF v6.0.2.

## Getting Started

### Prerequisites

* ESP32-P4 Development Board, 7-inch LCD TouchScreen, Onboard ESP32-C6, Camera Port, Speaker Port
* https://www.aliexpress.com/item/1005008851890291.html

### ESP-IDF Required

- This example supports ESP-IDF v6.0.2.
- Please follow the [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html) to set up the development environment. **We highly recommend** you [Build Your First Project](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#build-your-first-project) to get familiar with ESP-IDF and make sure the environment is set up correctly.

### Get the Repository

To get started, clone the repository to your local PC by running the following command in the terminal:

```
git clone https://github.com/diljay/LandCruiser40.git
```

### Configuration

#### Setup esp-idf v6.0.2
```
source /Users/<username>/.espressif/v6.0.2/esp-idf/export.sh
```

#### Update Chip Revision Info
```
idf.py menuconfig
```
Then go to ``Component Config > Hardware Settings > Chip revision``.

Update the chip revision based on your chip's revision version.
https://docs.espressif.com/projects/esp-chip-errata/en/latest/esp32p4/01-chip-identification/index.html

## How to Use the Example

### Build and Flash the Example

Build the project and flash it to the board, then run the monitor tool to view serial output:

```c
idf.py build flash monitor
```

To exit the serial monitor, type ``Ctrl-]``.

See the [ESP-IDF Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.


### Example Output

- The complete log is as follows:

    ```
    Executing action: monitor
    Serial port /dev/cu.usbmodem101:
    Connecting...
    Detecting chip type... ESP32-P4
    Running idf_monitor in directory /Users/dilhan/Projects/ESP_P4/LandCruiser40
    Executing "/Users/dilhan/.espressif/python_env/idf6.0_py3.14_env/bin/python /Users/dilhan/.espressif/v6.0.2/esp-idf/tools/idf_monitor.py -p /dev/cu.usbmodem101 -b 115200 --toolchain-prefix riscv32-esp-elf- --target esp32p4 --revision 100 --decode-panic backtrace -m '/Users/dilhan/.espressif/python_env/idf6.0_py3.14_env/bin/python' '/Users/dilhan/.espressif/v6.0.2/esp-idf/tools/idf.py'"...
    --- esp-idf-monitor 1.9.0 on /dev/cu.usbmodem101 115200
    --- Warning: No ELF files found. Please provide the ELF file paths, required for binary log decoding.
    --- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
    ESP-ROM:esp32p4-eco2-20240710
    Build:Jul 10 2024
    rst:0x17 (CHIP_USB_UART_RESET),boot:0x30f (SPI_FAST_FLASH_BOOT)
    Core0 Saved PC:0x4fc098f6
    Core1 Saved PC:0x4fc058e0
    SPI mode:DIO, clock div:1
    load:0x4ff33ce0,len:0x1738
    load:0x4ff28ed0,len:0xfb8
    load:0x4ff2bbd0,len:0x36cc
    entry 0x4ff28eda
    I (27) boot: ESP-IDF v6.0.2 2nd stage bootloader
    I (28) boot: compile time Jul 31 2026 16:14:56
    I (28) boot: Multicore bootloader
    I (30) boot: chip revision: v1.0
    I (31) boot: efuse block revision: v0.3
    I (34) qio_mode: Enabling default flash chip QIO
    I (39) boot.esp32p4: SPI Speed      : 80MHz
    I (42) boot.esp32p4: SPI Mode       : QIO
    I (46) boot.esp32p4: SPI Flash Size : 16MB
    I (50) boot: Enabling RNG early entropy source...
    I (55) boot: Partition Table:
    I (57) boot: ## Label            Usage          Type ST Offset   Length
    I (63) boot:  0 nvs              WiFi data        01 02 0000b000 00006000
    I (70) boot:  1 phy_init         RF data          01 01 00011000 00001000
    I (76) boot:  2 factory          factory app      00 00 00020000 00800000
    I (83) boot:  3 storage          Unknown data     01 82 00820000 00700000
    I (90) boot: End of partition table
    I (93) esp_image: segment 0: paddr=00020020 vaddr=48050020 size=13dcch ( 81356) map
    I (110) esp_image: segment 1: paddr=00033df4 vaddr=30100000 size=00088h (   136) load
    I (112) esp_image: segment 2: paddr=00033e84 vaddr=4ff00000 size=0c194h ( 49556) load
    I (122) esp_image: segment 3: paddr=00040020 vaddr=48000020 size=4f2e0h (324320) map
    I (160) esp_image: segment 4: paddr=0008f308 vaddr=4ff0c194 size=10cc4h ( 68804) load
    I (171) esp_image: segment 5: paddr=0009ffd4 vaddr=4ff1ce80 size=03f08h ( 16136) load
    I (175) esp_image: segment 6: paddr=000a3ee4 vaddr=50108080 size=00024h (    36) load
    I (182) boot: Loaded app from partition at offset 0x20000
    I (183) boot: Disabling RNG early entropy source...
    I (198) hex_psram: vendor id    : 0x0d (AP)
    I (198) hex_psram: Latency      : 0x01 (Fixed)
    I (199) hex_psram: DriveStr.    : 0x00 (25 Ohm)
    I (199) hex_psram: dev id       : 0x03 (generation 4)
    I (204) hex_psram: density      : 0x07 (256 Mbit)
    I (208) hex_psram: good-die     : 0x06 (Pass)
    I (212) hex_psram: SRF          : 0x02 (Slow Refresh)
    I (217) hex_psram: BurstType    : 0x00 ( Wrap)
    I (221) hex_psram: BurstLen     : 0x03 (2048 Byte)
    I (226) hex_psram: BitMode      : 0x01 (X16 Mode)
    I (230) hex_psram: Readlatency  : 0x04 (14 cycles@Fixed)
    I (235) hex_psram: DriveStrength: 0x00 (1/1)
    I (239) MSPI Timing: Enter psram timing tuning
    I esp_psram: Found 32MB PSRAM device
    I esp_psram: Speed: 200MHz
    I (417) mmu_psram: .rodata xip on psram
    I (432) mmu_psram: .text xip on psram
    I (435) hex_psram: psram CS IO is dedicated
    I (436) cpu_start: Multicore app
    I (920) esp_psram: SPI SRAM memory test OK
    I (930) cpu_start: GPIO 38 and 37 are used as console UART I/O pins
    I (930) cpu_start: Pro cpu start user code
    I (931) cpu_start: cpu freq: 360000000 Hz
    I (932) app_init: Application information:
    I (936) app_init: Project name:     LandCruiser40
    I (941) app_init: App version:      998827e-dirty
    I (945) app_init: Compile time:     Jul 31 2026 16:14:15
    I (950) app_init: ELF file SHA256:  5d932b14f...
    I (954) app_init: ESP-IDF:          v6.0.2
    I (958) efuse_init: Min chip rev:     v1.0
    I (962) efuse_init: Max chip rev:     v1.99 
    I (966) efuse_init: Chip rev:         v1.0
    I (970) heap_init: Initializing. RAM available for dynamic allocation:
    I (976) heap_init: At 4FF23140 len 00017E80 (95 KiB): RETENT_RAM
    I (982) heap_init: At 4FF3AFC0 len 00004BF0 (18 KiB): RAM
    I (987) heap_init: At 4FF40000 len 00040000 (256 KiB): RAM
    I (992) heap_init: At 501080A4 len 00007F5C (31 KiB): RTCRAM
    I (998) heap_init: At 30100088 len 00001F78 (7 KiB): SPM
    I (1003) esp_psram: Adding pool of 32320K of PSRAM memory to heap allocator
    I (1009) esp_psram: Adding pool of 3K of PSRAM memory gap generated due to end address alignment of irom to the heap allocator
    I (1020) esp_psram: Adding pool of 48K of PSRAM memory gap generated due to end address alignment of drom to the heap allocator
    I (1032) spi_flash: detected chip: boya
    I (1035) spi_flash: flash io: qio
    I (1038) sleep_gpio: Configure to isolate all GPIO pins in sleep state
    I (1045) sleep_gpio: Enable automatic switching of GPIO sleep configuration
    I (1051) main_task: Started on CPU0
    I (1054) esp_psram: Reserving pool of 32K of internal memory for DMA/internal allocations
    I (1062) main_task: Calling app_main()
    I (1066) LVGL: Starting LVGL task
    I (1069) ESP32_P4_EV: MIPI DSI PHY Powered on
    I (1074) ESP32_P4_EV: Install MIPI DSI LCD control panel
    I (1078) ESP32_P4_EV: Install JD9165 LCD control panel
    I (1082) jd9165: version: 1.0.2
    I (1400) ESP32_P4_EV: Display initialized
    I (1406) ESP32_P4_EV: Setting LCD backlight: 100%
    I (1429) main_task: Returned from app_main()
    ```

## Simulation Build (SDL2)

The UI (state machine, view manager, screens, sensor models under `components/`) is
shared between the target build and a desktop simulator, so you can iterate on
screens without flashing hardware. The simulator opens an SDL2 window at the
same 1024x600 resolution as the physical panel.

### Prerequisites

- CMake >= 3.16
- A C compiler (clang/gcc)
- SDL2

On macOS:
```
brew install sdl2
```

### Build

```
cd sim
cmake -S . -B build
cmake --build build -j 8
```

The first configure fetches LVGL v9.5.0 via CMake `FetchContent`, so it takes
noticeably longer than subsequent runs.

### Run

```
./build/landcruiser_sim
```

This opens a window showing the bootup screen with the live speed label. Quit
with Ctrl-C in the terminal or by closing the window.

## Technical Support and Feedback
Create an issue:
https://github.com/diljay/LandCruiser40/issues
