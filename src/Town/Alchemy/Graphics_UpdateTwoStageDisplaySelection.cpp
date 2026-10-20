#include <globaldefs.h>
ARM
struct List;
struct Node;
extern "C" void ConfigureSelectedPartsWithFlaggedEntryPercentage(char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" int KrakPot_HandleSelectionConfirmInput(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" Node* LinkedList_SelectAndRebuildNodes(List*,int,int,int,short,short*);
extern "C" void KrakPot_ResetRecipePagination(void*);
extern "C" void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
extern "C" int KrakPot_HandleSelectionCancelInput(void*);
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char*);
extern "C" void Graphics_ClearFlagAndRefreshBackgrounds(void*);
extern "C" void KrakPot_RequestExitOnNewInputMask(void*);
extern "C" void Util_DecodeSplitByteSelector(int,unsigned char*,signed char*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov006 @ 0x0215DAF0; symbol: func_ov006_0215daf0; size: 0x3F8.
extern "C" void Graphics_UpdateTwoStageDisplaySelection(unsigned char* self) {
if(self[0x390]==0) {
self[0x397]=2;
ConfigureSelectedPartsWithFlaggedEntryPercentage((char*)self,1);
*(short*)(self+0x36e)=8;
if(*(short*)(self+0x366)<0) *(short*)(self+0x366)=36;
*(short*)(*(char**)(self+0x14)+0x36)=*(short*)(self+0x366);
TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x14),*(short*)(self+0x36e));
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
self[0x390]++;
} else if(self[0x390]==1) {
*(void**)(self+0x44)=self+0x366;
if(KrakPot_HandleSelectionConfirmInput(self)) {
SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
*(short*)(self+0x368)=-1;*(short*)(self+0x36a)=-1;
*(signed char*)(self+0x384)=-1;*(signed char*)(self+0x385)=-1;
bool finish=false;
switch(*(short*)(self+0x366)) {
case 36:finish=true;break;
case 37:self[0x384]=0;self[0x390]++;break;
case 38:self[0x390]++;break;
case 39:self[0x384]=7;finish=true;break;
case 40:self[0x384]=8;finish=true;break;
}
if(finish) {
self[0x38f]=10;self[0x390]=0;
*(unsigned short*)(self+0x394)|=0x80;
}
short count=0;
LinkedList_SelectAndRebuildNodes((List*)(self+0x14c),*(signed char*)(self+0x384),*(signed char*)(self+0x385),self[0x386],16,&count);
void* head=*(void**)(self+0x14c);
*(void**)(self+0x2c)=head;
*(void**)(self+0x30)=head;
KrakPot_ResetRecipePagination(self);
TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),*(short*)(self+0x36e));
} else {
if(KrakPot_HandleSelectionCancelInput(self)) {
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
Graphics_UpdateCounted224ByteDisplayRecords(*(char**)(self+0x14));
self[0x38f]=4;self[0x390]=0;self[0x397]=0;
*(unsigned short*)(self+0x394)|=0x20;
*(short*)(self+0x37e)=0;self[0x392]=0;
Graphics_ClearFlagAndRefreshBackgrounds(*(void**)(self+0x10));
}
KrakPot_RequestExitOnNewInputMask(self);
}
} else if(self[0x390]==2) {
self[0x397]=2;
ConfigureSelectedPartsWithFlaggedEntryPercentage((char*)self,0);
if(*(short*)(self+0x366)==37) {
*(short*)(self+0x36e)=12;
if(*(short*)(self+0x368)<0) *(short*)(self+0x368)=72;
} else if(*(short*)(self+0x366)==38) {
*(short*)(self+0x36e)=11;
if(*(short*)(self+0x368)<0) *(short*)(self+0x368)=64;
}
*(short*)(*(char**)(self+0x14)+0x36)=*(short*)(self+0x368);
TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x14),*(short*)(self+0x36e));
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
self[0x390]++;
} else if(self[0x390]==3) {
*(void**)(self+0x44)=self+0x368;
if(KrakPot_HandleSelectionConfirmInput(self)) {
SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
*(short*)(self+0x36a)=-1;
Util_DecodeSplitByteSelector(*(short*)(self+0x368),self+0x384,(signed char*)(self+0x385));
short count=0;
LinkedList_SelectAndRebuildNodes((List*)(self+0x14c),*(signed char*)(self+0x384),*(signed char*)(self+0x385),self[0x386],16,&count);
void* head=*(void**)(self+0x14c);
*(void**)(self+0x2c)=head;
*(void**)(self+0x30)=head;
KrakPot_ResetRecipePagination(self);
TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),*(short*)(self+0x36e));
self[0x38f]=10;self[0x390]=0;
*(unsigned short*)(self+0x394)|=0x80;
} else {
if(KrakPot_HandleSelectionCancelInput(self)) {
KeyRepeater_Reset(self+0x9c);
*(void**)(self+0x44)=0;
*(short*)(self+0x368)=-1;
TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),*(short*)(self+0x36e));
self[0x390]=0;
}
KrakPot_RequestExitOnNewInputMask(self);
}
}
}
