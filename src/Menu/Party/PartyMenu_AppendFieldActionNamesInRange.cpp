#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*, int, const char*);
extern "C" int Text_AppendFormatString(char*, const char*);
extern "C" void Util_SetRecordProgressFlags(char*, unsigned, unsigned, unsigned);
#pragma always_inline on
static inline int IsPartyMemberIndex(int member) {
    return member >= 0 && member <= 3;
}
#pragma force_active on
// Original: arm9/ov002 @ 0x0215ECE4; symbol: func_ov002_0215ece4; size: 0xe4.
// Appends existing action names from the requested range and updates its eight-entry page controls.
extern "C" void PartyMenu_AppendFieldActionNamesInRange(void* owner, char* output, int member, int first, int last) {
    char* self = (char*)owner;
    int row = 0;
    if (IsPartyMemberIndex(member)) {
        for (int i = first; i < last; ++i) {
            char* action = *(char**)(self + 0x24a0 + i * 4);
            if (action) {
                Text_AppendFormattedIntegerAndStringFragment(output, row, *(const char**)action);
                if (i != last - 1) Text_AppendFormatString(output, *(const char**)(self + 0x1bdc));
                ++row;
            }
        }
    }
    unsigned char count = *(unsigned char*)(self + 0x2520);
    if (!count) Util_SetRecordProgressFlags(self, 17, 0, 0);
    else Util_SetRecordProgressFlags(self, 17, first / 8, (count + 7) / 8);
}
