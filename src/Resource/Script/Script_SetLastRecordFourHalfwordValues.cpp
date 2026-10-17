#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern unsigned char *data_02108ee0[];
    unsigned char *GetFortyEightByteRecordByBoundedIndex(void *,int);
// Original: arm9/main @ 0x0207F4A8; symbol: func_0207f4a8; size: 0x68.
    bool Script_SetLastRecordFourHalfwordValues(Script::Parameter *p){
        unsigned char *owner=data_02108ee0[1];
        short index=*(short *)(owner+4)-1;
        unsigned char *q=GetFortyEightByteRecordByBoundedIndex(owner,index);
        if(q){
            *(short *)(q+24)=p[0].ToInt();
            *(short *)(q+28)=p[1].ToInt();
            *(short *)(q+32)=p[2].ToInt();
            *(short *)(q+36)=p[3].ToInt();
        }return true;
    }
}
