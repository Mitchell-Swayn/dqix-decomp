#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" { int Script_ReadParameterAsInteger(IntegerParameterView*); float Script_ReadParameterAsFloat(FloatParameterView*); unsigned Script_ReadParameterString(void*); char* Event_GetObjectSession(int); void Memory_CreateNamedRecord(char*,unsigned,int,int); }
// Original: arm9/ov001 @ 0x0215C298; symbol: func_ov001_0215c298; size: 0x98.
extern "C" int Resource_DispatchIndexedRecordWithOptionalScale(unsigned char* parameters,int count) {
 int scale=4096;
 int flags;
 int id=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
 unsigned char* second=parameters+8;
 parameters+=16;
 unsigned value=Script_ReadParameterString(second);
 flags=0;
 if(count>=3) { flags=Script_ReadParameterAsInteger((IntegerParameterView*)parameters); parameters+=8; }
 if(count>=4) scale=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)parameters));
 char* record=Event_GetObjectSession(id);
 if(!record) return 0;
 Memory_CreateNamedRecord(record,value,flags,scale);
 return 1;
}
