use std::ffi::c_int;

unsafe extern "C" {
    pub fn vexc_sum(left: c_int, right: c_int) -> i32;
}
