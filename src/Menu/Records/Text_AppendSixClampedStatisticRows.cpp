#include <globaldefs.h>
ARM
struct Selected {unsigned padA:14,A:17,zA:1;unsigned padB:14,B:17,zB:1;unsigned unused;unsigned C:10,E:14,zC:8;unsigned D:9,F:14,zD:9;};
struct Source {unsigned u[2];unsigned B:17,zB:15;unsigned A:17,zA:15;unsigned C:9,E:14,zC:9;unsigned D:8,F:14,zD:10;};
struct Base {char pad[0x44];unsigned B:24,D:8;unsigned low:14,E:14,high:4;unsigned C:9,F:14,z:9;};
extern "C" {
unsigned TextContext_GetSharedInstance();void* _ZN9GameState11GetInstanceEv();
int GameState_CopyAlchemyOperationCount(void*);
void TextLayout_ResetFormattingWorkspace(signed char*);
void TextContext_SetNumericArgument(unsigned*,int,unsigned);
void TextContext_SetNumericArgumentAlignment(char*,int,int);
void TextContext_SetNumericArgumentWidth(char*,int,int);
int TextMarkup_AppendPaletteTag(char*,int);
void* GameState_GetSerializedProgressState();unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
int Text_AppendFormattedXYPair(char*,int,int);
void __clear(void*,unsigned);
void* ResourceStringTable_GetTextByKey(void*,void*);
unsigned strlen(const char*);void* memcpy(void*,const void*,unsigned);char* strstr(const char*,const char*);
int Text_AppendFormatString(char*,const char*);
extern char Text_AppendSixClampedStatisticRows_TextVal[];
}
// Original: arm9/ov008 @ 0x02187B20; symbol: func_ov008_02187b20; size: 0x44C.
extern "C" void Text_AppendSixClampedStatisticRows(char* self,char* text,unsigned* source){
 char temp[64];int a,b,d;
 if(!text)return;
 char* base;char* output=(char*)TextContext_GetSharedInstance();a=0;
 base=(char*)_ZN9GameState11GetInstanceEv()+0x7504;
 int c,e,f;
 unsigned* selected=*(unsigned**)(self+0xb34);
 if(selected){
 b=(*(Selected**)(self+0xb34))->B;a=(*(Selected**)(self+0xb34))->A;
 c=(*(Selected**)(self+0xb34))->C;d=(*(Selected**)(self+0xb34))->D;e=(*(Selected**)(self+0xb34))->E;f=(*(Selected**)(self+0xb34))->F;
 }else if(source){
 b=((Source*)source)->B;a=((Source*)source)->A;
 c=((Source*)source)->C;d=((Source*)source)->D;e=((Source*)source)->E;f=((Source*)source)->F;
 }else{
 b=((Base*)base)->B;
 GameState_CopyAlchemyOperationCount(&a);
 c=((Base*)base)->C;d=((Base*)base)->D;e=((Base*)base)->E;f=((Base*)base)->F;
 }
 if(*(int*)(self+0xb0c))c--;
 if(b>99999)b=99999;if(a>99999)a=99999;if(c>999)c=999;if(d>999)d=999;if(e>9999)e=9999;if(f>9999)f=9999;
 TextLayout_ResetFormattingWorkspace((signed char*)output);
 TextContext_SetNumericArgument((unsigned*)output,0,b);TextContext_SetNumericArgumentWidth(output,0,5);TextContext_SetNumericArgumentAlignment(output,0,1);
 TextContext_SetNumericArgument((unsigned*)output,1,a);TextContext_SetNumericArgumentWidth(output,1,5);TextContext_SetNumericArgumentAlignment(output,1,1);
 TextContext_SetNumericArgument((unsigned*)output,2,c);TextContext_SetNumericArgumentWidth(output,2,5);TextContext_SetNumericArgumentAlignment(output,2,1);
 TextContext_SetNumericArgument((unsigned*)output,3,d);TextContext_SetNumericArgumentWidth(output,3,5);TextContext_SetNumericArgumentAlignment(output,3,1);
 TextContext_SetNumericArgument((unsigned*)output,4,e);TextContext_SetNumericArgumentWidth(output,4,5);TextContext_SetNumericArgumentAlignment(output,4,1);
 TextContext_SetNumericArgument((unsigned*)output,5,f);TextContext_SetNumericArgumentWidth(output,5,5);TextContext_SetNumericArgumentAlignment(output,5,1);
 TextMarkup_AppendPaletteTag(text,14);
 output=(char*)GameState_GetSerializedProgressState();
 unsigned char mask=0;
 if(source){for(int i=0;i<6;i++)mask+=1<<i;}
 else{
 mask+=1;
 if(BitArray_ReadNonnegativeIndexMask(output,(unsigned char*)output+0x8c,0x1198))mask+=2;
 mask+=4;
 if(((Base*)base)->D)mask+=8;
 if(((Base*)base)->E)mask+=16;
 if(BitArray_ReadNonnegativeIndexMask(output,(unsigned char*)output+0x8c,0x1199))mask+=32;
 }
 int y;int row=0;
 for(int i=0;i<6;i++){
 if(!(mask&(1<<i)))continue;
 y=row*14;
 Text_AppendFormattedXYPair(text,2,y+7);
 __clear(temp,64);
 char* label=(char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)(short)(i+0x78));
 memcpy(temp,label,strlen(label));
 char* split=strstr(temp,Text_AppendSixClampedStatisticRows_TextVal);if(split)*split=0;
 Text_AppendFormatString(text,temp);
 Text_AppendFormattedXYPair(text,0x62,y+7);
 Text_AppendFormatString(text,(char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)(short)(i+0x1f4)));
 row++;
 }
}
