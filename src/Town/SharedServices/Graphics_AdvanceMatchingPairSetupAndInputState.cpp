#include <globaldefs.h>
ARM
struct Owner;
extern "C" {
void TextCanvas_ResetOtherDisplayParts(Owner*,unsigned);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
void TextCanvas_SetGroupPalette(char*,int,unsigned char);
void KeyRepeater_Reset(unsigned char*);
void Shop_RefreshSaleOwnerItemPreview(void*);
void Shop_CancelItemDetailLoads(void*);
short GameState_CountPositiveSignedByteQuantitiesForGlobalElement(void*);
int Shop_TestSelectionConfirmation(char*);
int Shop_TestSelectionCancellation(unsigned char*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov003 @ 0x0217B214; symbol: func_ov003_0217b214; size: 0x21C.
// Advances the matching-pair setup state and applies selection or pointer input.
extern "C" void Graphics_AdvanceMatchingPairSetupAndInputState(unsigned char* self) {
    unsigned char state=self[0x103f];
    Owner* owner=*(Owner**)(self+0x89c);
    if(state==0) {
        *(short*)(self+0x1014)=0;
        *(short*)(self+0x1016)=0;
        TextCanvas_ResetOtherDisplayParts(owner,0);
        self[0x103f]++;
        return;
    }
    if(state==1) {
        TextCanvas_CreateAndConfigureDisplayPart((char*)owner,0x15);
        *(short*)(self+0xffe)=0x1d;
        if(*(short*)(self+0x1012)<0) {
            *(short*)(self+0x1012)=(short)FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)owner,*(short*)(self+0xffe));
        }
        *(short*)((char*)owner+0x36)=*(short*)(self+0x1012);
        TextCanvas_SetGroupPalette((char*)owner,*(short*)(self+0xffe),0);
        TextCanvas_CreateAndConfigureDisplayPart((char*)owner,*(short*)(self+0xffe));
        KeyRepeater_Reset(self+0x88c);
        *(unsigned*)(self+0xff8)=0;
        self[0x103f]++;
        Shop_RefreshSaleOwnerItemPreview(self);
        Shop_CancelItemDetailLoads(self);
        return;
    }
    if(state!=2)return;
    *(unsigned char**)(self+0xff8)=(unsigned char*)(self+0x1012);
    Shop_RefreshSaleOwnerItemPreview(self);
    TextCanvas_SetGroupPalette((char*)owner,0x15,1);
    if(Shop_TestSelectionConfirmation((char*)self)!=0) {
        SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage,1,0);
        KeyRepeater_Reset(self+0x88c);
        *(unsigned*)(self+0xff8)=0;
        if(GameState_CountPositiveSignedByteQuantitiesForGlobalElement(self)==0) {
            *(short*)(self+0x1036)=0x24;
            TextCanvas_ResetOtherDisplayParts(owner,0);
            self[0x103f]=0;
            *(unsigned short*)(self+0x1046)|=0x20;
            return;
        }
        TextCanvas_ResetOtherDisplayParts(owner,0);
        self[0x103e]=8;
        self[0x103f]=0;
        TextCanvas_SetGroupPalette((char*)owner,*(short*)(self+0xffe),1);
        *(short*)(self+0xffc)=*(short*)(self+0xffe);
        *(short*)(self+0x100e)=-1;
        *(unsigned short*)(self+0x103a)=1;
        return;
    }
    if(!Shop_TestSelectionCancellation(self))return;
    TextCanvas_ResetOtherDisplayParts(owner,0);
    self[0x103e]=3;
    self[0x103f]=0;
    *(unsigned*)(self+0xff8)=0;
}
