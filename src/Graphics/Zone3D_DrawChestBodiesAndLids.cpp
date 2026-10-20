#include <globaldefs.h>
#pragma optimize_for_size on
#include "Graphics/Model3D.h"
#include "Graphics/NSBXX/RenderConfig.h"
extern "C" void __clear(void*,unsigned);
// Original data: arm9/main @ 0x20e6e2c; symbol: data_020e6e2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 001000000010000000100000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e6e38; symbol: data_020e6e38.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000008b06000094faffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const Vector3i Zone3DDrawChestBodiesAndLids_UnknownRoleInitializedBytes,Zone3DDrawChestBodiesAndLids_UnknownRoleInitializedBytes_Variant2;
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(Matrix3x3*);
struct RenderRecord {Vector3i pos;short y,x;char reserved[6];unsigned char visible,pass;char tail[12];};
// Original: arm9/main @ 0x02017540; symbol: func_02017540; size: 0x23C.
extern "C" ARM void Zone3D_DrawChestBodiesAndLids(char* self)
{
 if(!*(int*)(self+0x274c))return;
 NSBXXInternalModel* models[3];__clear(models,12);models[0]=*(NSBXXInternalModel**)(self+0x4ec);models[1]=*(NSBXXInternalModel**)(self+0x598);
 NSBXXTex* textures[3];__clear(textures,12);textures[0]=((Model3D*)(self+0x498))->GetTEX0();textures[1]=((Model3D*)(self+0x544))->GetTEX0();
 Vector3i scale=Zone3DDrawChestBodiesAndLids_UnknownRoleInitializedBytes;RenderConfig::SetObjectScale(&scale);unsigned* offsets=(unsigned*)(self+0x5f0);
 for(int pass=0;pass<2;pass++){
  NSBXXInternalModel** model=models;NSBXXTex** texture=textures;
  while(*texture&&*model){NSBXX_Tex_WritePaletteVRAMOffset(*texture,*offsets);NSBXX_DetachTexturePaletteFromModel(*model);NSBXX_AttachTexturePaletteToModel(*model,*texture);offsets++;model++;texture++;}
  RenderRecord* item=*(RenderRecord**)(self+0x47c);
  for(int i=0;i<*(unsigned char*)(self+0x477);item++,i++){
   if(item->visible&&((pass==0&&!item->pass)||(pass==1&&item->pass))){
    Vector3i pos=item->pos;short y=item->y,x=item->x;RenderConfig::SetObjectPosition(&pos);
    int cy=fix32cos(y),sy=fix32sin(y);Matrix3x3 rotationY;MTX_RotY33_(&rotationY,sy,cy);
    RenderConfig_CopyTransformAndClearFlagsA4(&rotationY);RenderConfig::SubmitToFifo();((Model3D*)(self+0x498))->DrawMeshWithMaterial(true,0,0,1);
    Vector3i offset=Zone3DDrawChestBodiesAndLids_UnknownRoleInitializedBytes_Variant2;Mat3x3_ApplyToVector(&offset,&rotationY,&offset);Vector3fix_Add(&pos,&offset,&pos);RenderConfig::SetObjectPosition(&pos);
    int cx=fix32cos(x),sx=fix32sin(x);Matrix3x3 rotationX,combined;MTX_RotX33_(&rotationX,sx,cx);Mat3x3_Multiply(&rotationX,&rotationY,&combined);
    RenderConfig_CopyTransformAndClearFlagsA4(&combined);RenderConfig::SubmitToFifo();((Model3D*)(self+0x544))->DrawMeshWithMaterial(true,0,0,1);
   }
  }
 }
}
