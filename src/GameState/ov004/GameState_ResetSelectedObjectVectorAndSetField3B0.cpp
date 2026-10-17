#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
struct Object {virtual void V0();virtual void V1();virtual void V2();virtual void V3();virtual void V4();virtual void V5();virtual void V6();virtual void SetVector(const Vec&);virtual Vec GetVector();int pad[2];unsigned char flags;};
extern "C" Object* func_ov004_0215e47c(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnknown3b0(void*,void*);
extern "C" void* data_ov004_021707e8[];
// Original: arm9/ov004 @ 0x021630A4; symbol: func_ov004_021630a4; size: 0x88.
extern "C" int GameState_ResetSelectedObjectVectorAndSetField3B0(void* context){
 Object* o=func_ov004_0215e47c(context,9);
 o->flags&=~0x80;
 Vec v=o->GetVector();
 v.x=0;v.y=0;v.z=0;
 o->SetVector(v);
 GameState_SetUnknown3b0(_ZN9GameState11GetInstanceEv(),data_ov004_021707e8[4]);
 return 0;
}
