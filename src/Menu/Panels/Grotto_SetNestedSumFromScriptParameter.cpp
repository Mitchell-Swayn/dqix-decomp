#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(void*, int);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021EAAE8; symbol: func_ov023_021eaae8; size: 0x40.
extern "C" int Grotto_SetNestedSumFromScriptParameter(void* parameter) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* list = GameState_GetIndexList(state);
    int value = Script_ReadParameterAsInteger(parameter);
    value = (short)value;
    int sum = SumIndexedValuesAcrossPresentPartyIds(list, value);
    Script_WriteIntegerReferenceOutput((char*)parameter + 8, sum);
    return 1;
}
