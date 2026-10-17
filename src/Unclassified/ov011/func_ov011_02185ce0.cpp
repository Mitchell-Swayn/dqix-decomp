#include <globaldefs.h>
struct EmbeddedObject { const void* vtable; char header[0x20]; char member24[4]; };
extern "C" const unsigned data_ov023_021feb40[];
extern "C" void InitializeRecordBuffersAndEnabledByte(void*);
// Original: arm9/ov011 @ 0x02185CE0; symbol: func_ov011_02185ce0; size: 0x24.
extern "C" EmbeddedObject* func_ov011_02185ce0(EmbeddedObject* self) {
 self->vtable = data_ov023_021feb40;
 InitializeRecordBuffersAndEnabledByte(self->member24);
 return self;
}
