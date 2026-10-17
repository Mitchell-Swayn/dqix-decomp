#include <globaldefs.h>
ARM
extern "C" {
int AppendFiveFormattedArguments(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadSupportedFirmwareLanguage(void*);
int Text_AppendFormattedIntegerFragmentAt020EFE91(char*,int);
int GameState_ReadProtagonistObjectIndex(void*);
char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
int Graphics_SelectObjectRatioColor(void*,int,int,int,unsigned char);
int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
int AppendFormatText(char*,const char*);
char* ReadWordFieldAtOffset150(void*);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int AppendFormattedPair_Main02041A90(char*,int,int);
int TextMarkup_AppendLineTag(char*,int);
struct Positions {short left,right;};
struct Labels {signed char left,right;};
extern Positions data_ov002_0216ca70[];
extern Labels data_ov002_0216ca10[];
extern int data_ov002_0216ca44[],data_ov002_0216ca1c[];
}
inline Positions* PositionsForLanguage(int language){return &data_ov002_0216ca70[language];}
inline Labels* LabelsForLanguage(Labels* base,int language){return &base[language];}
inline signed char* LabelBytes(){return (signed char*)data_ov002_0216ca10;}
inline int LabelOffset(int language){return language*2;}
struct PartyObject {char pad[0x134];char* name;char* GetName(){return name;}};
// Original: arm9/ov002 @ 0x0215F8B8; symbol: func_ov002_0215f8b8; size: 0x29C.
extern "C" void Text_AppendPartyMemberSelectionList(char* p,char* out,int format){
if(!out)return;
int cursor=*(short*)(p+0x1c02);
if(format)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
const char* title=ResolveIndexedRecordAndReturnSecondWord(p+0x20,0xfa2);
Text_AppendFormattedIntegerFragmentAt020EFE78(out,(240-TextLayout_ComputeWidthWithGlyphSpacing(title,0))>>1);
AppendFormattedNumberAndText(out,title,15);
int row=0;
void* gs=_ZN9GameState11GetInstanceEv();
unsigned char count=*(unsigned char*)(p+0x1c73);
signed char* members=(signed char*)p+0x1c6e;
int language=GameState_ReadSupportedFirmwareLanguage(gs);
Positions* positions=PositionsForLanguage(language);
signed char* labelBytes=LabelBytes();
int offset=LabelOffset(language);
Labels* pair=LabelsForLanguage((Labels*)labelBytes,language);
char firstLabel[8]={0};char secondLabel[8]={0};
Text_AppendFormattedIntegerFragmentAt020EFE91(firstLabel,labelBytes[offset]);
Text_AppendFormattedIntegerFragmentAt020EFE91(secondLabel,pair->right);
int protagonist=GameState_ReadProtagonistObjectIndex(gs);
int firstRow=count+1,secondRow=firstRow+count+1;
for(unsigned char i=0;i<count;i++){
int member=members[i];
char* obj=_ZN9GameState21GetPartyMemberByIndexEi(gs,member);
if(obj){
int color=Graphics_SelectObjectRatioColor(p,member,0,1,1);
Text_AppendFormattedIntegerFragmentAt020EFF74(out,color);
const char* name=((PartyObject*)obj)->GetName();
AppendFormatText(out,name);
Text_AppendFormattedIntegerFragmentAt020EFE78(out,0x4a);
Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
signed char kind=*(unsigned*)(ReadWordFieldAtOffset150(obj)+0x94c);
short key=kind+0x109c;
if(member==protagonist)key=0x109b;
const char* text=ResolveIndexedRecordAndReturnSecondWord(p+0x20,key);
Text_AppendFormattedIntegerAndStringFragment(out,row,text);
Text_AppendFormattedIntegerFragmentAt020EFE78(out,positions->left);
Text_AppendFormattedIntegerAndStringFragment(out,firstRow,firstLabel);
Text_AppendFormattedIntegerFragmentAt020EFE78(out,positions->right);
Text_AppendFormattedIntegerAndStringFragment(out,secondRow,secondLabel);
AppendFormatText(out,*(char**)(p+0x1bdc));
row++;firstRow++;secondRow++;
}
}
AppendFormattedPair_Main02041A90(out,0x4a,data_ov002_0216ca44[count]);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResolveIndexedRecordAndReturnSecondWord(p+0x20,0x11fa));
TextMarkup_AppendLineTag(out,data_ov002_0216ca1c[count]);
}
