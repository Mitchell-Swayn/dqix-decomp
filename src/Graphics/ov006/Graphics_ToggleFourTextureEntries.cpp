#include <globaldefs.h>
ARM
extern "C" void Object_SetSelectedTextureFlag20(unsigned char*,int);
extern "C" void ClearResolvedEntryByteC5Bit20(unsigned char*,int);
// Original: arm9/ov006 @ 0x0215E5F8; symbol: func_ov006_0215e5f8; size: 0xA4.
extern "C" void Graphics_ToggleFourTextureEntries(unsigned char* p,unsigned char* object,int enabled,unsigned char* output){
 if(!object)return;
 if(enabled){
 *(unsigned short*)(p+0x394)|=0x80;*output=1;
 ClearResolvedEntryByteC5Bit20(object,13);
 ClearResolvedEntryByteC5Bit20(object,14);
 ClearResolvedEntryByteC5Bit20(object,15);
 ClearResolvedEntryByteC5Bit20(object,9);
 }else{
 *(unsigned short*)(p+0x394)&=~0x80;*output=0;
 Object_SetSelectedTextureFlag20(object,13);
 Object_SetSelectedTextureFlag20(object,14);
 Object_SetSelectedTextureFlag20(object,15);
 Object_SetSelectedTextureFlag20(object,9);
 }
}
