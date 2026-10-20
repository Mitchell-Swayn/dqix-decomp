#include <globaldefs.h>
ARM
extern "C" char* MenuLayout_FindGroupByKey(char* p,int key);
extern "C" void AccumulateLinkedRecordOffsets(char*,int,short*,short*);
struct Output { char pad[0xac]; short x,y; };
// Original: arm9/ov023 @ 0x021DB45C; symbol: func_ov023_021db45c; size: 0x88.
extern "C" void Graphics_ApplyLinkedRecordPositionAndConsumeOffsets(char *self, Output *output, int key, short *xOffset, short *yOffset) {
    char *record = MenuLayout_FindGroupByKey(self, key);
    if (record) {
        short x = 0;
        short y = 0;
        AccumulateLinkedRecordOffsets(self, key, &x, &y);
        int px = x;
        int py = y;
        output->x = px >> 3;
        output->y = py >> 3;
        *xOffset = *(short*)(record + 8);
        *yOffset = *(short*)(record + 10);
        *(short*)(record + 8) = 0;
        *(short*)(record + 10) = 0;
    }
}
