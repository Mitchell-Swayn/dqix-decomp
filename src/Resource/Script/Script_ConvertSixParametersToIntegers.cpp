#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original: arm9/main @ 0x0201F894; symbol: func_0201f894; size: 0x3C.
    bool Script_ConvertSixParametersToIntegers(Script::Parameter *p){
        p[0].ToInt();
        p[1].ToInt();
        p[2].ToInt();
        p[3].ToInt();
        p[4].ToInt();
        p[5].ToInt();
        return true;
    }
}
