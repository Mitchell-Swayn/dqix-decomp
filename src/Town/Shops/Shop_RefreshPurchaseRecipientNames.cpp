#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* GameState_GetObjectWithFlag100(void*,int);void TextCanvas_ShowDisplayPart(unsigned char*,int);void TextCanvas_SetGroupPalette(char*,int,unsigned char);void TextCanvas_SetEntryTextPointer(char*,int,int);int SelectThresholdStateFromMemberAmountRatio(int);void TextCanvas_SetEntryTextColor(char*,int,unsigned);int TextCanvas_CreateAndConfigureDisplayPart(char*,int);}
// Original: arm9/ov003 @0x02177300; symbol:Graphics_RefreshPartyRatioDisplayGroup; size:0x110.
// Refreshes mode-specific party display group using member resources and amount-ratio nibble states.
struct PartyPage{char pad[0x101c];int indices[4];int unused;int count;};
extern "C" void Shop_RefreshPurchaseRecipientNames(unsigned char* self){PartyPage* page=(PartyPage*)self;unsigned char* owner;int group;short id;int value;void* game=_ZN9GameState11GetInstanceEv();group=-1;id=-1;owner=P(self,0x89c);switch(page->count){case 2:group=11;id=93;break;case 3:group=12;id=96;break;case 4:group=13;id=100;break;}if(group<0)return;TextCanvas_ShowDisplayPart(owner,group);TextCanvas_SetGroupPalette((char*)owner,group,0);for(unsigned char i=0;i<page->count;++i){value=0;unsigned char* member=GameState_GetObjectWithFlag100(game,page->indices[i]);if(member)value=W(member,0x134);TextCanvas_SetEntryTextPointer((char*)owner,id,value);TextCanvas_SetEntryTextColor((char*)owner,id,SelectThresholdStateFromMemberAmountRatio((signed char)page->indices[i]));++id;}TextCanvas_CreateAndConfigureDisplayPart((char*)owner,group);}
