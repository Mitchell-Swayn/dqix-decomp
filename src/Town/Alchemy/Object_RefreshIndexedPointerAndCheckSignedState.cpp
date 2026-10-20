#include <globaldefs.h>
extern "C" void KrakPot_CycleIngredientPagePreservingRow(void*);
extern "C" void KrakPot_RefreshSelectedIngredientPreview(void*);
extern "C" int HandlePageAndScreenToggleInput(void*);
// Original: arm9/ov006 @ 0x02159564; symbol: func_ov006_02159564; size: 0x50.
extern "C" int Object_RefreshIndexedPointerAndCheckSignedState(void* object) {
    *(void**)((char*)object + 0x44) = (char*)object + 0x364;
    KrakPot_CycleIngredientPagePreservingRow(object);
    short current = *(short*)((char*)object + 0x35e);
    short target = **(short**)((char*)object + 0x44);
    if (current != target) {
        KrakPot_RefreshSelectedIngredientPreview(object);
        return 0;
    }
    return HandlePageAndScreenToggleInput(object) != 0;
}
