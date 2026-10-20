#include <globaldefs.h>
ARM
extern "C" {
void BuildAndDispatchYRotationMatrixWhenAngleNonzero(int);
void _ZN8Object3D14AdvanceEffectsEv(void*);
void _ZN8Object3D15ApplyAnimationsEPS_(void*,void*);
void _ZN8Object3D4DrawEb(void*,bool);
bool _ZN8Object3D11DrawSimple2Eb(void*,bool);
void _ZN8Object3D19SendTransformToFifoEv(void*);
void _ZN8Object3D23SetCurrentAnimationTimeEi(void*,int);
int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
void* CharacterPalette_GetGlobalConfiguration();
bool _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(void*,void*,void*,unsigned);
void Graphics_CopySixteenBytesToEdgeColorRegisters(const void*);
extern char Graphics_DrawObjectWithBoneAttachments_TextHead[],Graphics_DrawObjectWithBoneAttachments_TextArm2R[],Graphics_DrawObjectWithBoneAttachments_TextArm2L[],Graphics_DrawObjectWithBoneAttachments_TextWeaponR[],Graphics_DrawObjectWithBoneAttachments_TextWeaponL[],Graphics_DrawObjectWithBoneAttachments_TextChest[];
}
// Original: arm9/ov023 @ 0x021E5628; symbol: func_ov023_021e5628; size: 0x34C.
extern "C" void Graphics_DrawObjectWithBoneAttachments(unsigned char* self,void** attached) {
if(self[0xc12] || !self[0xc14]) return;
unsigned char* global=(unsigned char*)CharacterPalette_GetGlobalConfiguration();
if(!global) return;
unsigned short color=*(unsigned short*)(global+0x128);
unsigned short colors[8]={color,color,color,color,color,color,color,color};
Graphics_CopySixteenBytesToEdgeColorRegisters(colors);
if(*(short*)(self+2)>=0) {
_ZN8Object3D14AdvanceEffectsEv(self);
int time=*(int*)(self+0x1c);
_ZN8Object3D23SetCurrentAnimationTimeEi(self+0x408,time);
_ZN8Object3D23SetCurrentAnimationTimeEi(self+0xac,time);
_ZN8Object3D23SetCurrentAnimationTimeEi(self+0x35c,time);
}
if(*(short*)(self+2)<=-1) return;
_ZN8Object3D4DrawEb(self,true);
void* model;
unsigned char* context=*(unsigned char**)(self+8);
if(context) {
if(!((int)(*(unsigned*)(context+0xa8)<<31)>>31)) context=0;
if(context) {
model=*(void* volatile*)(self+8);
if(!model) return;
int bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextHead);
if(bone>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
if(attached && attached[1]) _ZN8Object3D11DrawSimple2Eb(attached[1],false);
_ZN8Object3D19SendTransformToFifoEv(self+0x158);
_ZN8Object3D11DrawSimple2Eb(self+0x158,false);
_ZN8Object3D11DrawSimple2Eb(self+0x204,false);
_ZN8Object3D11DrawSimple2Eb(self+0x4b4,false);
if(self[0xc10]) {
bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextArm2R);
if(bone>-1 && *(short*)(self+0x562)>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
_ZN8Object3D11DrawSimple2Eb(self+0x560,false);
}
bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextArm2L);
if(bone>-1 && *(short*)(self+0x562)>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
BuildAndDispatchYRotationMatrixWhenAngleNonzero(0x3244);
_ZN8Object3D11DrawSimple2Eb(self+0x560,false);
}
} else {
bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextWeaponR);
if(bone>-1 && *(short*)(self+0x562)>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
_ZN8Object3D11DrawSimple2Eb(self+0x560,false);
}}
bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextWeaponL);
if(bone>-1 && *(short*)(self+0x60e)>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
_ZN8Object3D11DrawSimple2Eb(self+0x60c,false);
}
if(attached && attached[0]) {
bone=_ZN7Model3D12GetBoneIndexEPKc(model,Graphics_DrawObjectWithBoneAttachments_TextChest);
if(bone>-1) {
_Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
_ZN8Object3D11DrawSimple2Eb(attached[0],false);
}}
}}}
_ZN8Object3D15ApplyAnimationsEPS_(self,self+0x408);
_ZN8Object3D4DrawEb(self+0x408,true);
_ZN8Object3D15ApplyAnimationsEPS_(self,self+0xac);
_ZN8Object3D4DrawEb(self+0xac,true);
_ZN8Object3D15ApplyAnimationsEPS_(self,self+0x35c);
_ZN8Object3D4DrawEb(self+0x35c,true);
}
