#include <globaldefs.h>
struct EmbeddedObject { const void* vtable; char header[0x20]; char member24[4]; };
// Original data: arm9/ov023 @ 0x21feb40; symbol: data_ov023_021feb40.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 7ca81f0258aa1f025caa1f0284691f0288691f02186a1f02d4a71f02189b1f021c8c1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant5[];
extern "C" void Graphics_InitializeSpriteResourceBuffers(void*);
// Original: arm9/ov011 @ 0x02185CE0; symbol: func_ov011_02185ce0; size: 0x24.
extern "C" EmbeddedObject* Menu_ConstructSpriteResourceRecord(EmbeddedObject* self) {
 self->vtable = SharedData_UnknownRoleProcedureReferenceRecords_Variant5;
 Graphics_InitializeSpriteResourceBuffers(self->member24);
 return self;
}
