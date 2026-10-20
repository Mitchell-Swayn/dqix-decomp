#include <globaldefs.h>
extern "C" void Graphics_FillTiled4bppRectangle(int, int, int, int, int, int);
// Original: arm9/main @ 0x02081818; symbol: func_02081818; size: 0x58.
extern "C" void Graphics_DrawRecordRectangleWithPackedColor(int unused, int arg, unsigned char* record, int arg4) {
    Graphics_FillTiled4bppRectangle(arg, ((unsigned)record[0x13] << 24) >> 28,
                  *(short*)(record + 6), *(short*)(record + 8),
                  ((int)*(short*)(record + 6) + (int)*(short*)(record + 10)) * 0x10000 >> 16,
                  ((int)*(short*)(record + 8) + (int)*(short*)(record + 12)) * 0x10000 >> 16);
}
