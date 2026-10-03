// USA: func_02039ee8
extern "C" void func_02039ee8(void* object)
{
    unsigned char* bytes = (unsigned char*)object;
    *(unsigned short*)(bytes + 0) = 0;
    bytes[5] = 0;
    bytes[6] = 0;
    *(unsigned short*)(bytes + 8) = 0;
    bytes[7] = 0;
}
