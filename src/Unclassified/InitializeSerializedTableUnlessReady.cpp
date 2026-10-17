#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" unsigned WordPair_ComputeEightTimesComponentSum(const unsigned short*);extern "C" int Object_VisitEightByteEntriesWithCallback(void*,void(*)(void*,unsigned char*));
struct Flags{unsigned low:15;unsigned ready:1;unsigned high:16;};
// Original: arm9/main @ 0x020DFABC; symbol: func_020dfabc; size: 0x8C.
extern "C" ARM int InitializeSerializedTableUnlessReady(unsigned* out,unsigned* src,unsigned char* present,void(*callback)(void*,unsigned char*)){*present=0;if(!src)return 0;memcpy(out,src,8);out[2]=(unsigned)src+8;out[3]=WordPair_ComputeEightTimesComponentSum((unsigned short*)out)+8+(unsigned)src;if(((Flags*)(out+1))->ready){*present=1;return 1;}Object_VisitEightByteEntriesWithCallback(out,callback);out[1]|=32768;src[1]|=32768;return 1;}
