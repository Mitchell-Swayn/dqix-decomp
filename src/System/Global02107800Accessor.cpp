struct Global02107800 {
    unsigned char unknown00[0x1c];
    void* value1c;
};

extern Global02107800 data_02107800;

extern "C" void* func_020421a0() {
    return data_02107800.value1c;
}
