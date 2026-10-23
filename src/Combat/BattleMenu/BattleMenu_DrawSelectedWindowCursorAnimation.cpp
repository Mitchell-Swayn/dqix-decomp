#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_repositioncode off
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
struct WindowCanvasOwner; struct WindowCanvasRecord;struct Entry;struct List;
extern "C" {
WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
int TextCanvas_HasActiveTilemap(char*);
void SpriteAnimation_StartTrack(void*,unsigned);
Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
}
// Original: arm9/ov000 @ 0x02175544; symbol: func_ov000_02175544; size: 0xE4.
// Places animation track zero at the selected active canvas, advances it, and submits its frames.
extern "C" void BattleMenu_DrawSelectedWindowCursorAnimation(char* self) {
    if(!(UHALF(self,0x1d72)&0x100)) return;
    char* canvas=(char*)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0x188));
    if(!canvas) return;
    if(BYTE(canvas,0xc4)>=26) return;
    if(!TextCanvas_HasActiveTilemap(canvas)) return;
    short x=HALF(canvas,0xac), y=HALF(canvas,0xae);
    x*=8; y*=8;
    x+=HALF(canvas,0xbc); y+=HALF(canvas,0xbe);
    char* animation=PTR(self,0x174);
    SpriteAnimation_StartTrack(animation,0);
    char* track=(char*)SpriteAnimation_FindTrackByKey((List*)animation,0);
    if(track) BYTE(track,0x15)|=8;
    SpriteAnimation_AdvanceAllTracks(animation,WORD(self,0x94c));
    track=(char*)SpriteAnimation_FindTrackByKey((List*)animation,0);
    if(track) {HALF(track,4)=x-8;HALF(track,6)=y-2;}
    SpriteAnimation_SetTrackOamStartIndex(animation,0,0x50);
    SpriteAnimation_SubmitAllTrackFrames((unsigned char*)self+0x11c);
}
