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

- `atrun` adds clang to the path, sets `CC` env variable
- `CFLAGS` and static lib path defined in cargo config
- C file built with cc crate like normal
- C file contains syscall handlers for putc, getc, etc
  - (Implemented using extern vex-sdk functions)
