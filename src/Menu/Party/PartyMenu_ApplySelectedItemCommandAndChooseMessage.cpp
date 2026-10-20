#include <globaldefs.h>
ARM
extern "C" void PartyMenu_TransferEligibleCarriedItemsToBag(void*,int);extern "C" void PartyMenu_RemoveSelectedInventoryItem(void*,int,int,int,int);
// Original: arm9/ov002 @ 0x0215753C; symbol: SelectActionMessageFromCurrentMenuState; size: 0x98.
// Runs menu actions and selects messages238E/2366/125D from current menu fields.
extern "C" int PartyMenu_ApplySelectedItemCommandAndChooseMessage(char* self){int message=-1;if(!*(short*)(self+0x1c12)){if(*(short*)(self+0x1bf0)>=0){message=0x238e;PartyMenu_TransferEligibleCarriedItemsToBag(self,*(signed char*)(self+0x1c20));}if(*(short*)(self+0x1c22)>0 && *(short*)(self+0x1bea)==2){message=0x2366;PartyMenu_RemoveSelectedInventoryItem(self,*(signed char*)(self+0x1c20),*(short*)(self+0x1c22),*(short*)(self+0x1be8),0);}if(*(unsigned*)(self+0x1bbc)==36)message=0x125d;}return message;}
