# Vexide / C example

Linking to C programs from vexide via cargo-v5

## Usage

Install cargo-v5 from the Git branch "toolchain"

Then run:

```shell
cargo v5 toolchain install
cargo v5 build
```

## How?

Compiling C files:

- cargo v5 adds clang to the path, sets `CC` env variable, sets `CFLAGS`
  - It knows to do this because the toolchain is set to LLVM-21 in Cargo.toml.
- C file built with cc crate like normal

C Stdlibs:

- `vexc-sys/vexc.c` additionally contains syscall handlers for putc, getc, etc
  - Implemented using extern vex-sdk functions
  - These should be moved into vexide
- `clang` is configured as the linker, because it will automatically add stdlib search paths
  - cargo-v5 sets the correct Rust flags to use clang.
  - However, it needs to be told about the target to know the correct stdlibs to use.
  - cargo-v5 also sets the correct linker flags so that clang's multilib resolver can do its magic.
  - Target flags: `--target=armv7a-none-eabihf -mcpu=cortex-a9 -fno-rtti`
  - Link to correct stdlibs: `-nostartfiles -lc -lm`
    - Explicit `-lc` required because Rust calls the linker with `-nodefaultlibs` which disables libc, libm, etc.
