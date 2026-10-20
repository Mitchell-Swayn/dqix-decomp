#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vec {int x,y,z;};
struct Matrix {int v[12];};
struct Params {char name[16];unsigned char type,flags;unsigned short unused12,index;unsigned short field16,field18;unsigned char pad1a[18];Vec position,rotation,scale;};
extern "C" {
void* Object_GetGlobalSixteenEntryDisplayState();
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
void Object_InitializeRenderValuesAndUnitScales(void*);
int sprintf(char*,const char*,...);
int ObjectPool_SpawnFromTemplateKey(void*,int,void*);
int _Z24fix32SignedAngleDistanceii(int,int);
void* _ZN8Vector3iaSERKS_(void*,const void*);
unsigned char* ObjectPool_GetDisplayEntryByObjectIndex(unsigned char*,int);
void MTX_Identity43_(Matrix*);
void Mat4x3_ApplyTranslation(const Matrix*,Matrix*,int,int,int);
Matrix _Z15RotationMatrixYi(int);
void Mat4x3_Multiply(const Matrix*,const Matrix*,Matrix*);
void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char*,int,int);
void Object3D_ResetEffectStateFromStoredParameter(char*);
// Original data: arm9/main @ 0x20f2884; symbol: data_020f2884.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 257300.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2887; symbol: data_020f2887.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes[],GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2[],Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/main @ 0x020DA31C; symbol: func_020da31c; size: 0x460.
extern "C" void Graphics_UpdateIndexedObjectEffects(unsigned char* self) {
void* display=Object_GetGlobalSixteenEntryDisplayState();
void* state=_ZN9GameState11GetInstanceEv();
if(!display || !state) return;
switch(self[14]) {
case 1: {
unsigned char* object=_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,*(int*)(self+8));
if(!object) return;
if(!(self[13]&8)) {
self[13]|=8;Params p;Object_InitializeRenderValuesAndUnitScales(&p);
p.index=*(int*)(self+8);p.type=0;sprintf(p.name,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2);
p.position.x=0;p.position.y=0;p.position.z=0;p.scale.x=4096;p.scale.y=4096;p.scale.z=4096;
ObjectPool_SpawnFromTemplateKey(display,20,&p);
}
int speed=*(short*)(object+178);
int angle=_Z24fix32SignedAngleDistanceii(*(int*)(object+84),*(short*)(object+174));
if(speed>61 || angle) self[15]++;
if(self[15]>=3) {
self[15]=0;Params p;Object_InitializeRenderValuesAndUnitScales(&p);
_ZN8Vector3iaSERKS_(&p.position,object+68);_ZN8Vector3iaSERKS_(&p.rotation,object+80);
p.scale.x=200;p.scale.y=200;p.scale.z=200;
sprintf(p.name,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2);p.flags|=64;ObjectPool_SpawnFromTemplateKey(display,21,&p);
}
break;
}
case 2: {
unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(state,*(int*)(self+8));if(!object) return;
if(!(self[13]&8)) {
self[13]|=8;Params p;Object_InitializeRenderValuesAndUnitScales(&p);
p.index=*(int*)(self+8);p.type=0;sprintf(p.name,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2);
p.position.x=0;p.position.y=0;p.position.z=0;p.scale.x=0x3000;p.scale.y=0x1000;p.scale.z=0x3000;
ObjectPool_SpawnFromTemplateKey(display,20,&p);
}
if(++self[15]>=7) {
self[15]=0;Params p;Object_InitializeRenderValuesAndUnitScales(&p);
_ZN8Vector3iaSERKS_(&p.position,object+68);_ZN8Vector3iaSERKS_(&p.rotation,object+80);
p.scale.x=225;p.scale.y=225;p.scale.z=225;
sprintf(p.name,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2);ObjectPool_SpawnFromTemplateKey(display,21,&p);
}
break;
}
case 3: {
unsigned char* object=_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,*(int*)(self+8));if(!object) return;
unsigned char* record=ObjectPool_GetDisplayEntryByObjectIndex((unsigned char*)display,208);
if(record && *(void**)(record+4)) {
unsigned char* nested=*(unsigned char**)(record+4);
Matrix combined,translation,offset;
MTX_Identity43_(&combined);MTX_Identity43_(&translation);
Mat4x3_ApplyTranslation(&translation,&translation,*(int*)(object+68),*(int*)(object+72),*(int*)(object+76));
MTX_Identity43_(&offset);Mat4x3_ApplyTranslation(&offset,&offset,0,0x3000,0x800);
Matrix rotation=_Z15RotationMatrixYi(*(short*)(object+174));
Mat4x3_Multiply(&offset,&rotation,&combined);Mat4x3_Multiply(&combined,&translation,&combined);
*(Matrix*)(nested+232)=combined;
}
if(!(self[13]&16)) {self[15]=0;self[16]=0;break;}
self[15]++;
if(self[16]<1 && (self[13]&16)) {
if(!self[17]) {
Params p;Object_InitializeRenderValuesAndUnitScales(&p);
_ZN8Vector3iaSERKS_(&p.position,object+68);_ZN8Vector3iaSERKS_(&p.rotation,object+80);
p.field18=90;p.scale.x=409;p.scale.y=409;p.scale.z=409;
sprintf(p.name,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes,GraphicsUpdateIndexedObjectEffects_UnknownRoleInitializedBytes_Variant2);p.flags|=0xb8;ObjectPool_SpawnFromTemplateKey(display,22,&p);
self[17]=1;ResourceHandle_InvokeOperationWithValidHalfwordIndex(Main_UnknownRoleZeroInitializedStorage,1,0);
} else {
unsigned char* record=ObjectPool_GetDisplayEntryByObjectIndex((unsigned char*)display,208);
if(record) {Object3D_ResetEffectStateFromStoredParameter((char*)record);ResourceHandle_InvokeOperationWithValidHalfwordIndex(Main_UnknownRoleZeroInitializedStorage,1,0);}
}
self[16]++;
} else if(self[15]>=85) self[13]&=~16;
break;
}
}
}
