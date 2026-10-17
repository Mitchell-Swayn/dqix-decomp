#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN9GameState11GetInstanceEv();
    void* ReadGlobalAt02100044();
    void* GameState_GetObjectWithFlag100(void*,int);
    char* GetIndirectField150Address488(void*);
    void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
}
// Original: arm9/ov017 @ 0x021C4418; symbol: func_ov017_021c4418; size: 0xC0.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" void QueuePackedDisplayFieldsMessage(int index,unsigned char value) {
    void* state=_ZN9GameState11GetInstanceEv();
    void* queue=ReadGlobalAt02100044();
    void* object=GameState_GetObjectWithFlag100(state,index);
    if(object) {
        struct Data {
            char pad[20];
            unsigned char low:1;
            unsigned char middle:3;
            unsigned char high:4;
            unsigned char other:4;
            unsigned char top:4;
            short values[3];
        }
        ;
        Data* d=(Data*)GetIndirectField150Address488(object);
        if(d) {
            struct PackedMessage {
                unsigned char tag;
                char pad[3];
                unsigned char index;
                unsigned char a,b,c,e;
                char gap;
                short v[3];
                unsigned char final;
                char tail[3];
            }
            m;
            m.tag=1;
            m.index=index;
            m.a=d->other;
            m.b=d->high;
            m.c=d->middle;
            m.e=d->low;
            m.v[0]=d->values[0];
            m.v[1]=d->values[1];
            m.v[2]=d->values[2];
            m.final=value;
            MoveQueuedRecordAndApplySourceValue(queue,&m,0);
        }
    }
}
