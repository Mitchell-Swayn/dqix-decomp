#include <globaldefs.h>
extern "C" {
    void ScriptFlagHistory_AppendGlobalKey(int);
// Original: arm9/main @ 0x02028C64; symbol: func_02028c64; size: 0x28.
    void ZoneState_MarkType2FeatureActivated(unsigned char *p,int id){
        if(id<16){
            *(unsigned short *)(p+4)|=1<<id;
            return;
        }ScriptFlagHistory_AppendGlobalKey(5);
    }
}
