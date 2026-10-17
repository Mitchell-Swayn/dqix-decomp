#include <globaldefs.h>
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, void*, int);
struct MessagePayload3C { unsigned char opcode; unsigned char pad[3]; unsigned char value; };
// Original: arm9/ov017 @ 0x021D440C; symbol: func_ov017_021d440c; size: 0x30.
extern "C" ARM void DispatchByteMessageOpcode3C(int value) { void* context=ReadGlobalAt02100044(); unsigned char payload[20]; payload[0]=0x3c; payload[4]=(unsigned char)value; MoveQueuedRecordAndApplySourceValue(context, payload, 0); }
