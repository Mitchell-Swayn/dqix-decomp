#include <globaldefs.h>
ARM
#include <System/Timing.h>
#include <System/Interrupts.h>
void InitializeResourceMutex();void InitializeROMFilesystem(int);unsigned ChangeROMLoadDMAChannel(unsigned);
extern "C" void System_InitializeCoreSubsystems(),FX_Init(),GX_Init(),PowerManagement_InitializeIPCHandler(),RealTimeClock_InitializeIPCHandler(),InitializeGlobalInterruptFourStateOnce(),Filesystem_InitializeCardReadingAndLockOwner(),InitializeGlobalResourceCallbacksOnce(),ClearGlobalInputStateAndEnableInputHandlers(),func_02012bd8();
extern "C" void Graphics_WriteVBlankInterruptEnableAndReturnOldBit(int,unsigned short),AllocatorUnion_InitializeFromRemainingArena(void*),Object_InitializeSequentialHalfwordsAndCounter(void*),InitializeGlobalOwnerAndEmbeddedInputState(void*);
extern "C" unsigned data_02114e50;extern "C" char data_02114e20[],data_02114e30[],data_02114e54[],data_02114e00;
// Original: arm9/main @ 0x02012C34; symbol: func_02012c34; size: 0xE4.
extern "C" void System_InitializeInterruptsTimersAndROMFilesystem(){
 System_InitializeCoreSubsystems();FX_Init();data_020f2270=0;GX_Init();PowerManagement_InitializeIPCHandler();RealTimeClock_InitializeIPCHandler();Initialize64BitTimer();InitializeActiveAlarmList();InitializeGlobalInterruptFourStateOnce();InitializeResourceMutex();SetSpecificInterruptsEnabled(0);SetInterruptHandler(1,(void*)func_02012bd8);EnableSpecificInterrupts(1);EnableSpecificInterrupts(0xf08);
 volatile unsigned short* reg=(volatile unsigned short*)0x04000208;unsigned short old=*reg;*reg=1;Graphics_WriteVBlankInterruptEnableAndReturnOldBit(1,old);AllocatorUnion_InitializeFromRemainingArena(data_02114e20);EnableSpecificInterrupts(0x40000);InitializeROMFilesystem(2);ChangeROMLoadDMAChannel(2);Filesystem_InitializeCardReadingAndLockOwner();InitializeGlobalResourceCallbacksOnce();Object_InitializeSequentialHalfwordsAndCounter(data_02114e30);InitializeGlobalOwnerAndEmbeddedInputState(data_02114e54);ClearGlobalInputStateAndEnableInputHandlers();unsigned* last=&data_02114e50;data_02114e00=0;*last=0;
}
