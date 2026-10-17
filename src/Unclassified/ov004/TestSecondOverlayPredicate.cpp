// Returns whether the second overlay predicate returns a nonzero result.
extern "C" int GameResources_GetInstance();
extern "C" int OV017_ReadWordField4338();
// Original: arm9/ov004 @ 0x0215E460; symbol: func_ov004_0215e460; size: 0x1C.
extern "C" int TestSecondOverlayPredicate() {
    GameResources_GetInstance();
    return OV017_ReadWordField4338() != 0;
}
