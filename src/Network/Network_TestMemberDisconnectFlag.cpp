// Reviewed ARM field widths and callee argument/return behavior; symbols follow original relocation targets.
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21056b4; symbol: data_021056b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210782c; symbol: data_0210782c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {int Network_GetAssociationId();void Window_ReadResourceFormatAndLayer(void*,unsigned char*,unsigned char*);void Graphics_ResetCharacterResourceHeader(void*);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int memcmp(const void*,const void*,unsigned);extern char* TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[];int Network_FindWirelessSlotByMemberId(void*,int);int Network_FindPreviousWirelessSlotByMemberId(void*,int);void TextCache_Reset(void*);extern char GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage[];extern char* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage[];}struct Nibbles{unsigned char low:4;unsigned char high:4;};struct SignedSix{signed char value:6;unsigned char rest:2;};
// Original: arm9/main @ 0x0202C578; symbol: func_0202c578; size: 0x44.
extern "C" unsigned Network_TestMemberDisconnectFlag(char* p,int key){int i=Network_FindWirelessSlotByMemberId(p,key);if(i<0){i=Network_FindPreviousWirelessSlotByMemberId(p,key);if(i<0)return 0;}return *(unsigned char*)(p+0x100e)&(1<<i);}
