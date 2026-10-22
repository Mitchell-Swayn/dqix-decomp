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
// Original: arm9/ov003 @ 0x0216acf0; symbol: Graphics_PositionSelectedRecordResourceEntries; size: 0xcc.
extern "C" void Graphics_PositionSelectedRecordResourceEntries(unsigned self){
if(!(U8(self+0x59f)&1))return;unsigned record=(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0xe4));if(!record)return;if(!TextCanvas_HasActiveTilemap(record))return;if(U8(record+0xc5)&32)return;
short x=(short)(S16(record+0xac)*8)+S16(record+0xbc);short y=(short)(S16(record+0xae)*8)+S16(record+0xbe);
SpriteAnimation_StartTrack((void*)U32(self+0x4d8),0);unsigned entry=SpriteAnimation_FindTrackByKey(U32(self+0x4d8),0);if(entry)U8(entry+0x15)|=8;
SpriteAnimation_AdvanceAllTracks(U32(self+0x4d8),U32(self+0x4dc));entry=SpriteAnimation_FindTrackByKey(U32(self+0x4d8),0);if(entry){S16(entry+4)=x-8;S16(entry+6)=y-2;}SpriteAnimation_SubmitAllTrackFrames(self+0x480);
}