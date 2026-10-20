#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();int GameState_ReadSupportedFirmwareLanguage(void*);unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);void Graphics_CopyScreenAtPosition(char*,const short*,unsigned,unsigned,unsigned short);void Graphics_SubmitTransformedCellToOam(void*,void*);}
// Original: arm9/ov000 @0x0218124c; symbol:Graphics_DrawLanguageEntryAndInactivePartyMarker; size:0x118.
// Draws language-specific bounded entry and submits marker when selected party member has zero field1c4; preserves target-proven extra submit argument through canonical caller view.
extern "C" void Graphics_DrawLanguageEntryAndInactivePartyMarker(unsigned char* self,int index,char* output,int unused,short x,short y,short markerX,short markerY){void* game=_ZN9GameState11GetInstanceEv();unsigned entry=5;unsigned language=GameState_ReadSupportedFirmwareLanguage(game);switch(language){case 2:entry=6;break;case 3:entry=8;break;case 4:entry=7;break;case 5:entry=9;break;}char* record=Graphics_GetLoadedScreenDescriptor((char*)self+0x8c4,entry);Graphics_CopyScreenAtPosition(output,(const short*)record,(short)(x+2),(short)(y+1),(unsigned short)(index+2));unsigned char* member=_ZN9GameState21GetPartyMemberByIndexEi(game,index);if(member&&W(member,0x1c4)==0){unsigned char* marker=P(self,0x170)+(index+32)*40;W(marker,20)=markerX<<12;W(marker,24)=markerY<<12;marker[34]=index+92;marker[38]=1;((void(*)(void*,void*,int))Graphics_SubmitTransformedCellToOam)(self+0x11c,marker,1);}}
