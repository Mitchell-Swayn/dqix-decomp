#include <globaldefs.h>
extern "C" {
ARM int NNS_SndArcGetFileAddress(); int NNS_SndArcGetCurrent(); void ResourceManager_ConfigureAndSubmitMemoryRange(); int Filesystem_AllocateReadAndFlushFileBuffer(void*,void(*)(),int,void*,int); void NNS_SndArcSetFileAddress(void*,int);
// Original: arm9/main @ 0x020BE214; symbol: func_020be214; size: 0x6C.
 int SoundArchive_LoadBankFile(void* object,int argument,int flag) { int result=NNS_SndArcGetFileAddress(); if(!result) { int value=flag?NNS_SndArcGetCurrent():0; result=Filesystem_AllocateReadAndFlushFileBuffer(object,ResourceManager_ConfigureAndSubmitMemoryRange,value,object,argument); if(flag && result) NNS_SndArcSetFileAddress(object,result); } return result; }
}
