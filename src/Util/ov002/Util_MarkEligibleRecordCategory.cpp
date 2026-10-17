#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02108E10();
struct Record { char pad[0x18]; unsigned type : 5; unsigned category : 7; unsigned rest : 20; };
extern "C" Record* TryTransformFirstOrSecondEmbeddedRecord(char* p,void* a);
extern "C" void *ReadGlobalValueAt02153637();
extern "C" void RecordArray_SetFirstEmptyFlagWhenModeEnabled(unsigned char *p,unsigned char v);
// Original: arm9/ov002 @ 0x0215B720; symbol: func_ov002_0215b720; size: 0xB0.
extern "C" int Util_MarkEligibleRecordCategory(char *self, unsigned id) {
    int mode = *(int*)(self + 0x1bb8);
    int match = 0;
    if (mode == 6 || mode == 17) {
        if (id == 0x198 || id == 0x22 || id == 0x310) match = 1;
    } else {
        volatile Record *record = TryTransformFirstOrSecondEmbeddedRecord((char*)ReadGlobalAt02108E10(), (void*)id);
        if (record) {
            unsigned category = record->category;
            unsigned type = record->type;
            if (category == 2 || category == 7 || category == 79 || category == 80 || category == 18 || category == 26) match = 1;
            if (type == 5 && *(int*)(self + 0x1bb8) == 7) match = 1;
        }
    }
    if (match) RecordArray_SetFirstEmptyFlagWhenModeEnabled((unsigned char*)ReadGlobalValueAt02153637(), 1);
    return match;
}
