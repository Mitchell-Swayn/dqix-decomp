#include <globaldefs.h>
ARM
extern "C" int NNS_SndArcGetFileAddress(unsigned);extern "C" int NNS_SndArcGetCurrent();extern "C" void NNS_SndArcSetFileAddress(unsigned,int);typedef void (*Callback)(char*,unsigned,unsigned,unsigned);extern "C" void SoundArchive_DisposeSequenceFile(char*,unsigned,unsigned,unsigned);extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(unsigned,Callback,int,unsigned,unsigned);
// Original: arm9/main @ 0x020BE13C; symbol: func_020be13c; size: 0x6C.
extern "C" int ResourceManager_GetOrCreatePrimaryCachedValue(unsigned id,unsigned arg,int flags) {int result=NNS_SndArcGetFileAddress(id);if(!result) {int context=flags?NNS_SndArcGetCurrent():0;result=Filesystem_AllocateReadAndFlushFileBuffer(id,SoundArchive_DisposeSequenceFile,context,id,arg);if(flags && result)NNS_SndArcSetFileAddress(id,result);}return result; }
