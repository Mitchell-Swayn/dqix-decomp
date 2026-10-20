#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);void* GameResources_GetInstance();int GameResources_GetAlternatePartyModel(void*);void* TextLayout_GetThirtyTwoByteFontEntry(int);void* memcpy(void*,const void*,unsigned);void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);void LoadToMainObjVRAM(const void*,unsigned,unsigned);void _Z15CleanCacheRangePKvj(const void*,unsigned);}
// Original: arm9/ov002 @ 0x021619B4; symbol: Graphics_LoadMemberFontPaletteIntoObjectVRAM; size: 0xd8.
extern "C" void PartyMenu_LoadMemberVocationFontPalette(int index,unsigned char* owner,unsigned char* buffer){if(index<0)return;unsigned char* member=_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),index);if(!owner||!buffer||!member)return;unsigned char* record=0;if(P(owner,64)&&U(owner,78)>42)record=P(owner,64)+0x690;if(!record||!P(record,8))return;unsigned char* entry=P(record,8);index=W(P(member,0x150),0x950);if(GameResources_GetAlternatePartyModel(GameResources_GetInstance()))index=0;memcpy(buffer,TextLayout_GetThirtyTwoByteFontEntry((unsigned char)(index*4+40)),128);unsigned offset=(unsigned short)(U(entry,4)&1023)<<5;_Z25CleanInvalidateCacheRangePKvj(buffer,128);LoadToMainObjVRAM(buffer,offset,128);_Z15CleanCacheRangePKvj(buffer,128);}
