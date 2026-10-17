#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CC2F0; symbol: func_ov017_021cc2f0; size: 0x30.
extern "C" void System_MoveQueuedRecordWithTypeSixDescriptor(unsigned char value) { unsigned char descriptor[0x14]; void* object = ReadGlobalAt02100044(); descriptor[0] = 6; descriptor[4] = value; MoveQueuedRecordAndApplySourceValue(object, descriptor, 0); }
