#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" { int ReadScriptParameterAsInteger(IntegerParameterView*); float ReadScriptParameterAsFloat(FloatParameterView*); unsigned OV017_ReadWordField04(void*); char* GetBounded1416ByteRecord(int); void Memory_CreateNamedRecord(char*,unsigned,int,int); }
// Original: arm9/ov001 @ 0x0215C298; symbol: func_ov001_0215c298; size: 0x98.
extern "C" int Resource_DispatchIndexedRecordWithOptionalScale(unsigned char* parameters,int count) {
 int scale=4096;
 int flags;
 int id=ReadScriptParameterAsInteger((IntegerParameterView*)parameters);
 unsigned char* second=parameters+8;
 parameters+=16;
 unsigned value=OV017_ReadWordField04(second);
 flags=0;
 if(count>=3) { flags=ReadScriptParameterAsInteger((IntegerParameterView*)parameters); parameters+=8; }
 if(count>=4) scale=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)parameters));
 char* record=GetBounded1416ByteRecord(id);
 if(!record) return 0;
 Memory_CreateNamedRecord(record,value,flags,scale);
 return 1;
}
