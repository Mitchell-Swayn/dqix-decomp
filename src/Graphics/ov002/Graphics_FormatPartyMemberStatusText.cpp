#include <globaldefs.h>
ARM
struct GameState; struct Object3D;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
int TextMarkup_AppendYTag(char*,int);
int Text_AppendFormattedIntegerFragmentAt020EFE91(char*,int);
int AppendFormattedNumberAndText(char*,const char*,int);
int AppendFormatText(char*,const char*);
int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
unsigned int ReadWordFieldAtOffset1C();
void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned int*,int,unsigned int);
void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(char*,int,int);
void WriteBoundedIndexedByteAt902(char*,int,int);
void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
void* LookupGlobalResourceByKey(unsigned);
void __clear(void*,unsigned);
int sprintf(char*,const char*,...);
extern char data_ov002_0216d285[],data_ov002_0216d2ae[],data_ov002_0216d2b3[];
}
struct Positions { int x[5]; };
extern "C" Positions data_ov002_0216ca30;
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
char* extra=(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)(short)(special+0x8fc));
TextMarkup_AppendYTag(mainText,4);
AppendFormatText(mainText,name);
Text_AppendFormattedIntegerFragmentAt020EFE91(mainText,16);
AppendFormatText(mainText,extra);
Text_AppendFormattedIntegerFragmentAt020EFE91(mainText,4);
AppendFormatText(mainText,(char*)LookupGlobalResourceByKey(0x3f3));
char number[16]; __clear(number,16);
sprintf(number,data_ov002_0216d285,level);
AppendFormatText(mainText,number);
} else {
TextMarkup_AppendYTag(mainText,4);
AppendFormatText(mainText,name);
Text_AppendFormattedIntegerFragmentAt020EFE91(mainText,18);
AppendFormatText(mainText,(char*)LookupGlobalResourceByKey(0x3f3));
char number[16]; __clear(number,16);
sprintf(number,data_ov002_0216d285,level);
AppendFormatText(mainText,number);
}
char levelText[256]; __clear(levelText,256);
sprintf(levelText,data_ov002_0216d2ae,LookupGlobalResourceByKey(0x3f3),level);
int total=nameWidth+18+TextLayout_ComputeWidthWithGlyphSpacing(levelText,0);
if(special) total+=9;
int x=(128-total)>>1;
*(unsigned short*)(self+0x245c)=nameWidth+x+1;
Text_AppendFormattedIntegerFragmentAt020EFE78(output,x);
AppendFormatText(output,mainText);
AppendFormattedNumberAndText(output,data_ov002_0216d2b3,16);
char* owner=(char*)ReadWordFieldAtOffset1C();
ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)owner);
Positions positions=data_ov002_0216ca30;
unsigned short* a=*(unsigned short**)(member+0x130);
unsigned short* b=*(unsigned short**)(member+0x134);
unsigned values[7]={a[2],b[0x18],a[3],b[0x19],b[0x1a],b[0x1b],b[0x1c]};
for(int i=0;i<7;i++) {
Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(owner,i,1);
WriteBoundedIndexedByteAt902(owner,i,3);
SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)owner,i,values[i]);
}
for(int i=0;i<5;i++) {
AppendFormatText(output,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)label++));
Text_AppendFormattedIntegerFragmentAt020EFE78(output,positions.x[i]);
AppendFormatText(output,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)label2++));
if(i!=4) AppendFormatText(output,*(char**)(self+0x1bdc));
}
}
