#include <globaldefs.h>
ARM
struct Record; struct Owner; struct State;
extern "C" void WriteFieldD8Bit0AndResetProgress(unsigned char* self,unsigned int value);
extern "C" void SetMaskedFlagsAtOffsetD9(unsigned char* p,int v);
extern "C" void Object_SetElement218AndSetElement216To2(unsigned char* p, unsigned char v);
extern "C" Record* FindReadyRecordByIdBeforeStopIndex(Owner* self,unsigned id);
extern "C" void* GetCurrentRecordUnlessIdentifierAlreadyExists(State* self,unsigned id);
// Original: arm9/ov002 @ 0x0215B918; symbol: func_ov002_0215b918; size: 0x8C.
extern "C" void Util_SetRecordProgressFlags(char *self, unsigned id, unsigned flags, unsigned value) {
    char *part = self + 0x2c8;
    unsigned char *record = (unsigned char*)FindReadyRecordByIdBeforeStopIndex((Owner*)(part + 0xc00), id);
    if (!record) {
        record = (unsigned char*)GetCurrentRecordUnlessIdentifierAlreadyExists((State*)(part + 0xc00), id);
        if (!record) return;
    }
    if (value) {
        WriteFieldD8Bit0AndResetProgress(record, 1);
        SetMaskedFlagsAtOffsetD9(record, (unsigned char)flags);
        Object_SetElement218AndSetElement216To2(record, (unsigned char)value);
    } else {
        WriteFieldD8Bit0AndResetProgress(record, 0);
        SetMaskedFlagsAtOffsetD9(record, 0);
        Object_SetElement218AndSetElement216To2(record, 0);
    }
}
