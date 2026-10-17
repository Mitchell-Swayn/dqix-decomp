#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" int IsFirstWordNonzero(void *);
extern "C" int ReadIndexedSignedField1038(char *);
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021D1CB8; symbol: func_ov017_021d1cb8; size: 0x48.
extern "C" void Ov017_QueueConnectionStateRecord(void) {
    if (IsFirstWordNonzero(Object_GetGlobalConnectionState()) != 0) {
        if (ReadIndexedSignedField1038((char *)Object_GetGlobalConnectionState()) == 0) {
            void *object = ReadGlobalAt02100044();
            unsigned char record[20];
            record[0] = 0xb4;
            MoveQueuedRecordAndApplySourceValue(object, record, 0);
        }
    }
}
