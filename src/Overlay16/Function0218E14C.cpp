extern "C" void* func_ov016_0218e14c(void** object, int count)
{
    void* current = *object;
    while (count > 0) {
        if (current == 0) {
            return 0;
        }
        current = *reinterpret_cast<void**>(
            static_cast<unsigned char*>(current) + 0x18);
        --count;
    }
    return current;
}
