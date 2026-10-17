// ARM callee/header contracts and exact original relocations reviewed; MMIO/shared-memory retained.
#include <globaldefs.h>
#include <System/Memory.h>
#include <System/Matrix.h>
ARM
#pragma force_active on
#pragma optimization_level 4
struct Flags{unsigned short a:9,value:3,b:4;};extern "C"{void LinkedList_RemoveNodeByIdentityWithIRQGuard(void*,void*);void InitializeEightWordsWithRandomDelay2000To3999(void*);void MIi_CpuClearFast(unsigned,void*,unsigned);void Text_CopyBoundedNullTerminatedString(const char*,char*,unsigned);void WriteKindAndSetStateFive(char*,unsigned);void func_020e2d54(int,void*,void*);extern char data_02111800[],data_02107850[],data_020fe9cc[],data_020f2c14[];}
// Original: arm9/main @ 0x0202AD30; symbol: func_0202ad30; size: 0x1C.
extern "C" void Object_ClearGlobal1536ByteBuffer(){MIi_CpuClearFast(0,data_020fe9cc,1536);}
