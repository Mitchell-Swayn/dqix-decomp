#include <globaldefs.h>
ARM
extern "C" {void Object_GetGlobalConnectionState(void*);int ReadIndexedSignedField1038();void System_QueuePackedRecordAE(int,int,int,int,unsigned char,int,int);
// Original: arm9/main @ 0x020A8A34; symbol: func_020a8a34; size: 0x94.
void UpdateIndexedByteFlagOrDispatchPackedRecord(unsigned char* p,int mode,unsigned int index,int value){if(mode==0){p[5]&=~(1<<index);p[7]=value;}else if(mode==1){p[5]|=1<<index;p[7]=value;}else if(mode==2){Object_GetGlobalConnectionState(p);unsigned char v=ReadIndexedSignedField1038();System_QueuePackedRecordAE(p[0],p[1],p[2],p[4],v,1,0);}}}
