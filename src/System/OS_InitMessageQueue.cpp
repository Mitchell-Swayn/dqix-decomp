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
// Original: arm9/main @ 0x020C7DE4; symbol: func_020c7de4; size: 0x28.
extern "C" void OS_InitMessageQueue(int* p,int a,int b){p[1]=0;p[0]=0;p[3]=0;p[2]=0;p[4]=a;p[5]=b;p[6]=0;p[7]=0;}
