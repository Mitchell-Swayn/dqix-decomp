#include <globaldefs.h>
ARM
extern "C" void* ReadWordFieldAtOffset1C();extern "C" short func_02045d14(void*,void*,void*,int);extern "C" int MeasureMaximumEncodedTextLineWidth(void*,void*,int,int);
// Original: arm9/main @ 0x0205CB74; symbol: func_0205cb74; size: 0xDC.
extern "C" void TextLayout_AppendConvertedLineAndUpdateWidths(char* p,void* text){
 if(!text)return;void* manager=ReadWordFieldAtOffset1C();*(unsigned short*)((p+(unsigned char)p[0x232]*2)+0x220)=*(unsigned short*)(p+0x230);
 short length=func_02045d14(manager,text,(p+0x120)+*(unsigned short*)(p+0x230)*2,1);*(unsigned short*)(p+0x230)+=length;
 int width=MeasureMaximumEncodedTextLineWidth(manager,(p+0x120)+*(unsigned short*)((p+(unsigned char)p[0x232]*2)+0x220)*2,256,1);
 if(*(int*)(p+0xd0)<width)*(int*)(p+0xd0)=width;++*(unsigned char*)(p+0x232);if(*(int*)(p+0xdc)<8){*(short*)((p+*(int*)(p+0xdc)*2)+0x100)=width;*(short*)((p+*(int*)(p+0xdc)*2)+0x110)=12;}else *(int*)(p+0xdc)=7;++*(int*)(p+0xdc);
}
