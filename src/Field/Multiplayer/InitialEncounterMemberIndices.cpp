// Original data: arm9/ov017 @ 0x021D6D18; symbol: data_ov017_021d6d18; size: 16.
// Seed for the temporary four-member index list in Field_ApplyMemberEncounterExit.
// The caller copies all four signed -1 values, then writes matched member indices
// only into that local copy; this original seed remains read-only.
// Keep the existing external linkage name to agree with the owning caller;
// a descriptive symbol rename remains follow-up work.
extern "C" {
extern const int FieldApplyMemberEncounterExit_UnknownRoleInitializedBytes[4] = {-1, -1, -1, -1};
}
