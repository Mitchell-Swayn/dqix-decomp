#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
typedef unsigned int undefined4;
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*);
extern "C" void BattleMenu_ResetMemberCommandState(char*);
// Original: arm9/ov000 @ 0x02171138; symbol: BattleMenu_InitializeMemberCommandFromActor; size: 0xD8.
// Refreshes an indexed object's display record while preserving four layout halfwords.
extern "C" void BattleMenu_InitializeMemberCommandFromActor(char* self){
 if(*(int*)(self+0x4c)<0)return;
 GameState* game=GameState::GetInstance();
 GameObject* object=GameState_GetObjectWithFlag100(game,*(int*)(self+0x4c));if(!object)return;
 char* record=(char*)GameObject_GetLinkedIndexedState((int)object);if(!record)return;
 TextSprite_FormatAndUpdateTextReference((unsigned char*)self+0x68,*(const char**)((char*)object+0x134));
 *(int*)(self+0x5c)=2;self[0x440]=*(int*)(record+0x950);
 self[0x43f]=*(unsigned short*)(record+0x16c+*(int*)(record+0x950)*2);
 short first=*(short*)(self+0xc);short second=*(short*)(self+8);short third=*(short*)(self+0xe);short fourth=*(short*)(self+0xa);
 BattleMenu_ResetMemberCommandState(self+8);
 *(short*)(self+0xc)=first;*(short*)(self+8)=second;*(short*)(self+0xe)=third;*(short*)(self+0xa)=fourth;
 *(int*)(self+0x28)=*(int*)(record+0xa8);self[0x1c]=0;*(short*)(self+0x82)=0;*(short*)(self+0x84)=0;self[0x86]=0;
 if(*(int*)(self+0x4c)==GameState_ReadProtagonistObjectIndex(game))((unsigned char*)self)[0x24]|=2;
 ((unsigned char*)self)[0x24]&=~1;
}
