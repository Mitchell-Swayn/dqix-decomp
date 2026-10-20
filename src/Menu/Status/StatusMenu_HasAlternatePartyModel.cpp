// Returns whether the second overlay predicate returns a nonzero result.
extern "C" int GameResources_GetInstance();
extern "C" int GameResources_GetAlternatePartyModel();
// Original: arm9/ov004 @ 0x0215E460; symbol: func_ov004_0215e460; size: 0x1C.
extern "C" int StatusMenu_HasAlternatePartyModel() {
    GameResources_GetInstance();
    return GameResources_GetAlternatePartyModel() != 0;
}
