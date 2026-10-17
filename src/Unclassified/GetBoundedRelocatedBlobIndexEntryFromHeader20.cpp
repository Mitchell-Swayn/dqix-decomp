#pragma optimize_for_size off
#include <globaldefs.h>
ARM
struct Blob { unsigned char pad[0x20];unsigned indexOffset; };struct Owner { unsigned char pad[0x8c];Blob* blob; };extern "C" Owner* data_02110370;
// Original: arm9/main @ 0x020BD6AC; symbol: func_020bd6ac; size: 0x64.
extern "C" void* GetBoundedRelocatedBlobIndexEntryFromHeader20(unsigned index) {Owner* owner=data_02110370;Blob* blob=owner->blob;unsigned offset=blob->indexOffset;unsigned* table;if(offset==0)table=0;else table=(unsigned*)((unsigned char*)blob+offset);if(!table)return 0;if((int)index<0)return 0;if(index>=*table)return 0;unsigned resultOffset=*(unsigned*)((unsigned char*)(table+index)+4);Blob* base=owner->blob;if(resultOffset==0)return 0;else return (unsigned char*)base+resultOffset;}
