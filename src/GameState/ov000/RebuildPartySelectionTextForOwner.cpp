#include <globaldefs.h>
ARM
extern "C" void* ReadWordFieldAtOffset1C(void*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void func_ov000_02178648(void*, void*);
struct Owner { unsigned char pad[0x18c]; };
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(Owner*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x021785FC; symbol: func_ov000_021785fc; size: 0x4C.
extern "C" void RebuildPartySelectionTextForOwner(Owner* owner) {
    char* text = (char*)*((char**)ReadWordFieldAtOffset1C(owner) + 0x17);
    memset(text, 0, 0x960);
    func_ov000_02178648(owner, text);
    LoadMatchingReadyRecordAndRefreshOwner((Owner*)((char*)owner + 0x188), 8, text, 1, 0);
}
