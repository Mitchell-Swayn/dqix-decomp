#include <globaldefs.h>
ARM
extern "C" int ComputeObjectPositionOffsetFromIndexedObjectCenter(...);
extern "C" int Network_RefreshAdvertisedPartyCount(...);
extern "C" int GameState_GetFieldOrbitCamera(...);
extern "C" int GameState_GetIndexList(...);
extern "C" int GameState_ReadProtagonistObjectIndex(...);
extern "C" int Network_GetConnectionManager(...);
extern "C" int GameObject_GetLadderTraversalState(...);
extern "C" int GameObject_GetLadderTraversalActive(...);
extern "C" int Camera_GetFollowTargetIndex(...);
extern "C" int Camera_SetFollowTargetIndex(...);
extern "C" int _ZN8Object3D11DisableFlagEi(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState14GetProtagonistEv(...);
extern "C" int _ZN9GameState20GetGameObjectByIndexEi(...);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" int Field_BuildMemberFollowChainAndConfigureMovement(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
extern "C" char PartyMenu_DispatchActionEffects_ItemPropertyDispatchRecords_Copy4[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x02191108; symbol: GameState_RebuildActiveIndicesAndRetargetAttachedObject.
extern "C" void Field_RebuildActiveRosterAndCameraTarget(int unused,int mode,int first,int second,int reposition){
int game=_ZN9GameState11GetInstanceEv();if(!_ZN9GameState14GetProtagonistEv(game))return;char*object=C(_ZN9GameState20GetUnknownGameObjectEv(game));if(object&&GameObject_GetLadderTraversalActive(object)){B(C(GameObject_GetLadderTraversalState(object)),82)=1;return;}int indices[4];int count=0;Field_BuildMemberFollowChainAndConfigureMovement(GameState_ReadProtagonistObjectIndex(game),indices,&count,mode,first,second);int selected=indices[0];object=C(_ZN9GameState20GetGameObjectByIndexEi(game,selected));if(object)_ZN8Object3D11DisableFlagEi(object,128);object=C(GameState_GetFieldOrbitCamera(game));if(object){int old=Camera_GetFollowTargetIndex(object);if(old!=201&&old!=202){Camera_SetFollowTargetIndex(object,selected);if(reposition&&old!=selected)ComputeObjectPositionOffsetFromIndexedObjectCenter(object);}}char*list=C(GameState_GetIndexList(game));for(int i=0;i<count;i++)B(list+i,3960)=indices[i];B(list,3964)=count;Network_RefreshAdvertisedPartyCount(Network_GetConnectionManager());
}
