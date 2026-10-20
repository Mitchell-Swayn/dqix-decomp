#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#pragma opt_propagation off
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* Menu_FindInventorySpriteByKey(void*,unsigned);
extern "C" void Menu_SetSpriteCellIndex(void*,unsigned short);
// Original: arm9/ov004 @ 0x0215AEA8; symbol: func_ov004_0215aea8; size: 0x6C.
// Advances the selected decimal digit, wraps it at ten, and updates its keyed display record.
extern "C" int Graphics_AdvanceSelectedDecimalDigit(void* self) {
 unsigned index=MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2][0x3e];
 signed char* digits=(signed char*)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+0x3f;
 ++digits[index];
 if(digits[index]>=10)digits[index]=0;
 void* record=Menu_FindInventorySpriteByKey(self,MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2][0x3e]+0x2d);
 if(record)Menu_SetSpriteCellIndex(record,(unsigned short)(digits[index]+0x1a));
 return 0;
}
