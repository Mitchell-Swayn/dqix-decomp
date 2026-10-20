#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
struct Vector { int x,y,z; };
extern "C" void Pool_AllocateTypedCoordinateRecord(char*,Vector,int);
extern "C" char* Event_GetObjectSession(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
// Original: arm9/ov001 @ 0x0215C330; symbol: func_ov001_0215c330; size: 0xB8.
extern "C" int Script_ApplyFixedPointVectorToBoundedRecord(unsigned char* parameters,int count) {
int option=0;
int index=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
Vector vector;
vector.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+8)));
vector.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+16)));
vector.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+24)));
if(count>=5)option=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+32));
char* record=Event_GetObjectSession(index);
if(!record)return 0;
Pool_AllocateTypedCoordinateRecord(record,vector,option);
return 1;
}
