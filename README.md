# Vexide / C example

Linking to C programs from vexide

## Usage

Install: <https://github.com/vexide/arm-toolchain>

Then run:

```shell
arm-toolchain use v21.1.1
atrun cargo v5 build
```

## How?

Compiling C files:

- `atrun` adds clang to the path, sets `CC` env variable
- `CFLAGS` path defined in cargo config
- C file built with cc crate like normal

C Stdlibs:

- `vexc-sys/vexc.c` additionally contains syscall handlers for putc, getc, etc
  - Implemented using extern vex-sdk functions
  - These should be moved into vexide
- `clang` is configured as the linker, because it will automatically add stdlib search paths
  - However, it needs to be told about the target to know the correct stdlibs to use.
  - Target flags: `--target=armv7a-none-eabihf -mcpu=cortex-a9`
  - Link to correct stdlibs: `-nostartfiles -lc -lm`
    - Explicit `-lc` required because Rust calls the linker with `-nodefaultlibs` which disables libc, libm, etc.
