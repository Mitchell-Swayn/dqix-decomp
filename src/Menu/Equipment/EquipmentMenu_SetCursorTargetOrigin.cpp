// Coordinate offsets are established by original loads/stores; units remain unknown.
struct Coordinates { unsigned unknown[2]; int originX; int oppositeX; int originY; int oppositeY; int firstX; int firstY; int secondX; int secondY; int thirdX; int thirdY; int fourthX; int fourthY; };
// Original: arm9/ov005 @ 0x02154D18; symbol: func_ov005_02154d18; size: 0x1C.
extern "C" void EquipmentMenu_SetCursorTargetOrigin(Coordinates* self, int x, int y) { self->firstX = x + self->originX; self->firstY = y + self->originY; }
