// ARM instruction behavior reviewed; fields retain known byte offsets.
// Original data: arm9/main @ 0x210f840; symbol: data_0210f840.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char ResourceManagerSetIndexedThirtySixByteRecordValue_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020979C0; symbol: func_020979c0; size: 0x34.
extern "C" void VRAMBankConfig_Initialize(char* p,int v){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+8)=0;*(int*)(p+12)=0;*(int*)(p+16)=0;*(int*)(p+20)=0;*(int*)(p+24)=-1;p[28]=0;p[29]=v;p[30]=0;}
