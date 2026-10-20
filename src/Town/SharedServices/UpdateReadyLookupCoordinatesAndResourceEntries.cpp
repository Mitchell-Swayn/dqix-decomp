#include <globaldefs.h>
ARM
extern "C" {int TextCanvas_HasActiveTilemap(char*);void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);void TextCanvas_GetGroupEntryPixelPosition(char*,unsigned,int,short*,short*);unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);void Window_UpdateOptionSelectionAndEntry(void*,int);unsigned Window_IsVisible(void*);void Window_SetSelectedLookupEntryPosition(void*,unsigned,unsigned);}
// Original: arm9/ov003 @ 0x0215501C; symbol: func_ov003_0215501c; size: 0xC0.
extern "C" void UpdateReadyLookupCoordinatesAndResourceEntries(char* p){
if(!*(void**)(p+8))return;
if(*(short*)(p+0x1e6)<0)return;
char* record=(char*)TextCanvas_FindDisplayPartByKey(*(unsigned char**)(p+0x18),*(short*)(p+0x1e6));if(!record)return;
if(!TextCanvas_HasActiveTilemap(record)||!*(void**)(p+0x1c))return;
if(Window_IsVisible(*(void**)(p+0x1c)))return;
short x,y;
TextCanvas_GetGroupEntryPixelPosition(*(char**)(p+0x18),*(short*)(p+0x1e6),**(short**)(p+8),&x,&y);
Window_UpdateOptionSelectionAndEntry(*(void**)(p+0x1c),*(int*)(p+0x1dc));
x-=16;y-=3;
Window_SetSelectedLookupEntryPosition(*(void**)(p+0x1c),x,y);
SpriteAnimation_SubmitAllTrackFrames((unsigned char*)p+0x2c);
}
