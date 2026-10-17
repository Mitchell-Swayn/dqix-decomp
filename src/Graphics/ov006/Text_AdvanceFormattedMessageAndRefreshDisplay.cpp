#include <globaldefs.h>
ARM
extern "C" {
void ClearResolvedEntryByteC5Bit20(void*,int);
int Object_CreateAndConfigureSelectedDisplayPart(void*,int);
const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
char* ReadWordFieldAtOffset1C();
void* memset(void*,int,unsigned);
void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
void* ForwardTwoArgumentLookup(void*,int);
int _s32_div_f(int,int);
void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
void* _ZN9GameState11GetInstanceEv();
char* _ZN9GameState20GetUnknownGameObjectEv(void*);
void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,const void*,void*,int,int,unsigned);
char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
void* memcpy(void*,const void*,unsigned);
void SetKeyedRecordFirstWord(char*,int,int);
void Util_UpdateElapsedStateAndDispatchAt60(void*);
extern short data_ov006_0215ffd2[],data_ov006_0215ffea[];
}
struct SignedSix {signed char length:6;unsigned char flags:2;};
#define H(o) (*(unsigned short*)(self+(o)))
#define S(o) (*(short*)(self+(o)))
#define W(o) (*(int*)(self+(o)))
// Original: arm9/ov006 @ 0x0215A00C; symbol: func_ov006_0215a00c; size: 0x330.
extern "C" void Text_AdvanceFormattedMessageAndRefreshDisplay(unsigned char* self) {
if(self[0x392]==0) {
if(H(0x394)&32) {
ClearResolvedEntryByteC5Bit20(*(void**)(self+20),0);
Object_CreateAndConfigureSelectedDisplayPart(*(void**)(self+20),0);
}
H(0x394)&=~32;H(0x380)=0;
if(!ResolveIndexedRecordAndReturnSecondWord(self+0x158,S(0x37e))) S(0x37e)=-1;
W(0x3b0)=-1;self[0x392]++;
} else if(self[0x392]==1) {
char* formatter=ReadWordFieldAtOffset1C();char* text=*(char**)(formatter+0x5c);
memset(text,0,0x960);ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)formatter);
unsigned short rounded=0;
if(W(0x34)) {
void* data=ForwardTwoArgumentLookup(self+0x170,S(0x1ec));if(data) *(void**)(formatter+24)=data;
rounded=_s32_div_f(S(0x382),10)*10;
}
SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)formatter,0,self[0x387]);
SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)formatter,1,rounded);
char* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
char descriptor[12];
if(object) {GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(short*)(object+4));*(void**)formatter=descriptor;}
int index=0;short* ids=data_ov006_0215ffd2;
while(1) {
if(*ids<0) break;
if(*ids==S(0x37e)) {
void* data=ForwardTwoArgumentLookup(self+0x170,*(short*)(self+index*2+0x378));if(data) *(void**)(formatter+24)=data;break;
}++ids;++index;
}
ProcessSixStagesUsingSharedWordScratchBuffer(formatter,12,ResolveIndexedRecordAndReturnSecondWord(self+0x158,S(0x37e)),text,227,0,1);
char* cursor;unsigned short offset=H(0x380);
int old=W(0)>>4;W(0)+=W(0x34c)<<4;cursor=text+offset;int steps=(W(0)>>4)-old;
if(W(0)>=0xffffff) W(0)=0;
for(int i=0;i<steps;i++) {
if(!*cursor) break;
int length=1;
if(cursor[0]=='\\' && cursor[1]=='n') {cursor+=2;offset+=2;}
else {
char* entry=TextLookup_FindMatchingByteKeyEntry(cursor,1);if(entry) length=((SignedSix*)(entry+5))->length;
cursor+=length;offset+=length;
}
}
if(H(0x380)>=offset) S(0x37e)=-1;
H(0x380)=offset;
char buffer[1024]={0};memcpy(buffer,text,offset);
SetKeyedRecordFirstWord(*(char**)(self+20),1,(int)buffer);
Object_CreateAndConfigureSelectedDisplayPart(*(void**)(self+20),1);
ClearResolvedEntryByteC5Bit20(*(void**)(self+20),1);
W(0x3b0)=1;
short* stop=data_ov006_0215ffea;
while(1) {if(*stop<0) break;if(*stop==S(0x37e)) {W(0x3b0)=-1;break;}++stop;}
Util_UpdateElapsedStateAndDispatchAt60(self);
}
}
