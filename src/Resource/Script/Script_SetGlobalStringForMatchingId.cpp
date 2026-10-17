#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
    extern unsigned int data_020fdc4c[];
    unsigned short *ReadGlobalValueAt020FB3F0();
// Original: arm9/main @ 0x0201F950; symbol: func_0201f950; size: 0x50.
    bool Script_SetGlobalStringForMatchingId(Script::Parameter *p){
        if(data_020fdc4c[1])return true;
        int value=p[0].ToInt();
        if(value==*ReadGlobalValueAt020FB3F0())data_020fdc4c[1]=(unsigned int)p[1].ToString();
        return true;
    }
}
