// VerifyDownloadPlayStruct inverts this64-byte key before digest verification.
// Original data: arm9/main @ 0x20ed6ec; symbol: data_020ed6ec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2106c0deba98ce3fa692e39d46f2ed0176e3cc08562363facad4ecdf9a6278348f6d633cfe22ca9220889723d2cfaec232678dfeca836498acfd3e3787465824 ...; full span in module reference.
// Observed span: 320 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const unsigned char SharedData_UnknownRoleInitializedBytes_Variant51[];
struct DownloadPlayVerificationKeyDescriptor { const void* pointer; unsigned length; };
// Original data: arm9/main @ 0x20f2290; symbol: data_020f2290.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex ecd60e0240000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" DownloadPlayVerificationKeyDescriptor VerifyDownloadPlayStruct_UnknownRoleDataReferences = { SharedData_UnknownRoleInitializedBytes_Variant51, 64 };
