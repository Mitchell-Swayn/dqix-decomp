struct Overlay8Handles { unsigned char unknown[0x60]; int first; int second; };
// Original: arm9/ov008 @ 0x02185964; symbol: func_ov008_02185964; size: 0x38.
extern "C" int func_ov008_02185964(const Overlay8Handles* object) { return ((object->first == -1) & (object->second == -1)) != 0; }
