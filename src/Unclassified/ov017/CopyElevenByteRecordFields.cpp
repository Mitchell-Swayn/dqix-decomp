// Copies fields at offsets 0, 2, 4, 6, 8 and 0xA with their observed widths.
// Original: arm9/ov017 @ 0x021C90F8; symbol: func_ov017_021c90f8; size: 0x34.
extern "C" void CopyElevenByteRecordFields(void* destination, const void* source) {
    volatile unsigned char* out = (volatile unsigned char*)destination;
    const volatile unsigned char* in = (const volatile unsigned char*)source;
    *(volatile unsigned short*)(out + 0) = *(const volatile unsigned short*)(in + 0);
    *(volatile unsigned short*)(out + 2) = *(const volatile short*)(in + 2);
    *(volatile unsigned short*)(out + 4) = *(const volatile unsigned short*)(in + 4);
    *(volatile unsigned short*)(out + 6) = *(const volatile unsigned short*)(in + 6);
    *(volatile unsigned short*)(out + 8) = *(const volatile unsigned short*)(in + 8);
    out[10] = in[10];
}
