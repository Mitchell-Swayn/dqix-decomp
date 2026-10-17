#include <globaldefs.h>
extern "C" unsigned char data_02114e54[];extern "C" void ReadSelectedCoordinatePair(void*,unsigned*,unsigned*);extern "C" int Grid_FindCellContainingPointAndSelectIndex(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0205BEA0; symbol: func_0205bea0; size: 0x58.
extern "C" ARM bool TestCurrentCoordinatesResolveValidEntry(unsigned object){if(data_02114e54[0x55]){unsigned a,b;ReadSelectedCoordinatePair(data_02114e54,&a,&b);return Grid_FindCellContainingPointAndSelectIndex(object,a,b)>=0;}return false;}
