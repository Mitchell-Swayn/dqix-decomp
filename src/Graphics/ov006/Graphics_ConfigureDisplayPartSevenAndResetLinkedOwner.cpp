#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void Object_SetSelectedTextureFlag20(unsigned char*,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char*);
extern "C" void ResetOwnerSetLinkedValueAndRefresh(unsigned char*,int);
extern "C" void WriteWordPairAtOffsets4And8(void*,int,int);
extern "C" char data_02108760[];
// Original: arm9/ov006 @ 0x02159DB0; symbol: func_ov006_02159db0; size: 0xA0.
extern "C" void Graphics_ConfigureDisplayPartSevenAndResetLinkedOwner(unsigned char* p){
 DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,5,0);
 short part=7;short value=34;
 *(short*)(p+0x36e)=part;
 *(short*)(p+0x35e)=*(short*)(p+0x36c)=value;
 *(short*)(*(unsigned char**)(p+0x14)+0x36)=*(short*)(p+0x36c);
 Object_CreateAndConfigureSelectedDisplayPart(*(char**)(p+0x14),*(short*)(p+0x36e));
 ResetPointedHalfwordAndSynchronizeSignedByteState(p+0x9c);
 *(int*)(p+0x44)=0;
 if(*(void**)(p+0x18)){
 Object_SetSelectedTextureFlag20(*(unsigned char**)(p+0x14),*(short*)(p+0x36e));
 ResetOwnerSetLinkedValueAndRefresh(*(unsigned char**)(p+0x18),-1);
 WriteWordPairAtOffsets4And8(*(unsigned char**)(*(unsigned char**)(p+0x18)+0x10)+0x28,24,1);
 }
}
