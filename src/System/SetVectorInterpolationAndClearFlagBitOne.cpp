#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Bits12 { unsigned short low:4,value:12; };
extern "C"{int Object_InvokeLockMutex();int UnlockGlobalCommandMutex(int);void AdvanceFixedPointProgressAndSetStateThree(void*);void AdvanceFixedPointElapsedValueAndMarkComplete(void*);void Object_DecrementWord18AndResetAtZero(void*);void Object3D_SetNormalizedAngleAndUpdatePosition(void*);int func_02030f30(int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int func_0201b5d8(int);void* ReadGlobalValueAt020FB3F0();void Object_SetByteBEAndSavePreviousInBF(void*,int);void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);void InitializePacked999FieldsAndInvalidIndex(void*);unsigned GetSelectedEmbeddedTextBufferPointer(void*,int);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);int TestActiveInputAndSelectionFlags(void*);char* FindReadyRecordByIdBeforeStopIndex(void*,int);int TestField9CEqualsThree(void*);}
#pragma force_active on
// Original: arm9/main @ 0x0202EDB4; symbol: func_0202edb4; size: 0x44.
extern "C" void SetVectorInterpolationAndClearFlagBitOne(char* p,const Vector3fix* a,const Vector3fix* b,int n,int m){InitializeVectorTransitionAndStepValues(p+404,(Vector3fix*)(p+16),a,b,n,m);*(unsigned*)(p+360)&=~2;}
