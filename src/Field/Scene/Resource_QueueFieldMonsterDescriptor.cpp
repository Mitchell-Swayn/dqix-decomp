#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
extern "C" void OverlayLoader_PushPrimarySelection(unsigned int);
extern "C" void Grotto_InitializeMonsterMessageCommand(signed char*);
extern "C" void Grotto_SetMonsterMessageOverlayRestoreRequired(void*,unsigned char);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*,unsigned int);
extern "C" void FieldBattle_InitializeCommand(unsigned char*);
extern "C" void Field_InitializeEncounterDescriptor(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" unsigned char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void*);
extern "C" int FieldBattle_ResolveMonsterAndTreasureMapFlags(unsigned char*,int);
extern "C" unsigned int Resource_EncodeTypeAndKeyCode(unsigned int,unsigned int,unsigned int);
extern "C" void FieldBattle_ConfigureEncounterRequest(unsigned char*,unsigned char*);
// Original: arm9/ov017 @ 0x02196E58; symbol: func_ov017_02196e58; size: 0x170.
// Initializes and queues monster-associated nodes and descriptor with optional grotto key.
extern "C" void Resource_QueueFieldMonsterDescriptor(unsigned char *r){
 GameState *game=(GameState*)_ZN9GameState11GetInstanceEv();char *lighting=_ZN15LightingManager11GetInstanceEv();
 char *monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(game,*(unsigned short*)(r+0x36b6));if(!monster)return;
 OverlayLoader_PushPrimarySelection(4);
 Grotto_InitializeMonsterMessageCommand(*(signed char**)(r+0x3b74));
 *(unsigned short*)(*(unsigned char**)(r+0x3b74)+8)=*(unsigned short*)(r+0x36b6);
 Grotto_SetMonsterMessageOverlayRestoreRequired(*(void**)(r+0x3b74),1);
 LinkedQueue_AppendAndMarkActive(*(unsigned int**)(r+0x36fc),*(unsigned int*)(r+0x3b74));
 FieldBattle_InitializeCommand(*(unsigned char**)(r+0x3718));
 unsigned char descriptor[24];Field_InitializeEncounterDescriptor(descriptor);descriptor[0]=1;descriptor[1]=GameState_ReadProtagonistObjectIndex(game);
 *(unsigned short*)(descriptor+4)=*(unsigned short*)(monster+0x16a);*(unsigned short*)(descriptor+2)=*(unsigned short*)(r+0x36b6);
 descriptor[18]=*(int*)(lighting+0x98);
 unsigned char *zone=(unsigned char*)Zone3D_GetMainInstance();void *active=0;if(zone)active=zone+0x23ec;
 unsigned char *detail=0;if(active)detail=_ZN17ActiveGrottoClass15GetDetailedDataEv(active);
 FieldBattle_ResolveMonsterAndTreasureMapFlags(descriptor,*(unsigned short*)(descriptor+2));
 if(descriptor[12]){if(detail)*(unsigned*)(descriptor+8)=Resource_EncodeTypeAndKeyCode(1,*(unsigned short*)(detail+0x54),0);}
 else if(descriptor[13]&&detail)*(unsigned*)(descriptor+8)=Resource_EncodeTypeAndKeyCode(2,detail[0x4c],*(unsigned*)(detail+0x84));
 FieldBattle_ConfigureEncounterRequest(*(unsigned char**)(r+0x3718),descriptor);
 LinkedQueue_AppendAndMarkActive(*(unsigned int**)(r+0x36fc),*(unsigned int*)(r+0x3718));
}
