struct TitleSelectionGridState {
    int count;
    int unknown_04;
    int columns;
    int rows;
    unsigned char orientation;
    unsigned char padding_11[3];
    int page;
    int column;
    int row;
    int* majorCount;
    int* minorCount;
    int* majorPosition;
    int* minorPosition;
};

extern "C" void func_0205ba2c(TitleSelectionGridState* grid) {
    grid->count = 0;
    grid->unknown_04 = 1;
    grid->columns = 1;
    grid->rows = 1;
    grid->orientation = 0;
    grid->page = 0;
    grid->column = 0;
    grid->row = 0;
    grid->majorCount = 0;
    grid->minorCount = 0;
    grid->majorPosition = 0;
    grid->minorPosition = 0;
}
