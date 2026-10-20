#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0207F7F0; symbol: func_0207f7f0; size: 0x5C.
    void DisplayLayout_AttachBackwardLinkedCanvases(unsigned char *p,char *data,unsigned char count){
        *(char **)(p+48)=data;
        p[57]=count;
        if(!*(char **)(p+48)||!p[57])return;
        for(unsigned char i=1;i<p[57];i++){
            char *q=*(char **)(p+48);
            *(char **)(q+i*224)=q+(i-1)*224;
        }
    }
}
