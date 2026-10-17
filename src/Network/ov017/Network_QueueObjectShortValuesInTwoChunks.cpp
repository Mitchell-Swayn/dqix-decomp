#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_GetIndexList(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
struct Record { int id; unsigned char start,count; short values[4]; };
struct Packet { unsigned char type; unsigned char padding[3]; Record record; };
// ARM9 ov017 0x021cff8c func_ov017_021cff8c
// Original: arm9/ov017 @ 0x021CFF8C; symbol: func_ov017_021cff8c; size: 0x13C.
extern "C" void Network_QueueObjectShortValuesInTwoChunks(int id,int force) {
    void* queue=ReadGlobalAt02100044();
    void* state=_ZN9GameState11GetInstanceEv();
    unsigned char* list=GameState_GetIndexList(state);
    bool allowed=false;
    if(force) allowed=true;
    else {
        for(int i=0;i<list[0xf7c];i++) {
            if(id==(list+i)[0xf78]) { allowed=true; break; }
        }
    }
    if(!allowed) return;
    void* object=GameState_GetObjectWithFlag100(state,id);
    if(!object) return;
    unsigned char* data=ReadWordFieldAtOffset150(object);
    if(!data) return;
    short* values;
    Packet packet;
    Record* rec=&packet.record;
    packet.type=0xa8;
    rec->id=id;
    rec->count=4;
    rec->start=0;
    values=(short*)(data+0x454);
    for(int i=0;i<rec->count;i++) rec->values[i]=values[rec->start+i];
    MoveQueuedRecordAndApplySourceValue(queue,&packet,0);
    rec->start=rec->count;
    for(int i=0;i<rec->count;i++) rec->values[i]=values[rec->start+i];
    MoveQueuedRecordAndApplySourceValue(queue,&packet,0);
}
