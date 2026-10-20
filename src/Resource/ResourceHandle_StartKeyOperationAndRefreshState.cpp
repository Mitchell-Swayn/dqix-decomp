#include <globaldefs.h>
ARM
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(void*,unsigned,unsigned,unsigned);extern "C" void ResourceHandle_RestoreArchiveHeapState(void*,int);extern "C" int ResourceHandle_UpdateAndReadOrClose(void*,int,void*);extern "C" bool ResourceHandle_StartArchiveSequence(void*,int,void*);extern "C" void Bgm_SetPlaybackVolumeAndFade(void*,unsigned char,int);extern "C" void Sound_UpdatePlaybackAndFlushCommands();
// Original: arm9/main @ 0x0209C6D8; symbol: func_0209c6d8; size: 0x64.
extern "C" void ResourceHandle_StartKeyOperationAndRefreshState(char* p,int key,unsigned a,unsigned b) {Bgm_StopActiveSequenceUnlessBlocked(p,0,a,b);int state=*(int*)(p+0xb4);if(state>0)ResourceHandle_RestoreArchiveHeapState(p,state);*(short*)(p+0xce)=key;ResourceHandle_UpdateAndReadOrClose(p,key,0);ResourceHandle_StartArchiveSequence(p,key,p+0xc4);Bgm_SetPlaybackVolumeAndFade(p,(unsigned char)p[0xcd],0);Sound_UpdatePlaybackAndFlushCommands(); }
