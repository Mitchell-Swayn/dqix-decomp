#include <globaldefs.h>
ARM
struct Object { char pad[0x5d4]; unsigned readyA; unsigned pad2; unsigned readyB; char pad3[0x10]; int index; };
typedef void (Object::*Callback)();
struct CallbackTable { Callback entries[3]; };
// Original data: arm9/ov023 @ 0x21fd79c; symbol: data_ov023_021fd79c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 8c7d1e0200000000687f1e02000000002c801e0200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" CallbackTable MenuDispatchSecondaryPanelCharacterView_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov023 @ 0x021E7BC4; symbol: func_ov023_021e7bc4; size: 0x94.
extern "C" void Menu_DispatchSecondaryPanelCharacterView(Object* self,int selector,int index) {
 if(self->readyA && self->readyB) {
  int valid;
  if(index>=0 && index<=3) valid=1; else valid=0;
  if(valid) {
   self->index=index;
   CallbackTable table=MenuDispatchSecondaryPanelCharacterView_UnknownRoleProcedureReferenceRecords;
   (self->*table.entries[selector])();
  }
 }
}
