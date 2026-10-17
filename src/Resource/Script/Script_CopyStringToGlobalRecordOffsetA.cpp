#include <globaldefs.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
extern "C" {
    extern unsigned char *data_02108740[];
// Original: arm9/main @ 0x0205E0D0; symbol: func_0205e0d0; size: 0x2C.
    bool Script_CopyStringToGlobalRecordOffsetA(Script::Parameter *p){
        const char *s=p->ToString();
        if(s)strcpy((char *)data_02108740[1]+10,s);
        return true;
    }
}
