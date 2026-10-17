#include <globaldefs.h>
extern "C" { int TestElapsedTimestampWithinDuration(); extern unsigned data_02153628[]; extern char data_02114e30[],data_02114e54[]; void SetByteFieldAtOffset1C(void*,int); void SetByteFieldAtOffset61(void*,int);
// Original: arm9/main @ 0x020E123C; symbol: func_020e123c; size: 0x4C.
 void ClearModeTimestampAndEnableTwoInputOwners() { if(TestElapsedTimestampWithinDuration())return; unsigned* p=data_02153628;p[1]=0;p[2]=0;p[0]=0;SetByteFieldAtOffset1C(data_02114e30,1);SetByteFieldAtOffset61(data_02114e54,1); } }
