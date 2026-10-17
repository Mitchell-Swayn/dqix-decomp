#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char* p,int a,void* b);
extern "C" void Object_SetSelectedTextureFlag20(unsigned char* p,int i);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char* self,int index);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char* p);
extern "C" void ResetOwnerSetLinkedValueAndRefresh(unsigned char* p,int value);
extern "C" char data_02108760[];
// Original: arm9/ov003 @ 0x02176468; symbol: func_ov003_02176468; size: 0x8C.
extern "C" void Graphics_ResetDisplaySelectionAndLinkedOwner(unsigned char* p) {
*(short*)(p+0xffe)=1;
*(short*)(p+0x1000)=*(short*)(p+0x1002)=2;
*(short*)(*(unsigned char**)(p+0x89c)+0x36)=*(short*)(p+0x1002);
Object_CreateAndConfigureSelectedDisplayPart(*(char**)(p+0x89c),*(short*)(p+0xffe));
ResetPointedHalfwordAndSynchronizeSignedByteState(p+0x88c);
*(int*)(p+0xff8)=0;
DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,5,0);
if(*(void**)p){Object_SetSelectedTextureFlag20(*(unsigned char**)(p+0x89c),*(short*)(p+0xffe));ResetOwnerSetLinkedValueAndRefresh(*(unsigned char**)p,-1);}
}
