#include <globaldefs.h>
ARM
struct Value {unsigned data[3];};
struct Object { virtual void A();virtual void B();virtual void C();virtual void D();virtual void E();virtual void F();virtual void G();virtual void Set(const Value&);virtual Value Get(); };
extern "C" void* MenuRecordList_LocateByKey(void*,int);
extern "C" unsigned MotionRecord_GetSelectionParameterByKey(void*,unsigned);
extern "C" signed char* ReadTypeFourDescriptorKeyValue(void*,int,unsigned);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
// Original: arm9/ov004 @ 0x021536E0; symbol: CopyVirtualRecordValueWhenTargetIsInactive; size: 0x98.
extern "C" void Menu_CopyPositionUnlessSourceDescriptorIsActive(void* self,int target,int source) {
 void* dst=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),target);if(!dst)return;
 signed char* state=ReadTypeFourDescriptorKeyValue(self,4,MotionRecord_GetSelectionParameterByKey(self,source));if(state && *state)return;
 void* src=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),source);if(!src)return;
 Value value;((void(*)(void*,void*))(*(void***)(src))[8])(&value,src);
 ((Object*)dst)->Set(value);
}
