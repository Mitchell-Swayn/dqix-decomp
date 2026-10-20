struct Vector3 { int x, y, z; };
// Original: arm9/ov026 @ 0x021D8B98; symbol: func_ov026_021d8b98; size: 0x8.
extern "C" void BattleScene_SetCameraPresetVectorComponents(Vector3 *out, int x, int y, int z) { out->x=x; out->y=y; out->z=z; }
