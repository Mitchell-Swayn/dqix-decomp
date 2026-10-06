#include "Filesystem/FileAccessor.h"

extern "C" void func_020c0100(void* object)
{
    NitroVM_CancelCommand(reinterpret_cast<NitroVM*>(
        static_cast<unsigned char*>(object) + 0x5c));
}
