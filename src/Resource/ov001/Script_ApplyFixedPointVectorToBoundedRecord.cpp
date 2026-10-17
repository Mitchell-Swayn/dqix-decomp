#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
struct Vector { int x,y,z; };
extern "C" void Pool_AllocateTypedCoordinateRecord(char*,Vector,int);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
// Original: arm9/ov001 @ 0x0215C330; symbol: func_ov001_0215c330; size: 0xB8.
extern "C" int Script_ApplyFixedPointVectorToBoundedRecord(unsigned char* parameters,int count) {
int option=0;
int index=ReadScriptParameterAsInteger((IntegerParameterView*)parameters);
Vector vector;
vector.x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+8)));
vector.y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+16)));
vector.z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+24)));
if(count>=5)option=ReadScriptParameterAsInteger((IntegerParameterView*)(parameters+32));
char* record=GetBounded1416ByteRecord(index);
if(!record)return 0;
Pool_AllocateTypedCoordinateRecord(record,vector,option);
return 1;
}
