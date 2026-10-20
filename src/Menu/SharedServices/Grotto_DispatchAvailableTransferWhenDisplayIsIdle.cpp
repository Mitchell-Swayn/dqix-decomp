#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" char* GameResources_GetInstance(...);
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" int GameResources_IsSelectedScreenBrightnessNeutral(...);
extern "C" int GameState_TransferAvailableGrottoDescriptorAndTexts(...);
extern "C" int GameState_CopyAvailableGrottoTransferMetadata(...);
extern "C" void Menu_QueueScriptEntry(...);
extern "C" void GameState_SetTransferredTreasureMapTypeInvalid(...);
extern "C" void World_SetIndexedByteValue(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov004 @ 0x021650F8; symbol: Grotto_DispatchAvailableTransferWhenDisplayIsIdle; size: 0xd0.
// Checks idle display fields and shared owner, transfers available grotto metadata, then dispatches code107 or100.
extern "C" int Grotto_DispatchAvailableTransferWhenDisplayIsIdle(char* self){char* game=_ZN9GameState11GetInstanceEv();char* resources=GameResources_GetInstance();if(!GameResources_IsSelectedScreenBrightnessNeutral(resources,0)||!GameResources_IsSelectedScreenBrightnessNeutral(resources,1))return 0;if(W(TextContext_GetSharedInstance(),0x998))return 0;if(GameState_TransferAvailableGrottoDescriptorAndTexts(game,0,0,0))Menu_QueueScriptEntry(self,107);else if(GameState_CopyAvailableGrottoTransferMetadata(game,0)){GameState_SetTransferredTreasureMapTypeInvalid(_ZN9GameState11GetInstanceEv());World_SetIndexedByteValue(GameResources_GetInstance(),2);Menu_QueueScriptEntry(self,100);}else Menu_QueueScriptEntry(self,100);return 0;}
