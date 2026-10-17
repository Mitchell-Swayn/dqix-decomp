#include <globaldefs.h>
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void func_ov017_02192654(void*, unsigned short, unsigned char);
extern "C" void FieldMonster_HideByRecordIdentifier(void*, unsigned short);
// Original: arm9/ov017 @ 0x021D0AE4; symbol: func_ov017_021d0ae4; size: 0x4C.
extern "C" ARM void Ov017_ApplyRecordWhenIndexInactive(void* target, unsigned char* record, void* unused, void* owner, unsigned* indexState) {
    if (TestInactiveOrPrimaryIndexState(indexState)) {
        func_ov017_02192654(target, *(unsigned short*)(record + 4), record[6]);
        return;
    }
    if (!target)
        FieldMonster_HideByRecordIdentifier(owner, *(unsigned short*)(record + 4));
}
