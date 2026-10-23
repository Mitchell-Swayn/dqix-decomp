struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Bits12 { unsigned short low:4,value:12; };
extern "C"{int Object_InvokeLockMutex();int SoundCommand_UnlockMutex(int);void AdvanceFixedPointProgressAndSetStateThree(void*);void AdvanceFixedPointElapsedValueAndMarkComplete(void*);void DisplaySpriteAnimation_ShrinkAndReset(void*);void Object3D_SetNormalizedAngleAndUpdatePosition(void*);int func_02030f30(int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int func_0201b5d8(int);void* Zone3D_GetMainInstance();void GameObject_SetMotionState(void*,int);void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);void ZoneSerializedRecord_Reset(void*);unsigned CharacterState_GetEquipmentNameBuffer(void*,int);void ScriptFlagHistory_AppendGlobalKey(int);int TestActiveInputAndSelectionFlags(void*);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);int TextCanvas_IsReady(void*);}
#pragma force_active on
// Original: arm9/main @ 0x0205DA38; symbol: func_0205da38; size: 0x50.
extern "C" int TestSelectedRecordReadyAndByteFlagBitOne(char* p, int ignored){if(TestActiveInputAndSelectionFlags(p+4)){char* q=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(p),(unsigned char)p[176]);if(q&&TextCanvas_IsReady(q)&&((unsigned char)q[197]&2))return 1;}return 0;}
