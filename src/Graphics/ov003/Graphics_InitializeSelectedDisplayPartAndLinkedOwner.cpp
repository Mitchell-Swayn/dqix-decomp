#include <globaldefs.h>
ARM
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void Object_SetSelectedTextureFlag20(unsigned char*,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char*);
extern "C" void ResetOwnerSetLinkedValueAndRefresh(unsigned char*,int);
extern "C" void Object_SetByte16ClampedToTwo(char*,int);
extern "C" char data_02108760[];
// Original: arm9/ov003 @ 0x02155580; symbol: func_ov003_02155580; size: 0x98.
extern "C" void Graphics_InitializeSelectedDisplayPartAndLinkedOwner(unsigned char* self,int value) {
 *(short*)(self+0x1e6)=1;
 *(short*)(self+0x1e8)=*(short*)(self+0x1ea)=6;
 *(short*)(*(char**)(self+0x18)+0x36)=*(short*)(self+0x1ea);
 Object_CreateAndConfigureSelectedDisplayPart(*(char**)(self+0x18),*(short*)(self+0x1e6));
 ResetPointedHalfwordAndSynchronizeSignedByteState(self+0x80);
 *(int*)(self+8)=0;
 DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,5,0);
 if(*(void**)(self+0x1c)) {
  Object_SetSelectedTextureFlag20(*(unsigned char**)(self+0x18),*(short*)(self+0x1e6));
  Object_SetByte16ClampedToTwo(*(char**)(self+0x1c),(signed char)value);
  ResetOwnerSetLinkedValueAndRefresh(*(unsigned char**)(self+0x1c),-1);
 }
}
