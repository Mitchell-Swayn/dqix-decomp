#include <globaldefs.h>
ARM
struct Names {const char* names[8];};
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov025 @ 0x21eef58; symbol: data_ov025_021eef58.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 95f41e02a2f41e027df41e0283f41e0278f41e0289f41e028ff41e029bf41e02.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" Names CombatTestSelectedObjectAnimationReady_UnknownRoleDataReferences;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" unsigned Camera_GetObjectFlags(void*);
extern "C" char* BoneTrackingCamera_GetSourceObject(void*);
extern "C" int Combat_DispatchSelectionProcedure(void*,int,int,int*);
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" bool _ZNK8Object3D19HasAnimationStoppedEv(void*);
extern "C" bool _ZNK8Object3D22HasAnimationReachedEndEv(void*);
extern "C" bool _ZNK8Object3D7GetFlagEi(void*,int);
extern "C" int strcmp(const char*,const char*);
// Original: arm9/ov025 @ 0x021E4868; symbol: func_ov025_021e4868; size: 0x178.
extern "C" bool Combat_TestSelectedObjectAnimationReady(char* record,int selection,int unused,void* context) {
 if(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[7]&4)return false;
 void* game=_ZN9GameState11GetInstanceEv();
 char* object;
 int kind=*(unsigned char*)(record+8);
 if(kind==25) {
 void* special=GameState_ReadUnknownB0(game);
 if(Camera_GetObjectFlags(special)&16)object=BoneTrackingCamera_GetSourceObject(special);
 else return true;
 } else {
 int indices[8];
 if(Combat_DispatchSelectionProcedure(context,selection,kind,indices)!=1)return true;
 object=_ZN9GameState20GetGameObjectByIndexEi(game,indices[0]);
 }
 if(!object)return true;
 int threshold=*(short*)(record+10);
 if(threshold<4096)return *(int*)(object+0x24)>=threshold;
 if(_ZNK8Object3D19HasAnimationStoppedEv(object)||_ZNK8Object3D22HasAnimationReachedEndEv(object))return true;
 if(_ZNK8Object3D7GetFlagEi(object,0x40000))return true;
 if(!(*(unsigned char*)(object+0x19)&1)) {
 const char* name=*(const char**)(object+0x14);
 if(name) {
 unsigned i; Names names=CombatTestSelectedObjectAnimationReady_UnknownRoleDataReferences; const char** p=names.names;
 for(i=0;i<8;i++,p++)if(!strcmp(name,*p))return true;
 }
 }
 return false;
}
