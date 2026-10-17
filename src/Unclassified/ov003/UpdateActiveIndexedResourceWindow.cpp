#include <globaldefs.h>
ARM
extern "C" void ResetEachIndexedEntryResource(void *);
extern "C" void WriteWordPairAtOffsets4And8(void *, unsigned int, unsigned int);
extern "C" unsigned int ReadBit(void **);
extern "C" void RegisterBit_UpdateSelectedBankWhenValueChanges(void *, unsigned int);
extern "C" void Window_SetWidgetPositionAndToggleTwoOptions(void *);
// Original: arm9/ov003 @ 0x02159100; symbol: func_ov003_02159100; size: 0x6C.
extern "C" void UpdateActiveIndexedResourceWindow(void *owner) {
    if (*(signed char *)((char *)owner + 0x588) == 0) return;
    if (*((unsigned char *)owner + 0x587) != 0) return;
    ResetEachIndexedEntryResource((char *)owner + 0xf4);
    void *resource = *(void **)((char *)owner + 0x570);
    if (resource == 0) return;
    void *inner = *(void **)((char *)resource + 0x10);
    WriteWordPairAtOffsets4And8((char *)inner + 0x28, 0x11, 1);
    unsigned int bit = ReadBit((void **) * (void **)((char *)owner + 0x570));
    RegisterBit_UpdateSelectedBankWhenValueChanges((char *)inner + 0x28, bit);
    Window_SetWidgetPositionAndToggleTwoOptions(*(void **)((char *)owner + 0x570));
}
