// Original data: arm9/ov017 @ 0x021D7A38; symbol: data_ov017_021d7a38; size: 8.
// Equipment reload uses [0] for individual part models and [1] for member animations.
// The two entries point respectively to chara_pc.gp2 and chara_mp.gp2 paths.
// The original table is mutable storage of pointers to read-only text, matching
// the current caller's const char*[] contract. It does not own either string.
// Keep the existing external linkage name to agree with that owning caller;
// a descriptive symbol rename remains follow-up work.
extern "C" {
// Original data: arm9/ov017 @ 0x021D7A5B; symbol: data_ov017_021d7a5b.
extern char ProgramData_PathDataPackLv5CharaPcGp2[];
// Original data: arm9/ov017 @ 0x021D7A40; symbol: data_ov017_021d7a40.
extern char ProgramData_PathDataPackLv5CharaMpGp2[];
// Original data: arm9/ov017 @ 0x021D7A38; symbol: data_ov017_021d7a38.
const char* ResourceQueueChangedMemberEquipmentModels_UnknownRoleDataReferences[2] = {
    ProgramData_PathDataPackLv5CharaPcGp2,
    ProgramData_PathDataPackLv5CharaMpGp2
};
}
