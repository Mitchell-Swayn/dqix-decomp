struct ThreeWords { unsigned first, second, third; };
struct Owner { unsigned unknown[7]; ThreeWords value; };
// Original: arm9/ov005 @ 0x02157174; symbol: func_ov005_02157174; size: 0x1C.
extern "C" void func_ov005_02157174(Owner* self, const ThreeWords* value) { self->value.first=value->first; self->value.second=value->second; self->value.third=value->third; }
