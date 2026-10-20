#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" int TextMarkup_AppendYTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int TextMarkup_AppendWidthTag(char*,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" void* Text_LookupStandardString(unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgumentAlignment(char*,int,int);
extern "C" void TextContext_SetNumericArgumentWidth(char*,int,int);
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
// Original data: arm9/ov013 @ 0x2187e3c; symbol: data_ov013_02187e3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
// Original data: arm9/ov013 @ 0x2187e44; symbol: data_ov013_02187e44.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
// Original data: arm9/ov013 @ 0x2187e45; symbol: data_ov013_02187e45.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a0000.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" char AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant2[],AppendCenteredHeadingAndSevenValues_FormatSD[],AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant3[],AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/ov013 @ 0x2187dac; symbol: data_ov013_02187dac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3b003b004e004e004e000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" short AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes[];
// Original: arm9/ov013 @ 0x02185E40; symbol: func_ov013_02185e40; size: 0x320.
// Centers a formatted heading, installs seven text values, and appends five indexed labels.
extern "C" void AppendCenteredHeadingAndSevenValues(char* p,char* out){
 if(out){
 _ZN9GameState11GetInstanceEv();
 short first=400,second=500; char heading[512]={0};
 int width=TextLayout_ComputeWidthWithGlyphSpacing(*(char**)(p+0x6a4),0);
 if(*(int*)(p+0x6b8)){
 const char* label=(const char*)ResourceStringTable_GetTextByKey(p+0x620,(void*)(int)(short)(*(int*)(p+0x6b8)+300));
 int style=5;if(*(int*)(p+0x6b8)==10)style=13;
 TextMarkup_AppendYTag(heading,4);Text_AppendFormatString(heading,*(char**)(p+0x6a4));
 TextMarkup_AppendWidthTag(heading,16);TextMarkup_AppendPaletteTag(heading,style);Text_AppendFormatString(heading,label);
 TextMarkup_AppendWidthTag(heading,4);TextMarkup_AppendPaletteTag(heading,15);
 Text_AppendFormatString(heading,(const char*)Text_LookupStandardString(1011));
 char number[16]={0};sprintf(number,AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant2,*(int*)(p+0x6b0));Text_AppendFormatString(heading,number);
 }else{
 TextMarkup_AppendYTag(heading,4);Text_AppendFormatString(heading,*(char**)(p+0x6a4));TextMarkup_AppendWidthTag(heading,18);
 Text_AppendFormatString(heading,(const char*)Text_LookupStandardString(1011));char number[16]={0};sprintf(number,AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant2,*(int*)(p+0x6b0));Text_AppendFormatString(heading,number);
 }
 char suffix[256]={0};sprintf(suffix,AppendCenteredHeadingAndSevenValues_FormatSD,Text_LookupStandardString(1011),*(int*)(p+0x6b0));
 int total=width+18+TextLayout_ComputeWidthWithGlyphSpacing(suffix,0);if(*(int*)(p+0x6b8))total+=9;
 int x=(120-total)>>1;*(short*)(p+0x1e)=width+x+1;
 TextMarkup_AppendXPositionTag(out,x);Text_AppendFormatString(out,heading);AppendFormattedNumberAndText(out,AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant3,16);
 unsigned owner=TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace((signed char*)owner);
 unsigned values[7]={*(unsigned short*)(p+0x6be),*(unsigned short*)(p+0x6c0),*(unsigned short*)(p+0x6c2),*(unsigned short*)(p+0x6c4),*(unsigned short*)(p+0x6c6),*(unsigned short*)(p+0x6c8),*(unsigned short*)(p+0x6ca)};
 for(int i=0;i<7;i++){TextContext_SetNumericArgumentAlignment((char*)owner,i,1);TextContext_SetNumericArgumentWidth((char*)owner,i,3);TextContext_SetNumericArgument((unsigned*)owner,i,values[i]);}
 for(int i=0;i<5;i++){
 Text_AppendFormatString(out,(const char*)ResourceStringTable_GetTextByKey(p+0x620,(void*)(int)first++));TextMarkup_AppendXPositionTag(out,AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes[i]);
 Text_AppendFormatString(out,(const char*)ResourceStringTable_GetTextByKey(p+0x620,(void*)(int)second++));if(i!=4)Text_AppendFormatString(out,AppendCenteredHeadingAndSevenValues_UnknownRoleInitializedBytes_Variant4);
 }
 }
}
