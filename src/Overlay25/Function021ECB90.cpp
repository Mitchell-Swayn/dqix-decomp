extern "C" void func_ov025_021ecb90(void* destination, const void* source)
{
    unsigned char* out = static_cast<unsigned char*>(destination);
    const unsigned char* in = static_cast<const unsigned char*>(source);

    *reinterpret_cast<unsigned int*>(out + 0x00) = *reinterpret_cast<const unsigned int*>(in + 0x00);
    out[0x04] = in[0x04];
    out[0x05] = in[0x05];
    out[0x06] = in[0x06];
    *reinterpret_cast<unsigned int*>(out + 0x08) = *reinterpret_cast<const unsigned int*>(in + 0x08);
    *reinterpret_cast<unsigned int*>(out + 0x0c) = *reinterpret_cast<const unsigned int*>(in + 0x0c);
    *reinterpret_cast<unsigned int*>(out + 0x10) = *reinterpret_cast<const unsigned int*>(in + 0x10);
    *reinterpret_cast<unsigned int*>(out + 0x14) = *reinterpret_cast<const unsigned int*>(in + 0x14);
    *reinterpret_cast<unsigned int*>(out + 0x18) = *reinterpret_cast<const unsigned int*>(in + 0x18);
    *reinterpret_cast<unsigned int*>(out + 0x1c) = *reinterpret_cast<const unsigned int*>(in + 0x1c);
    *reinterpret_cast<short*>(out + 0x20) = *reinterpret_cast<const short*>(in + 0x20);
    *reinterpret_cast<short*>(out + 0x22) = *reinterpret_cast<const short*>(in + 0x22);
    *reinterpret_cast<unsigned int*>(out + 0x24) = *reinterpret_cast<const unsigned int*>(in + 0x24);
    *reinterpret_cast<unsigned int*>(out + 0x28) = *reinterpret_cast<const unsigned int*>(in + 0x28);
    *reinterpret_cast<unsigned short*>(out + 0x2c) = *reinterpret_cast<const unsigned short*>(in + 0x2c);
    *reinterpret_cast<unsigned short*>(out + 0x2e) = *reinterpret_cast<const unsigned short*>(in + 0x2e);
    *reinterpret_cast<unsigned short*>(out + 0x30) = *reinterpret_cast<const unsigned short*>(in + 0x30);
    *reinterpret_cast<unsigned short*>(out + 0x32) = *reinterpret_cast<const unsigned short*>(in + 0x32);
    *reinterpret_cast<unsigned short*>(out + 0x34) = *reinterpret_cast<const unsigned short*>(in + 0x34);
    *reinterpret_cast<unsigned short*>(out + 0x36) = *reinterpret_cast<const unsigned short*>(in + 0x36);
    out[0x38] = in[0x38];
    out[0x39] = in[0x39];
    out[0x3a] = in[0x3a];
    *reinterpret_cast<unsigned short*>(out + 0x3c) = *reinterpret_cast<const unsigned short*>(in + 0x3c);
}
