#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
extern "C" {
    unsigned char *ReadGlobalValueAt020FB3F0();
    void SetNestedSecondWordForTypeThree(void *,int);
// Original: arm9/main @ 0x0209DB5C; symbol: func_0209db5c; size: 0x50.
    bool Script_ReadDetailedGrottoByte63(void *p){
        ActiveGrottoClass *g=(ActiveGrottoClass *)(ReadGlobalValueAt020FB3F0()+9196);
        if(!g)return false;
        DetailedTreasureMapData *q=g->GetDetailedData();
        if(!q)return false;
        unsigned char *b=(unsigned char *)q;
        if(b[1]!=1)return false;
        SetNestedSecondWordForTypeThree(p,b[99]);
        return true;
    }
}
