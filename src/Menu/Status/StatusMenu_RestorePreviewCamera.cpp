#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
struct Object {virtual void V0();virtual void V1();virtual void V2();virtual void V3();virtual void V4();virtual void V5();virtual void V6();virtual void SetVector(const Vec&);virtual Vec GetVector();int pad[2];unsigned char flags;};
extern "C" Object* Menu_FindCanvasNodeByKey(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnknown3b0(void*,void*);
// Original data: arm9/ov004 @ 0x21707e8; symbol: data_ov004_021707e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x021630A4; symbol: func_ov004_021630a4; size: 0x88.
extern "C" int StatusMenu_RestorePreviewCamera(void* context){
 Object* o=Menu_FindCanvasNodeByKey(context,9);
 o->flags&=~0x80;
 Vec v=o->GetVector();
 v.x=0;v.y=0;v.z=0;
 o->SetVector(v);
 GameState_SetUnknown3b0(_ZN9GameState11GetInstanceEv(),StatusMenuSelectNextSubpage_UnknownRoleZeroInitializedStorage[4]);
 return 0;
}
