#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState14GetProtagonistEv(void*);extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsParentOrOffline(void*);extern "C" char* Zone3D_GetMainInstance();extern "C" char* GameState_GetSerializedProgressState();extern "C" char* Network_GetCommandRecordPool();extern "C" char* GameResources_GetInstance();extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);extern "C" unsigned World_TestSelectedZoneInstanceFlagWithStateInversion(void*);extern "C" int ZoneState0840_TestCurrentZoneRequiresModeRefresh(void*);extern "C" int Script_MergeSynchronizedProgressState(void*);extern "C" int GameState_AlignRequestedDayTimerToTransition(void*,int,int);
// Original: arm9/ov017 @ 0x0219BDDC; symbol: Network_TestZoneOrMatchingObjectRecordChanges; size: 0xF4.
extern "C" int Field_MergeClientStateAndTestZoneRefresh(unsigned char* out){GameResources_GetInstance();void* game=_ZN9GameState11GetInstanceEv();void* connection=Network_GetConnectionManager();void* records=GameState_GetSerializedProgressState();char* zone=Zone3D_GetMainInstance();void* object=_ZN9GameState20GetGameObjectByIndexEi(game,0);void* protagonist=_ZN9GameState14GetProtagonistEv(game);if(Network_IsParentOrOffline(connection))return 0;if(!object)return 0;if(!protagonist)return 0;int result=0;if(World_TestSelectedZoneInstanceFlagWithStateInversion(zone))result=1;else if(ZoneState0840_TestCurrentZoneRequiresModeRefresh(zone+0x840)){result=1;*out=1;}else{unsigned short first=_ZNK8Object3D10GetField06Ev(object);if(first!=_ZNK8Object3D10GetField06Ev(protagonist))return result;if(Script_MergeSynchronizedProgressState(records))result=1;if(GameState_AlignRequestedDayTimerToTransition(P(zone,8),0,0))result=1;}return result;}
