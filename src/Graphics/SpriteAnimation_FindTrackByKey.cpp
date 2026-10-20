#pragma optimize_for_size off
#include <globaldefs.h>
ARM
struct Entry { unsigned int a,b; unsigned short key; unsigned char rest[14]; };
struct List { Entry* entries; unsigned short count; };
// Original: arm9/main @ 0x0205A3D0; symbol: func_0205a3d0; size: 0x5C.
extern "C" Entry* SpriteAnimation_FindTrackByKey(List* list, unsigned int key) { unsigned short i;Entry* entries=list->entries; if (!entries) return 0; unsigned short count=list->count; Entry* result=0; if (!count) return result; for(i=0;i<count;++i) { Entry* entry=&entries[i]; if (key==entry->key) { result=entry; break; } } return result; }
