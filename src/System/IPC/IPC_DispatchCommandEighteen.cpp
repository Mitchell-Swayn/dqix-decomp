#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" int SendPackedArm7CommandFive(unsigned);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x020CF89C; symbol: func_020cf89c; size: 0x10.
extern "C" int IPC_DispatchCommandEighteen(){return SendPackedArm7CommandFive(18);}
