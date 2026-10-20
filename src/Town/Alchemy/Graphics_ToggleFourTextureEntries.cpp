#include <globaldefs.h>
ARM
extern "C" void TextCanvas_HideDisplayPart(unsigned char*,int);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*,int);
// Original: arm9/ov006 @ 0x0215E5F8; symbol: func_ov006_0215e5f8; size: 0xA4.
extern "C" void Graphics_ToggleFourTextureEntries(unsigned char* p,unsigned char* object,int enabled,unsigned char* output){
 if(!object)return;
 if(enabled){
 *(unsigned short*)(p+0x394)|=0x80;*output=1;
 TextCanvas_ShowDisplayPart(object,13);
 TextCanvas_ShowDisplayPart(object,14);
 TextCanvas_ShowDisplayPart(object,15);
 TextCanvas_ShowDisplayPart(object,9);
 }else{
 *(unsigned short*)(p+0x394)&=~0x80;*output=0;
 TextCanvas_HideDisplayPart(object,13);
 TextCanvas_HideDisplayPart(object,14);
 TextCanvas_HideDisplayPart(object,15);
 TextCanvas_HideDisplayPart(object,9);
 }
}
