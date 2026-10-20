#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov017 @ 0x021B8478; symbol: func_ov017_021b8478; size: 0x8.
extern "C" void* FieldBattle_GetEncounterRequest(void* self)
{
    return (char*)self + 0x1C;
}
