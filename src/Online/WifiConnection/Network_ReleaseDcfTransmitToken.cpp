#include <globaldefs.h>
ARM
extern "C" void Ov031_DecrementBlockedContextCount(void *);
// Original data: arm9/ov031 @ 0x224e54c; symbol: data_ov031_0224e54c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220F2CC; symbol: func_ov031_0220f2cc; size: 0x14.
extern "C" void Network_ReleaseDcfTransmitToken(void) { Ov031_DecrementBlockedContextCount(&NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage); }
