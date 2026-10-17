#include <globaldefs.h>
#include <World/WorldPlacementSource.h>
#include <World/WorldObjectInstanceList.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int* GameState_GetField5CDCEntryWithHighBit(char*,int);
extern "C" WorldObjectInstanceList* WorldObjectInstanceList_GetInstance();
// Original: arm9/ov017 @ 0x021D3950; symbol: func_ov017_021d3950; size: 0x154.
extern "C" int World_ClearPlacementFlagsAndRemoveInstance(unsigned char* p) {
 char* game=(char*)_ZN9GameState11GetInstanceEv();
 WorldPlacementSource* source=WorldPlacementSource::GetInstance();
 WorldPlacementSource::PersistentState* state=(WorldPlacementSource::PersistentState*)GameState_GetField5CDCEntryWithHighBit(game,p[3]);
 if(state && (state->flags & p[2])) {
 state->flags &= ~p[2];
 state->unknown0=state->unknown25*30;
 WorldPlacementSource::Record* rec=source->FindRecord(p[3]);
 if(!rec) return 1;
 rec->flags &= ~p[2];
 WorldPlacementSource::Record* it=source->head;
 int index=0;
 while(it) {
 if(it->index==p[3]) break;
 it=it->next;
 index++;
 }
 if(!it) return 1;
 int bit=0;
 for(;bit<8;bit++) if(p[2] & (1<<bit)) break;
 if(it && bit<8) WorldObjectInstanceList_GetInstance()->RemoveInstance(bit+(index<<3));
 return 1;
 }
 return 0;
}
