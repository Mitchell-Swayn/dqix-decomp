#include <globaldefs.h>
ARM
struct GameState;struct Record;struct ActionAmountRecord;struct AmountParameters;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" int ActionData_FindDamageInPrimaryOrSecondaryTable(char*,unsigned);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
// Pending submitted rename: ComputeRandomizedIndexedActionAmount; current owning symbol remains the original.
extern "C" int PartyMenu_ComputeRandomizedRecoveryAmount(void*,ActionAmountRecord*,AmountParameters*,int);
extern "C" void PartyMenu_ClearTargetActionResult(Record*);
extern "C" short Combat_AddCappedValue(void*,int,int,unsigned char*);
extern "C" int GameState_HasFlaggedObjectValue(void*,int);
extern "C" int GameState_TestMatchingOrCompatibleObjectIdentifiers(int,int,int);
extern "C" bool PartyMenu_HasTargetActionBlocker(int,int);
extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
struct TargetActionResult {unsigned char status,pad;short amount;unsigned char unlisted,pad5;};
struct IndexedActionSearch {unsigned low:14;unsigned key:8;unsigned high:10;};
// Original: arm9/ov002 @ 0x02153CCC; symbol: func_ov002_02153ccc; size: 0x1C4.
// Clears one four-record result bank, applies a capped action to eligible targets, and queues connection notifications.
extern "C" int PartyMenu_ApplyHpRecoveryToTargets(char* self,char* action,char* record,int secondBank) {
 if(!action)return 0;if(!record)return 0;
 unsigned char* list=(unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
 void* connection=Network_GetConnectionManager();
 TargetActionResult* results=(TargetActionResult*)(action+8);int changed=0;
 if(secondBank)results=(TargetActionResult*)(action+0x20);
 for(int i=0;i<4;i++)PartyMenu_ClearTargetActionResult((Record*)(results+i));
 for(int i=0;i<*(unsigned char*)(action+3);i++) {
  TargetActionResult* result=results+i;int target=*(signed char*)(action+4+i);
  if(!PartyRoster_ContainsActiveObjectIndex(list,target))result->unlisted=1;
  if(!GameState_TestMatchingOrCompatibleObjectIdentifiers((int)self,target,*(signed char*)(action+2)))result->status=1;
  else if(PartyMenu_HasTargetActionBlocker((int)self,target))result->status=2;
  else if(GameState_HasFlaggedObjectValue(self,target)) {
   int amount;
   if(*(short*)action==33)amount=999;
   else {
    AmountParameters* parameters=(AmountParameters*)ActionData_FindDamageInPrimaryOrSecondaryTable(*(char**)self,((IndexedActionSearch*)(record+8))->key);
    if(!parameters)continue;
    amount=PartyMenu_ComputeRandomizedRecoveryAmount(self,(ActionAmountRecord*)record,parameters,*(signed char*)(action+2));
   }
   if(result->unlisted){result->amount=amount;result->status=3;}
   else result->amount=Combat_AddCappedValue(self,target,amount,(unsigned char*)result);
   if(result->status) {
    if(Network_IsSessionActive(connection) && PartyRoster_ContainsActiveObjectIndex(list,target))Network_QueueCurrentPartyMemberState(target,0,0,1);
    changed=1;
   }
  }
 }
 return changed;
}
