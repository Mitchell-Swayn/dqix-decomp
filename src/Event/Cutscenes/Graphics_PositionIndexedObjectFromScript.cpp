#include <globaldefs.h>
ARM
struct IntegerParameterView { int words[2]; };struct GameResources;
struct Vector {int x,y,z;};
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Graphics_SelectIndexedObjectAndPositionOnScreen(char*,int,const void*,int,int);
// Original: arm9/ov001 @ 0x0215FE50; symbol: func_ov001_0215fe50; size: 0xA4.
extern "C" int Graphics_PositionIndexedObjectFromScript(IntegerParameterView* args,int inputCount) {
int index;
int count=inputCount;
int id=Script_ReadParameterAsInteger(args++);
index=Script_ReadParameterAsInteger((IntegerParameterView*)(args++));
char* record=Event_GetObjectSession(id);
if(!record) return 0;
Vector v=*(Vector*)(record+0x74);
int dx=0,dy=0;
if(count>=3) {dx=Script_ReadParameterAsInteger(args);++args;}
if(count>=4) dy=Script_ReadParameterAsInteger(args);
Graphics_SelectIndexedObjectAndPositionOnScreen((char*)GameResources_GetInstance(),index,&v,dx,dy);
return 1;
}
