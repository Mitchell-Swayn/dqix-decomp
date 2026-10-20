#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" int GameState_CopyBoundedIdWordRecords(int,short*,char*,int);
extern "C" {
struct Node { unsigned type; unsigned* nested; };
void Script_WriteIntegerReferenceOutput(Node*,unsigned);
}
struct IdWordRecord {unsigned value:10,flag:1,first:7,second:7,reserved:7;};
// Original: arm9/ov023 @ 0x021EAE38; symbol: func_ov023_021eae38; size: 0x68.
// Copies one bounded ID record and writes its ten-bit value to the script output.
extern "C" int Script_ReadBoundedIdRecordValue(char* parameters){
 IdWordRecord record;record.value=0;record.flag=0;record.first=0;record.second=0;
 short id=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
 GameState_CopyBoundedIdWordRecords(0,&id,(char*)&record,1);
 Script_WriteIntegerReferenceOutput((Node*)(parameters+8),record.value);
 return 1;
}
