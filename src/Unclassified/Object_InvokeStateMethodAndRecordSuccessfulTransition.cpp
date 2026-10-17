#include <globaldefs.h>
ARM
struct Object {unsigned char pad[0x130];int current,previous;unsigned char unknown[0x14];int value;};typedef bool (Object::*Method)();extern "C" Method data_020e8994[];
// Original: arm9/main @ 0x02076CCC; symbol: func_02076ccc; size: 0x68.
extern "C" bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object* object,int index) {if(object->current==index)return true;bool success=(object->*data_020e8994[index])();bool result=false;if(success){object->previous=object->current;object->current=index;object->value=0;result=true;}return result;}
