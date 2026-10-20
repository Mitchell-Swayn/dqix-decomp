#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void __clear(void*,unsigned);
extern "C" int BattleMenu_HasCommandBlockingStatus(char*);
extern "C" int Graphics_FormatPriorityFlaggedPartyLabel(char*,void*);
extern "C" void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*);
// Original: arm9/ov000 @ 0x021814BC; symbol: FormatTextForFourFlaggedIndexedRecords; size: 0xa0.
// Copies field28 into3C and formats text for four indexed records with matching flags.
extern "C" void BattleMenu_RefreshFlaggedPartyStatusLabels(char* p){
 _ZN9GameState11GetInstanceEv();char buffer[128];char* r;
 for(int i=0;i<4;i++){r=p+0x958+*(signed char*)(p+i+0x6c)*0x448;
 if(*(int*)(r+0x4c)>=0){*(int*)(r+0x3c)=*(int*)(r+0x28);if(BattleMenu_HasCommandBlockingStatus(r)){__clear(buffer,128);if(Graphics_FormatPriorityFlaggedPartyLabel(r,buffer)>=0)TextSprite_FormatAndUpdateTextReference((unsigned char*)r+0x50,buffer);}}}
}
