struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(void*);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void SpriteAnimation_StartTrack(void*,int);
extern "C" unsigned char* SpriteAnimation_FindTrackByKey(void*,unsigned);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Window_SetLookupEntryPosition(void*,unsigned,unsigned,unsigned);
// Original: arm9/ov023 @ 0x021DA9B4; symbol: func_ov023_021da9b4; size: 0x1A8.
extern "C" void Graphics_UpdateSelectedResourcePositions(char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 if(*(int*)(self+0x7d8)) {
 int selected=*(signed char*)(self+0xc58);
 if(selected>=1 && selected<=8) {
 short x;
 short y=(selected-1)*16+43;
 x=108;
 void* game2=_ZN9GameState11GetInstanceEv();
 int language=GameState_ReadSupportedFirmwareLanguage(game2);
 char* lookup=*(char**)(self+0x7e0);
 if(language==4) x=100;
 SpriteAnimation_SetTrackOamStartIndex(lookup,0,120);
 SpriteAnimation_StartTrack(lookup,0);
 unsigned char* entry=SpriteAnimation_FindTrackByKey(lookup,0);
 if(entry) entry[0x15]|=8;
 SpriteAnimation_AdvanceAllTracks(lookup,_ZNK9GameState12GetTickCountEv(game2));
 Window_SetLookupEntryPosition(lookup,0,x,y);
 SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(self+0x7d8));
 }
 }
 if(!*(int*)(self+0x7e4)) return;
 char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0x2b4),1);
 if(!record) return;
 if(!TextCanvas_HasActiveTilemap(record)) return;
 short x=*(short*)(record+0xac);
 short y=*(short*)(record+0xae);
 x=(short)(x<<3)+*(short*)(record+0xbc);
 y=(short)(y<<3)+*(short*)(record+0xbe);
 char* lookup=*(char**)(self+0x7ec);
 SpriteAnimation_SetTrackOamStartIndex(lookup,0,120);
 SpriteAnimation_StartTrack(lookup,0);
 unsigned char* entry=SpriteAnimation_FindTrackByKey(lookup,0);
 if(entry) entry[0x15]|=8;
 SpriteAnimation_AdvanceAllTracks(lookup,_ZNK9GameState12GetTickCountEv(game));
 Window_SetLookupEntryPosition(lookup,0,(short)(x-8),(short)(y-2));
 SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(self+0x7e4));
}
