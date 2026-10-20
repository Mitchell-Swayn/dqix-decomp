#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];int Input_TestKeyMask(void *,int);
// Original: arm9/main @ 0x0202AA94; symbol: func_0202aa94; size: 0xA0.
bool Input_TestModeDependentButtonCombination(int *p){switch(p[16]){case 0:if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128))return true;case 1:if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128)&&Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1024))return true;case 2:if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128)&&Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2048))return true;}return false;}
}
