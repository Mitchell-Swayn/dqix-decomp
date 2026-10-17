#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void Object_SetHalfword7CAndClear1EC1EE(void*,short);
extern "C" void SetAngleAndCacheTrig(void*,unsigned);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
// Original: arm9/main @ 0x0204700C; symbol: func_0204700c; size: 0x150.
extern "C" int Graphics_UpdateTimedAngleAndBrightness(char* self) {
 if(*(unsigned*)self>35) return 1;
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned ticks=_ZNK9GameState12GetTickCountEv(state);
 *(float*)(self+8)-=8.0f;
 if(*(float*)(self+8)<=-180.0f) *(float*)(self+8)=180.0f;
 float angle=3.14f*(*(float*)(self+8)/180.0f);
 *(float*)(self+12)-=0.433300f;
 void* object=GameState_ReadUnknownB0(state);
 Object_SetHalfword7CAndClear1EC1EE(object,(short)_Z22fix32ReduceAngle0To2Pii((int)(4096.0f*angle)));
 SetAngleAndCacheTrig(object,(int)(4096.0f**(float*)(self+12)));
 if(*(void**)(self+0xe8)) _ZN8Object3D14AdvanceEffectsEv(*(void**)(self+0xe8));
 else _ZN8Object3D14AdvanceEffectsEv(self+0x3c);
 *(unsigned*)self+=ticks;
 if(*(unsigned*)self>15 && *(unsigned char*)(self+0x1c)) {
  void* resources=GameResources_GetInstance();
  _Z17SetMainBrightnessP13GameResourcesii(resources,-16,20);
  _Z16SetSubBrightnessP13GameResourcesii(resources,-16,20);
  *(unsigned char*)(self+0x1c)=0;
 }
 return *(unsigned*)self>35;
}
