#include <globaldefs.h>
#include <std_library_functions.h>
struct TextRecord { unsigned flags;unsigned short reserved;short x,y;unsigned short measuredX,measuredY;short key,width;unsigned char unused;unsigned char font:4;unsigned char style:4;unsigned char alignment:2;unsigned char padding:6;unsigned char gap[19];short extraX;unsigned char options; };
struct TextOwner { void* source;unsigned pad[5];char* buffer; };
struct TextUI { unsigned char pad[168];short width;unsigned char gap[10];unsigned short font,nextFont; };
extern "C" void* TestValueEqualsTwelve(int);extern "C" const char* FindRecordValueByKeyOrZero(void*,int);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);extern "C" void* ReadWordFieldAtOffset1C();extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(void*);extern "C" void CopyBoundedNameToIndexedSlot(void*,int,unsigned);extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,const char*,char*,int,int,int);extern "C" void func_0204f41c(TextUI*,int,int,char*,int,int,unsigned short*,unsigned short*,int);
// Original: arm9/main @ 0x02081870; symbol: func_02081870; size: 0x1A4.
extern "C" void RenderTextRecordWithConditionalCentering(TextOwner* owner,TextUI* ui,TextRecord* record){
 unsigned style=record->style;if(record->options&4)style=5;void* font=TestValueEqualsTwelve(record->font);
 if(record->options&8){const char* text=FindRecordValueByKeyOrZero(owner->source,record->key);if(text){short width=ui->width<<3;record->x=(short)(width-TextLayout_ComputeWidthWithGlyphSpacing(text,font))>>1;}}
 void* renderer=ReadWordFieldAtOffset1C();memset(owner->buffer,0,0x960);ClearOwnerBuffersAndResetSignedByteSentinels(renderer);CopyBoundedNameToIndexedSlot(renderer,record->width,record->flags);
 const char* text=FindRecordValueByKeyOrZero(owner->source,record->key);ProcessSixStagesUsingSharedWordScratchBuffer(renderer,record->font,text,owner->buffer,256,0,0);
 unsigned fontIndex=record->font;ui->font=fontIndex;ui->nextFont=fontIndex+1;if((record->options&16)&&record->font==12){ui->font=record->font;ui->nextFont=20;}
 int alignment=0;if(record->alignment)alignment=TextLayout_ComputeWidthWithGlyphSpacing(owner->buffer,0);
 func_0204f41c(ui,(short)(record->x+record->extraX-alignment),record->y,owner->buffer,record->font,style,&record->measuredX,&record->measuredY,0);
}
