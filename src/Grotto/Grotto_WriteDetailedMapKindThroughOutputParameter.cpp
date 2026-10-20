#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
extern "C" {
    unsigned char *Zone3D_GetMainInstance();
    void Script_WriteIntegerReferenceOutput(void *,int);
// Original: arm9/main @ 0x0209D7AC; symbol: func_0209d7ac; size: 0x40.
    bool Grotto_WriteDetailedMapKindThroughOutputParameter(void *p){
        ActiveGrottoClass *g=(ActiveGrottoClass *)(Zone3D_GetMainInstance()+9196);
        if(!g)return false;
        DetailedTreasureMapData *q=g->GetDetailedData();
        if(!q)return false;
        Script_WriteIntegerReferenceOutput(p,((unsigned char *)q)[1]);
        return true;
    }
}
