#include <globaldefs.h>
ARM
struct Table;
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" int GameState_GetFieldAddress468(int);
extern "C" void* GetFieldAddress114(void*);
extern "C" int DecodePackedDecimalIdentifier(void*);
extern "C" int Object_ReadFlagSelectedIdBitMask(Table*, unsigned);
// Original: arm9/ov017 @ 0x021A26E8; symbol: func_ov017_021a26e8; size: 0x50.
extern "C" int GameState_TestSelectedIdFlag(void* unused, int index) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* object = GameState_GetObjectWithFlag100(state, index);
    if (!object) return 0;
    void* field = GetFieldAddress114(object);
    if (!field) return 0;
    int id = DecodePackedDecimalIdentifier(field);
    return Object_ReadFlagSelectedIdBitMask((Table*)GameState_GetFieldAddress468((int)state), id);
}
