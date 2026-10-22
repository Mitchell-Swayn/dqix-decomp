struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" int SpriteAnimation_AdvanceAllTracks(...);
extern "C" int TextCanvas_HasActiveTilemap(...);
extern "C" int SpriteAnimation_FindTrackByKey(...);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" void SpriteAnimation_StartTrack(void*, unsigned);
extern "C" int SpriteAnimation_SubmitAllTrackFrames(...);
extern "C" int Selection_ReadEnabledIndexFromControl(...);
extern "C" int Window_SetLookupEntryPosition(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK9GameState12GetTickCountEv(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x0216DCF0; symbol: UpdateSelectedRecordCursorOrHideMissingEntry.
extern "C" void Inn_DrawAnimatedServiceMenuCursor(char*self){
int state=_ZN9GameState11GetInstanceEv();char*selected=C((int)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(P(self+0x1000,0x2c0))));if(selected&&TextCanvas_HasActiveTilemap(selected)){short vertical=S(selected,174)*8;short horizontal=S(selected,172);short y=(short)Selection_ReadEnabledIndexFromControl(P(self+0x1000,0x2c0))*12+vertical;char*control=P(self+0x1000,0x2a8);if(!control)return;SpriteAnimation_StartTrack(control,0);char*record=C(SpriteAnimation_FindTrackByKey(control,0));if(record)B(record,21)|=8;SpriteAnimation_AdvanceAllTracks(control,_ZNK9GameState12GetTickCountEv(state));short x=(short)(horizontal*8)-4;short outputY=y+2;Window_SetLookupEntryPosition(control,0,x,outputY);SpriteAnimation_SubmitAllTrackFrames(self+0x126c);}else{char*control=P(self+0x1000,0x2a8);if(!control)return;char*record=C(SpriteAnimation_FindTrackByKey(control,0));if(record)B(record,21)&=~8;}
}
