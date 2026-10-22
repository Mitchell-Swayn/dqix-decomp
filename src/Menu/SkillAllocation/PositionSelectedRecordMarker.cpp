struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Entry;struct List;
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" void SpriteAnimation_StartTrack(void*, unsigned);
extern "C" Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
#define H(o) (*(short*)(record+(o)))
#pragma always_inline on
inline void ResolveCoordinates(char* record,short* x,short* y){*x=(short)(H(0xac)*8);*y=(short)(H(0xae)*8);*x+=H(0xbc);*y+=H(0xbe);}
// Original: arm9/ov013 @ 0x02186CAC; symbol: func_ov013_02186cac; size: 0x108.
// Positions a keyed marker from selected-record coordinates with mode-specific offsets.
extern "C" void PositionSelectedRecordMarker(unsigned char* p){
 if(!*(void**)(p+0x18)||!(p[0x6bc]&1))return;
 char* record=(char*)(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)((char*)p+0x38));if(!record||!TextCanvas_HasActiveTilemap(record))return;
 short x,y;ResolveCoordinates(record,&x,&y);
 if(p[0x63c]==3||p[0x63c]==4)x-=8;else{x-=8;y-=2;}
 char* list=*(char**)(*(char**)(p+0x18)+0x3c);if(!list)return;
 SpriteAnimation_StartTrack(list,*(unsigned short*)(p+0x1c));
 char* entry=(char*)SpriteAnimation_FindTrackByKey((List*)list,*(unsigned short*)(p+0x1c));if(entry)*(unsigned char*)(entry+0x15)|=8;
 SpriteAnimation_AdvanceAllTracks(list,*(unsigned*)(p+0x14));entry=(char*)SpriteAnimation_FindTrackByKey((List*)list,*(unsigned short*)(p+0x1c));
 if(entry){*(short*)(entry+4)=x;*(short*)(entry+6)=y;}
 SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(p+0x18));
}
