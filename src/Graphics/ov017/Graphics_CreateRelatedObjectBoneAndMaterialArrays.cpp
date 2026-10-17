#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void GameState_BuildRelatedObjectIdList(int,int*);
extern "C" void _ZN7Model3D33CreateBoneMatrixAndMaterialArraysEP13SafeAllocatori(void*,void*,int);
extern "C" int data_ov017_021d61c0[];
// Original: arm9/ov017 @ 0x021901AC; symbol: func_ov017_021901ac; size: 0x8C.
extern "C" void Graphics_CreateRelatedObjectBoneAndMaterialArrays(){
 int ids[11];
 void* gs=_ZN9GameState11GetInstanceEv();
 for(int i=0;i<4;i++){
 GameState_BuildRelatedObjectIdList(i,ids);
 for(int j=0;j<7;j++){
 unsigned char* obj=_ZN9GameState20GetGameObjectByIndexEi(gs,ids[data_ov017_021d61c0[j]]);
 if(obj && *(void**)(obj+8))_ZN7Model3D33CreateBoneMatrixAndMaterialArraysEP13SafeAllocatori(*(void**)(obj+8),0,0);
 }
 }
}
