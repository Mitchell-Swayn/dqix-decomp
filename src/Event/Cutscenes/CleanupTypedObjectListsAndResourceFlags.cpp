#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Resource/GameResources.h>
ARM
struct Entry; struct Table; struct T;
extern "C" void GameState_ClearObjectByIndex(GameState*,int);
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" void* ActorPool_GetSpriteResourceDirectory(void*);
extern "C" unsigned *ActorPool_GetActiveSlot(unsigned**,unsigned);
extern "C" void ActorPool_SetSlot(int,unsigned,unsigned);
extern "C" Entry* ActorPool_FindActiveActorById(Table*,unsigned);
extern "C" void Resource_ReleaseNamedGraphicCacheEntry(Table*,int);
extern "C" unsigned Resource_FindActiveGraphicCacheEntryByName(T*,const char*);
extern "C" void Object_ClearThreeWordsAndResetContainer(char*);
extern "C" void GameState_InitializeFourWordStateAtIndex(int);
extern "C" char CleanupTypedObjectListsAndResourceFlags_TextStand[];
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
struct PackedType { unsigned char type:4; unsigned char rest:4; };
struct PackedFlags { unsigned flags:27; unsigned remaining:5; };
// Original: arm9/ov001 @ 0x02154974; symbol: func_ov001_02154974; size: 0x2F0.
// Restores animations for referenced objects, clears typed list entries, and releases resource flags.
extern "C" void CleanupTypedObjectListsAndResourceFlags(char *self) {
 GameState *game=GameState::GetInstance();
 void *container=ActorPool_GetGlobalInstance();
 GameResources *resources=GameResources_GetInstance();
 char *node=P(self,0xd4);
 while(node) {
  char *record=P(self,0xd0);
  while(record) {
   if(B(record,1)==B(node,0)) {
    unsigned type=((PackedType*)record)->type;
    if(type==0 || type==1 || type==9 || type==11 || type==12 || type==13 || type==10 || type==4) {
     Object3D *object=(Object3D*)game->GetGameObjectByIndex(S(record,2));
     if(object) {
      int flags=B(object,0x19);
      const char *animation=*(const char**)((char*)object+0x14);
      object->RemoveAnimationPackageByID(3);
      if(!object->SetAnimationByName(animation,flags)) object->SetAnimationByName(CleanupTypedObjectListsAndResourceFlags_TextStand,0);
     }
    }
    break;
   }
   record=P(record,0x34);
  }
  node=P(node,0x28);
 }
 node=P(self,0xd0);
 while(node) {
  switch(((PackedType*)node)->type) {
  case 5: {
   Entry *entry=ActorPool_FindActiveActorById((Table*)container,W(node,8));
   if(entry) W(entry,0)&=~0x10000;
   break;
  }
  case 4: {
   GameState_ClearObjectByIndex(game,S(node,2));
   Entry *entry=ActorPool_FindActiveActorById((Table*)container,W(node,8));
   if(entry && P(entry,0x18)) {
    B(P(entry,0x18),0xd4)&=~1;
    W(entry,0)&=~0x10000;
   }
   break;
  }
  case 2: case 6: case 7: case 8:
   if(game->GetGameObjectByIndex(S(node,2))) GameState_ClearObjectByIndex(game,S(node,2));
   break;
  case 3: {
   unsigned *object=ActorPool_GetActiveSlot((unsigned**)container,S(node,2));
   if(object) {
    void *table=ActorPool_GetSpriteResourceDirectory(container);
    Resource_ReleaseNamedGraphicCacheEntry((Table*)table,Resource_FindActiveGraphicCacheEntryByName((T*)table,node+0x11));
    Object_ClearThreeWordsAndResetContainer((char*)object);
    ActorPool_SetSlot((int)container,S(node,2),0);
   }
   break;
  }
  case 0: case 1: case 9: case 10: case 11: case 12: case 13: break;
  }
  GameState_InitializeFourWordStateAtIndex(B(node,1));
  node=P(node,0x34);
 }
 if(((PackedFlags*)(self+0xf8))->flags) {
  if(((PackedFlags*)(self+0xf8))->flags&1) GameResources_ClearSecondaryFlags((int)resources,8);
  if(((PackedFlags*)(self+0xf8))->flags&2) GameResources_ClearSecondaryFlags((int)resources,16);
  if(((PackedFlags*)(self+0xf8))->flags&4) {
   for(int i=0;i<4;++i) {
    Object3D *object=(Object3D*)game->GetGameObjectByIndex(i);
    if(object) object->DisableFlag(1);
   }
  }
  if(((PackedFlags*)(self+0xf8))->flags&8) GameResources_ClearSecondaryFlags((int)resources,0x400);
  if(((PackedFlags*)(self+0xf8))->flags&0x20) {
   void *global=ActorPool_GetGlobalInstance();
   W(global,0x98)&=~2;
  }
 }
}
