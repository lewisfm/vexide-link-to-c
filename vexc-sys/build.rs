fn main() {
    println!("cargo:rerun-if-env-changed=vexc.c");

    let mut build = cc::Build::new();
    build
        .file("vexc.c")
        .flag("-std=gnu23");
    build.compile("vexc");
}
