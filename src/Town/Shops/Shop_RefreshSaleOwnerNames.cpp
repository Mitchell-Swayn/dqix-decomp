#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameState_GetIndexList(void*);void TextCanvas_ShowGroupEntries(unsigned char*,int);unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);void TextCanvas_ShowDisplayPart(unsigned char*,int);void TextCanvas_SetGroupPalette(char*,int,unsigned char);void TextCanvas_SetEntryTextPointer(char*,int,int);int SelectThresholdStateFromMemberAmountRatio(int);void TextCanvas_SetEntryTextColor(char*,int,unsigned);int TextCanvas_CreateAndConfigureDisplayPart(char*,int);}
// Original: arm9/ov003 @0x02177820; symbol:Graphics_RefreshExpandedPartyRatioDisplayGroup; size:0x118.
// Refreshes mode-specific party display group using member resources and amount-ratio nibble states.
struct PartyPage{char pad[0x101c];int indices[4];int unused;int count;};
extern "C" void Shop_RefreshSaleOwnerNames(unsigned char* self){PartyPage* page=(PartyPage*)self;unsigned char* owner;int group;short id;int value;owner=P(self,0x89c);void* game=_ZN9GameState11GetInstanceEv();GameState_GetIndexList(game);group=17;id=121;switch(page->count){case 2:group=18;id=124;break;case 3:group=19;id=128;break;case 4:group=20;id=133;break;}TextCanvas_ShowDisplayPart(owner,group);TextCanvas_SetGroupPalette((char*)owner,group,0);TextCanvas_ShowGroupEntries(owner,group);for(unsigned char i=0;i<page->count;++i){value=0;unsigned char* member=_ZN9GameState21GetPartyMemberByIndexEi(game,page->indices[i]);if(member)value=W(member,0x134);TextCanvas_SetEntryTextPointer((char*)owner,id,value);TextCanvas_SetEntryTextColor((char*)owner,id,SelectThresholdStateFromMemberAmountRatio((signed char)page->indices[i]));++id;}TextCanvas_CreateAndConfigureDisplayPart((char*)owner,group);}
