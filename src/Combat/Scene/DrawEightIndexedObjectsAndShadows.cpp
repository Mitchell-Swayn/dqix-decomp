#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" char* Zone3D_GetMainInstance();
extern "C" int Object3D_DrawWithTemporaryHeightAndCameraDisplacement(void*,int,int);
extern "C" int _ZNK8Object3D9IsVisibleEv(void*);
extern "C" int _ZNK8Object3D16GetCombinedAlphaEv(void*);
extern "C" void _ZNK8Object3D23GetShadowSourcePositionEv(void*,void*);
extern "C" int GameResources_GetMaskedSecondaryFlags(void*,int);
extern "C" char* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void UpdateInactiveEntriesForMatchingParentObject(char*,int);
extern "C" void Graphics_RenderPresentModelWithDiffuseColorAndScale(Vector3i*,unsigned,int,int,int);
extern "C" int NSBXX_Model_GetMaterialPolygonID(void*,unsigned);
extern "C" void ObjectPool_EnableResourceSlot(unsigned char*,int);
extern "C" void ObjectPool_DisableResourceSlot(char*,int);
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov000 @ 0x02161020; symbol: func_ov000_02161020; size: 0x16C.
extern "C" void DrawEightIndexedObjectsAndShadows(char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 void* resources=GameResources_GetInstance();
 char* display=Object_GetGlobalSixteenEntryDisplayState();
 char* settings=Zone3D_GetMainInstance();
 char* flags=*(char**)(self+0xea4);
 unsigned color=*(unsigned short*)(settings+0x38);
 for(int i=0;i<8;i++) {
 char* obj=GameState_FindIndexedObjectWithFlag400(state,i+0xc0);
 if(!obj || !_ZNK8Object3D9IsVisibleEv(obj)) continue;
 int drawn=0;
 if(!GameResources_GetMaskedSecondaryFlags(resources,0x200)) drawn=Object3D_DrawWithTemporaryHeightAndCameraDisplacement(obj,1,0);
 if(drawn) {
 UpdateInactiveEntriesForMatchingParentObject(display,i+0xc0);
 int intensity=*(int*)(settings+0x3c);
 int alpha=_ZNK8Object3D16GetCombinedAlphaEv(obj);
 int ratio=_fdiv(_fflt(intensity),0x41f80000);
 alpha=_ffix(_fmul(ratio,_fflt(alpha)));
 int polygon=1;
 char* model=*(char**)(obj+8);
 if(model && *(void**)(model+0x54)) polygon=NSBXX_Model_GetMaterialPolygonID(*(void**)(model+0x54),0);
 Vector3i pos;
 _ZNK8Object3D23GetShadowSourcePositionEv(&pos,obj);
 Graphics_RenderPresentModelWithDiffuseColorAndScale(&pos,color,*(short*)(obj+0x18e),alpha,polygon);
 if(flags) ObjectPool_EnableResourceSlot((unsigned char*)flags,i+0xc0);
 } else {
 if(flags) ObjectPool_DisableResourceSlot(flags,i+0xc0);
 }
 }
}
