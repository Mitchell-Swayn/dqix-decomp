#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Interrupts.h>
#include <System/Matrix.h>
ARM
extern "C" {int Card_IsReadManagerIdle();void InvokeGenerationMatchedHandleCallback(int);char* LinkedList_FindNodeByInitialIntegerKey(void*,int);int ObjectPool_SpawnFromTemplate(void*,void*,void*);void InitializeRecordWithInvalidWord30(void*);void InitializeSelectionDefaultsAndByteFields(void*);int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void* ResourceManager_ExchangeGlobalValue(void*);void DispatchValueThroughFirstPointer(void*,int);void* TestInactiveOrPrimaryIndexState(void*);int ReadHalfwordFieldAtOffsetA(void*);char* GetRecordAtResolvedIndexWithStride116(void*,int);void InitializeRecordWithField20Enabled(void*);void ClearMemoryRange192(void*);void Clear456ByteBufferAndInitializeTrailingWords(void*);void ClearOutputWordAndByte(void*);void func_02037aa4(void*,int);void InitializeRecordWithEnabledAndPercentDefaults(void*);void ShiftCurrentByteValueToPreviousAndRefresh(void*,int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int ReadCachedStatusHalfwordAndClassify();void SetGlobalIndexedWordAtOffset18(int,void*);int func_020d40bc(int,int,...);void GameState_RemoveOrApplyTexturesForRelatedObjects(void*,int);}
#pragma force_active on
// Original: arm9/main @ 0x020D27FC; symbol: func_020d27fc; size: 0x24.
extern "C" void SoundCommand_ReleaseRecordByIdAtomically(int ignored,int id){int state=DisableIRQInterrupts();InvokeGenerationMatchedHandleCallback(id);SetIRQInterruptState(state);}
