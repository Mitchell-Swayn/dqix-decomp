#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(void*);
void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
void SpriteAnimation_StartTrack(void*,int);
unsigned char* SpriteAnimation_FindTrackByKey(void*,unsigned);
void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
}
// Original: arm9/ov023 @ 0x021E3304; symbol: func_ov023_021e3304; size: 0x88.
extern "C" void Resource_ResetAndPositionFirstEntry(unsigned char* object,short x,short y) {
 void* state=_ZN9GameState11GetInstanceEv();
 SpriteAnimation_SetTrackOamStartIndex(*(void**)(object+0xd0),0,0);
 SpriteAnimation_StartTrack(*(void**)(object+0xd0),0);
 unsigned char* entry=SpriteAnimation_FindTrackByKey(*(void**)(object+0xd0),0);
 if(entry) entry[0x15]|=8;
 SpriteAnimation_AdvanceAllTracks(*(char**)(object+0xd0),_ZNK9GameState12GetTickCountEv(state));
 entry=SpriteAnimation_FindTrackByKey(*(void**)(object+0xd0),0);
 if(entry) { *(short*)(entry+4)=x; *(short*)(entry+6)=y; }
 SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(object+0xc8));
}
