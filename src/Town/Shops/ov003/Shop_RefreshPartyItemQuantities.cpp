#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
ARM
typedef unsigned int undefined4;
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" void TextCanvas_ShowGroupEntries(unsigned char*,int);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" int CharacterState_CountCarriedItemCopies(unsigned char*,int);
extern "C" void TextCanvas_SetEntryTextPointer(char*,int,int);
extern "C" int SelectThresholdStateFromMemberAmountRatio(int);
extern "C" void TextCanvas_SetEntryTextColor(char*,int,unsigned);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" void TextCanvas_HideEntry(unsigned char*,int);
extern "C" void TextCanvas_HideGroupEntries(char*,int);
extern "C" void TextCanvas_HideDisplayPart(unsigned char*,int);
extern "C" int PartyInventory_GetTotalItemQuantity(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
struct LowNibble { unsigned value:4; unsigned other:28; };
// Original: arm9/ov003 @ 0x02176F94; symbol: Shop_RefreshPartyItemQuantities; size: 0x274.
// Updates grouped party-member display records with keyed counts and amount-ratio styles.
// The semantic role of the serialized key and selected display groups remains unresolved.
extern "C" void Shop_RefreshPartyItemQuantities(char* self) {
    char* display=*(char**)(self+0x89c);
    GameState* game=GameState::GetInstance();
    unsigned char* list=(unsigned char*)GameState_GetIndexList(game);
    int group=25;
    short memberId=233, countId=235, zeroId=237, nonzeroId=239;
    switch (*(int*)(self+0x1030)) {
    case 2: group=26;memberId=240;countId=243;zeroId=246;nonzeroId=249;break;
    case 3: group=27;memberId=251;countId=255;zeroId=259;nonzeroId=263;break;
    case 4: group=28;memberId=266;countId=271;zeroId=276;nonzeroId=281;break;
    }
    TextCanvas_ShowDisplayPart((unsigned char*)display,group);
    TextCanvas_SetGroupPalette(display,group,0);
    TextCanvas_ShowGroupEntries((unsigned char*)display,group);
    bool hidden=true;
    char* record=(char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)(self+0x874),*(short*)(self+0x103a));
    if (record) hidden=(bool)(int)(((LowNibble*)(record+8))->value<=7 ? 1 : 0);
    if (!hidden) {
        for (unsigned char slot=0; slot<*(int*)(self+0x1030); ++slot) {
            int stats;
            int count;
            int member=(signed char)*(int*)(self+0x101c+slot*4);
            stats=0;count=0;
            GameObject* object=game->GetPartyMemberByIndex(member);
            if (object) {
                stats=(int)object->baseStats_;
                unsigned char* values=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);
                count=(short)CharacterState_CountCarriedItemCopies(values,*(short*)(self+0x103a));
            }
            TextCanvas_SetEntryTextPointer(display,memberId,stats);
            TextCanvas_SetEntryTextColor(display,memberId,SelectThresholdStateFromMemberAmountRatio(member));
            TextCanvas_SetEntryNumericValue(display,countId,count);
            if (count) TextCanvas_HideEntry((unsigned char*)display,nonzeroId);
            else {TextCanvas_HideEntry((unsigned char*)display,countId);TextCanvas_HideEntry((unsigned char*)display,zeroId);}
            ++memberId;++countId;++zeroId;++nonzeroId;
        }
    } else {
        TextCanvas_HideGroupEntries(display,group);
        TextCanvas_HideDisplayPart((unsigned char*)display,group);
    }
    TextCanvas_SetEntryNumericValue(display,countId,PartyInventory_GetTotalItemQuantity(list,*(short*)(self+0x103a)));
    TextCanvas_CreateAndConfigureDisplayPart(display,group);
}
