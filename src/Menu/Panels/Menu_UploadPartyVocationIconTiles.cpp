#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <System/LoadToVRAM.h>
ARM


extern "C" ARM GameResources* GameResources_GetInstance();
extern "C" unsigned GameResources_GetAlternatePartyModel(void*);
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
// Original: arm9/ov023 @ 0x021E2CE8; symbol: func_ov023_021e2ce8; size: 0xF0.
// Uploads four font tiles selected by party state into descriptor OBJ tile storage.
extern "C" void Menu_UploadPartyVocationIconTiles(int index,char* descriptor) {
 if(index<0)return;
 GameState* state=GameState::GetInstance();
 GameObject* member=state->GetPartyMemberByIndex(index);
 if(!descriptor || !member)return;
 char* resource=*(char**)(descriptor+0x40);
 char* record=0;
 if(resource && *(unsigned short*)(descriptor+0x4e)>15)record=resource+0x258;
 if(!record || !(descriptor=*(char**)(record+8)))return;
 index=*(unsigned*)(*(char**)((char*)member+0x150)+0x950);
 GameResources* resources=GameResources_GetInstance();
 if(GameResources_GetAlternatePartyModel(resources))index=0;
 unsigned char tile=index*4+40;
 unsigned offset=(unsigned short)(*(unsigned short*)(descriptor+4)&0x3ff)*32;
 for(int i=0;i<4;i++){
 char* data=TextLayout_GetThirtyTwoByteFontEntry(tile);
 _Z25CleanInvalidateCacheRangePKvj(data,32);
 LoadToMainObjVRAM(data,offset,32);
 _Z15CleanCacheRangePKvj(data,32);
 tile++;offset+=32;
 }
}
