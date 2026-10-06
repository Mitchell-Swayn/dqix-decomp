extern "C" void func_ov003_0215385c(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    if (bytes[0x5a] == 0) {
        bytes[0x5a] = 0;
        bytes[0x5b] = 0;
    }
}
