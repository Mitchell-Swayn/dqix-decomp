#include <globaldefs.h>
struct EmbeddedObject { const void* vtable; char header[0x1c]; char member20[0x14]; char member34[4]; };
// Original data: arm9/ov023 @ 0x21fe3e4; symbol: data_ov023_021fe3e4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 906f1f0230711f0234711f0284691f0288691f02186a1f02806f1f0258711f0274711f0258741f0250741f024c741f0244741f0240741f0238741f0288711f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned MenuInitializeContainerRenderRecord_UnknownRoleProcedureReferenceRecords[];
extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void*);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void*);
// Original: arm9/ov011 @ 0x02185110; symbol: func_ov011_02185110; size: 0x2C.
extern "C" EmbeddedObject* Menu_InitializeContainerRenderRecord(EmbeddedObject* self) {
 self->vtable = MenuInitializeContainerRenderRecord_UnknownRoleProcedureReferenceRecords;
 _ZN21ZoneRenderPartEntries5ResetEv(self->member34);
 _ZN23ZoneContainerRenderPart5ResetEv(self->member20);
 return self;
}
