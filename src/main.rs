use vexc_sys::vexc_sum;
use vexide::prelude::*;

#[vexide::main]
async fn main(_p: Peripherals) {
    println!("Vexide LLVM toolchain: {}", cfg!(vexide_toolchain = "llvm"));

    for n in 0..5 {
        let sum = unsafe { vexc_sum(n, 5) };
        println!("(From Rust) Sum: {sum}");
    }
}
