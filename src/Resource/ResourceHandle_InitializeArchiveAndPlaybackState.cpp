#include <globaldefs.h>
ARM
extern "C" void ResourceHandle_InitializeSequenceHandle(void*);extern "C" void NNS_SndStrmHandleInit(void*);
// Original: arm9/main @ 0x0203A914; symbol: func_0203a914; size: 0x3C.
extern "C" void ResourceHandle_InitializeArchiveAndPlaybackState(unsigned char* p) { *(unsigned int*)p=0;ResourceHandle_InitializeSequenceHandle(p+0x98);NNS_SndStrmHandleInit(p+0x9c);*(short*)(p+0xa4)=-1;*(unsigned int*)(p+0xa8)=0;*(short*)(p+0xac)=-1;*(short*)(p+0xae)=-1; }
