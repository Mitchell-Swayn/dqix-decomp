#include <globaldefs.h>
ARM
extern "C" void* OV017_GetEmbeddedField1C(void*);
extern "C" void* OV017_ReadWordField6AC(void*);
extern "C" void Util_CallStateHandlerIfLastStackEntryIs3(void*);
// Original: arm9/ov017 @ 0x021CC080; symbol: func_ov017_021cc080; size: 0x4C.
extern "C" void OV017_ApplyMatchingEmbeddedOverride(void *unused0, unsigned char *query, void *unused2, char *owner) {
    void *object = *(void **)(owner + 0x3718);
    void *embedded = OV017_GetEmbeddedField1C(object);
    void *value = OV017_ReadWordField6AC(object);
    if (!embedded) return;
    if (*(unsigned short *)((char *)embedded + 8) != *(unsigned short *)(query + 4)) return;
    if (!value) return;
    Util_CallStateHandlerIfLastStackEntryIs3(value);
}
