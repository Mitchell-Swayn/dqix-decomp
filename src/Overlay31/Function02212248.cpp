extern "C" unsigned char data_ov031_0224e5b4[];

extern "C" int func_ov031_02212248()
{
    unsigned char* state = *reinterpret_cast<unsigned char**>(data_ov031_0224e5b4 + 4);
    return state != 0 && *reinterpret_cast<unsigned short*>(state + 4) == 6;
}
