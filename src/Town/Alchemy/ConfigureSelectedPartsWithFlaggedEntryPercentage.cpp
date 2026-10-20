#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryXOrRightAlignToGroup(void**,int,int,int,short);
extern "C" void TextCanvas_ShowEntry(unsigned char*,int);
extern "C" void TextCanvas_HideGroupEntries(char*,int);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" void TextCanvas_SetEntryMessageKey(char*,int,short);
extern "C" void TextCanvas_SetGroupInteriorFillSuppressed(unsigned char*,int,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" unsigned _ffltu(unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" short GameState_CountAndStoreFlaggedEntries(void*);
// Original: arm9/ov006 @ 0x0215FA1C; symbol: func_ov006_0215fa1c; size: 0x160.
extern "C" void ConfigureSelectedPartsWithFlaggedEntryPercentage(char* self,int enabled) {
 char* obj=*(char**)(self+0x14);
 TextCanvas_HideGroupEntries(obj,13);
 TextCanvas_ShowEntry((unsigned char*)obj,0x56);
 TextCanvas_SetEntryMessageKey(*(char**)(self+0x14),0x56,0x2b);
 if(*(unsigned char*)(self+0x38f)!=10 && *(unsigned char*)(self+0x38f)!=3) {
 short value=0x2c;
 if(!enabled) {
 switch(*(short*)(self+0x366)) {
 case 0x25:value=0x12;break;
 case 0x26:value=0x13;break;
 }
 }
 TextCanvas_SetEntryMessageKey(obj,0x57,value);
 TextCanvas_ShowEntry((unsigned char*)obj,0x57);
 TextCanvas_SetEntryXOrRightAlignToGroup((void**)obj,13,0x57,1,4);
 if(enabled) {
 unsigned count=(unsigned short)GameState_CountAndStoreFlaggedEntries(self+0x74);
 int n=_ffix(_fmul(_fdiv(_ffltu(count),0x43e00000),0x461c4000));
 int percent=(n-n%100)/100;
 if(count && percent<=0) percent=1;
 if(percent>100) percent=100;
 TextCanvas_SetEntryNumericValue(obj,0x58,percent);
 TextCanvas_ShowEntry((unsigned char*)obj,0x58);
 TextCanvas_SetEntryMessageKey(*(char**)(self+0x14),0x56,0x2e);
 }
 }
 TextCanvas_SetGroupInteriorFillSuppressed((unsigned char*)obj,13,1);
 TextCanvas_CreateAndConfigureDisplayPart(obj,13);
}
