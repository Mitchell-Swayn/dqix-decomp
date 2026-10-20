#include <globaldefs.h>
ARM
extern "C" {
void TextCanvas_ShowDisplayPart(void*,int);
int TextCanvas_CreateAndConfigureDisplayPart(void*,int);
const char* ResourceStringTable_GetTextByKey(void*,int);
char* TextContext_GetSharedInstance();
void* memset(void*,int,unsigned);
void TextLayout_ResetFormattingWorkspace(signed char*);
void* Text_LookupNameTableEntry(void*,int);
int _s32_div_f(int,int);
void TextContext_SetNumericArgument(unsigned*,int,unsigned);
void* _ZN9GameState11GetInstanceEv();
char* _ZN9GameState20GetUnknownGameObjectEv(void*);
void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
void TextMarkup_ExpandAndWrapText(void*,int,const void*,void*,int,int,unsigned);
char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
void* memcpy(void*,const void*,unsigned);
void TextCanvas_SetEntryTextPointer(char*,int,int);
void KrakPot_UpdateDialogueNotificationTimer(void*);
// Original data: arm9/ov006 @ 0x215ffd2; symbol: data_ov006_0215ffd2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 39003a003b00ffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x215ffea; symbol: data_ov006_0215ffea.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0c00360037003800ffff.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern short TextAdvanceFormattedMessageAndRefreshDisplay_UnknownRoleInitializedBytes[],TextAdvanceFormattedMessageAndRefreshDisplay_UnknownRoleInitializedBytes_Variant2[];
}
struct SignedSix {signed char length:6;unsigned char flags:2;};
#define H(o) (*(unsigned short*)(self+(o)))
#define S(o) (*(short*)(self+(o)))
#define W(o) (*(int*)(self+(o)))
// Original: arm9/ov006 @ 0x0215A00C; symbol: func_ov006_0215a00c; size: 0x330.
extern "C" void Text_AdvanceFormattedMessageAndRefreshDisplay(unsigned char* self) {
if(self[0x392]==0) {
if(H(0x394)&32) {
TextCanvas_ShowDisplayPart(*(void**)(self+20),0);
TextCanvas_CreateAndConfigureDisplayPart(*(void**)(self+20),0);
}
H(0x394)&=~32;H(0x380)=0;
if(!ResourceStringTable_GetTextByKey(self+0x158,S(0x37e))) S(0x37e)=-1;
W(0x3b0)=-1;self[0x392]++;
} else if(self[0x392]==1) {
char* formatter=TextContext_GetSharedInstance();char* text=*(char**)(formatter+0x5c);
memset(text,0,0x960);TextLayout_ResetFormattingWorkspace((signed char*)formatter);
unsigned short rounded=0;
if(W(0x34)) {
void* data=Text_LookupNameTableEntry(self+0x170,S(0x1ec));if(data) *(void**)(formatter+24)=data;
rounded=_s32_div_f(S(0x382),10)*10;
}
TextContext_SetNumericArgument((unsigned*)formatter,0,self[0x387]);
TextContext_SetNumericArgument((unsigned*)formatter,1,rounded);
char* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
char descriptor[12];
if(object) {GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,*(short*)(object+4));*(void**)formatter=descriptor;}
int index=0;short* ids=TextAdvanceFormattedMessageAndRefreshDisplay_UnknownRoleInitializedBytes;
while(1) {
if(*ids<0) break;
if(*ids==S(0x37e)) {
void* data=Text_LookupNameTableEntry(self+0x170,*(short*)(self+index*2+0x378));if(data) *(void**)(formatter+24)=data;break;
}++ids;++index;
}
TextMarkup_ExpandAndWrapText(formatter,12,ResourceStringTable_GetTextByKey(self+0x158,S(0x37e)),text,227,0,1);
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
TextCanvas_SetEntryTextPointer(*(char**)(self+20),1,(int)buffer);
TextCanvas_CreateAndConfigureDisplayPart(*(void**)(self+20),1);
TextCanvas_ShowDisplayPart(*(void**)(self+20),1);
W(0x3b0)=1;
short* stop=TextAdvanceFormattedMessageAndRefreshDisplay_UnknownRoleInitializedBytes_Variant2;
while(1) {if(*stop<0) break;if(*stop==S(0x37e)) {W(0x3b0)=-1;break;}++stop;}
KrakPot_UpdateDialogueNotificationTimer(self);
}
}
