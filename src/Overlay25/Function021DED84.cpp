extern "C" void func_ov025_021ded84(void* destination, const void* source)
{
    unsigned short* out = static_cast<unsigned short*>(destination);
    const unsigned short* in = static_cast<const unsigned short*>(source);

    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
}
