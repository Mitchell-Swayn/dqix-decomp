#include <globaldefs.h>
extern "C" void *OV017_GetEmbeddedField1C(void *);
extern "C" void *OV017_ReadWordField6AC(void *);
extern "C" void func_ov000_02163338(void *, unsigned char);
// Original: arm9/ov017 @ 0x021CF024; symbol: func_ov017_021cf024; size: 0x54.
extern "C" void Ov017_UpdateEmbeddedObjectFromRecord(void *unused0, char *record, void *unused2, char *resources) {
    void *object = *(void **)(resources + 0x3718);
    void *embedded = OV017_GetEmbeddedField1C(object);
    void *value = OV017_ReadWordField6AC(object);
    if (value == 0) return;
    if (*(unsigned short *)((char *)embedded + 8) != *(unsigned short *)(record + 4)) return;
    func_ov000_02163338(value, *(unsigned char *)(record + 6));
    *(unsigned char *)((char *)value + 0x7748) = *(unsigned char *)(record + 7);
}
