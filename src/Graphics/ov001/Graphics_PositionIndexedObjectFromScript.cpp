#include <globaldefs.h>
ARM
struct IntegerParameterView { int words[2]; };struct GameResources;
struct Vector {int x,y,z;};
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void Graphics_SelectIndexedObjectAndPositionOnScreen(char*,int,const void*,int,int);
// Original: arm9/ov001 @ 0x0215FE50; symbol: func_ov001_0215fe50; size: 0xA4.
extern "C" int Graphics_PositionIndexedObjectFromScript(IntegerParameterView* args,int inputCount) {
int index;
int count=inputCount;
int id=ReadScriptParameterAsInteger(args++);
index=ReadScriptParameterAsInteger((IntegerParameterView*)(args++));
char* record=GetBounded1416ByteRecord(id);
if(!record) return 0;
Vector v=*(Vector*)(record+0x74);
int dx=0,dy=0;
if(count>=3) {dx=ReadScriptParameterAsInteger(args);++args;}
if(count>=4) dy=ReadScriptParameterAsInteger(args);
Graphics_SelectIndexedObjectAndPositionOnScreen((char*)GameResources_GetInstance(),index,&v,dx,dy);
return 1;
}
