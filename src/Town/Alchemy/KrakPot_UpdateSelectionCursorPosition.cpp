#include <globaldefs.h>
ARM
extern "C" int Window_UpdateOptionSelectionAndEntry(...);
extern "C" int TextCanvas_HasActiveTilemap(...);
extern "C" void Window_SetSelectedLookupEntryPosition(void*,unsigned,unsigned);
extern "C" int TextCanvas_FindDisplayPartByKey(...);
extern "C" void TextCanvas_GetGroupEntryPixelPosition(void*,unsigned,int,short*,short*);
extern "C" int SpriteAnimation_SubmitAllTrackFrames(...);
extern "C" int Window_IsVisible(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov006 @ 0x021585C4; symbol: UpdateReadyPartCoordinatesAndResourceEntries; size: 0xc8.
extern "C" void KrakPot_UpdateSelectionCursorPosition(char* self){
if(!B(self,0x38f)||!P(self,68))return;int key=S(self,0x36e);if(key<0)return;char* entry=C(TextCanvas_FindDisplayPartByKey(P(self,20),key));if(!entry||!TextCanvas_HasActiveTilemap(entry)||!P(self,24))return;if(Window_IsVisible(P(self,24)))return;struct XY{short x,y;};XY point;TextCanvas_GetGroupEntryPixelPosition(P(self,20),S(self,0x36e),S(P(self,68),0),&point.y,&point.x);Window_UpdateOptionSelectionAndEntry(P(self,24),W(self,0x34c));short x=point.x-3;short y=point.y-16;point.x=x;point.y=y;Window_SetSelectedLookupEntryPosition(P(self,24),point.y,point.x);SpriteAnimation_SubmitAllTrackFrames(self+0xac);
}
