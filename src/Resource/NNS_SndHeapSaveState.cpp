#include <globaldefs.h>
ARM
extern "C" int _ZN13HMRFAllocator16SaveCurrentStateEi(void*,int);extern "C" int _ZN13HMRFAllocator12RestoreStateEi(void*,int);extern "C" int AllocateTwentyByteNodeAndAppendToAllocatorList(void*);
// Original: arm9/main @ 0x020BDAC0; symbol: func_020bdac0; size: 0x4C.
extern "C" int NNS_SndHeapSaveState(unsigned char* p){if(!_ZN13HMRFAllocator16SaveCurrentStateEi(*(void**)p,*(unsigned short*)(p+12)))return -1;if(AllocateTwentyByteNodeAndAppendToAllocatorList(p))return *(unsigned short*)(p+12)-1;_ZN13HMRFAllocator12RestoreStateEi(*(void**)p,0);return -1;}
