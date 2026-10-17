#include <globaldefs.h>
extern "C" {
ARM int ReadIndexedSixteenByteTableWord14(); int ReadGlobalAt02110370(); void ResourceManager_ConfigureAndSubmitMemoryRange(); int Filesystem_AllocateReadAndFlushFileBuffer(void*,void(*)(),int,void*,int); void SetSixteenByteRecordWordField14(void*,int);
// Original: arm9/main @ 0x020BE214; symbol: func_020be214; size: 0x6C.
 int ResolveCachedFileBufferOrAllocateAndRead(void* object,int argument,int flag) { int result=ReadIndexedSixteenByteTableWord14(); if(!result) { int value=flag?ReadGlobalAt02110370():0; result=Filesystem_AllocateReadAndFlushFileBuffer(object,ResourceManager_ConfigureAndSubmitMemoryRange,value,object,argument); if(flag && result) SetSixteenByteRecordWordField14(object,result); } return result; }
}
