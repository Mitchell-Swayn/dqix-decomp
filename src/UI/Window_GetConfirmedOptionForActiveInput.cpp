#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
    int Input_IsKeyMaskNewlyPressed(void *,int);
// Original: arm9/main @ 0x020E2918; symbol: func_020e2918; size: 0x6C.
    int Window_GetConfirmedOptionForActiveInput(signed char *p){
        if(Main_UnknownRoleZeroInitializedStorage_Variant4[85]||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1024)||Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,512))return p[21];
        return -1;
    }
}
