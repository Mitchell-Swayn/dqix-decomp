#include <globaldefs.h>
ARM
#pragma optimize_for_size on
#pragma opt_common_subs off
struct NodeFlags {unsigned short id:9;unsigned short inherited:1;unsigned short reserved:3;unsigned short special:1;unsigned short tail:2;};
struct Node {unsigned short unused;NodeFlags flags;unsigned unknown[2];Node* next;};
struct Record {unsigned id:9;unsigned active:1;unsigned inherited:1;unsigned mode:3;unsigned reserved:2;unsigned special:1;unsigned tail:15;unsigned payload[3];};
extern "C" {void* memset(void*,int,unsigned);void* Network_GetConnectionManager(unsigned);int Network_IsSessionActive(void*);int Network_GetLocalMemberId(void*);int Quest_InsertActiveRecordInIdOrder(unsigned char*,Record);void Quest_SetBoundedIdFlag(unsigned char*,unsigned char*,int);}
// Original: arm9/main @ 0x020961B0; symbol: func_020961b0; size: 0x144.
extern "C" int Quest_ActivateFromDefinition(unsigned char* object,unsigned id){
    int party=*object;if(party>=8)return 0;
    void* member=Network_GetConnectionManager(party);
    Node* node=*(Node**)(object+0xa0);
    for(;node;node=node->next){
        if(id!=node->flags.id)continue;
        Record record;memset(&record,0,16);
        record.id=node->flags.id;record.inherited=node->flags.inherited;record.special=node->flags.special;record.mode=1;
        if(Network_IsSessionActive(member) && Network_GetLocalMemberId(member))record.active=1;else record.active=0;
        Quest_InsertActiveRecordInIdOrder(object,record);
        Quest_SetBoundedIdFlag(object,object+0x4a8,id);
        break;
    }
    if(node==0)return 0;return 1;
}
