#include <globaldefs.h>
#include "Graphics/Vector.h"
struct Entry { unsigned head;short x,y,z;short pad[3]; };struct List { unsigned char pad[2],count,reserved;Entry *entries; };
// Original: arm9/main @ 0x02028460; symbol: func_02028460; size: 0xC4.
extern "C" int FindNearestEntryToFixedPointPosition(List *list,const Vector3fix *point){if(!list->count)return 0;Entry *entries=list->entries;int best=0;Vector3fix first={entries[0].x*4096,entries[0].y*4096,entries[0].z*4096};int distance=Vector3fix_Distance(point,&first);for(int i=1;i<list->count;++i){Vector3fix pos={entries[i].x*4096,entries[i].y*4096,entries[i].z*4096};int d=Vector3fix_Distance(point,&pos);if(d<distance){best=i;distance=d;}}return best;}
