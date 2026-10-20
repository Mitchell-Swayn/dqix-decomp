#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void TextCanvas_SetEntryTextPointer(char*,int,int);
extern "C" void TextCanvas_SetEntryTextColor(char*,int,unsigned int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
// Original: arm9/ov003 @ 0x02158334; symbol: func_ov003_02158334; size: 0x14C.
extern "C" void UpdateObjectRatioDisplayParts(char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 int part=3; int index=10;
 switch(*(unsigned char*)(self+0x1f6)) {case 3:part=4;index=12;break;case 4:part=5;index=15;break;}
 char* display=*(char**)(self+0x18);
 for(unsigned char i=0;i<*(unsigned char*)(self+0x1f6);i++) {
  char* object=(char*)GameState_GetObjectWithFlag100(state,*(unsigned char*)(self+0x1f2+i));
  if(object) {
   unsigned int color=15;
   TextCanvas_SetEntryTextPointer(display,index,*(int*)(object+0x134));
   int max=*(unsigned short*)(*(char**)(object+0x134)+0x30);
   float ratio;
   if((float)max==0.0f) ratio=0.0f;
   else ratio=(float)(int)*(unsigned short*)(*(char**)(object+0x130)+4)/(float)max;
   if(ratio<=0.25f) color=13;
   if(ratio<=0.08f) color=11;
   if(*(unsigned int*)(*(char**)(object+0x130))&1) color=9;
   TextCanvas_SetEntryTextColor(display,index,color);
  }
  index=(short)(index+1);
 }
 TextCanvas_CreateAndConfigureDisplayPart(display,part);
}
