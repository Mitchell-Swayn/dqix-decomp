#include <globaldefs.h>
ARM
struct Packed { unsigned a:14,pad0:18,b:14,pad1:18,c:7,d:7; };
struct Overlay8SmallRecord { unsigned short value; unsigned char first,second; };
extern "C" void TimeRecord_Reset(Overlay8SmallRecord*);
extern "C" int sprintf(char*,const char*,...);
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendYTag(char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int Text_AppendFormatString(char*,const char*);
// Original: arm9/ov008 @ 0x02187278; symbol: func_ov008_02187278; size: 0x134.
extern "C" void Text_AppendSelectedPackedRecord(unsigned char* self,char* out,int index,Overlay8SmallRecord* fallback) {
 if(out) {
  Overlay8SmallRecord temporary;
  Overlay8SmallRecord* selected=0;
  TimeRecord_Reset(&temporary);
  if(index==0) {
   selected=(Overlay8SmallRecord*)(self+0xb40);
   if(*(unsigned**)(self+0xb34)) {
    temporary.value=(*(Packed**)(self+0xb34))->a;
    temporary.first=(*(Packed**)(self+0xb34))->c;
    selected=&temporary;
   } else if(fallback) selected=fallback;
  } else if(index==1) {
   selected=(Overlay8SmallRecord*)(self+0xb44);
   if(*(unsigned**)(self+0xb34)) {
    temporary.value=(*(Packed**)(self+0xb34))->b;
    temporary.first=(*(Packed**)(self+0xb34))->d;
    selected=&temporary;
   } else if(fallback) selected=fallback+1;
  }
  if(selected) {
   _ZN9GameState11GetInstanceEv();
   TextContext_GetSharedInstance();
   TextMarkup_AppendPaletteTag(out,14);
   TextMarkup_AppendYTag(out,2);
   char buffer[64];
   __clear(buffer,64);
   const char* format=(const char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)0x6e);
   if(format) sprintf(buffer,format,selected->value,selected->first);
   Text_AppendFormatString(out,buffer);
  }
 }
}
