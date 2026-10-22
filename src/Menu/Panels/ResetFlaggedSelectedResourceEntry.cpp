#include <globaldefs.h>
ARM
struct GameState;struct List;struct Entry {char pad[4];short x,y;char pad2[13];unsigned char flags;};
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(GameState*);void SpriteAnimation_AdvanceAllTracks(char*,unsigned);void SpriteAnimation_StartTrack(void*, unsigned);Entry* SpriteAnimation_FindTrackByKey(List*,unsigned);void SpriteAnimation_SetTrackOamStartIndex(void*,int,unsigned char);void SpriteAnimation_SubmitAllTrackFrames(unsigned char*);}
// Original: arm9/ov023 @ 0x021ECF78; symbol: func_ov023_021ecf78; size: 0x9C.
extern "C" void ResetFlaggedSelectedResourceEntry(unsigned char* p){
if(!(*(unsigned short*)(p+0x438)&0x80))return;
GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
SpriteAnimation_SetTrackOamStartIndex(*(void**)(p+0x42c),0,0x40);
SpriteAnimation_StartTrack(*(void**)(p+0x42c),0);
Entry* entry=SpriteAnimation_FindTrackByKey(*(List**)(p+0x42c),0);
if(entry)entry->flags|=8;
unsigned ticks=_ZNK9GameState12GetTickCountEv(game);
SpriteAnimation_AdvanceAllTracks(*(char**)(p+0x42c),ticks);
short x=*(short*)(p+0x448);
entry=SpriteAnimation_FindTrackByKey(*(List**)(p+0x42c),0);
if(entry){entry->x=x;entry->y=0x24;}
SpriteAnimation_SubmitAllTrackFrames(*(unsigned char**)(p+0x424));
}
