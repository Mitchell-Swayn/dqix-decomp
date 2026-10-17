#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma opt_propagation off
ARM
extern "C" void Object_ClearPointerAndHalfwordCountPair(void*);
extern "C" void ClearPointerAndTwoHalfwords(void*);
// Original: arm9/main @ 0x0207F84C; symbol: func_0207f84c; size: 0x70.
extern "C" void InitializeEmbeddedListsAndInvalidIndices(char* self) {
 *(int*)self=0;Object_ClearPointerAndHalfwordCountPair(self+4);ClearPointerAndTwoHalfwords(self+12);
 int empty=0;int invalid=empty-1;
 *(int*)(self+20)=empty;
 *(int*)(self+24)=empty;
 *(int*)(self+28)=invalid;*(int*)(self+32)=*(int*)(self+36)=*(int*)(self+40)=invalid;
 *(int*)(self+44)=0;*(int*)(self+48)=0;
 *(short*)(self+52)=8;*(short*)(self+54)=invalid;
 self[56]=0;self[57]=0;self[58]=0;self[59]=16;self[60]=16;
}
