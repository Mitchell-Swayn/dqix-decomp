extern "C" void func_020465c0(void* object, int index, unsigned int value)
{
    if (index >= 0 && index < 16) {
        ((unsigned int*)((unsigned char*)object + 0x8b0))[index] = value;
    }
}
