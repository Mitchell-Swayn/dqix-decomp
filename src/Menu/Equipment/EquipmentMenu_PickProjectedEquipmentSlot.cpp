#include <globaldefs.h>
#include <Graphics/Vector.h>
#include <GameState/GameState.h>
ARM
struct Words3;
extern "C" {
void* _ZN9GameState11GetInstanceEv();ARM GameResources* GameResources_GetInstance();unsigned Field_GetSharedSubscreenInstance(void*);
void* GameState_ReadUnknownB0(GameState*);
void *Menu_GetActiveCharacterPreviewObject(void *);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const Words3*,int*,int*);
double _dsqrt(double);
// Original data: arm9/ov005 @ 0x215cc24; symbol: data_ov005_0215cc24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000d00000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern Vector3fix EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov005 @ 0x215cc2c; symbol: data_ov005_0215cc2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000800100000000000000000000000000000000000080ffff0070000000600000006000000070000000400000000000000070000000000000 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern Vector3fix EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov005 @ 0x215cbf4; symbol: data_ov005_0215cbf4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0302060001050404.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern unsigned char EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov005 @ 0x021586C4; symbol: func_ov005_021586c4; size: 0x1B4.
// Projects eight rotated points, keeps those within twenty pixels, then chooses greatest table depth.
extern "C" unsigned EquipmentMenu_PickProjectedEquipmentSlot(void* unused,int x,int y){
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 char* resource=(char*)GameResources_GetInstance();
 char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resource+0x3708));
 void* camera;int i;int member=*(int*)(object+0x4fc);
 if(x>0 && x<128){
  camera=GameState_ReadUnknownB0(game);
  char* transform=(char*)Menu_GetActiveCharacterPreviewObject(object);
  Vector3fix points[8];int screenX[8],screenY[8];
  Matrix4x3 rotation=RotationMatrixY(*(int*)(transform+0x54));
  for(i=0;i<8;i++){
   Mat4x3_ApplyToVector(&EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes_Variant2[i],&rotation,&points[i]);
   Graphics_ConvertCopiedWorldVectorToScreenCoordinates(camera,(Words3*)&points[i],&screenX[i],&screenY[i]);
  }
  GameState_GetObjectWithFlag100(game,member);
  int count=0;float radius[8];int candidates[8];
  for(int i=0;i<8;i++){
   radius[i]=20.0f;
   int dy=y-screenY[i],dx=x-screenX[i];
   if((float)_dsqrt((double)(dx*dx+dy*dy))<radius[i])candidates[count++]=i;
  }
  if(count>0){
   int selected=candidates[0];int depth=EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes_Variant3[selected].x;
   for(int i=1;i<count;i++){int candidate=candidates[i];int z=EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes_Variant3[candidate].x;if(depth<z){selected=candidate;depth=z;}}
   return EquipmentMenuPickProjectedEquipmentSlot_UnknownRoleInitializedBytes[selected];
  }
 }
 return 255;
}
