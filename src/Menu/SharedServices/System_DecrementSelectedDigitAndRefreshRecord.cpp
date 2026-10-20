#pragma thumb off
#pragma optimize_for_size off
struct Digits {char pad[0x3e];unsigned char index;signed char values[1];};
struct Globals {char pad[8];Digits* digits;};
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Globals MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void* Menu_FindInventorySpriteByKey(void*,unsigned);
extern "C" void Menu_SetSpriteCellIndex(void*,unsigned short);
// Original: arm9/ov004 @ 0x0215AF14; symbol: func_ov004_0215af14; size: 0x6C.
extern "C" int System_DecrementSelectedDigitAndRefreshRecord(void* state) {
 signed char* digits=MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.digits->values;
 unsigned char index=MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.digits->index;
 digits[index]--;
 if(digits[index]<0)digits[index]=9;
 void* record=Menu_FindInventorySpriteByKey(state,MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.digits->index+0x2d);
 if(record)Menu_SetSpriteCellIndex(record,(unsigned short)(digits[index]+0x1a));
 return 0;
}
