#include <globaldefs.h>
#include <std_library_functions.h>
ARM
// Original: arm9/ov017 @ 0x021B6C78; symbol: func_021b6c78; size: 0xE8.
extern "C" void* _ZN9GameState11GetInstanceEv(); extern "C" void* GameState_GetIndexList(void*); extern "C" void PartyTransfer_ClearAllSnapshots(char*);
extern "C" unsigned GameState_CopyProtagonistPartySlotList(void*,void*); extern "C" int GameState_ReadProtagonistObjectIndex(void*); extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void*); extern "C" void __clear(void*,unsigned); extern "C" int GameState_AppendSerializedRecord(int,int);


extern "C" int PartyTransfer_StoreSnapshotInFreeSlot(void*,int,void*); extern "C" void* _ZN9GameState14GetProtagonistEv(void*); extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" void GameState_RebuildRecordsForNonprotagonistObjects(void) {
 void *gs=_ZN9GameState11GetInstanceEv(); unsigned char *list=(unsigned char*)GameState_GetIndexList(gs); PartyTransfer_ClearAllSnapshots((char*)list);
 if(list[0xf7c]<=1) return; signed char ids[4]; unsigned count=GameState_CopyProtagonistPartySlotList(gs,ids);
 for(unsigned char i=0;i<count;i++){ signed char id=ids[i]; if(id==GameState_ReadProtagonistObjectIndex(gs)) continue; unsigned char record[16]; __clear(record,16); void *obj=GameState_GetObjectWithFlag100(gs,id);
   if(obj){ unsigned char *source=GameObject_GetLinkedIndexedState(obj)+0x454; memcpy(record,source,16); }
   int slot=GameState_AppendSerializedRecord(id,1); if(slot>=0) PartyTransfer_StoreSnapshotInFreeSlot(list,slot,record);
 }
 void *hero=_ZN9GameState14GetProtagonistEv(gs); if(hero) GameObject_DisableMovementInput(hero,1);
}
