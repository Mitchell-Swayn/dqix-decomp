#include <globaldefs.h>
ARM
struct Object { char pad[0x5d4]; unsigned readyA; unsigned pad2; unsigned readyB; char pad3[0x10]; int index; };
typedef void (Object::*Callback)();
struct CallbackTable { Callback entries[3]; };
extern "C" CallbackTable data_ov023_021fd79c;
// Original: arm9/ov023 @ 0x021E7BC4; symbol: func_ov023_021e7bc4; size: 0x94.
extern "C" void DispatchReadyObjectIndexedMemberCallback(Object* self,int selector,int index) {
 if(self->readyA && self->readyB) {
  int valid;
  if(index>=0 && index<=3) valid=1; else valid=0;
  if(valid) {
   self->index=index;
   CallbackTable table=data_ov023_021fd79c;
   (self->*table.entries[selector])();
  }
 }
}
