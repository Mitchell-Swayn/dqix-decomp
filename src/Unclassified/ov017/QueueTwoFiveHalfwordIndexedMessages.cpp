#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN9GameState11GetInstanceEv();
    void* ReadGlobalAt02100044();
    void* GameState_GetObjectWithFlag100(void*,int);
    short* Object_GetNestedOffset150Subrecord488(void*);
    void MoveQueuedRecordAndApplySourceValue(void*,const void*,short);
}
struct Message {
    unsigned char tag;
    char pad[3];
    unsigned char index:4;
    unsigned char flag:1;
    unsigned char upper:3;
    unsigned char ids[5];
    short values[5];
};
// Original: arm9/ov017 @ 0x021C3FB4; symbol: func_ov017_021c3fb4; size: 0x138.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" void QueueTwoFiveHalfwordIndexedMessages(int index,int flag) {
    void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
    if(object) {
        short* data=Object_GetNestedOffset150Subrecord488(object);
        if(data) {
            void* queue=ReadGlobalAt02100044();
            Message m;
            m.tag=2;
            m.index=(unsigned char)index;
            m.ids[0]=0;
            m.values[0]=data[0];
            m.ids[1]=1;
            m.values[1]=data[1];
            m.ids[2]=2;
            m.values[2]=data[2];
            m.ids[3]=3;
            m.values[3]=data[3];
            m.ids[4]=4;
            m.values[4]=data[4];
            m.flag=0;
            MoveQueuedRecordAndApplySourceValue(queue,&m,0);
            m.ids[0]=5;
            m.values[0]=data[5];
            m.ids[1]=6;
            m.values[1]=data[6];
            m.ids[2]=7;
            m.values[2]=data[7];
            m.ids[3]=8;
            m.values[3]=data[8];
            m.ids[4]=9;
            m.values[4]=data[9];
            m.flag=(unsigned char)flag;
            MoveQueuedRecordAndApplySourceValue(queue,&m,0);
        }
    }
}
