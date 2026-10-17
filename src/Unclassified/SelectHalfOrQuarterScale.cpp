// Caller arm9/ov000:02157288 passes this result to _fmul, proving a float return.
// Original: arm9/main @ 0x02074978; symbol: func_02074978; size: 0x10.
extern "C" float SelectHalfOrQuarterScale(int v){return v ? 0.5f : 0.25f;}
