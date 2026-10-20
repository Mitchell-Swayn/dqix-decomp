#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void* Zone3D_GetMainInstance();
struct Vec { int x,y,z; };
extern "C" int Zone3D_FindGroundHeightBelowPosition(void*,const Vec*);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec*,int,Vec*);
extern "C" void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(const Vec*,int,Vec*);
extern "C" void Vector3fix_Add(const Vec*,const Vec*,Vec*);
extern "C" void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);
extern "C" void Graphics_SetIndexedObjectRegularAnimation(void*,unsigned,void*,int,int);
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x021592BC; symbol: func_ov001_021592bc; size: 0x14C.
extern "C" int World_UpdateTimedPositionInterpolation(char* event,char* object) {
 void* game=_ZN9GameState11GetInstanceEv();
 int tick=_ZNK9GameState12GetTickCountEv(game)<<12;
 int elapsed=*(int*)(object+0x48);
 int duration=*(int*)(event+0x10);
 if(elapsed>=duration*2) {
 if(*(int*)(event+0x14)==0) memcpy(object+0x74,event+4,12);
 else if(*(int*)(event+0x14)==1) {
 *(int*)(object+0x74)=*(int*)(event+4);
 *(int*)(object+0x7c)=*(int*)(event+12);
 }
 if(event+0x1c) Graphics_SetIndexedObjectRegularAnimation(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(unsigned*)(object+0x70),event+0x1c,0,0);
 *(int*)(object+0x48)=0;
 return 0;
 }
 if(elapsed<=0) {
 Vec difference;
 Vector3fix_Subtract((Vec*)(event+4),(Vec*)(object+0x74),&difference);
 _Z22Vector3fixDivideScalarPK8Vector3iiPS_(&difference,*(int*)(event+0x10)<<13,(Vec*)(object+0x94));
 } else {
 Vec delta=*(Vec*)(object+0x94);
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&delta,tick,&delta);
 if(*(int*)(event+0x14)==0) Vector3fix_Add((Vec*)(object+0x74),&delta,(Vec*)(object+0x74));
 else if(*(int*)(event+0x14)==1) {
 Vector3fix_Add((Vec*)(object+0x74),&delta,(Vec*)(object+0x74));
 *(int*)(object+0x78)=Zone3D_FindGroundHeightBelowPosition(Zone3D_GetMainInstance(),(Vec*)(object+0x74));
 }
 }
 *(int*)(object+0x48)+=_ZNK9GameState12GetTickCountEv(game);
 return 1;
}
