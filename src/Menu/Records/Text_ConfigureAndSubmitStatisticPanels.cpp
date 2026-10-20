#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma always_inline on
struct Record;
extern "C" {
unsigned TextContext_GetSharedInstance();void* _ZN9GameState11GetInstanceEv();void* _ZN9GameState14GetProtagonistEv(void*);
void _ZN16BackgroundLoader13AddLockGlobalEv();void _ZN16BackgroundLoader16RemoveLockGlobalEv();void* __clear(void*,unsigned);void* Filesystem_ExtractLocalizedGp2FileToScratch(const char*,const char*,unsigned*);
char* ResourceStringTable_CopyTextByKey(char*,int,int,int);int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);int Text_AppendFormattedXYPair(char*,int,int);int Text_AppendFormatString(char*,const char*);
void* GameState_GetSerializedProgressState();unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);void* ResourceStringTable_GetTextByKey(void*,void*);
bool GameState_CopyStatisticsRecord(void*);unsigned GameStats_GetCompletionPercentOf307(Record*);unsigned GameStats_GetCompletionPercentOf944(Record*);unsigned GameStats_GetCompletionPercentOf232(Record*);unsigned GameStats_GetCompletionPercentOf448(unsigned*);
void TextLayout_ResetFormattingWorkspace(signed char*);void TextContext_SetNumericArgument(unsigned*,int,unsigned);
int TextMarkup_AppendYTag(char*,int);int TextMarkup_AppendXRWrappedText(char*,const char*,int);
extern char Text_AppendStoredNameOrPercentageRows_PathDataBinTtlnameDGp2[],Text_AppendStoredNameOrPercentageRows_FormatTtlnameDLGNat[];
}
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct LowBit {unsigned char value:1,other:7;};
struct StoredSelection {char pad[16];unsigned low:23,selection:9;};
struct PackedPercents {char pad[8];unsigned pad8:14,first:7,third:7,tail8:4;unsigned padc:24,second:7,tailc:1;unsigned pad10:23,fourth:7,tail10:2;};
struct RawCounts {char pad[16];unsigned low:23,fourth:9;unsigned first:9,third:9,second:11,tail:3;char rest[152];};
inline void AppendStoredNameOrLabels(char* self,char* output,int mode,StoredSelection* stored) {
 if(!output)return;
 signed char* context=(signed char*)TextContext_GetSharedInstance();
 if(stored) {
  void* member=_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());char* name=P(self,0xb8)+0x8e0;
  _ZN16BackgroundLoader13AddLockGlobalEv();char archive[64],inner[32];unsigned size=0;__clear(archive,64);__clear(inner,32);
  sprintf(archive,Text_AppendStoredNameOrPercentageRows_PathDataBinTtlnameDGp2,((LowBit*)(P(member,0x150)+0x49c))->value);
  sprintf(inner,Text_AppendStoredNameOrPercentageRows_FormatTtlnameDLGNat,((LowBit*)(P(member,0x150)+0x49c))->value);
  char* data=(char*)Filesystem_ExtractLocalizedGp2FileToScratch(archive,inner,&size);if(data)ResourceStringTable_CopyTextByKey(name,(int)data,size,stored->selection);
  _ZN16BackgroundLoader16RemoveLockGlobalEv();int left=(160-TextLayout_ComputeWidthWithGlyphSpacing(name,1))/2;if(left<0)left=0;
  Text_AppendFormattedXYPair(output,left,6);if(name)Text_AppendFormatString(output,name);
 } else {
  int rows=3;char* flags=(char*)GameState_GetSerializedProgressState();if(BitArray_ReadNonnegativeIndexMask(flags,(unsigned char*)flags+0x8c,0x1198))rows=4;
  if(mode==0){for(int i=0;i<rows;i++){Text_AppendFormattedXYPair(output,4,15*i+4);Text_AppendFormatString(output,(char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)(int)(short)(130+i)));}}

 }
}

extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" void Text_AppendStoredNameOrPercentageRows(char*,char*,int,StoredSelection*);
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov008 @ 0x02187F6C; symbol: func_ov008_02187f6c; size: 0x49C.
// Configures stored/current statistic panels, appends name/labels and submits the percentage pass.
extern "C" void Text_ConfigureAndSubmitStatisticPanels(char* self,StoredSelection* stored) {
 if(stored) {
  H(self,0x1d0)=20;H(self,0x1d2)=3;H(self,0x1d4)=6;H(self,0x1d6)=17;H(self,0x1d8)=0;H(self,0x1da)=6;H(self,0x1dc)=12;H(self,0x1de)=14;
  B(self,0x1e7)=12;B(self,0x1e1)=4;B(self,0x1e5)=1;B(self,0x1e6)=1;
  memset(P(self,0xb8),0,0x960);AppendStoredNameOrLabels(self,P(self,0xb8),0,stored);
  Window_PushTextCanvas(self+0x130,P(self,0xb8),0,0,0,0,0,1);
 } else {
  H(self,0x1d0)=22;H(self,0x1d2)=8;H(self,0x1d4)=1;H(self,0x1d6)=15;H(self,0x1d8)=4;H(self,0x1da)=5;H(self,0x1dc)=10;H(self,0x1de)=14;
  B(self,0x1e7)=10;B(self,0x1e1)=4;B(self,0x1e5)=1;B(self,0x1e6)=1;
  memset(P(self,0xb8),0,0x960);AppendStoredNameOrLabels(self,P(self,0xb8),0,stored);
  Window_PushTextCanvas(self+0x130,P(self,0xb8),0,0,0,0,0,0);
  H(self,0x1d0)=3;H(self,0x1d2)=8;H(self,0x1d4)=27;H(self,0x1d6)=15;H(self,0x1d8)=4;H(self,0x1da)=5;H(self,0x1dc)=10;H(self,0x1de)=14;
  B(self,0x1e7)=10;B(self,0x1e1)=5;B(self,0x1e5)=1;B(self,0x1e6)=1;
  memset(P(self,0xb8),0,0x960);Text_AppendStoredNameOrPercentageRows(self,P(self,0xb8),1,stored);
  Window_PushTextCanvas(self+0x130,P(self,0xb8),0,0,0,0,0,0);
 }
}
