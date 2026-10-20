#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(void*);
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const char* ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021F5788; symbol: func_ov023_021f5788; size: 0x3C.
extern "C" int Resource_StoreStringForMatchingSupportedLanguage(const void* p) {
    int language = _ZNK6Script9Parameter5ToIntEv(p);
    void* gameState = _ZN9GameState11GetInstanceEv();
    if (language == GameState_ReadSupportedFirmwareLanguage(gameState)) {
        *(const char**)((char*)&ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage + 0x10) = _ZNK6Script9Parameter8ToStringEv((const char*)p + 8);
    }
    return 1;
}
