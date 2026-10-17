#include <globaldefs.h>
ARM
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned* p);
extern "C" void *ReadGlobalValueAt02153637();
extern "C" char* FindByteKeyAmongEightRecordsWhenContextActive(unsigned char* p,int key);
extern "C" void UpdateActiveContextEntryByIdAndValue(void* p,unsigned id,unsigned value);
extern "C" void ClearMatchingActiveContextEntry(void *p,int id,int value);
// Original: arm9/ov017 @ 0x021CEB28; symbol: func_ov017_021ceb28; size: 0xA4.
extern "C" void Util_ApplyActiveContextEntryUpdate(int mode, unsigned char *input, int unused, int unused2, char *state) {
    unsigned char *context = (unsigned char*)ReadGlobalValueAt02153637();
    if (TestInactiveOrPrimaryIndexState((unsigned*)state) && mode > 0) {
        if (input[4]) {
            UpdateActiveContextEntryByIdAndValue(context, input[5], input[7]);
            return;
        }
        ClearMatchingActiveContextEntry(context, input[5], input[7]);
        return;
    } else if (mode == 0) {
        if (input[7] != ReadIndexedSignedField1038(state)) return;
        char *entry = FindByteKeyAmongEightRecordsWhenContextActive(context, input[5]);
        if (!entry) return;
        if (input[4]) entry[2] = 1;
        else entry[2] = 3;
    }
}
