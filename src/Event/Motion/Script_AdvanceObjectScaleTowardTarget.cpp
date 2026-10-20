#include <globaldefs.h>
#include <System/Matrix.h>
#include <GameState/GameState.h>
ARM
struct Vec {int x,y,z;};
extern "C" int Graphics_ReadIndexedObjectScale(unsigned char*,int,Vec*);
extern "C" int CutsceneActor_SetIndexedScaleFromVector(unsigned char*,int,Vector3fix);
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char *AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
void Vector3fixMultiplyScalar(const Vector3i*,int,Vector3i*);
// Original: arm9/ov001 @ 0x02159BBC; symbol: func_ov001_02159bbc; size: 0x138.
// Initializes scale velocity toward a target, then applies half-tick-scaled increments.
extern "C" int Script_AdvanceObjectScaleTowardTarget(char *command,char *session) {
 GameState *game=GameState::GetInstance();
 int tick=game->GetTickCount()<<12;
 if(*(int*)(session+0x5c)>=(*(int*)(command+0x10)<<1)) {
  *(int*)(session+0x5c)=0;return 0;
 }
 if(*(int*)(session+0x5c)<=0) {
  Vector3fix delta,current;
  Graphics_ReadIndexedObjectScale(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(session+0x70),(Vec*)&current);
  int duration=*(int*)(command+0x10)<<12;
  Vector3fix_Subtract((Vector3fix*)(command+4),&current,&delta);
  *(int*)(session+0x108)=fix32_Divide(delta.x,duration);
  *(int*)(session+0x10c)=fix32_Divide(delta.y,duration);
  *(int*)(session+0x110)=fix32_Divide(delta.z,duration);
 } else {
  Vector3fix delta=*(Vector3fix*)(session+0x108);
  Vector3fixMultiplyScalar(&delta,fix32_Divide(tick,0x2000),&delta);
  Vector3fix current;
  Graphics_ReadIndexedObjectScale(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(session+0x70),(Vec*)&current);
  Vector3fix_Add(&current,&delta,&current);
  CutsceneActor_SetIndexedScaleFromVector(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage,*(int*)(session+0x70),current);
 }
 *(int*)(session+0x5c)+=game->GetTickCount();
 return 1;
}
