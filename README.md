# msp430-tiny-starter-kit
## Setup
- Install toolchain from https://www.ti.com/tool/MSP430-GCC-OPENSOURCE#downloads
- Build `mspdebug` from https://github.com/dlbeer/mspdebug
- Download Energia from https://energia.nu/download/, un-archive it, and copy `libmsp430.so` to `/usr/local/lib/`

## Use
### Compile
```shell
make -f <target>.mk
```

### Clean
```shell
make -f <target>.mk clean
```

### Erase via selected tool
```shell
make -f <target>.mk erase
```

### Flash via selected tool
```shell
make -f <target>.mk upload
```
