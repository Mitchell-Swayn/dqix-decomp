#include <globaldefs.h>
ARM
extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);
extern "C" unsigned Window_IsVisible(void*);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" void TextCanvas_GetGroupEntryPixelPosition(char*,unsigned,int,short*,short*);
extern "C" void SpriteAnimation_StartTrack(void*, unsigned);
extern "C" unsigned char* SpriteAnimation_FindTrackByKey(void*,unsigned);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void Window_SetLookupEntryPosition(void*,unsigned,unsigned,unsigned);
// Original: arm9/ov003 @ 0x0216039C; symbol: func_ov003_0216039c; size: 0x134.
extern "C" void Tavern_DrawPartySelectionCursor(unsigned char* p) {
 if (!*(void**)(p+0x470) || *(short*)(p+0x488)<0 || !*(void**)(p+0x324)) return;
 unsigned char* r=TextCanvas_FindDisplayPartByKey(*(unsigned char**)(p+0x324),*(short*)(p+0x488));
 if (!r) return;
 if (*(void**)(p+0x390) && Window_IsVisible(*(void**)(p+0x390))) {
 SpriteAnimation_SetTrackOamStartIndex(*(void**)(p+0x38c),0,0);
 SpriteAnimation_SubmitAllTrackFrames(p+0x334);
 } else if (TextCanvas_HasActiveTilemap((char*)r)) {
 short x,y;
 TextCanvas_GetGroupEntryPixelPosition(*(char**)(p+0x324),*(short*)(p+0x488),**(short**)(p+0x470),&x,&y);
 x-=16; y-=3;
 SpriteAnimation_StartTrack(*(void**)(p+0x38c),0);
 unsigned char* e=SpriteAnimation_FindTrackByKey(*(void**)(p+0x38c),0);
 if(e) e[0x15]|=8;
 e=SpriteAnimation_FindTrackByKey(*(void**)(p+0x38c),1);
 if(e) e[0x15]&=~8;
 SpriteAnimation_AdvanceAllTracks(*(char**)(p+0x38c),*(unsigned*)(p+0x460));
 Window_SetLookupEntryPosition(*(void**)(p+0x38c),0,x,y);
 SpriteAnimation_SubmitAllTrackFrames(p+0x334);
 }
}
