#include <globaldefs.h>
extern "C" void BackgroundLoader_CancelTaskAndResetCountAndValue(void*);
extern "C" void ClearRecordAndInvalidateTwoIndices(void*);
// Three-argument path formatter contract used here: the mode is sign extended
// from a 16-bit input into r2; the result is ignored.
extern "C" bool FormatTextAndReplaceMatchingSuffix(char*, const char*, short);
extern "C" void ManageQueuedBackgroundFileLoadByState(void*, const void*, const void*);
struct DfcScratch { char second[32]; char first[32]; char spare[32]; };
// Original: arm9/main @ 0x020DFC84; symbol: func_020dfc84; size: 0xBC.
extern "C" ARM void Object_ConfigureMemberAndOptionalFormattedTextPair(void* self, void* member, const char* first, const char* second, short mode, short value)
{
    DfcScratch scratch;
    BackgroundLoader_CancelTaskAndResetCountAndValue(self);
    ClearRecordAndInvalidateTwoIndices(self);
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(self) + 0x14) = member;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(self) + 0x0c) = value;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(self) + 0x0e) = 1;
    if (mode >= 0) {
        FormatTextAndReplaceMatchingSuffix(scratch.first, first, mode);
        if (second != 0) {
            FormatTextAndReplaceMatchingSuffix(scratch.second, second, mode);
            ManageQueuedBackgroundFileLoadByState(self, scratch.first, scratch.second);
        } else {
            ManageQueuedBackgroundFileLoadByState(self, scratch.first, 0);
        }
    } else {
        if (second) ManageQueuedBackgroundFileLoadByState(self, first, second);
        else ManageQueuedBackgroundFileLoadByState(self, first, 0);
    }
}
