#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" bool TestActiveWordAndGlobalStateNonzero(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ReadGlobalAt02100044();
extern "C" unsigned char* _ZN9GameState15GetGrottoStructEv(void*);
extern "C" void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
struct Record {
    unsigned short id; unsigned char field2;
    unsigned char active:1; unsigned char unknown:1; unsigned char flag:1; char type:5;
    unsigned char field4,field5; unsigned short field6;
    short x,y,z; char field14;
    unsigned char low:4; unsigned char high:4;
};
struct Packet { unsigned char type; unsigned char padding[3]; Record record; };
// ARM9 ov017 0x021cf730 func_ov017_021cf730
// Original: arm9/ov017 @ 0x021CF730; symbol: func_ov017_021cf730; size: 0x13C.
extern "C" void Network_QueueGrottoStateRecord(char type,unsigned char flag) {
    void* connection=Object_GetGlobalConnectionState();
    if(!IsFirstWordNonzero(connection) || TestActiveWordAndGlobalStateNonzero(connection)) return;
    void* state=_ZN9GameState11GetInstanceEv();
    void* queue=ReadGlobalAt02100044();
    Packet packet;
    Record* rec=&packet.record;
    unsigned char* grotto=_ZN9GameState15GetGrottoStructEv(state);
    packet.type=0xa0;
    rec->id=*(int*)(grotto+12);
    rec->field2=grotto[0x6c];
    rec->active=grotto[0]!=0;
    rec->flag=flag;
    rec->x=*(int*)(grotto+16)>>7;
    rec->y=*(int*)(grotto+20)>>7;
    rec->z=*(int*)(grotto+24)>>7;
    rec->field4=grotto[0x83];
    rec->field5=grotto[0x84];
    rec->field6=*(unsigned short*)(grotto+0x86);
    rec->low=grotto[6];
    rec->high=grotto[5];
    rec->field14=*(char*)(grotto+8);
    rec->type=type;
    MoveQueuedRecordAndApplySourceValue(queue,&packet,0);
}
