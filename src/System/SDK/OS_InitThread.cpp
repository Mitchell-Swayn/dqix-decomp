#include "System/ProcessorContext.h"
#include "Memory/Arena.h"
#pragma thumb off
#pragma optimize_for_size off
// Absolute linker values (USA 0 and 0x400), not objects to dereference.
// Their bindings already live in config/usa/arm9/linker_symbols.json.
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern char Entry_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x2111308; symbol: data_02111308.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ProcessorContext* OSInitThread_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/main @ 0x020C745C; symbol: func_020c745c; size: 0x148.
// NitroSDK OS_InitThread: initialize launcher and idle contexts once.
extern "C" void OS_InitThread()
{
    if (OSInitThread_UnknownRoleZeroInitializedStorage.hasSetupPrimaryContext) return;
    OSInitThread_UnknownRoleZeroInitializedStorage.hasSetupPrimaryContext = 1;
    OSInitThread_UnknownRoleZeroInitializedStorage.ppActiveContext = &OSInitThread_UnknownRoleZeroInitializedStorage_Variant3;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.priority = 16;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.uniqueID = 0;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.blockState = CONTEXT_STATE_READY;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.pNext = 0;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.unknown_74 = 0;
    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext = &OSInitThread_UnknownRoleZeroInitializedStorage_Variant5;
    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.activeContext = &OSInitThread_UnknownRoleZeroInitializedStorage_Variant5;
    unsigned int stackLow = (int)SDK_SYS_STACKSIZE <= 0
        ? 0x027e0080 - (int)SDK_SYS_STACKSIZE
        : (unsigned int)Entry_UnknownRoleProcedureReferenceRecords + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE - (int)SDK_SYS_STACKSIZE;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.stackBottom = (unsigned int)Entry_UnknownRoleProcedureReferenceRecords + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.stackTop = stackLow;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.stackUnknownTopSubspaceSize = 0;
    *(unsigned int*)(OSInitThread_UnknownRoleZeroInitializedStorage.contextB.stackBottom - 4) = STACK_BOTTOM_MAGIC;
    *(unsigned int*)OSInitThread_UnknownRoleZeroInitializedStorage.contextB.stackTop = STACK_TOP_MAGIC;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextB.contextsAwaitingThisCompletion.first =
        OSInitThread_UnknownRoleZeroInitializedStorage.contextB.contextsAwaitingThisCompletion.last = 0;
    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.unknown_0 = 0;
    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.unknown_2 = 0;
    *(Struct_02111304**)0x027fffa0 = &OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
    SetSwitchContextProcB(0);
    // The following arena-state object marks the end of the 200-byte idle stack.
    PopulateProcessorContext(&OSInitThread_UnknownRoleZeroInitializedStorage_Variant4, (unsigned int)InterruptWaitLoopFunction, 0,
        (unsigned int)&g_arenaInitializationState, 200, 31);
    OSInitThread_UnknownRoleZeroInitializedStorage.contextA.priority = 32;
    OSInitThread_UnknownRoleZeroInitializedStorage.contextA.blockState = CONTEXT_STATE_READY;
}
