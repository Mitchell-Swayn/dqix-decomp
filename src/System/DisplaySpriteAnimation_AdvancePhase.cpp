struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Bits12 { unsigned short low:4,value:12; };
extern "C"{int Object_InvokeLockMutex();int SoundCommand_UnlockMutex(int);void AdvanceFixedPointProgressAndSetStateThree(void*);void AdvanceFixedPointElapsedValueAndMarkComplete(void*);void DisplaySpriteAnimation_ShrinkAndReset(void*);void Object3D_SetNormalizedAngleAndUpdatePosition(void*);int func_02030f30(int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int func_0201b5d8(int);void* Zone3D_GetMainInstance();void GameObject_SetMotionState(void*,int);void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);void ZoneSerializedRecord_Reset(void*);unsigned CharacterState_GetEquipmentNameBuffer(void*,int);void ScriptFlagHistory_AppendGlobalKey(int);int TestActiveInputAndSelectionFlags(void*);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);int TextCanvas_IsReady(void*);}
#pragma force_active on
// Original: arm9/main @ 0x020DDFB4; symbol: func_020ddfb4; size: 0x40.
extern "C" void DisplaySpriteAnimation_AdvancePhase(char* p){unsigned char type=p[4];if(type==2){AdvanceFixedPointProgressAndSetStateThree(p);return;}if(type==1)return;if(type==3){AdvanceFixedPointElapsedValueAndMarkComplete(p);return;}if(type==4)DisplaySpriteAnimation_ShrinkAndReset(p);}
