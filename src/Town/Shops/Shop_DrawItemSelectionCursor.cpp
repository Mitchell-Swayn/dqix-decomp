#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* TextCanvas_FindDisplayPartByKey(void*,int);
extern "C" int TextCanvas_HasActiveTilemap(void*);
extern "C" int Window_IsVisible(void*);
extern "C" void TextCanvas_GetGroupEntryPixelPosition(void*,int,int,short*,short*);
extern "C" void Window_UpdateOptionSelectionAndEntry(void*,int);
extern "C" void Window_SetSelectedLookupEntryPosition(void*,int,int);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(void*);
// Original: arm9/ov003 @ 0x02175FD4; symbol: Input_UpdateLookupFromSelectedDisplayPartCoordinates; size: 0xc4.
extern "C" void Shop_DrawItemSelectionCursor(char* self) {
 if(!P(self,0xff8)||H(self,0xffe)<0)return;void* record=TextCanvas_FindDisplayPartByKey(P(self,0x89c),H(self,0xffe));if(!record)return;
 if(!TextCanvas_HasActiveTilemap(record)||!P(self,0)||Window_IsVisible(P(self,0)))return;
 short x,y;TextCanvas_GetGroupEntryPixelPosition(P(self,0x89c),H(self,0xffe),H(P(self,0xff8),0),&x,&y);Window_UpdateOptionSelectionAndEntry(P(self,0),W(self,0xfe0));x-=16;y-=3;Window_SetSelectedLookupEntryPosition(P(self,0),x,y);SpriteAnimation_SubmitAllTrackFrames(self+0x7d8);
}
