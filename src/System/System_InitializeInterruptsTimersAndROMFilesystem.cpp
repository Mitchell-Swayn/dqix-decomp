#include <globaldefs.h>
ARM
#include <System/Timing.h>
#include <System/Interrupts.h>
void InitializeResourceMutex();void InitializeROMFilesystem(int);unsigned ChangeROMLoadDMAChannel(unsigned);
extern "C" void System_InitializeCoreSubsystems(),FX_Init(),GX_Init(),PowerManagement_InitializeIPCHandler(),RealTimeClock_InitializeIPCHandler(),OS_InitVAlarm(),Filesystem_InitializeCardReadingAndLockOwner(),Sound_InitializeManagerAndLifecycleCallbacks(),Input_InitializeSuppressionAndEnableSampling(),System_HandleVBlankAndRefreshBrightness();
extern "C" void Graphics_WriteVBlankInterruptEnableAndReturnOldBit(int,unsigned short),AllocatorUnion_InitializeFromRemainingArena(void*),Input_InitializeKeyStateAndRepeatDefaults(void*),TouchInput_InitializeCalibratedSamplingState(void*);
// Original data: arm9/main @ 0x2114e00; symbol: data_02114e00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[],KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[],GraphicsAdvanceTimedFrameSequence_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02012C34; symbol: func_02012c34; size: 0xE4.
extern "C" void System_InitializeInterruptsTimersAndROMFilesystem(){
 System_InitializeCoreSubsystems();FX_Init();LoadToSubOAM_UnknownRoleInitializedBytes=0;GX_Init();PowerManagement_InitializeIPCHandler();RealTimeClock_InitializeIPCHandler();Initialize64BitTimer();InitializeActiveAlarmList();OS_InitVAlarm();InitializeResourceMutex();SetSpecificInterruptsEnabled(0);SetInterruptHandler(1,(void*)System_HandleVBlankAndRefreshBrightness);EnableSpecificInterrupts(1);EnableSpecificInterrupts(0xf08);
 volatile unsigned short* reg=(volatile unsigned short*)0x04000208;unsigned short old=*reg;*reg=1;Graphics_WriteVBlankInterruptEnableAndReturnOldBit(1,old);AllocatorUnion_InitializeFromRemainingArena(Main_UnknownRoleZeroInitializedStorage_Variant3);EnableSpecificInterrupts(0x40000);InitializeROMFilesystem(2);ChangeROMLoadDMAChannel(2);Filesystem_InitializeCardReadingAndLockOwner();Sound_InitializeManagerAndLifecycleCallbacks();Input_InitializeKeyStateAndRepeatDefaults(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage);TouchInput_InitializeCalibratedSamplingState(Main_UnknownRoleZeroInitializedStorage_Variant4);Input_InitializeSuppressionAndEnableSampling();unsigned* last=&FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;GraphicsAdvanceTimedFrameSequence_UnknownRoleZeroInitializedStorage=0;*last=0;
}
