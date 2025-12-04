use std::env;

fn main() {
    println!("cargo:rerun-if-env-changed=vexc.c");
    println!("cargo:rerun-if-env-changed=support.c");

    let mut build = cc::Build::new();
    build
        .file("vexc.c")
        .flag("-std=gnu23");

    let target = env::var("TARGET").unwrap();
    if target == "armv7a-vex-v5" {
        build.file("support.c");
    }

    build.compile("vexc");
}
