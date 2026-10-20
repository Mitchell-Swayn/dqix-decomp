#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" unsigned char* ResourceTracks_GetSingleScalarSection(void*);extern "C" unsigned** _ZN19SignedAllocatorList13GetNthElementEj(void*,unsigned);extern "C" unsigned Point_ComputeFloatingPointSlope(unsigned**,unsigned**);
struct Sequence {char pad[4];unsigned time;char pad2[0x28];char* owner;char pad3[0x68];unsigned current;unsigned short index;};
// Original: arm9/main @ 0x02055C30; symbol: func_02055c30; size: 0x9C.
extern "C" void ResourceTracks_AdvanceEmissionCountTrack(Sequence* p){unsigned char* meta=ResourceTracks_GetSingleScalarSection(p->owner);if(meta[4]<=1)return;if((int)meta[4]<=(int)p->index)return;unsigned** item=_ZN19SignedAllocatorList13GetNthElementEj(p->owner+0x74,p->index);if(!item)return;if(**item>=p->time)return;p->index++;if((int)p->index>=(int)meta[4]){p->current=0;return;}unsigned** next=_ZN19SignedAllocatorList13GetNthElementEj(p->owner+0x74,p->index);if(!next)return;p->current=Point_ComputeFloatingPointSlope(item,next);}
