#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" short Menu_SumCompletedSubtypeCounts();
extern "C" int SumSixIndexedEntryByteValues();
extern "C" int GameState_ReadEntrySevenByteCount();
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
struct Widget {
 virtual void Pad0();
 virtual void Pad1();
 virtual void Pad2();
 virtual void Pad3();
 virtual void Pad4();
 virtual void Pad5();
 virtual void Pad6();
 virtual void Pad7();
 virtual void Pad8();
 virtual void Pad9();
 virtual void Pad10();
 virtual void Pad11();
 virtual void Pad12();
 virtual void Pad13();
 virtual void Pad14();
 virtual void SetMode(int);
 virtual void Pad16();
 virtual void Pad17();
 virtual void Pad18();
 virtual void Pad19();
 virtual void Pad20();
 virtual void Pad21();
 virtual void Pad22();
 virtual void Pad23();
 virtual void Pad24();
 virtual void Pad25();
 virtual void Pad26();
 virtual void Pad27();
 virtual void Pad28();
 virtual void Pad29();
 virtual void Pad30();
 virtual void Pad31();
 virtual void Pad32();
 virtual void Pad33();
 virtual void Pad34();
 virtual void Pad35();
 virtual void Pad36();
 virtual void Pad37();
 virtual void Pad38();
 virtual void Pad39();
 virtual void Pad40();
 virtual void Pad41();
 virtual void Pad42();
 virtual void Pad43();
 virtual void Pad44();
 virtual void Pad45();
 virtual void Pad46();
 virtual void Pad47();
 virtual void Pad48();
 virtual void Pad49();
 virtual void Pad50();
 virtual void Pad51();
 virtual void Pad52();
 virtual void Pad53();
 virtual void Pad54();
 virtual void Pad55();
 virtual void Pad56();
 virtual void Pad57();
 virtual void Pad58();
 virtual void Refresh();
};
// Original: arm9/ov004 @ 0x02154C78; symbol: func_ov004_02154c78; size: 0x130.
extern "C" int Object_UpdateAvailabilityOfSelectedWidgets(void* self) {
 Widget* selected=(Widget*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x39);
 if(!selected)return 0;
 if(MenuRecord_GetType(selected)!=0x12)return 0;
 selected->Refresh();
 if(!selected)return 0;
 if(*(short*)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage+0x7a)==0) {
  Widget* target=(Widget*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x1a);
  if(target)target->SetMode(0);
 }
 if(!Menu_SumCompletedSubtypeCounts()) {
  Widget* target=(Widget*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x1b);
  if(target)target->SetMode(0);
 }
 if(!SumSixIndexedEntryByteValues()) {
  Widget* target=(Widget*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x1c);
  if(target)target->SetMode(0);
 }
 if(!GameState_ReadEntrySevenByteCount()) {
  Widget* target=(Widget*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x1d);
  if(target)target->SetMode(0);
 }
 return 0;
}
