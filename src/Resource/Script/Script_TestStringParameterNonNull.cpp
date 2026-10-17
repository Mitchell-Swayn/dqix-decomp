#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original: arm9/main @ 0x0201F864; symbol: func_0201f864; size: 0x30.
    bool Script_TestStringParameterNonNull(Script::Parameter *p){
        p[0].ToInt();
        const char *s=p[1].ToString();
        p[2].ToInt();
        return s!=0;
    }
}
