#include <globaldefs.h>
struct EmbeddedObject { const void* vtable; char header[0x1c]; char member20[0x14]; char member34[4]; };
extern "C" const unsigned data_ov023_021fe3e4[];
extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void*);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void*);
// Original: arm9/ov011 @ 0x02185110; symbol: func_ov011_02185110; size: 0x2C.
extern "C" EmbeddedObject* func_ov011_02185110(EmbeddedObject* self) {
 self->vtable = data_ov023_021fe3e4;
 _ZN21ZoneRenderPartEntries5ResetEv(self->member34);
 _ZN23ZoneContainerRenderPart5ResetEv(self->member20);
 return self;
}
