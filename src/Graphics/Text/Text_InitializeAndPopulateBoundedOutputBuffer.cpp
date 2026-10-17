#include <globaldefs.h>
ARM
extern "C" {extern int data_020f2a3c;extern int data_020f2a24;void Object_ResetEmbeddedStateAndReturnSelf(void*);void ClearRecordAndInvalidateTwoIndices(void*);void LoadAndProcessDataWithOptionalBackgroundLoaderLock(char*,int,int,int,int,int);
// Original: arm9/main @ 0x020DCFC8; symbol: func_020dcfc8; size: 0x78.
void Text_InitializeAndPopulateBoundedOutputBuffer(int size,char* out){if(size>0&&out){*out=0;int b;int a=data_020f2a3c;b=data_020f2a24;unsigned char state[24];Object_ResetEmbeddedStateAndReturnSelf(state);ClearRecordAndInvalidateTwoIndices(state);LoadAndProcessDataWithOptionalBackgroundLoaderLock(out,b,size,0,1,a);}}}
