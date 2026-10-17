#include "System/ProcessorContext.h"
#include "Memory/Arena.h"
#pragma thumb off
#pragma optimize_for_size off
// Absolute linker values (USA 0 and 0x400), not objects to dereference.
// Their bindings already live in config/usa/arm9/linker_symbols.json.
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char data_027e0000[];
extern ProcessorContext* data_02111308;
// Original: arm9/main @ 0x020C745C; symbol: func_020c745c; size: 0x148.
// NitroSDK OS_InitThread: initialize launcher and idle contexts once.
extern "C" void OS_InitThread()
{
    if (data_021112e0.hasSetupPrimaryContext) return;
    data_021112e0.hasSetupPrimaryContext = 1;
    data_021112e0.ppActiveContext = &data_02111308;
    data_021112e0.contextB.priority = 16;
    data_021112e0.contextB.uniqueID = 0;
    data_021112e0.contextB.blockState = CONTEXT_STATE_READY;
    data_021112e0.contextB.pNext = 0;
    data_021112e0.contextB.unknown_74 = 0;
    data_021112e0.substruct_24.firstContext = &data_021113d4;
    data_021112e0.substruct_24.activeContext = &data_021113d4;
    unsigned int stackLow = (int)SDK_SYS_STACKSIZE <= 0
        ? 0x027e0080 - (int)SDK_SYS_STACKSIZE
        : (unsigned int)data_027e0000 + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE - (int)SDK_SYS_STACKSIZE;
    data_021112e0.contextB.stackBottom = (unsigned int)data_027e0000 + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE;
    data_021112e0.contextB.stackTop = stackLow;
    data_021112e0.contextB.stackUnknownTopSubspaceSize = 0;
    *(unsigned int*)(data_021112e0.contextB.stackBottom - 4) = STACK_BOTTOM_MAGIC;
    *(unsigned int*)data_021112e0.contextB.stackTop = STACK_TOP_MAGIC;
    data_021112e0.contextB.contextsAwaitingThisCompletion.first =
        data_021112e0.contextB.contextsAwaitingThisCompletion.last = 0;
    data_021112e0.substruct_24.unknown_0 = 0;
    data_021112e0.substruct_24.unknown_2 = 0;
    *(Struct_02111304**)0x027fffa0 = &data_02111304;
    SetSwitchContextProcB(0);
    // The following arena-state object marks the end of the 200-byte idle stack.
    PopulateProcessorContext(&data_02111314, (unsigned int)InterruptWaitLoopFunction, 0,
        (unsigned int)&g_arenaInitializationState, 200, 31);
    data_021112e0.contextA.priority = 32;
    data_021112e0.contextA.blockState = CONTEXT_STATE_READY;
}
