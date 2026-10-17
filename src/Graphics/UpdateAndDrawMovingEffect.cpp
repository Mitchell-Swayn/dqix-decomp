#include <globaldefs.h>
struct EffectVector { int x,y,z; };
struct EffectModel { char prefix[0x54]; void* volatile model; };
struct EffectRecord { char prefix[5]; unsigned char simple; };
struct EffectDrawState {
 char prefix[4]; unsigned tick; char gap08[8]; EffectVector origin;
 char gap1c[12]; void* resource; unsigned char active; char gap2d[0x23];
 float scaleX,scaleY; char gap58[0x14]; float velocityX,velocityY,velocityZ,speed;
 char object[8]; EffectModel* model; char gap88[0x38]; EffectVector position;
 char gapcc[0x5c]; unsigned polygon; float red,green,blue,alpha,scaleFactorX,scaleFactorY;
};
struct EffectRenderState { char prefix[0xbc]; char rotation[0x24]; char gap[0x1c]; unsigned flags; };
extern "C" {
 int Object_TestInactiveCounterWithinLimit(EffectDrawState*);
 EffectRecord* ReadResolvedRecordWordField14OrZero(void*);
 void NSBXX_Model_SetDiffuseReflectionColor(void*,unsigned short);
 void NSBXX_Model_SetPolygonID(void*,unsigned);
 void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(EffectVector*);
 void _ZN12RenderConfig14SetObjectScaleEP8Vector3i(EffectVector*);
 void* _ZN9GameState11GetInstanceEv();
 void* GameState_ReadUnknownB0(void*);
 void* Object_GetSubrecordAtOffset144(void*);
 void MI_Copy36B(const void*,void*);
 void _ZN8Object3D17SetInheritedAlphaEi(void*,int);
 void _ZN8Object3D10DrawSimpleEb(void*,bool);
 void _ZN8Object3D4DrawEb(void*,bool);
 extern EffectRenderState data_0210a010;
 extern const EffectVector data_020e7da4;
}
// Original: arm9/main @ 0x02059a54; symbol: func_02059a54; size: 0x23c.
// Update an effect's time-based position and submit its colored, scaled object.
extern "C" void UpdateAndDrawMovingEffect(EffectDrawState* state) {
 if(!state->active || Object_TestInactiveCounterWithinLimit(state)) return;
 EffectRecord* record=ReadResolvedRecordWordField14OrZero(state->resource);
 int x,y,z;
 unsigned tick=state->tick;
 x=state->origin.x+(int)(4096.0f*((float)tick*(state->velocityX*state->speed)));
 y=state->origin.y+(int)(4096.0f*((float)tick*(state->velocityY*state->speed)));
 z=state->origin.z+(int)(4096.0f*((float)tick*(state->velocityZ*state->speed)));
 state->position.x=x;state->position.y=y;state->position.z=z;
 if(!record->simple) {
  void* model=state->model->model;
  int blue=(int)state->blue;
  int red=(int)state->red;
  int green=(int)state->green;
  NSBXX_Model_SetDiffuseReflectionColor(model,(unsigned short)(red|(green<<5)|(blue<<10)));
  NSBXX_Model_SetPolygonID(state->model->model,state->polygon);
  EffectVector position=state->position;
  _ZN12RenderConfig17SetObjectPositionEP8Vector3i(&position);
  void* world=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
  if(world) {
   MI_Copy36B(Object_GetSubrecordAtOffset144(world),data_0210a010.rotation);
   data_0210a010.flags&=~0xa4;
  }
  EffectVector scale=data_020e7da4;
  scale.x=(int)((float)(int)(4096.0f*state->scaleFactorX)*state->scaleX);
  scale.y=(int)((float)(int)(4096.0f*state->scaleFactorY)*state->scaleY);
  _ZN12RenderConfig14SetObjectScaleEP8Vector3i(&scale);
  _ZN8Object3D17SetInheritedAlphaEi(state->object,(int)state->alpha);
  _ZN8Object3D10DrawSimpleEb(state->object,true);
 } else _ZN8Object3D4DrawEb(state->object,true);
}
