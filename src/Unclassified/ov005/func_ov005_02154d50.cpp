// Coordinate offsets are established by original loads/stores; units remain unknown.
struct Coordinates { unsigned unknown[2]; int originX; int oppositeX; int originY; int oppositeY; int firstX; int firstY; int secondX; int secondY; int thirdX; int thirdY; int fourthX; int fourthY; };
// Original: arm9/ov005 @ 0x02154D50; symbol: func_ov005_02154d50; size: 0x2C.
extern "C" void func_ov005_02154d50(Coordinates* self, int x, int y) { self->secondX = self->oppositeX + (x - self->originX); self->secondY = self->oppositeY + (y - self->originY); }
