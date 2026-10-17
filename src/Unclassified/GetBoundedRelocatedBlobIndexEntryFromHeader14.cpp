#pragma optimize_for_size off
#pragma optimization_level 4
#include <globaldefs.h>
struct Blob { char pad[0x14];unsigned indexOffset; };
struct BlobOwner { char pad[0x8c];Blob* blob; };
extern "C" BlobOwner* data_02110370;
// Original: arm9/main @ 0x020BD580; symbol: func_020bd580; size: 0x64.
extern "C" void* GetBoundedRelocatedBlobIndexEntryFromHeader14(unsigned index) {BlobOwner* owner=data_02110370;Blob* blob=owner->blob;unsigned* table=blob->indexOffset==0?0:(unsigned*)((char*)blob+blob->indexOffset);if(!table)return 0;if((int)index<0)return 0;if(index>=*table)return 0;unsigned offset=*(unsigned*)((char*)(table+index)+4);Blob* base=owner->blob;return offset==0?0:(char*)base+offset;}
