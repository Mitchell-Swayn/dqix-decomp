// Shared coordinate object; signed coordinate units remain unidentified.
struct CoordinateState { unsigned flags; int scale; int originX,oppositeX,originY,oppositeY; int firstX,firstY,secondX,secondY,thirdX,thirdY,fourthX,fourthY; unsigned state; };
// Original: arm9/ov005 @ 0x021536E0; symbol: func_ov005_021536e0; size: 0x48.
extern "C" void EquipmentMenu_ResetCursorRectangle(CoordinateState* self) { self->flags=0; self->scale=0x8000; self->originX=self->oppositeX=0; self->originY=self->oppositeY=0; self->firstX=self->firstY=0; self->secondX=self->secondY=0; self->thirdX=self->thirdY=0; self->fourthX=self->fourthY=0; self->state=0; }
