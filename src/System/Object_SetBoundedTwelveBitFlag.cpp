#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct Bits12 { unsigned short low:4,value:12; };
extern "C"{int Object_InvokeLockMutex();int UnlockGlobalCommandMutex(int);void AdvanceFixedPointProgressAndSetStateThree(void*);void AdvanceFixedPointElapsedValueAndMarkComplete(void*);void Object_DecrementWord18AndResetAtZero(void*);void Object3D_SetNormalizedAngleAndUpdatePosition(void*);int func_02030f30(int);void InitializeVectorTransitionAndStepValues(void*,const Vector3fix*,const Vector3fix*,const Vector3fix*,int,int);int func_0201b5d8(int);void* ReadGlobalValueAt020FB3F0();void Object_SetByteBEAndSavePreviousInBF(void*,int);void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);void InitializePacked999FieldsAndInvalidIndex(void*);unsigned GetSelectedEmbeddedTextBufferPointer(void*,int);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);int TestActiveInputAndSelectionFlags(void*);char* FindReadyRecordByIdBeforeStopIndex(void*,int);int TestField9CEqualsThree(void*);}
#pragma force_active on
// Original: arm9/main @ 0x02028C14; symbol: func_02028c14; size: 0x50.
extern "C" void Object_SetBoundedTwelveBitFlag(char* p,int bit){if(bit>=12){AppendKeyToGlobalTwentyFourHalfwordHistory(4);return;}Bits12* b=(Bits12*)(p+2);b->value|=1<<bit;}
