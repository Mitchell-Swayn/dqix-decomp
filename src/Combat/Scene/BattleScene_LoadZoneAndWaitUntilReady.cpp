#include "globaldefs.h"
#include "std_library_functions.h"
// Original: arm9/ov000 @ 0x02166880; symbol: InitializeZoneResourcesAndWaitForUpdate.
#define W(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))

extern "C" unsigned BattleScene_EnableFlags(...);
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned GameState_GetFieldAddress468(...);
extern "C" unsigned ZoneTable_FindEntryById(...);
extern "C" unsigned Network_GetConnectionManager(...);
extern "C" unsigned Object_IgnoreNonNullHook(...);
extern "C" unsigned ZoneTransition_HasOptionalIdentifier(...);
extern "C" unsigned PowerManagement_HandleLidStateAndResourceTransitions(...);
extern "C" unsigned Zone3D_GetMainInstance(...);
extern "C" unsigned _Z19GetCurrentTimestampv(...);
extern "C" unsigned _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" unsigned _ZN16BackgroundLoader14RemoveAllLocksEv(...);
extern "C" unsigned _ZN6Zone3D10SwitchZoneEt(...);
extern "C" unsigned _ZN6Zone3D19InitializeResourcesEP13SafeAllocatorPv(...);
extern "C" unsigned _ZN6Zone3D6UpdateEv(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState14GetProtagonistEv(...);
extern "C" ARM void BattleScene_LoadZoneAndWaitUntilReady(unsigned self){GameResources_GetInstance();unsigned state=_ZN9GameState11GetInstanceEv();unsigned loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN9GameState14GetProtagonistEv(state);Network_GetConnectionManager();_ZN6Zone3D19InitializeResourcesEP13SafeAllocatorPv(self+0xec8,self+8,self+0x36f0);Zone3D_GetMainInstance();if(ZoneTransition_HasOptionalIdentifier(W(self,0x2a0))&&H(W(self,0x2a0),0x20))H(W(self,0x2a0),2)=H(W(self,0x2a0),0x20);if(!ZoneTable_FindEntryById(GameState_GetFieldAddress468(state),H(W(self,0x2a0),2))||H(W(self,0x2a0),2)==30000)H(W(self,0x2a0),2)=30116;_ZN6Zone3D10SwitchZoneEt(self+0xec8,H(W(self,0x2a0),2),0);_Z19GetCurrentTimestampv();for(;;){PowerManagement_HandleLidStateAndResourceTransitions();_ZN16BackgroundLoader14RemoveAllLocksEv(loader);_ZN6Zone3D6UpdateEv(self+0xec8);if(!W(self,0x12ec))break;Object_IgnoreNonNullHook(W(self,0x12ec));}BattleScene_EnableFlags(self,16);}