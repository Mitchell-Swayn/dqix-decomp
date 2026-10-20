#include <globaldefs.h>
ARM
struct GameState;struct MapGameObject;struct GameObject;struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" void* Zone3D_GetMainInstance();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" GameObject* GameState_GetFieldVisualObject(GameState*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* GameState_GetSerializedProgressState();
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char**);
extern "C" int GameObject_HasPositiveTransitionValueOrTarget(char*);
extern "C" int GameResources_GetMaskedSecondaryFlags(void*,int);
extern "C" int GameObject_GetEncounterControlMode(int);
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" void* _Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void*,int,int);
extern "C" void FieldBattle_InitializeCommand(unsigned char*);
extern "C" void Field_InitializeEncounterDescriptor(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" unsigned GameState_AllocateUnusedHighIdentifier(void);
extern "C" void* GameObject_GetFloorContactDescriptor(void*);
extern "C" unsigned short ActorDescriptor_DecodeThirdHalfwordDecimalCode(unsigned short*);
extern "C" int Field_RollEncounterOpeningOutcome(int);
extern "C" int FieldBattle_ResolveMonsterAndTreasureMapFlags(unsigned char*,int);
extern "C" void FieldBattle_ConfigureEncounterRequest(unsigned char*,unsigned char*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
// Original: arm9/ov017 @ 0x02196C4C; symbol: func_ov017_02196c4c; size: 0x20C.
// Gates a timed type-ten descriptor on player, queue, zone and indexed-bit conditions.
extern "C" int TryQueueTimedTypeTenDescriptor(unsigned char *r){
 GameState *game=(GameState*)_ZN9GameState11GetInstanceEv();Network_GetConnectionManager();
 unsigned char *zone=(unsigned char*)Zone3D_GetMainInstance();unsigned char *entry=*(unsigned char**)(r+0x36f8);
 char *player=(char*)_ZN9GameState20GetUnknownGameObjectEv(game);GameObject *object=GameState_GetFieldVisualObject(game);
 char *lighting;unsigned char *paired=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
 unsigned char *bits=(unsigned char*)GameState_GetSerializedProgressState();lighting=_ZN15LightingManager11GetInstanceEv();
 if(!LinkedQueue_IsEmpty(*(int**)(r+0x36fc)))return LinkedQueue_GetFrontKindOrInvalid(*(char***)(r+0x36fc))==0x45?0:2;
 if(!entry)return 2;
 if(GameObject_HasPositiveTransitionValueOrTarget(player))return 2;
 if(*(unsigned*)(player+0x18c)&1)return 2;
 if(GameResources_GetMaskedSecondaryFlags(r,0x10))return 2;
 if(paired[3])return 2;
 if(GameObject_GetEncounterControlMode((int)player))return 0;
 if(*(unsigned short*)entry!=10000)return 0;
 if(!BitArray_ReadNonnegativeIndexMask(bits,bits+0x8c,0x2b))return 0;
 int expired=0;if(*(int*)(zone+0x2794)<=0){expired=1;*(int*)(zone+0x2794)=_Z17NextRandomBetweenP6Randomii(_Z11GetBTRandomv(),30,100);}
 if(!expired)return 0;
 FieldBattle_InitializeCommand(*(unsigned char**)(r+0x3718));
 unsigned char descriptor[24];Field_InitializeEncounterDescriptor(descriptor);descriptor[0]=1;descriptor[1]=GameState_ReadProtagonistObjectIndex(game);
 *(unsigned short*)(descriptor+4)=GameState_AllocateUnusedHighIdentifier();*(unsigned short*)(descriptor+2)=0xffff;descriptor[14]=1;
 *(unsigned short*)(descriptor+16)=ActorDescriptor_DecodeThirdHalfwordDecimalCode((unsigned short*)GameObject_GetFloorContactDescriptor(object));descriptor[15]=Field_RollEncounterOpeningOutcome(0);
 FieldBattle_ResolveMonsterAndTreasureMapFlags(descriptor,*(unsigned short*)(descriptor+2));descriptor[18]=*(int*)(lighting+0x98);
 FieldBattle_ConfigureEncounterRequest(*(unsigned char**)(r+0x3718),descriptor);
 LinkedQueue_AppendAndMarkActive(*(unsigned**)(r+0x36fc),*(unsigned*)(r+0x3718));return 1;
}
