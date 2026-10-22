struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma opt_common_subs off
struct A;struct Entry;struct List;struct Lookup;
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void SpriteAnimation_StartTrack(void*, unsigned);
extern "C" Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" void Window_SetLookupEntryPosition(Lookup*,unsigned,unsigned,unsigned);
extern "C" unsigned Window_IsVisible(A**);
// Original: arm9/ov003 @ 0x0215C32C; symbol: func_ov003_0215c32c; size: 0x138.
extern "C" void Graphics_UpdateSelectedRecordMarker(unsigned char* self) {
 if(self[0x59f]&1) {
  if(*(A***)(self+0x570) && Window_IsVisible(*(A***)(self+0x570))) {
   SpriteAnimation_SubmitAllTrackFrames(self+0x98);
   return;
  }
  char* record=(char*)(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)((char*)self+0xf4));
  if(!record)return;
  if(!TextCanvas_HasActiveTilemap(record))return;
  if(((unsigned char*)record)[0xc5]&0x20)return;
  short x=*(short*)(record+0xac)*8;
  short y=*(short*)(record+0xae)*8;
  x+=*(short*)(record+0xbc);
  y+=*(short*)(record+0xbe);
  char* list=*(char**)(self+0xd4);
  if(list) {
   SpriteAnimation_StartTrack(list,0);
   unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)list,0);
   if(entry)entry[0x15]|=8;
   SpriteAnimation_AdvanceAllTracks(list,*(unsigned*)(self+0x574));
   Window_SetLookupEntryPosition((Lookup*)list,0,(short)(x-8),(short)(y-2));
   SpriteAnimation_SetTrackOamStartIndex(list,0,0);
  }
  SpriteAnimation_SubmitAllTrackFrames(self+0x98);
 } else {
  if(!*(List**)(self+0xd4))return;
  unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey(*(List**)(self+0xd4),0);
  if(entry)entry[0x15]&=~8;
 }
}
