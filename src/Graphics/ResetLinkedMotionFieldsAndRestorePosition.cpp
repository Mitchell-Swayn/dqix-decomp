#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" {
// Original: arm9/main @ 0x02048C90; symbol: func_02048c90; size: 0x60.
    void ResetLinkedMotionFieldsAndRestorePosition(char **p){
        if(!p[79])return;
        p[79][52]=0;
        *(int *)(p[79]+56)=0;
        *(short *)(p[79]+60)=0;
        *(Vector3i *)(p[79]+64)=*(Vector3i *)(p[79]+16);
        *(int *)(p[79]+32)&=~16;
        *(int *)(p[79]+32)&=~64;
    }
}
