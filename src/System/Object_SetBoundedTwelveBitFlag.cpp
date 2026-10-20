struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Bits12 { unsigned short low:4,value:12; };
extern "C"{int Object_InvokeLockMutex();int SoundCommand_UnlockMutex(int);void AdvanceFixedPointProgressAndSetStateThree(void*);void AdvanceFixedPointElapsedValueAndMarkComplete(void*);void DisplaySpriteAnimation_ShrinkAndReset(void*);void Object3D_SetNormalizedAngleAndUpdatePosition(void*);int func_02030f30(int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int func_0201b5d8(int);void* Zone3D_GetMainInstance();void GameObject_SetMotionState(void*,int);void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);void ZoneSerializedRecord_Reset(void*);unsigned CharacterState_GetEquipmentNameBuffer(void*,int);void ScriptFlagHistory_AppendGlobalKey(int);int TestActiveInputAndSelectionFlags(void*);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);int TextCanvas_IsReady(void*);}
#pragma force_active on
// Original: arm9/main @ 0x02028C14; symbol: func_02028c14; size: 0x50.
extern "C" void Object_SetBoundedTwelveBitFlag(char* p,int bit){if(bit>=12){ScriptFlagHistory_AppendGlobalKey(4);return;}Bits12* b=(Bits12*)(p+2);b->value|=1<<bit;}
