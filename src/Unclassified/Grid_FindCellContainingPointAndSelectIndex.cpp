#include <globaldefs.h>
struct GridSelection {
    int count;
    char pad04[0x20-4];
    int *rows;
    int *columns;
    int *row;
    int *column;
    int unknown30;
    int boundsCount;
    short originX, originY;
    short *left;
    short *top;
    short *width;
    short *height;
};
extern "C" int Grid_ReadLinearIndexWhenEnabled(GridSelection *);
extern "C" void Selection_InvalidateIndexAndComputePageCoordinates(GridSelection *,int);
// Original: arm9/main @ 0x0205BD78; symbol: func_0205bd78; size: 0x128.
extern "C" int Grid_FindCellContainingPointAndSelectIndex(GridSelection *grid, int x, int y) {
    if (!grid->boundsCount) return -1;
    if (!grid->left) return -1;
    if (!grid->top) return -1;
    if (!grid->width) return -1;
    if (!grid->height) return -1;
    x -= grid->originX;
    y -= grid->originY;
    for (int col = 0; col < *grid->columns; ++col) {
        for (int row = 0; row < *grid->rows; ++row) {
            int index = row * *grid->columns + col;
            if (grid->boundsCount > index) {
                int l = grid->left[index];
                int t = grid->top[index];
                int w = grid->width[index];
                int h = grid->height[index];
                int right = l + w;
                int bottom = t + h;
                if (x >= l && right >= x && y >= t && bottom >= y) {
                    *grid->column = col;
                    *grid->row = row;
                    int result = Grid_ReadLinearIndexWhenEnabled(grid);
                    if (grid->count <= result) result = -1;
                    Selection_InvalidateIndexAndComputePageCoordinates(grid, result);
                    return result;
                }
            }
        }
    }
    return -1;
}
