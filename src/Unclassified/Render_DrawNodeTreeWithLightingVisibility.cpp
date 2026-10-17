#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/LightingManager.h>
#include <Graphics/Model3D.h>
#include <Graphics/NSBXX/RenderConfig.h>
#include <World/Object3D.h>
#include <System/Matrix.h>
struct DrawDescriptor {short unknown,id;unsigned short unknown4,visibility;};
struct DrawAsset {short kind,pad;Model3D* model;};
struct DrawAlpha {signed char value:7; signed char marked:1;};
struct DrawNode {
 unsigned short unknown,flags;DrawAlpha alpha;char pad5;short angle;
 Vector3fix position,scale;DrawDescriptor* descriptor;DrawAsset* asset;
 unsigned unknown28;DrawNode* child;DrawNode* next;unsigned unknown34;
 short angleOffset;char unknown3a[0x1a];Object3D* object;
};
struct OwnerMode {char unknown[12];unsigned char value:4;unsigned char rest:4;};
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(Matrix3x3*);
// Original: arm9/main @ 0x02016E14; symbol: func_02016e14; size: 0x284.
extern "C" ARM void Render_DrawNodeTreeWithLightingVisibility(unsigned char* owner,unsigned* source,DrawNode* node,int hidden) {
 GameState::GetInstance();
 LightingManager* lighting=LightingManager::GetInstance();
 DrawAsset* asset=node->asset;
 DrawDescriptor* descriptor=node->descriptor;
 int lightingIndex=lighting->timeOfDayIndex_;
 if((owner[0x832] || owner[0x833]) && *(OwnerMode**)(owner+8)){
  unsigned kind=(*(OwnerMode**)(owner+8))->value;
  if((!kind || kind==7 || owner[0x833]) && !(descriptor->visibility&16)){
   if(descriptor->visibility & (1U<<lightingIndex))node->flags &= ~4;
   else node->flags |=4;
  }
 }
 Model3D* model=0;
 *(volatile unsigned*)0x040004c0=0x7fff7fff;
 Object3D* object=0;
 int childHidden=0;
 if(!hidden && !(node->flags&4) && asset){
  if(!asset->kind)model=asset->model;
  else if(asset->kind==2){object=node->object;if(object)model=object->pModel_;}
 }
 if(model){
  RenderConfig::SetObjectPosition(&node->position);
  int angle=node->angle;
  if(node->angleOffset)angle=fix32ReduceAngle0To2Pi(angle+node->angleOffset);
  fix32_t cosine=fix32cos(angle);
  fix32_t sine=fix32sin(angle);
  Matrix3x3 rotation;
  MTX_RotY33_(&rotation,sine,cosine);
  RenderConfig_CopyTransformAndClearFlagsA4(&rotation);
  Vector3fix scale;
  scale.x=node->scale.x;scale.y=node->scale.y;scale.z=node->scale.z;
  RenderConfig::SetObjectScale(&scale);
  if((node->flags&8) || node->alpha.marked)model->SetAlpha(node->alpha.value);
  if(*(NSBXXInternalModel* volatile*)((char*)model+0x54)){
   LightingManager::GetInstance()->ApplyAmbientColorToModel(*(NSBXXInternalModel* volatile*)((char*)model+0x54));
   int drawn=0;
   if(!asset->kind){RenderConfig::SubmitToFifo();drawn=model->Draw(true);}
   else if(asset->kind==2){object->AdvanceEffects();drawn=object->DrawSimple(true);}
   if(drawn){(owner+owner[0x281c]*2+0x2000)[0x7dc]=descriptor->id;(owner+owner[0x281c]*2+0x2000)[0x7dd]=*source;++owner[0x281c];}
  }
 }
 else childHidden=1;
 if(node->child)Render_DrawNodeTreeWithLightingVisibility(owner,source,node->child,childHidden);
 if(node->next)Render_DrawNodeTreeWithLightingVisibility(owner,source,node->next,hidden);
}
