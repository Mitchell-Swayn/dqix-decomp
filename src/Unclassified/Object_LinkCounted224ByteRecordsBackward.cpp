#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0205CF78; symbol: func_0205cf78; size: 0x5C.
    void Object_LinkCounted224ByteRecordsBackward(unsigned char *p,char *data,unsigned char count){
        *(char **)(p+0x9c)=data;
        p[0xb3]=count;
        if(!*(char **)(p+0x9c)||!p[0xb3])return;
        for(unsigned char i=1;i<p[0xb3];i++){
            char *q=*(char **)(p+0x9c);
            *(char **)(q+i*224)=q+(i-1)*224;
        }
    }
}
