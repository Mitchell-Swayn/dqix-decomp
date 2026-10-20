// Original ARM range reviewed. Opaque offsets document observed fields.
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109da6; symbol: data_02109da6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[];extern "C" char OverlayLoaderSetSecondarySelection_UnknownRoleZeroInitializedStorage[];extern "C" char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0202D0B4; symbol: func_0202d0b4; size: 0x2C.
extern "C" int Network_RequestPeerDiscoveryStop(){if(*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)!=2)return 0;*(short*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+4)=0;*(int*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=3;return 1;}
