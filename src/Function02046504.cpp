extern "C" void func_020464a4(void* source, void* destination, unsigned int size);

extern "C" void func_02046504(void* object, void* source)
{
    func_020464a4(source, static_cast<unsigned char*>(object) + 0x3ac, 0x40);
}
