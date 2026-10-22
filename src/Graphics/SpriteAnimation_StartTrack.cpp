#pragma optimize_for_size off
#include <globaldefs.h>
struct List;
struct Entry;
extern "C" Entry* SpriteAnimation_FindTrackByKey(List*, unsigned);
// Original: arm9/main @ 0x0205A370; symbol: func_0205a370; size: 0x3C.
extern "C" ARM void SpriteAnimation_StartTrack(void* list, unsigned key){unsigned char* object=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)list,key);if(!object)return;if(object[21]&1){*(unsigned short*)(object+16)=0;*(unsigned short*)(object+18)=0;}object[21]&=~7;object[21]|=2;}
