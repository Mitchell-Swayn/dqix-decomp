#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryMessageKey(char*,int,short);
extern "C" void TextCanvas_EnableEntryHorizontalCentering(unsigned char*,int);
extern "C" void TextCanvas_SetGroupInteriorFillSuppressed(unsigned char*,int,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*,int);
// Original: arm9/ov006 @ 0x0215FB7C; symbol: func_ov006_0215fb7c; size: 0x174.
extern "C" void KrakPot_RefreshRecipeCategoryHeading(char* self){
 char* display=*(char**)(self+0x14);
 short value=47;
 switch(*(short*)(self+0x366)){case 39:value=20;break;case 40:value=21;break;}
 switch(*(short*)(self+0x368)){
 case 72:value=29;break;
 case 73:value=30;break;
 case 74:value=31;break;
 case 75:value=32;break;
 case 76:value=33;break;
 case 77:value=34;break;
 case 78:value=35;break;
 case 79:value=36;break;
 case 80:value=37;break;
 case 81:value=38;break;
 case 82:value=39;break;
 case 83:value=40;break;
 case 64:value=23;break;
 case 65:value=24;break;
 case 66:value=25;break;
 case 67:value=26;break;
 case 68:value=27;break;
 case 69:value=28;break;
 }
 TextCanvas_SetEntryMessageKey(display,89,value);
 TextCanvas_EnableEntryHorizontalCentering((unsigned char*)display,89);
 TextCanvas_SetGroupInteriorFillSuppressed((unsigned char*)display,14,1);
 TextCanvas_CreateAndConfigureDisplayPart(display,14);
 TextCanvas_SetGroupPalette(display,14,2);
 TextCanvas_ShowDisplayPart((unsigned char*)display,14);
}
