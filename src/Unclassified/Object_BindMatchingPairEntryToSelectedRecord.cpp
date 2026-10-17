#include <globaldefs.h>
ARM
extern "C" void ReadLowAndHighBytesIntoOutputPointers(void*,unsigned char*,unsigned char*);
// Original: arm9/main @ 0x0205DE24; symbol: func_0205de24; size: 0x90.
extern "C" void Object_BindMatchingPairEntryToSelectedRecord(char* p,unsigned a,unsigned b){if(!*(void**)(p+152)||!*(void**)(p+156))return;char* target=*(char**)(p+156)+(short)(unsigned char)p[180]*224;if(!target)return;char* e;unsigned char pair[2];for(unsigned char i=0;i<(unsigned char)p[178];++i){e=*(char**)(p+152)+i*32;ReadLowAndHighBytesIntoOutputPointers(e,pair+1,pair);if(pair[1]==a&&pair[0]==b){*(char**)(target+4)=e;return;}}}
