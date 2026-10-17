#include <globaldefs.h>
extern "C" void* memcpy(void*,const void*,unsigned);struct Header{unsigned payload:31;unsigned ready:1;};struct Group{Header header;char* start;char* end;};extern "C" int ComputeTwentyEightByteRecordOffset(Group*);extern "C" void Object_InvokeCallbackForAllTwentyEightByteEntries(Group*,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x0206F170; symbol: func_0206f170; size: 0x90.
extern "C" ARM int InitializeSerializedBlockUnlessReady(Group* out,Header* src,bool* already,int mode){*already=false;if(!src)return 0;memcpy(out,src,4);out->start=(char*)(src+1);out->end=(char*)src+(ComputeTwentyEightByteRecordOffset(out)+4);if(out->header.ready){*already=true;return 1;}Object_InvokeCallbackForAllTwentyEightByteEntries(out,mode);out->header.ready=1;src->ready=1;return 1;}
