#include <globaldefs.h>
ARM
struct Vector3i { int x,y,z; };
extern "C" {
void Ov023_InitializeFourEmbeddedFields(void*,int);
void Object3D_ReadRotationVector(Vector3i*,void*);
void CharacterPreview_SetBodyRotation(void*,Vector3i*);
void *Menu_GetCharacterPreviewBaseModel(void *);
int String_CountBytesUntilTerminator(const char*);
void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
void _ZN8Object3D23SetCurrentAnimationTimeEi(void*,int);
void CharacterCreation_ReadBodyScalePreset(void*,int,short*,short*);
void CharacterPreview_ApplyBodyProportions(void*,int,int);
}
#define W(o) (*(unsigned*)(self+(o)))
#define P(o) (*(unsigned char**)(self+(o)))
// Original: arm9/ov009 @ 0x02188454; symbol: func_ov009_02188454; size: 0x164.
// Swaps a ready preview, preserving equal-length animation state and requested body proportions.
extern "C" void CharacterCreation_SwapReadyAppearancePreview(unsigned char* self) {
 if (!(W(0xd9c)&4))return;
 if(P(0x7fc) && P(0x7fc)[0xc12])return;
 if(W(0xd9c)&0x40000){Ov023_InitializeFourEmbeddedFields(P(0x7f8),0x1eb);W(0xd9c)&=~0x40000;}
 Vector3i rotation;Object3D_ReadRotationVector(&rotation,P(0x7f8));CharacterPreview_SetBodyRotation(P(0x7fc),&rotation);
 unsigned char* oldModel=(unsigned char*)Menu_GetCharacterPreviewBaseModel(P(0x7f8));
 unsigned char* newModel=(unsigned char*)Menu_GetCharacterPreviewBaseModel(P(0x7fc));
 const char* newAnimation=*(const char**)(newModel+0x14);
 int newLength=0,oldLength=0;
 const char* oldAnimation=*(const char**)(oldModel+0x14);
 if(newAnimation)newLength=String_CountBytesUntilTerminator(newAnimation);
 if(oldAnimation)oldLength=String_CountBytesUntilTerminator(oldAnimation);
 if(newLength==oldLength && oldAnimation){_ZN8Object3D18SetAnimationByNameEPKci(newModel,oldAnimation,0);_ZN8Object3D23SetCurrentAnimationTimeEi(newModel,*(int*)(oldModel+0x1c));}
 unsigned char* old=P(0x7f8);P(0x7f8)=P(0x7fc);P(0x7fc)=old;
 if(W(0xd9c)&0x20000){
 unsigned char* settings=P(0xd88)+0x88+0x400;
 CharacterCreation_ReadBodyScalePreset(self,*(self+self[0xda3]+0xda4),(short*)(settings+0x18),(short*)(settings+0x1a));
 CharacterPreview_ApplyBodyProportions(P(0x7f8),*(short*)(settings+0x18),*(short*)(settings+0x1a));
 CharacterPreview_ApplyBodyProportions(P(0x7fc),*(short*)(settings+0x18),*(short*)(settings+0x1a));
 W(0xd9c)&=~0x20000;
 }
 W(0xd9c)&=~4;
}
