#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void **,unsigned short);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" void *Menu_GetRecordMessageTable(void *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned TextContext_GetSharedInstance(void);
extern "C" int SaveData_InitializeDefaultStateAndPackets(void);
extern "C" unsigned MessageTextTable_FindTextById(void *,int);
extern "C" void TextWindow_StartFormattedMessage(int,int,int,int);
extern "C" void GameState_SetUnk4Element0(void *,int);
extern "C" void GameState_WriteUnknownF70(void *,unsigned);
extern "C" void Menu_QueueScriptEntry(void *,unsigned);
// Original: arm9/ov004 @ 0x0216D5B0; symbol: SaveData_ApplyResolvedRecordAndResetOwnerState; size: 0xF0.
// Resolves a type-0x192 resource, applies the keyed saved value, and resets owner/game-state fields according to save initialization state.
extern "C" int TitleMenu_DeleteAdventureLogAndShowResult(void *self) {
    void *owner=Menu_GetDisplayRecordRegistry(self); void *record=MenuRecordList_LocateByKey((void**)owner,0x192); if(!record)return 0; if(MenuRecord_GetType(record)!=4)return 0; void *embedded=Menu_GetRecordMessageTable(record); void *game=_ZN9GameState11GetInstanceEv(); unsigned key=TextContext_GetSharedInstance(); if(SaveData_InitializeDefaultStateAndPackets()==0){unsigned value=MessageTextTable_FindTextById(embedded,0x5dd);TextWindow_StartFormattedMessage((int)key,(int)value,0,0xe3);unsigned char *bytes=(unsigned char*)key;bytes[0x19ca]=0;bytes[0x19af]=0;GameState_WriteUnknownF70(game,0);return 0;} unsigned value=MessageTextTable_FindTextById(embedded,0x4b1);TextWindow_StartFormattedMessage((int)key,(int)value,0,0xe3);GameState_SetUnk4Element0(game,7);GameState_WriteUnknownF70(game,0);Menu_QueueScriptEntry(self,0x97);return 0;
}
