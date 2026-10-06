extern "C" int func_ov017_0218d75c(void* object)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    void* state = *reinterpret_cast<void**>(bytes + 0x4498);
    return state != 0 && *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(state) + 0x14) != 0;
}
