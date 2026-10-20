#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_SaveDisplayModeAndClearDisplayModeBits();
extern "C" bool _Z23Is64BitTimerInitializedv();
extern "C" bool _Z22IsAlarmListInitializedv();
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void Graphics_WriteVBlankInterruptEnableAndReturnOldBit(int);
extern "C" void FX_Init();
extern "C" void _Z23InitializeROMFilesystemi(int);
extern "C" void TouchInput_InitializeIPCHandler();
extern "C" void RealTimeClock_InitializeIPCHandler();
extern "C" void Filesystem_InitializeOverlayArchiveHandle();
extern "C" void Memory_InitializeHPXEAllocatorAtLocation(void*);
extern "C" void Input_InitializeCalibratedTouchSampling();
extern "C" void WfcUtility_InitializeTaskQueues();
extern "C" void Ov031_InstallVBlankInterrupt();
extern "C" void Graphics_SaveVramMappingsAndClearDisplayMemory();
extern "C" void Graphics_ConfigureDisplayBrightness();
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void WfcUtility_LoadAndRepairSettingsPages();
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02227128; symbol: System_InitializeModalOverlayServices; size: 0xc8.
// Initializes modal overlay display, SDK timer/alarm prerequisites, input, archive and temporary allocation.
extern "C" void System_InitializeModalOverlayServices(){(void)*(volatile unsigned short*)0x4000208;*(volatile unsigned short*)0x4000208=0;Graphics_SaveDisplayModeAndClearDisplayModeBits();*(volatile unsigned*)0x4001000&=~0x10000;if(!_Z23Is64BitTimerInitializedv())DisableInterruptsAndHaltForever();if(!_Z22IsAlarmListInitializedv())DisableInterruptsAndHaltForever();Graphics_WriteVBlankInterruptEnableAndReturnOldBit(0);FX_Init();_Z23InitializeROMFilesystemi(-1);TouchInput_InitializeIPCHandler();RealTimeClock_InitializeIPCHandler();Graphics_SaveDisplayModeAndClearDisplayModeBits();*(volatile unsigned*)0x4001000&=~0x10000;Graphics_SaveVramMappingsAndClearDisplayMemory();Memory_InitializeHPXEAllocatorAtLocation((void*)Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[1]);Ov031_InstallVBlankInterrupt();WfcUtility_InitializeTaskQueues();Filesystem_InitializeOverlayArchiveHandle();Input_InitializeCalibratedTouchSampling();Graphics_ConfigureDisplayBrightness();void* allocation=Memory_AllocateZeroedBlock(0x700,32);WfcUtility_LoadAndRepairSettingsPages();WfcUtility_FreeAllocationAndClearPointer(&allocation);}
