// ARM control flow, field widths and constants reviewed.
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Mode{unsigned int low:23;unsigned int mode:3;unsigned int high:6;};struct Nibble{unsigned char low:4;unsigned char high:4;};struct Field{unsigned short low:9;unsigned short mode:3;unsigned short high:4;};struct Low{unsigned int flag:1;unsigned int rest:31;};struct Bit5{unsigned int low:5;unsigned int flag:1;unsigned int rest:26;};extern "C" unsigned int PMGoSleepMode_UnknownRoleZeroInitializedStorage[];extern "C" void* DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);void CleanInvalidateCacheRange(void*,unsigned int);
// Original: arm9/main @ 0x02085078; symbol: func_02085078; size: 0x2C.
extern "C" int CharacterState_HasEquippedWeaponTraitBitZero(char* p){if(*(short*)(p+0x2ac)<=0)return 0;return ((Low*)(p+0x2f4))->flag!=0;}
