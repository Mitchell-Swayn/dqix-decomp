#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fe3e4; symbol: data_ov023_021fe3e4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 906f1f0230711f0234711f0284691f0288691f02186a1f02806f1f0258711f0274711f0258741f0250741f024c741f0244741f0240741f0238741f0288711f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned MenuInitializeContainerRenderRecord_UnknownRoleProcedureReferenceRecords;
extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void *);
extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void *);
// Original: arm9/ov004 @ 0x0215C448; symbol: ZoneRenderPart_InitializeEmbeddedEntriesAndContainer; size: 0x2C.
// Sets the zone-render-part vtable, resets embedded render-part entries and container state, and returns the object.
extern "C" void *ZoneRenderPart_InitializeEmbeddedEntriesAndContainer(void *object) {
    *(unsigned *)object = (unsigned)&MenuInitializeContainerRenderRecord_UnknownRoleProcedureReferenceRecords;
    _ZN21ZoneRenderPartEntries5ResetEv((char *)object + 0x34);
    _ZN23ZoneContainerRenderPart5ResetEv((char *)object + 0x20);
    return object;
}
