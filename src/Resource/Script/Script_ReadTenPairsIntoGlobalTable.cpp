#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern short data_02109928[10][2];
// Original: arm9/main @ 0x02099AC4; symbol: func_02099ac4; size: 0x5C.
    bool Script_ReadTenPairsIntoGlobalTable(Script::Parameter *p){
        for(int i=0;i<10;i++)for(int j=0;j<2;j++){
            data_02109928[i][j]=p->ToInt();
            p++;
        }return true;
    }
}
