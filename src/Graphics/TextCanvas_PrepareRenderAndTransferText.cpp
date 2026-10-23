#include <globaldefs.h>
#include <System/Cache.h>

struct Format { char pad[0x1c]; struct { unsigned char low:4, high:4; } channels; unsigned GetLow()const {return channels.low;} unsigned GetHigh()const{return channels.high;} };
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void* __clear(void*,unsigned);
extern "C" int TextCanvas_MeasureMarkupAndConfigureLayout(unsigned char*,void*,int,int,unsigned,unsigned char);
extern "C" void TextCanvas_RenderMarkupAndMarkedRegions(unsigned char*,void*,int,unsigned char);
extern "C" void TextCanvas_DrawPageNumberPair(unsigned char*,int);
extern "C" unsigned Graphics_GetCharacterTransferCallback(unsigned,unsigned);
extern "C" void TextCanvas_ClearMarkedTextRectangles(unsigned char*);
extern "C" void* memset(void*,int,unsigned);
// Preserves the configured canvas while rendering expanded markup, transfers its
// character buffer, then resets the tilemap bookkeeping for subsequent drawing.
// Format accessors preserve the two independently extracted SDK channel fields.
// Original: arm9/main @ 0x0204C980; symbol: func_0204c980; size: 0x1A0.
extern "C" void TextCanvas_PrepareRenderAndTransferText(unsigned char* p,void* text,unsigned offset,int align,unsigned char style,unsigned char mode,unsigned char flags) {
 if(!*(void**)(p+4)||!*(void**)(p+8)||!text)return;
 TextCanvas_ClearMarkedTextRectangles(p);
 int wrap=*(short*)(p+0xa8)*8;if(!(p[0xc5]&16))wrap-=4;if(mode)wrap=256;
 char buffer[2048];__clear(buffer,2048);
 TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),p[0xc7],text,buffer,wrap,*(short*)(p+0xb0),flags);
 int measured=TextCanvas_MeasureMarkupAndConfigureLayout(p,buffer,align,style,mode,flags);
 TextCanvas_RenderMarkupAndMarkedRegions(p,buffer,measured,flags);
 *(unsigned*)(p+0xa0)=offset;
 unsigned callback=Graphics_GetCharacterTransferCallback((*(Format**)(p+4))->GetLow(),(*(Format**)(p+4))->GetHigh());
 CleanInvalidateCacheRange(*(void**)(p+8),*(unsigned*)(p+0xa4));
 ((void(*)(void*,unsigned,unsigned))callback)(*(void**)(p+8),*(unsigned*)(p+0xa0),*(unsigned*)(p+0xa4));
 if(p[0xc5]&1){
 *(short*)(p+0xc0)=0;short h=*(short*)(p+0xaa),w=*(short*)(p+0xa8);*(short*)(p+0xc8)=w;*(short*)(p+0xca)=h;*(unsigned*)(p+0xd0)=w*h*2;*(short*)(p+0xc2)=0;*(unsigned*)(p+0x9c)=1;
 }else{
 p[0xc5]|=1;*(short*)(p+0xc0)=0;int size=*(short*)(p+0xa8)* *(short*)(p+0xaa)*2;memset(*(void**)(p+0xd4),0,size);short h=*(short*)(p+0xaa),w=*(short*)(p+0xa8);*(short*)(p+0xc8)=w;*(short*)(p+0xca)=h;*(unsigned*)(p+0xd0)=size;*(short*)(p+0xc2)=0;*(unsigned*)(p+0x9c)=1;
 }
}
