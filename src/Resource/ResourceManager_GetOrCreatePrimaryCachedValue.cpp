#include <globaldefs.h>
ARM
extern "C" int ReadIndexedSixteenByteTableWord14(unsigned);extern "C" int ReadGlobalAt02110370();extern "C" void SetSixteenByteRecordWordField14(unsigned,int);typedef void (*Callback)(char*,unsigned,unsigned,unsigned);extern "C" void InitializeObjectAndDispatchRelativeDataPointer(char*,unsigned,unsigned,unsigned);extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(unsigned,Callback,int,unsigned,unsigned);
// Original: arm9/main @ 0x020BE13C; symbol: func_020be13c; size: 0x6C.
extern "C" int ResourceManager_GetOrCreatePrimaryCachedValue(unsigned id,unsigned arg,int flags) {int result=ReadIndexedSixteenByteTableWord14(id);if(!result) {int context=flags?ReadGlobalAt02110370():0;result=Filesystem_AllocateReadAndFlushFileBuffer(id,InitializeObjectAndDispatchRelativeDataPointer,context,id,arg);if(flags && result)SetSixteenByteRecordWordField14(id,result);}return result; }
