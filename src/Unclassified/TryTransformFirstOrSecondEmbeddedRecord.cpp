#include <globaldefs.h>
extern "C" void TestFieldAtOffset4();extern "C" int BinarySearchSixtyByteRecordsUsingKeyCallback(void*,void*,void(*)());
#pragma optimization_level 4
// Original: arm9/main @ 0x02079E2C; symbol: func_02079e2c; size: 0x34.
extern "C" ARM void TryTransformFirstOrSecondEmbeddedRecord(char* p,void* a){if(BinarySearchSixtyByteRecordsUsingKeyCallback(p,a,TestFieldAtOffset4))return;BinarySearchSixtyByteRecordsUsingKeyCallback(p+12,a,TestFieldAtOffset4);}
