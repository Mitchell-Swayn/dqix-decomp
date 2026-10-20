#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
struct SharedCursorState { char unknown0[0x30]; volatile unsigned cursor; char unknown34[0x24]; unsigned char* bytes; unsigned limit; };
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" SharedCursorState NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02200BB8; symbol: func_ov031_02200bb8; size: 0x44.
// Advances the byte cursor by the current record's halfword length, wrapping at the stored limit under IRQ protection.
// Shared layout is a projection of the observed offsets only.
extern "C" void Network_ConsumeReceivedEthernetFrame()
{
 int irq=DisableIRQInterrupts();
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.cursor+=*(unsigned short*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.bytes+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.cursor);
 if(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.cursor>=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.limit)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.cursor=0;
 SetIRQInterruptState(irq);
}
