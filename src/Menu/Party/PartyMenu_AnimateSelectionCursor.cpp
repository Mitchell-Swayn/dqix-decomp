#include <globaldefs.h>
ARM
struct WindowCanvasOwner;struct WindowCanvasRecord;struct Entry;struct List;struct Lookup;struct A;
extern "C" {
WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
int TextCanvas_HasActiveTilemap(char*);
unsigned Window_IsVisible(A**);
void SpriteAnimation_StartTrack(void*,unsigned);
Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
void Window_SetLookupEntryPosition(Lookup*,unsigned,unsigned,unsigned);
void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
}
// Original: arm9/ov002 @ 0x0215AFB8; symbol: PartyMenu_AnimateSelectionCursor; size: 0xF0.
extern "C" void PartyMenu_AnimateSelectionCursor(unsigned char* self){
if(!(*(unsigned*)(self+0x247c)&4))return;
char* canvas=(char*)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+0xec8));if(!canvas)return;
if(!TextCanvas_HasActiveTilemap(canvas)||!*(void**)(self+4))return;
if(Window_IsVisible(*(A***)(self+4)))return;
short tileX=*(short*)(canvas+0xac),tileY=*(short*)(canvas+0xae);
short x,y;char* sprite=*(char**)(self+0x1a6c);
x=*(short*)(canvas+0xbc)+(short)(tileX*8);y=*(short*)(canvas+0xbe)+(short)(tileY*8);
SpriteAnimation_StartTrack(sprite,0);
unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)sprite,0);if(entry)entry[0x15]|=8;
SpriteAnimation_AdvanceAllTracks(sprite,*(unsigned*)(self+0x1ba0));
Window_SetLookupEntryPosition((Lookup*)sprite,0,(short)(x-8),(short)(y-2));
SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(self+0x1a68));
}
