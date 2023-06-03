# CH58x

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
