#include <globaldefs.h>
extern "C" void* memcpy(void*,const void*,unsigned);
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Graphics/NSBXX/GeometryFifo.h>
#include <Graphics/NSBXX/RenderConfig.h>
#pragma always_inline on
ModelRenderContext* GetModel3DContext(Model3D*);

#pragma always_inline off
extern "C" void Object3D_DrawEntryWithOptionalInverseViewTransform(Object3D*,int);
static inline void CopyMatrix(Matrix4x3 *out,const Matrix4x3 *in){*out=*in;}
struct MatrixWords { int words[12]; };
struct AttachedObject { Object3D object;int kind;short active,parent,bone;char rest[0xd4-0xb6]; };
// Original: arm9/main @ 0x02057AB8; symbol: func_02057ab8; size: 0x300.
extern "C" void UpdateInactiveEntriesForMatchingParentObject(char *self,int parent){
GameState *state=GameState::GetInstance();if(parent<0)return;
for(int i=0;i<16;++i){AttachedObject *entry=(AttachedObject*)(self+8+i*0xd4);Object3D *object=&entry->object;
if(parent!=entry->parent||entry->active>0)continue;
GameObject *owner=state->GetGameObjectByIndex(entry->parent);
if(!owner){entry->parent=-1;continue;}if(!owner->obj3D_.pModel_){entry->parent=-1;continue;}
ModelRenderContext *context=GetModel3DContext(owner->obj3D_.pModel_);if(!context){entry->parent=-1;continue;}
Matrix4x3 boneMatrix;MTX_Identity43_(&boneMatrix);
Vector3fix position=owner->obj3D_.position_;Vector3fix rotation=owner->obj3D_.rotation_;Vector3fix scale=owner->obj3D_.GetScale();bool hasBone=false;
if(entry->bone>-1&&GetModelBonePositionAndDirectionMatrices(context,0,0,entry->bone)){
const Matrix4x3 *inverse=RenderConfig::GetInverseViewMatrix();GetCurrentPositionAndDirectionMatrices(&boneMatrix,0);Mat4x3_Multiply(&boneMatrix,inverse,&boneMatrix);hasBone=true;}
if(entry->kind==0){Vector3fix savedPosition=object->position_;Vector3fix savedRotation=object->rotation_;Vector3fix savedScale=object->GetScale();
Matrix4x3 rotationMatrix=RotationMatrixY(rotation.y);Vector3fix offset;Mat4x3_ApplyToVector(&savedPosition,&rotationMatrix,&offset);Vector3fix_Add(&position,&offset,&position);Vector3fixMultiply(&scale,&savedScale,&scale);
object->position_=position;object->rotation_=rotation;object->SetScale(&scale);Object3D_DrawEntryWithOptionalInverseViewTransform(object,i+0xd0);UpdateInactiveEntriesForMatchingParentObject(self,i+0xd0);object->position_=savedPosition;object->rotation_=savedRotation;object->SetScale(&savedScale);
}else if(entry->kind==1){char *target=*(char**)((char*)object+4);if(target){if(!hasBone){*(Vector3fix*)(target+0xc4)=position;*(Vector3fix*)(target+0xd0)=rotation;*(Vector3fix*)(target+0xdc)=scale;}else{position.x=boneMatrix.translation.x;position.y=boneMatrix.translation.y;position.z=boneMatrix.translation.z;Mat4x3_ApplyScale(&boneMatrix,&boneMatrix,0xf627,0xf627,0xf627);boneMatrix.translation.x=position.x;boneMatrix.translation.y=position.y;boneMatrix.translation.z=position.z;*(MatrixWords*)(target+0xe8)=*(const MatrixWords*)&boneMatrix;}}
Object3D_DrawEntryWithOptionalInverseViewTransform(object,i+0xd0);UpdateInactiveEntriesForMatchingParentObject(self,i+0xd0);}
}
}
