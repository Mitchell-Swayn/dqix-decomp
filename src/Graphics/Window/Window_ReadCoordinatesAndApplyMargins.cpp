#include <globaldefs.h>
extern "C" {
void ReadIndirectIndexedTextCoordinates(void *,short *,short *,signed char);
// Original: arm9/main @ 0x020E2604; symbol: func_020e2604; size: 0x38.
void Window_ReadCoordinatesAndApplyMargins(char *p){ReadIndirectIndexedTextCoordinates(*(void **)(p+16),(short *)(p+24),(short *)(p+26),p[20]);*(short *)(p+24)-=16;*(short *)(p+26)-=2;}
}
