extern "C" void func_020535f4(void* object)
{
    unsigned char* counter = static_cast<unsigned char*>(object) + 0x184;
    *counter = static_cast<unsigned char>(*counter + 1);
}
