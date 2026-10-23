#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* Zone3D_GetMainInstance();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" bool _ZNK8Object3D7IsChildEv(void*);
extern "C" bool _ZNK8Object3D7GetFlagEi(void*,int);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" bool _ZN8Object3D4DrawEb(void*,bool);
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(void*);
typedef Vector3i Vector3;
extern "C" void _ZNK8Object3D23GetShadowSourcePositionEv(Vector3*,void*);
extern "C" int _ZNK8Object3D9GetRadiusEv(void*);
extern "C" int GameResources_GetMaskedSecondaryFlags(void*,int);
extern "C" void Graphics_RenderPresentModelWithDiffuseColorAndScale(Vector3*,unsigned,int,int,int);
// Original: arm9/ov017 @ 0x021973E8; symbol: func_ov017_021973e8; size: 0x140.
extern "C" void Graphics_DrawObjectRangeAndShadows(void* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* globals=Zone3D_GetMainInstance();
 unsigned color=*(unsigned short*)(globals+0x38);
 unsigned globalAlpha=*(unsigned*)(globals+0x3c);
 if(!GameResources_GetMaskedSecondaryFlags(self,0x100)) {
  bool mode=true;
  if(GameResources_GetMaskedSecondaryFlags(self,0x1000))mode=false;
  for(int i=0xa0;i<0xc0;i++) {
   void* obj=_ZN9GameState20GetGameObjectByIndexEi(state,i);
   if(!obj || _ZNK8Object3D7IsChildEv(obj) || _ZNK8Object3D7GetFlagEi(obj,0x40000000))continue;
   _ZN8Object3D10EnableFlagEi(obj,4);
   if(!_ZN8Object3D4DrawEb(obj,mode) || _ZNK8Object3D7GetFlagEi(obj,0x10))continue;
   int inherited=_ZNK8Object3D17GetInheritedAlphaEv(obj);
   float factor=(float)globalAlpha/31.0f;
   int alpha=(int)(factor*(float)inherited);
   Vector3 source;
   _ZNK8Object3D23GetShadowSourcePositionEv(&source,obj);
   int radius=_ZNK8Object3D9GetRadiusEv(obj);
   Graphics_RenderPresentModelWithDiffuseColorAndScale(&source,color,radius,alpha,8);
  }
 }
}
