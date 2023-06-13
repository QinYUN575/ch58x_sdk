# CH58x


## Samples list

| Status | Sample | Description | Notes |
| :---: | :---: | :---: | :---: |
| ✅ | [blink](./example/blink) | Blink LED | |
| :construction: Todo | [uart](./example/uart) | UART | |
| :construction: Todo | [i2c](./example/i2c) | I2C | |
| :construction: Todo | [spi](./example/spi) | SPI | |
| :construction: Todo | [timer](./example/timer) | Timer | |
| :construction: Todo | [adc](./example/adc) | ADC | |
| :construction: Todo | [pwm](./example/pwm) | PWM | |
| :construction: Todo | [usb](./example/usb) | USB | |
| :construction: Todo | [usb_cdc](./example/usb_cdc) | USB CDC | |
| :construction: Todo | [usb_hid](./example/usb_hid) | USB HID | |
| :construction: Todo | [usb_msc](./example/usb_msc) | USB MSC | |
| :construction: Todo | [usb_mtp](./example/usb_mtp) | USB MTP | |
| :construction: Todo | [usb_dfu](./example/usb_dfu) | USB DFU | |
| :construction: Todo | [usb_audio](./example/usb_audio) | USB Audio | |
| :construction: Todo | [usb_midi](./example/usb_midi) | USB MIDI | |



## Build

```shell
cd example/blink
mkdir build && cd build
cmake ..
make
```

## Flash

- [wchisp](https://github.com/QinYUN575/ch58x_sdk) - WCH ISP Tool in Rust

```shell
wchisp flash ./blink.bin
```
