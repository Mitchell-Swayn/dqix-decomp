// Regular-animation names and the lookup tables consumed by
// Object_SelectRegularAnimationAndStoreIndex (arm9/main 0x02033BA0).
// Original data: arm9/main 0x020EF920..0x020EF9C4.
// Legacy external linker identities are retained; semantic renames are follow-up.
extern "C" {
// Original data: arm9/main @ 0x020EF920; symbol: data_020ef920; animation name "run".
extern char ProgramData_TextRun[];
// Original data: arm9/main @ 0x020EF924; symbol: data_020ef924; animation name "slip".
extern char ProgramData_TextSlip_Copy2[];
// Original data: arm9/main @ 0x020EF929; symbol: data_020ef929; animation name "stand".
extern char ProgramData_TextStand_Copy2[];
// Original data: arm9/main @ 0x020EF92F; symbol: data_020ef92f; animation name "smile".
extern char ProgramData_TextSmile_Copy2[];
// Original data: arm9/main @ 0x020EF935; symbol: data_020ef935; animation name "hirou".
extern char ProgramData_TextHirou[];
// Original data: arm9/main @ 0x020EF93B; symbol: data_020ef93b; animation name "guard".
extern char ProgramData_TextGuard_Copy2[];
// Original data: arm9/main @ 0x020EF941; symbol: data_020ef941; animation name "death".
extern char ProgramData_TextDeath[];
// Original data: arm9/main @ 0x020EF947; symbol: data_020ef947; animation name "dance".
extern char ProgramData_TextDance_Copy2[];
// Original data: arm9/main @ 0x020EF94D; symbol: data_020ef94d; animation name "sleep".
extern char ProgramData_TextSleep_Copy2[];
// Original data: arm9/main @ 0x020EF953; symbol: data_020ef953; animation name "appear".
extern char ProgramData_TextAppear[];
// Original data: arm9/main @ 0x020EF95A; symbol: data_020ef95a; animation name "takara".
extern char ProgramData_TextTakara[];
// Original data: arm9/main @ 0x020EF961; symbol: data_020ef961; animation name "tenchi".
extern char ProgramData_TextTenchi_Copy2[];
// Original data: arm9/main @ 0x020EF968; symbol: data_020ef968; animation name "damage".
extern char ProgramData_TextDamage[];
// Original data: arm9/main @ 0x020EF96F; symbol: data_020ef96f; animation name "attack0a".
extern char ProgramData_TextAttack0A[];
// Original data: arm9/main @ 0x020EF978; symbol: data_020ef978.
// The idle branch chooses among these seven names using the mapped object type.
const char* ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences[7] = {
    ProgramData_TextStand_Copy2, // "stand"
    ProgramData_TextGuard_Copy2, // "guard"
    ProgramData_TextSleep_Copy2, // "sleep"
    ProgramData_TextSlip_Copy2, // "slip"
    ProgramData_TextSmile_Copy2, // "smile"
    ProgramData_TextDance_Copy2, // "dance"
    ProgramData_TextTenchi_Copy2, // "tenchi"
};
// Original data: arm9/main @ 0x020EF994; symbol: data_020ef994.
// The non-idle branch indexes these twelve names by the requested animation state.
const char* ObjectSelectRegularAnimationAndStoreIndex_UnknownRoleDataReferences_Variant2[12] = {
    ProgramData_TextStand_Copy2, // "stand"
    ProgramData_TextRun, // "run"
    ProgramData_TextRun, // "run"
    ProgramData_TextRun, // "run"
    ProgramData_TextStand_Copy2, // "stand"
    ProgramData_TextStand_Copy2, // "stand"
    ProgramData_TextAttack0A, // "attack0a"
    ProgramData_TextDamage, // "damage"
    ProgramData_TextDeath, // "death"
    ProgramData_TextAppear, // "appear"
    ProgramData_TextTakara, // "takara"
    ProgramData_TextHirou, // "hirou"
};
}
