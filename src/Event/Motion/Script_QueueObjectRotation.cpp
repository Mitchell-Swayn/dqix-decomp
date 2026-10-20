#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" char* Event_GetObjectSession(int);
struct Vector { int x,y,z; };
extern "C" void Event_QueueObjectRotation(char*,Vector);
// Original: arm9/ov001 @ 0x0215C138; symbol: func_ov001_0215c138; size: 0x98.
extern "C" int Script_QueueObjectRotation(char* params) {
 int index=Script_ReadParameterAsInteger((IntegerParameterView*)params);
 Vector vector;
 vector.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(params+8)));
 vector.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(params+16)));
 vector.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(params+24)));
 char* record=Event_GetObjectSession(index);
 if(!record) return 0;
 Event_QueueObjectRotation(record,vector);
 return 1;
}
