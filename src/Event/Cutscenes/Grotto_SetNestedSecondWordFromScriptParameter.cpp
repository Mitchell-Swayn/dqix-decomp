#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *p, unsigned int mask);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0215AE84; symbol: func_ov001_0215ae84; size: 0x34.
extern "C" int Grotto_SetNestedSecondWordFromScriptParameter(void *parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    int result = Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, (unsigned short)value);
    Script_WriteIntegerReferenceOutput((char *)parameter + 8, result);
    return 1;
}
