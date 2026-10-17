#include <globaldefs.h>
extern "C" void VectorizedMemset(void*,int,unsigned);
// Original: arm9/main @ 0x02070378; symbol: func_02070378; size: 0x50.
extern "C" ARM void InitializeRecordWithEnabledAndInvalidIndices(char* object){VectorizedMemset(object,0,112);object[4]=1;object[8]=1;object[9]=1;object[11]=-1;*(int*)(object+32)=-1;*(int*)(object+36)=-1;*(int*)(object+40)=-1;*(int*)(object+44)=-1;*(short*)(object+30)=-1;object[12]=0;*(short*)(object+108)=-1;}
