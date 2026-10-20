#include <globaldefs.h>
ARM
extern "C" {
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
const char* ResourceStringTable_GetTextByKey(void*,int);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
int TextMarkup_AppendXPositionTag(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadSupportedFirmwareLanguage(void*);
int TextMarkup_AppendWidthTag(char*,int);
int GameState_ReadProtagonistObjectIndex(void*);
char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
int Graphics_SelectObjectRatioColor(void*,int,int,int,unsigned char);
int TextMarkup_AppendPaletteTag(char*,int);
int Text_AppendFormatString(char*,const char*);
char* GameObject_GetLinkedIndexedState(void*);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int Text_AppendFormattedXYPair(char*,int,int);
int TextMarkup_AppendLineTag(char*,int);
struct Positions {short left,right;};
struct Labels {signed char left,right;};
// Original data: arm9/ov002 @ 0x216ca70; symbol: data_ov002_0216ca70.
// Pairs of text style parameters; Text_AppendPartyMemberSelectionList loads halfwords at offsets0/2 for each four-byte entry.
// Initial values: hex a800d200a800d200a200cc00a800d200a000d200a000d200.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern Positions TextAppendPartyMemberSelectionList_PairsOfTextStyleParameters[];
// Original data: arm9/ov002 @ 0x216ca10; symbol: data_ov002_0216ca10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 181818182020181820182018.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern Labels TextAppendPartyMemberSelectionList_UnknownRoleInitializedBytes[];
// Original data: arm9/ov002 @ 0x216ca1c; symbol: data_ov002_0216ca1c.
// Text formatting parameters indexed by item count; Text_AppendPartyMemberSelectionList selects words for func_02041cc0.
// Initial values: hex 00000000250000002f0000003f00000047000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
// Original data: arm9/ov002 @ 0x216ca44; symbol: data_ov002_0216ca44.
// Text placement parameters by item count; Text_AppendPartyMemberSelectionList selects words for text-control 0x4a.
// Initial values: hex 0000000028000000310000004100000049000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern int TextAppendPartyMemberSelectionList_TextPlacementParametersByItemCount[],TextAppendPartyMemberSelectionList_TextFormattingParametersIndexedByItemCount[];
}
inline Positions* PositionsForLanguage(int language){return &TextAppendPartyMemberSelectionList_PairsOfTextStyleParameters[language];}
inline Labels* LabelsForLanguage(Labels* base,int language){return &base[language];}
inline signed char* LabelBytes(){return (signed char*)TextAppendPartyMemberSelectionList_UnknownRoleInitializedBytes;}
inline int LabelOffset(int language){return language*2;}
struct PartyObject {char pad[0x134];char* name;char* GetName(){return name;}};
// Original: arm9/ov002 @ 0x0215F8B8; symbol: func_ov002_0215f8b8; size: 0x29C.
extern "C" void Text_AppendPartyMemberSelectionList(char* p,char* out,int format){
if(!out)return;
int cursor=*(short*)(p+0x1c02);
if(format)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
const char* title=ResourceStringTable_GetTextByKey(p+0x20,0xfa2);
TextMarkup_AppendXPositionTag(out,(240-TextLayout_ComputeWidthWithGlyphSpacing(title,0))>>1);
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
TextMarkup_AppendWidthTag(firstLabel,labelBytes[offset]);
TextMarkup_AppendWidthTag(secondLabel,pair->right);
int protagonist=GameState_ReadProtagonistObjectIndex(gs);
int firstRow=count+1,secondRow=firstRow+count+1;
for(unsigned char i=0;i<count;i++){
int member=members[i];
char* obj=_ZN9GameState21GetPartyMemberByIndexEi(gs,member);
if(obj){
int color=Graphics_SelectObjectRatioColor(p,member,0,1,1);
TextMarkup_AppendPaletteTag(out,color);
const char* name=((PartyObject*)obj)->GetName();
Text_AppendFormatString(out,name);
TextMarkup_AppendXPositionTag(out,0x4a);
TextMarkup_AppendPaletteTag(out,15);
signed char kind=*(unsigned*)(GameObject_GetLinkedIndexedState(obj)+0x94c);
short key=kind+0x109c;
if(member==protagonist)key=0x109b;
const char* text=ResourceStringTable_GetTextByKey(p+0x20,key);
Text_AppendFormattedIntegerAndStringFragment(out,row,text);
TextMarkup_AppendXPositionTag(out,positions->left);
Text_AppendFormattedIntegerAndStringFragment(out,firstRow,firstLabel);
TextMarkup_AppendXPositionTag(out,positions->right);
Text_AppendFormattedIntegerAndStringFragment(out,secondRow,secondLabel);
Text_AppendFormatString(out,*(char**)(p+0x1bdc));
row++;firstRow++;secondRow++;
}
}
Text_AppendFormattedXYPair(out,0x4a,TextAppendPartyMemberSelectionList_TextPlacementParametersByItemCount[count]);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResourceStringTable_GetTextByKey(p+0x20,0x11fa));
TextMarkup_AppendLineTag(out,TextAppendPartyMemberSelectionList_TextFormattingParametersIndexedByItemCount[count]);
}
