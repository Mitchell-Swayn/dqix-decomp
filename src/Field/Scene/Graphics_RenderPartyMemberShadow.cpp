#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" bool GameObject_IsMovementPauseActive(char*);
extern "C" char* GameResources_GetInstance();
extern "C" char* Zone3D_GetMainInstance();
extern "C" Vec _ZNK8Object3D23GetShadowSourcePositionEv(void*);
extern "C" int _ZNK8Object3D16GetCombinedAlphaEv(void*);
extern "C" unsigned char* GameObject_GetLadderTraversalState(void*);
extern "C" char* GameState_ReadUnkF8(void*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);
extern "C" bool _ZNK8Object3D7GetFlagEi(void*,int);
extern "C" int _ZNK8Object3D9GetRadiusEv(void*);
extern "C" void Graphics_RenderPresentModelWithDiffuseColorAndScale(Vec*,unsigned,int,int,int);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv();
// Original: arm9/ov017 @ 0x0218DBA0; symbol: func_ov017_0218dba0; size: 0x178.
extern "C" void Graphics_RenderPartyMemberShadow(int index) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* object=_ZN9GameState21GetPartyMemberByIndexEi(game,index);
 if(!object||GameObject_IsMovementPauseActive(object))return;
 unsigned color; int opacity;
 void* control=*(void**)(GameResources_GetInstance()+0x36fc);
 char* global=Zone3D_GetMainInstance();
 color=*(unsigned short*)(global+0x38);
 int scale=*(int*)(global+0x3c);
 Vec position=_ZNK8Object3D23GetShadowSourcePositionEv(object);
 int alpha=_ZNK8Object3D16GetCombinedAlphaEv(object);
 opacity=(int)(((float)scale/31.0f)*(float)alpha);
 if(object && GameObject_GetLadderTraversalState(object)[0]) {
 unsigned char* sub=GameObject_GetLadderTraversalState(object);
 int mode=sub[1];
 if(mode==1||mode==4)opacity=*(short*)(sub+0x50);
 if(mode==2||mode==6) {
 opacity=*(short*)(sub+0x50);
 position.y=*(int*)(sub+0x4c);
 }
 }
 if(*(short*)(GameState_ReadUnkF8(game)+0x6c)==9999) {
 if(LinkedQueue_GetFrontKindOrInvalid(control)==3)opacity=0;
 }
 if(!_ZNK8Object3D7GetFlagEi(object,16)) {
 int radius=(int)(0.9f*(float)_ZNK8Object3D9GetRadiusEv(object));
 Graphics_RenderPresentModelWithDiffuseColorAndScale(&position,color,radius,opacity,8);
 } else _ZN12RenderConfig12SubmitToFifoEv();
}
