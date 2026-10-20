#pragma always_inline on
class GameState
{
    public: static GameState *GetInstance();
};
extern "C"
{
    void *Network_GetCommandRecordPool();
    unsigned char *GameState_GetObjectWithFlag100(void*,int);
    void Network_QueueOutgoingRecord(void*,const void*,short);
    struct Bits
    {
        unsigned char index:3,a:1,b:1,c:1,rest:2;
    };
    struct Payload
    {
        Bits bits;
        unsigned char byte;
        unsigned short a,b,c,d,pad;
        unsigned word;
    };
    struct Packet
    {
        unsigned char type;
        char pad[3];
        Payload payload;
    };
}
struct First
{
    unsigned word;
    unsigned short a,b;
    unsigned char byte;
};
struct Second
{
    char pad[0x30];
    unsigned short a,b;
};
struct Object
{
    char pad[0x130];
    First *first;
    Second *second;
};
inline bool IsCharacterIndexInRange(int index)
{
    if(index>=0)
    {
        if(index<=3)return true;
    }
    return false;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov017 @ 0x021C9E00; symbol: func_ov017_021c9e00; size: 0x118.
extern "C" void Network_QueueCurrentPartyMemberState(int index,int a,int b,int c)
{
    void *queue=Network_GetCommandRecordPool();
    void *state=GameState::GetInstance();
    bool valid=IsCharacterIndexInRange(index);
    if(valid)
    {
        Object *object=(Object*)GameState_GetObjectWithFlag100(state,index);
        if(object)
        {
            unsigned char packet[20];
            Payload *payload=(Payload*)(packet+4);
            packet[0]=4;
            payload->bits.index=(unsigned char)index;
            payload->a=object->first->a;
            payload->c=object->first->b;
            payload->b=object->second->a;
            payload->d=object->second->b;
            payload->byte=object->first->byte;
            payload->word=object->first->word;
            payload->bits.a=(unsigned char)a;
            payload->bits.b=(unsigned char)b;
            payload->bits.c=(unsigned char)c;
            Network_QueueOutgoingRecord(queue,packet,0);
        }
    }
}
