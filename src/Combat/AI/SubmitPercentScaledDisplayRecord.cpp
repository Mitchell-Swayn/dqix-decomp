#include <globaldefs.h>
ARM
struct Record {float value;unsigned char a,b,c,amount;unsigned char type;char pad[3];};
extern "C" void AppendTenByteRecordIfCapacity(void*,const Record*);
// Original: arm9/ov024 @ 0x021FD088; symbol: func_ov024_021fd088; size: 0x7C.
extern "C" void SubmitPercentScaledDisplayRecord(char* p,float percent,unsigned char mode){
Record record=*(Record*)(p+0x65c);
record.value=(float)*(short*)(*(char**)(p+0x64c)+0x32);
record.a=mode;
record.amount=(int)(((float)(unsigned)record.amount*percent)/100.0f);
record.type=5;
AppendTenByteRecordIfCapacity(*(void**)(p+0x658),&record);
}
