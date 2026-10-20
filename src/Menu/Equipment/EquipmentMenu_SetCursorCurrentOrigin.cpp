// Coordinate offsets are established by original loads/stores; units remain unknown.
struct Coordinates { unsigned unknown[2]; int originX; int oppositeX; int originY; int oppositeY; int firstX; int firstY; int secondX; int secondY; int thirdX; int thirdY; int fourthX; int fourthY; };
// Original: arm9/ov005 @ 0x02154D34; symbol: func_ov005_02154d34; size: 0x1C.
extern "C" void EquipmentMenu_SetCursorCurrentOrigin(Coordinates* self, int x, int y) { self->thirdX = x + self->originX; self->thirdY = y + self->originY; }
