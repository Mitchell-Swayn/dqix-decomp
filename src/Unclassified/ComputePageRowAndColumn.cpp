#include <globaldefs.h>
struct GridSelection {
    int count;
    int unknown04;
    int width;
    int height;
    int unknown10;
    int page;
    int unknown18[3];
    int *rowWidth;
    int *row;
    int *column;
};
// Original: arm9/main @ 0x0205BB04; symbol: func_0205bb04; size: 0x80.
extern "C" void ComputePageRowAndColumn(GridSelection *selection, int index) {
    if (index < 0) return;
    if (index >= selection->count) return;
    int pageSize = selection->height * selection->width;
    if (pageSize == 0) return;
    selection->page = index / pageSize;
    index = index % pageSize;
    *selection->column = index % *selection->rowWidth;
    *selection->row = index / *selection->rowWidth;
}
