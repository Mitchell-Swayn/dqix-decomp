#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
struct Buffer;struct T;struct Record;struct Source;
extern "C" {
void* _ZN9GameState11GetInstanceEv();void* _ZN9GameState14GetProtagonistEv(void*);void* _ZN16BackgroundLoader11GetInstanceEv();unsigned TextContext_GetSharedInstance();void* __clear(void*,unsigned);
void TextLayout_ResetFormattingWorkspace(signed char*);void* Text_ClearNameDescriptor(void*);void Text_BuildNameDescriptorFromActor(void*,Source*);
void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);
void Text_InitializeNameDescriptor(Record*,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char);
void MessageTextTable_Reset(char*);void* ResourceStringTable_GetTextByKey(void*,void*);
void _ZN16BackgroundLoader13AddLockGlobalEv();void _ZN16BackgroundLoader16RemoveLockGlobalEv();void* Filesystem_ExtractLocalizedGp2FileToScratch(const char*,const char*,unsigned*);
char* ResourceStringTable_CopyTextByKey(char*,int,int,int);unsigned MessageTextTable_FindTextById(T*,int);
void Script_ExecuteCodeWithOwnerModeAndOutputValue(unsigned,void*,unsigned,unsigned,unsigned,unsigned char);
void TextContext_SetStringArgument(Buffer*,int,const char*);void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
char* String_FindFirstSubstring(char*,const char*);int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);int TextMarkup_AppendYTag(char*,int);int Text_AppendFormatString(char*,const char*);
// Original data: arm9/ov008 @ 0x218b4c1; symbol: data_ov008_0218b4c1.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov008.md.
extern char Text_AppendStoredNameOrPercentageRows_PathDataBinTtlnameDGp2[],Text_AppendStoredNameOrPercentageRows_FormatTtlnameDLGNat[],Text_AppendSelectedTitleAndPanelFormat_PathDataBinProfstrGp2[],Text_AppendSelectedTitleAndPanelFormat_MarkupProfstrLGBin[],TextAppendSelectedTitleAndPanelFormat_UnknownRoleInitializedBytes[];
}
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
struct LowBit {unsigned char value:1,other:7;};
struct TitleContainer;
struct TitleBits {unsigned low:19;int title:11;unsigned tail:2;};
// Original: arm9/ov008 @ 0x02187708; symbol: func_ov008_02187708; size: 0x368.
// Resolves live or received title/name text and appends the selected panel format, updating scrolling width when enabled.
extern "C" void Text_AppendSelectedTitleAndPanelFormat(char* self,char* output,int mode) {
 if(!output)return;
 void* game=_ZN9GameState11GetInstanceEv();_ZN16BackgroundLoader11GetInstanceEv();signed char* context=(signed char*)TextContext_GetSharedInstance();
 unsigned char name[48];char titleBuffer[64];unsigned liveDescriptor[3],receivedDescriptor[3];__clear(name,48);short title=0;__clear(titleBuffer,64);
 unsigned char gender=0;TextLayout_ResetFormattingWorkspace(context);
 char* record=P(self,0xb30);
 if(!record) {
  char* titleOwner=(char*)game+0x569c;title=(short)((TitleBits*)(titleOwner+4))->title;
  void* member=_ZN9GameState14GetProtagonistEv(game);
  if(member) {
   if(title<=0){char* state=P(member,0x150);int base=0x50dc;if(((LowBit*)(state+0x49c))->value==1)base+=50;title=(short)(base-20000+(int)W(state,0x950));}
   gender=((LowBit*)(P(member,0x150)+0x49c))->value;
   Text_ClearNameDescriptor(liveDescriptor);Text_BuildNameDescriptorFromActor(liveDescriptor,(Source*)member);P(context,16)=(char*)liveDescriptor;
  }
 } else {
  char* state=P(self,0xb34);unsigned mapMode=1;if(state)title=H(state,20);gender=((LowBit*)(state+22))->value;
  Text_MapInputBytesToVariableLengthOutputSequences((unsigned char*)record,name,mapMode);
  Text_ClearNameDescriptor(receivedDescriptor);Text_InitializeNameDescriptor((Record*)receivedDescriptor,(unsigned)name,(unsigned)name,0,0,0,0,gender,0,1,0,1);P(context,16)=(char*)receivedDescriptor;
 }
 if(title>0) {
  char script[8];MessageTextTable_Reset(script);unsigned length=0;char* titleText=0;
  if(title<700) {
   if(P(self,0xb3c))titleText=(char*)ResourceStringTable_GetTextByKey(P(self,0xb3c),(void*)(int)title);
   else {
    _ZN16BackgroundLoader13AddLockGlobalEv();char archive[64],inner[32];unsigned size=0;__clear(archive,64);__clear(inner,32);
    sprintf(archive,Text_AppendStoredNameOrPercentageRows_PathDataBinTtlnameDGp2,gender);sprintf(inner,Text_AppendStoredNameOrPercentageRows_FormatTtlnameDLGNat,gender);
    char* data=(char*)Filesystem_ExtractLocalizedGp2FileToScratch(archive,inner,&size);if(data)titleText=ResourceStringTable_CopyTextByKey(titleBuffer,(int)data,size,title);
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
   }
  } else {
   if(P(self,0xb38))titleText=(char*)MessageTextTable_FindTextById((T*)P(self,0xb38),(short)(title+20000));
   else {
    _ZN16BackgroundLoader13AddLockGlobalEv();void* code=Filesystem_ExtractLocalizedGp2FileToScratch(Text_AppendSelectedTitleAndPanelFormat_PathDataBinProfstrGp2,Text_AppendSelectedTitleAndPanelFormat_MarkupProfstrLGBin,&length);
    if(code){Script_ExecuteCodeWithOwnerModeAndOutputValue((unsigned)script,code,length,(short)(title+20000),(unsigned)titleBuffer,0);titleText=titleBuffer;}
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
   }
  }
  TextContext_SetStringArgument((Buffer*)context,0,titleText);
 }
 char* buffer=P(self,0xb8);int format=100,width=238;if(mode){format=101;width=223;}
 void* text=ResourceStringTable_GetTextByKey(self+0xa0,(void*)format);
 TextMarkup_ExpandAndWrapText(context,10,text,buffer+0x760,width,1,0);
 int y=7;if(String_FindFirstSubstring(buffer+0x760,TextAppendSelectedTitleAndPanelFormat_UnknownRoleInitializedBytes))y=2;
 if(mode){W(self,0xb2c)=(TextLayout_ComputeWidthWithGlyphSpacing(buffer+0x760,0)+16)<<12;if(y==2)W(self,0xb2c)=0xe0000;}
 TextMarkup_AppendYTag(output,y);Text_AppendFormatString(output,buffer+0x760);
}
