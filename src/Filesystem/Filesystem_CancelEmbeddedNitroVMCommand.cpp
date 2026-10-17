#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020C0100; symbol: func_020c0100; size: 0x10.
extern "C" void Filesystem_CancelEmbeddedNitroVMCommand(char* a){NitroVM_CancelCommand((NitroVM*)(a+92));}
