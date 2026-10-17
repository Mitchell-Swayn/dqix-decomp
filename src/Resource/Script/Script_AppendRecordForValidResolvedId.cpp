#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern unsigned char *data_02109bac;
    void *FindThirtyTwoByteRecordByHalfwordKey(void *,int);
// Original: arm9/main @ 0x0209AE9C; symbol: func_0209ae9c; size: 0x98.
    bool Script_AppendRecordForValidResolvedId(Script::Parameter *p){
        *(int *)(data_02109bac+8)=0;
        int id=p->ToInt();
        if(!FindThirtyTwoByteRecordByHalfwordKey(*(void **)(data_02109bac+4),id))return true;
        unsigned char *owner=*(unsigned char **)data_02109bac;
        int count=*(int *)(owner+0x1c8)+1;
        *(int *)(owner+0x1c8)=count;
        *(int *)(*(unsigned char **)data_02109bac+0x1cc)=0;
        *(int *)(*(unsigned char **)data_02109bac+0x1d0)=0;
        *(short *)(*(unsigned char **)data_02109bac+count*76)=id;
        *(int *)(data_02109bac+8)=1;
        return true;
    }
}
