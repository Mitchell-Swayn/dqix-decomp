#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
int TextMarkup_AppendXPositionTag(char*,int);
int TextMarkup_AppendYTag(char*,int);
int TextMarkup_AppendWidthTag(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
int Text_AppendFormatString(char*,const char*);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
unsigned int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char*);
void TextContext_SetNumericArgument(unsigned int*,int,unsigned int);
void TextContext_SetNumericArgumentAlignment(char*,int,int);
void TextContext_SetNumericArgumentWidth(char*,int,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
void* Text_LookupStandardString(unsigned);
void __clear(void*,unsigned);
int sprintf(char*,const char*,...);
// Original data: arm9/ov002 @ 0x216d285; symbol: data_ov002_0216d285.
// Source-defined character literal. Text: "%d". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%d".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
// Original data: arm9/ov002 @ 0x216d2b3; symbol: data_ov002_0216d2b3.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern char PartyMenuFormatActionTargetStatus_TextD[],Graphics_FormatPartyMemberStatusText_FormatSD[],PartyMenuAppendSoundVolumeSettings_UnknownRoleInitializedBytes[];
}
struct Positions { int x[5]; };
// Original data: arm9/ov002 @ 0x216ca30; symbol: data_ov002_0216ca30.
// Text formatting parameters by element count; word table used by func_ov002_0215fb54.
// Initial values: hex 3b0000003b0000004e0000004e0000004e000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" Positions GraphicsFormatPartyMemberStatusText_TextFormattingParametersByElementCount;
// Original: arm9/ov002 @ 0x0215FCC0; symbol: func_ov002_0215fcc0; size: 0x344.
extern "C" void Graphics_FormatPartyMemberStatusText(unsigned char* self,char* output) {
if(!output) return;
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
unsigned char* member;
short label=0x10fe;
short label2=label+20;
member=(unsigned char*)_ZN9GameState21GetPartyMemberByIndexEi(state,*(signed char*)(self+0x1c20));
if(!member) return;
char* name=*(char**)(member+0x134);
int nameWidth=TextLayout_ComputeWidthWithGlyphSpacing(name,0);
char mainText[512]; __clear(mainText,512);
unsigned char* details=*(unsigned char**)(member+0x150);
int index=*(int*)(details+0x950);
int level;
int special=(details+index)[0x186];
level=*(unsigned short*)(details+index*2+0x16c);
if(special) {
char* extra=(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)(short)(special+0x8fc));
TextMarkup_AppendYTag(mainText,4);
Text_AppendFormatString(mainText,name);
TextMarkup_AppendWidthTag(mainText,16);
Text_AppendFormatString(mainText,extra);
TextMarkup_AppendWidthTag(mainText,4);
Text_AppendFormatString(mainText,(char*)Text_LookupStandardString(0x3f3));
char number[16]; __clear(number,16);
sprintf(number,PartyMenuFormatActionTargetStatus_TextD,level);
Text_AppendFormatString(mainText,number);
} else {
TextMarkup_AppendYTag(mainText,4);
Text_AppendFormatString(mainText,name);
TextMarkup_AppendWidthTag(mainText,18);
Text_AppendFormatString(mainText,(char*)Text_LookupStandardString(0x3f3));
char number[16]; __clear(number,16);
sprintf(number,PartyMenuFormatActionTargetStatus_TextD,level);
Text_AppendFormatString(mainText,number);
}
char levelText[256]; __clear(levelText,256);
sprintf(levelText,Graphics_FormatPartyMemberStatusText_FormatSD,Text_LookupStandardString(0x3f3),level);
int total=nameWidth+18+TextLayout_ComputeWidthWithGlyphSpacing(levelText,0);
if(special) total+=9;
int x=(128-total)>>1;
*(unsigned short*)(self+0x245c)=nameWidth+x+1;
TextMarkup_AppendXPositionTag(output,x);
Text_AppendFormatString(output,mainText);
AppendFormattedNumberAndText(output,PartyMenuAppendSoundVolumeSettings_UnknownRoleInitializedBytes,16);
char* owner=(char*)TextContext_GetSharedInstance();
TextLayout_ResetFormattingWorkspace((signed char*)owner);
Positions positions=GraphicsFormatPartyMemberStatusText_TextFormattingParametersByElementCount;
unsigned short* a=*(unsigned short**)(member+0x130);
unsigned short* b=*(unsigned short**)(member+0x134);
unsigned values[7]={a[2],b[0x18],a[3],b[0x19],b[0x1a],b[0x1b],b[0x1c]};
for(int i=0;i<7;i++) {
TextContext_SetNumericArgumentAlignment(owner,i,1);
TextContext_SetNumericArgumentWidth(owner,i,3);
TextContext_SetNumericArgument((unsigned*)owner,i,values[i]);
}
for(int i=0;i<5;i++) {
Text_AppendFormatString(output,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)label++));
TextMarkup_AppendXPositionTag(output,positions.x[i]);
Text_AppendFormatString(output,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)label2++));
if(i!=4) Text_AppendFormatString(output,*(char**)(self+0x1bdc));
}
}
