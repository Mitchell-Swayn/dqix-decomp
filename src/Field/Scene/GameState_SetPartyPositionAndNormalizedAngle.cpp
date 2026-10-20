#include <globaldefs.h>
ARM
#include <System/Matrix.h>
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* GameState_ReadUnkF8(void*);
unsigned char* Zone3D_GetMainInstance();
void* GameResources_GetInstance();
void* GameState_GetIndexList(void*);
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
int GameObject_GetLadderTraversalActive(void*);
Vector3fix _ZN12ZoneFeatures9GetVectorEv(void*);
short _ZN12ZoneFeatures8GetAngleEv(void*);
int _Z22fix32ReduceAngle0To2Pii(int);
void World_InitializeObjectFromLinkedZoneFeatures(void*,unsigned,const Vector3fix*,int);
}
struct PartyIndexList { char pad[0xf78]; unsigned char ids[4],count,extra; };
// Original: arm9/ov017 @ 0x0219C598; symbol: func_ov017_0219c598; size: 0x15C.
extern "C" void GameState_SetPartyPositionAndNormalizedAngle(const Vector3fix* input,const short* inputAngle,int force) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* saved=GameState_ReadUnkF8(state);
 unsigned char* global=Zone3D_GetMainInstance();
 GameResources_GetInstance();
 PartyIndexList* list=(PartyIndexList*)GameState_GetIndexList(state);
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(saved[0xa] && !force) return;
 if(saved[0x67] && GameObject_GetLadderTraversalActive(object)) return;
 Vector3fix position;
 int angle;
 if(input) {
  position=*input;
  if(inputAngle) angle=*inputAngle;
 } else if(saved[7]) {
  position=*(Vector3fix*)(saved+0x10);
  angle=*(short*)(saved+0x1c);
 } else {
  position=_ZN12ZoneFeatures9GetVectorEv(global+0x6c);
  angle=_ZN12ZoneFeatures8GetAngleEv(global+0x6c);
 }
 angle=_Z22fix32ReduceAngle0To2Pii(angle);
 for(int i=0;i<list->count;i++) {
  void* party=_ZN9GameState21GetPartyMemberByIndexEi(state,list->ids[i]);
  if(party) World_InitializeObjectFromLinkedZoneFeatures(party,*(unsigned short*)global,&position,angle);
 }
 if(list->extra) {
  void* party=_ZN9GameState21GetPartyMemberByIndexEi(state,0xce);
  if(party) World_InitializeObjectFromLinkedZoneFeatures(party,*(unsigned short*)global,&position,angle);
 }
}
