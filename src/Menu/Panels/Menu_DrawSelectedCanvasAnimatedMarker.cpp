struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned SpriteAnimation_AdvanceAllTracks(...);
extern "C" unsigned TextCanvas_HasActiveTilemap(...);
extern "C" unsigned SpriteAnimation_FindTrackByKey(...);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" void SpriteAnimation_StartTrack(void*, unsigned);
extern "C" unsigned SpriteAnimation_SubmitAllTrackFrames(...);
// Original: arm9/ov023 @ 0x021e67f4; symbol: Graphics_PositionEnabledSelectedRecordResourceEntries; size: 0xd8.
extern "C" void Menu_DrawSelectedCanvasAnimatedMarker(unsigned self){
if(!U8(self+0x13a0))return;unsigned record=(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0xac));if(!record)return;if(!TextCanvas_HasActiveTilemap(record))return;
short x=S16(record+0xac),y=S16(record+0xae);short dx=S16(record+0xbc),dy=S16(record+0xbe);x=(short)(x*8)+dx;y=(short)(y*8)+dy;
SpriteAnimation_StartTrack((void*)U32(self+0x1360),0);unsigned entry=SpriteAnimation_FindTrackByKey(U32(self+0x1360),0);if(entry)U8(entry+0x15)|=8;SpriteAnimation_AdvanceAllTracks(U32(self+0x1360),U32(self+0x13a4));entry=SpriteAnimation_FindTrackByKey(U32(self+0x1360),0);if(entry){S16(entry+4)=x-8;S16(entry+6)=y-2;}SpriteAnimation_SubmitAllTrackFrames(U32(self+0x135c));
}