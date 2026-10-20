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
// Original: arm9/main @ 0x0206F7F4; symbol: func_0206f7f4; size: 0x28.
extern "C" int Script_ReadResultListValue(char* p,int i){if(i<0 || *(int*)(p+4)<=i)return -1;return *(short*)(p+i*2+8);}
