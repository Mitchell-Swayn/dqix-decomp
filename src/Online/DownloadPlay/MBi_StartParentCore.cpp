#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/IPC.h>
#include <System/Memory.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
#pragma optimize_for_size on
#pragma optimization_level 4
#pragma opt_common_subs off
extern "C" void Network_SetParentStateCallback(void *callback);
extern "C" void Network_InitializeSendGameInfoStatus(void);
extern "C" int MBi_StartCommon(void);
extern "C" void Network_SetChildMPMaxSize(int size);
extern "C" void SetParentPieceBufferAndClear(void *buffer);
extern "C" void MBi_CommParentCallback(void *);
extern "C" void MBi_HandleParentWirelessEvent(void *);
struct ParentCore {
    unsigned char pad[0x1318];
    unsigned blockSize;
    unsigned char gap[0x14e4 - 0x131c];
    void *callback;
    unsigned states[15];
    unsigned char field1524, pad1;
    signed char slots[15];
};
struct CoreState {
    unsigned char pad[0x32];
    unsigned short channel, parentSize, childSize;
    unsigned char gap[0x500 - 0x38];
    unsigned short maxParent, maxChild;
    unsigned unused;
    void *request;
    unsigned char gap1[0x518 - 0x50c];
    unsigned short sendBuffer, receiveBuffer;
    void *callback;
    unsigned char gap2[4];
    unsigned short mode;
};
struct CoreContext {
    unsigned unused;
    void *work;
    CoreState *state;
    unsigned char *parent;
};
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
#define S ((CoreContext *)MBEnd_UnknownRoleZeroInitializedStorage)
#define P ((ParentCore *)S->parent)
// Original: arm9/ov027 @ 0x021DCA40; symbol: func_ov027_021dca40; size: 0x1e4.
// Starts parent multiboot by clearing child slots, installing callbacks, and aligning packet buffers.
extern "C" int MBi_StartParentCore(void *argument)
{
    unsigned len = 0x69c0;
    int irq = DisableIRQInterrupts();
    S->state->channel = (unsigned short)(unsigned)argument;
    unsigned char *parent = S->parent;
    void *work = (void *)(((unsigned)parent + 0x1f + 0x7d00) & ~31u);
    S->work = work;
    void *callback = ((ParentCore *)parent)->callback;
    MIi_CpuClear16(0, parent + 0x1340, len);
    Network_SetParentStateCallback(callback);
    P->blockSize = S->state->maxParent - 6;
    Network_SetChildMPMaxSize(S->state->maxChild);
    SetParentPieceBufferAndClear(S->parent + 0x1538);
    for (int i = 0; i < 15; i++) {
        P->states[i] = 0;
        P->slots[i] = -1;
    }
    P->field1524 = 0;
    MIi_CpuClear16(0, S->parent + 0x1788, 0x5d40);
    VectorizedMemset(S->parent + 0x1754, 0, 30);
    S->state->mode = 1;
    S->state->callback = (void *)MBi_CommParentCallback;
    S->state->request = (void *)MBi_HandleParentWirelessEvent;
    S->state->parentSize = S->state->maxParent;
    S->state->sendBuffer = (S->state->parentSize + 35) & ~31u;
    S->state->childSize = S->state->maxChild;
    S->state->receiveBuffer = (unsigned short)((((S->state->childSize + 14) * 15 + 41) & ~31u) * 2);
    Network_InitializeSendGameInfoStatus();
    int result = MBi_StartCommon();
    SetIRQInterruptState(irq);
    *(unsigned *)(S->parent + 0x74c8) = (unsigned)IsIPCCommandHandlerRegistered(15, IPCSide_Arm7);
    return result;
}
