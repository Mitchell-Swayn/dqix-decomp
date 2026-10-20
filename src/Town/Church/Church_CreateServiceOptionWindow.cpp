#include <globaldefs.h>
ARM
extern "C" int Window_BindNextCanvasResourceByFormatAndLayer(...);
extern "C" int ResourceStringTable_GetTextByKey(...);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(...);
extern "C" int Text_AppendIndexedRecordList(...);
extern "C" int Window_PushTextCanvas(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x0215B5C4; symbol: Text_SizeIndexedRecordWindowAndAttachFormattedList.
extern "C" void Church_CreateServiceOptionWindow(char*self){
Window_BindNextCanvasResourceByFormatAndLayer(self+244,0,2);short height;int maximum=0;height=(short)((14*(short)B(self,1417)+18)/8);for(int i=0;i<B(self,1417);i++){short width=(short)TextLayout_ComputeWidthWithGlyphSpacing(ResourceStringTable_GetTextByKey(self+100,*(signed char*)(self+1418+i)),0);if(maximum<width)maximum=width;}short width=(maximum+24)>>3;S(self+256,148)=width;S(self+256,150)=height;S(self+256,152)=31-width;S(self+256,154)=2;S(self+256,156)=12;S(self+256,158)=8;S(self+256,160)=10;S(self+256,162)=14;B(self,421)=1;B(self,425)=1;B(self,1412)=0;memset(P(self,124),0,2400);Text_AppendIndexedRecordList(self,P(self,124),0);Window_PushTextCanvas(self+244,P(self,124),0,1,0,1,0,0);
}
