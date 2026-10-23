#include <globaldefs.h>
struct E {short key;short pad;unsigned int value;};struct T {E *data;short count;};
struct FontBits {unsigned char low:4,high:4;};
struct AlignBits {unsigned char align:2,rest:6;};
struct Label {char pad[6];short x,y;short measuredX,measuredY;short key;char pad10[3];FontBits font;AlignBits align;char pad15[19];short extraX;unsigned char flags,width,height;};
struct Sprite { unsigned char head[8]; void* tiles; unsigned char body[0x94]; unsigned fielda0,fielda4; unsigned short width,height,x,y; unsigned char tail[0x30]; };
struct CanvasView {char pad[0xa8];short width,height;char padac[8];short spacing,lineHeight;};
struct Owner {T* table;char pad[0x14];void* buffer;};
extern "C" int TextLookup_SelectFontTableForFont(int);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* memset(void*,int,unsigned);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void TextCanvas_RenderStyledTextAndMeasure(Sprite*,short,short,char*,unsigned char,unsigned char,short*,short*,int);
// Resolves a label, applies its font, optional centering and markup expansion,
// then renders into the existing canvas and writes back measured dimensions.
// CanvasView names the signed layout fields accessed by the original routine;
// Sprite preserves the established public canvas type used by its render callee.
// Original: arm9/main @ 0x0208166C; symbol: func_0208166c; size: 0x1AC.
extern "C" void TextCanvas_RenderResolvedDisplayLabel(Owner* owner,Sprite* canvas,Label* label){
 CanvasView* view=(CanvasView*)canvas;
 unsigned char style=label->font.high;if(label->flags&4)style=5;
 int font=TextLookup_SelectFontTableForFont(label->font.low);
 char* text=(char*)MessageTextTable_FindTextById(owner->table,label->key);
 if(text&&(label->flags&8)){short width=view->width*8;int textWidth=TextLayout_ComputeWidthWithGlyphSpacing((const char*)text,font);label->x=(short)(width-textWidth)>>1;}
 unsigned spacing=label->font.low;view->spacing=spacing;view->lineHeight=spacing+1;
 if((label->flags&16)&&label->font.low==12){view->spacing=label->font.low;view->lineHeight=20;}
 int offset=0;if(label->align.align)offset=TextLayout_ComputeWidthWithGlyphSpacing((const char*)text,0);
 if(label->flags&32){void* context=(void*)TextContext_GetSharedInstance();memset(owner->buffer,0,2400);TextMarkup_ExpandAndWrapText(context,label->font.low,text,owner->buffer,label->width,0,0);text=(char*)owner->buffer;unsigned height=label->height;view->spacing=label->font.low;view->lineHeight=height;}
 TextCanvas_RenderStyledTextAndMeasure(canvas,(short)(label->x+label->extraX-offset),label->y,text,label->font.low,style,&label->measuredX,&label->measuredY,0);
}
