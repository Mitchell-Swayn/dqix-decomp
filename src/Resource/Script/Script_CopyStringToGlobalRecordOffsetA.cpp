#include <globaldefs.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x2108740; symbol: data_02108740.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char *ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0205E0D0; symbol: func_0205e0d0; size: 0x2C.
    bool Script_CopyStringToGlobalRecordOffsetA(Script::Parameter *p){
        const char *s=p->ToString();
        if(s)strcpy((char *)ScriptWriteGlobalHalfword2A_UnknownRoleZeroInitializedStorage[1]+10,s);
        return true;
    }
}
