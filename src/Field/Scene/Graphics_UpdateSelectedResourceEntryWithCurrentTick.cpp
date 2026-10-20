#include <globaldefs.h>
ARM
struct GameState; struct Entry; struct List;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" void SpriteAnimation_StartTrack(void*,int);
extern "C" Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);
extern "C" void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
extern "C" void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);
extern "C" void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);
extern "C" void QuestMessagePanel_FinishOptionalOverlayUpdate(void*);
// Original: arm9/ov017 @ 0x021BB930; symbol: func_ov017_021bb930; size: 0xBC.
extern "C" void Graphics_UpdateSelectedResourceEntryWithCurrentTick(unsigned char* self) {
 if(self[0xfe] && *(void**)(self+0x168)) {
  GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
  char* entries=*(char**)(*(char**)(self+0x168)+0x3c);
  if(entries) {
   SpriteAnimation_StartTrack(entries,1);
   unsigned char* entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)entries,1);
   if(entry) entry[0x15]|=8;
   SpriteAnimation_AdvanceAllTracks(entries,_ZNK9GameState12GetTickCountEv(state));
   entry=(unsigned char*)SpriteAnimation_FindTrackByKey((List*)entries,1);
   if(entry) { *(short*)(entry+4)=0xd8; *(short*)(entry+6)=0x98; }
   SpriteAnimation_SetTrackOamStartIndex(entries,1,6);
  }
  SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(self+0x168));
 }
 void* object=*(void**)(self+0x120);
 if(object) QuestMessagePanel_FinishOptionalOverlayUpdate(object);
}
