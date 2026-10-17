#include <globaldefs.h>
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, void*, int);
struct MessagePayload1B { unsigned char opcode; unsigned char pad[3]; };
// Original: arm9/ov017 @ 0x021D2400; symbol: func_ov017_021d2400; size: 0x28.
extern "C" ARM void DispatchMessageOpcode1B() { void* context=ReadGlobalAt02100044(); unsigned char payload[20]; payload[0]=0x1b; MoveQueuedRecordAndApplySourceValue(context, payload, 0); }
