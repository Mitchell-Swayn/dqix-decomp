#include <globaldefs.h>
ARM
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameResources_GetInstance();void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);void Field_CreatePartyObjectAndEquipmentSlots(void*,int,int,int,int);void* Network_GetConnectionManager();void Network_ActivateMember(void*,int);}
// Original: arm9/ov017 @ 0x021B0A7C; symbol: GameState_CreateMissingFlaggedPartyObjects; size: 0xd0.
extern "C" void GameState_CreateMissingFlaggedPartyObjects(unsigned char* self){unsigned char* flags;void* state=_ZN9GameState11GetInstanceEv();void* resources=GameResources_GetInstance();flags=self+27;for(int i=0;i<4;++i)if(flags[i]&&!_ZN9GameState20GetGameObjectByIndexEi(state,i)){if(flags[i]==1)Field_CreatePartyObjectAndEquipmentSlots(resources,i,512,0,0);else Field_CreatePartyObjectAndEquipmentSlots(resources,i,4096,0,0);}void* connection=Network_GetConnectionManager();for(int i=0;i<4;++i)if((self+i)[27]==1)Network_ActivateMember(connection,i);}
