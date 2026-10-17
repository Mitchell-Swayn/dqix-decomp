#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Object {unsigned char pad[4];}; struct Record {unsigned char pad[42];unsigned char flags;};
extern "C" int Geometry_FindEntryContainingPoint(Object*,int,int,int); extern "C" Record* FindNonnegativeKeyInEntryArray(void*,int); extern "C" void SelectMatchingKindRecordAndOptionalFinalize(Object*,int,int,int,unsigned char);
// Original: arm9/main @ 0x02080DD4; symbol: func_02080dd4; size: 0x6C.
extern "C" int SelectHitEntryAndWriteFlagOutput(Object*o,int id,int x,int y,unsigned char*out,unsigned char flag){int index=Geometry_FindEntryContainingPoint(o,id,x,y);if(index==-1)return -1;*out=0;Record*r=FindNonnegativeKeyInEntryArray(o+1,index);if(r->flags&4)*out=1;SelectMatchingKindRecordAndOptionalFinalize(o,id,index,1,flag);return index;}
