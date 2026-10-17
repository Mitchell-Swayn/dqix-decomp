#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern short data_021099b0[8][8];
// Original: arm9/main @ 0x02099BD8; symbol: func_02099bd8; size: 0x5C.
    bool Script_ReadEightByEightGlobalTable(Script::Parameter *p){
        for(int i=0;i<8;i++)for(int j=0;j<8;j++){
            data_021099b0[i][j]=p->ToInt();
            p++;
        }return true;
    }
}
