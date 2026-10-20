#include <globaldefs.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
struct Object {
 virtual void HeaderSlot0();
 virtual void HeaderSlot1();
 virtual void Slot0();
 virtual void Slot1();
 virtual void Slot2();
 virtual void Slot3();
 virtual void Slot4();
 virtual void Slot5();
 virtual void Slot6();
 virtual void Slot7();
 virtual void Slot8();
 virtual void Slot9();
 virtual void Slot10();
 virtual void Slot11();
 virtual void Slot12();
 virtual void Slot13();
 virtual void Slot14();
 virtual void ApplyFirst(int);
 virtual void Slot16();
 virtual void Slot17();
 virtual void Slot18();
 virtual void Slot19();
 virtual void Slot20();
 virtual void Slot21();
 virtual void Slot22();
 virtual void Slot23();
 virtual void Slot24();
 virtual void Slot25();
 virtual void Slot26();
 virtual void Slot27();
 virtual void Slot28();
 virtual void ApplySecond(int);
};
// Original: arm9/ov004 @ 0x0216B20C; symbol: func_ov004_0216b20c; size: 0xBC.
extern "C" void TitleMenu_BindMappedActivationCallbacks(State* self,unsigned short key,int value,int direct) {
 Object* object=(Object*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),key);
 if(!object) return;
 if(!direct) {
  switch(value) {
  case 100: value=21; break;
  case 150: value=22; break;
  case 151: value=23; break;
  case 200: value=24; break;
  case 201: value=25; break;
  case 300: value=26; break;
  }
 }
 object->ApplyFirst(value);
 object->ApplySecond(value);
}
