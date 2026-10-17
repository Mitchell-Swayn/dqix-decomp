#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void ResolveAndResetPresentEntry(unsigned char*,int);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char*);
extern "C" void SetLinkedFlagStateAndResetOwner(void**);
extern "C" int UpdateSelectionFromActiveInputOrHitTest(char*);
extern "C" int TestInputOrPointerRectangleGate(unsigned char*);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];
// Original: arm9/ov003 @ 0x021764F4; symbol: func_ov003_021764f4; size: 0xC0.
extern "C" int Graphics_ProcessSelectionConfirmationAndReset(unsigned char* p){
 *(void**)(p+0xff8)=p+0x1002;
 int result=0;
 if(UpdateSelectionFromActiveInputOrHitTest((char*)p) || Object_TestNewlySetHalfwordMask(data_02114e30,0x200)){
 DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
 result=-1;
 if(*(short*)(p+0x1002)==2)result=1;
 }else if(TestInputOrPointerRectangleGate(p))result=-1;
 if(result){
 ResolveAndResetPresentEntry(*(unsigned char**)(p+0x89c),*(short*)(p+0xffe));
 ResetPointedHalfwordAndSynchronizeSignedByteState(p+0x88c);
 *(void**)(p+0xff8)=0;
 }
 if(*(void**)p && result)SetLinkedFlagStateAndResetOwner(*(void***)p);
 return result;
}
