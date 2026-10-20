#include <globaldefs.h>
ARM
struct GameResources; struct IntegerParameterView;
extern "C" void GameResources_SetSecondaryFlags(int self,unsigned int mask);
extern "C" void GameResources_ClearSecondaryFlags(int self,unsigned int mask);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original: arm9/ov001 @ 0x0215EE2C; symbol: func_ov001_0215ee2c; size: 0x84.
extern "C" int Script_SetResourceFlagFromParameters(char* p) {
GameResources* resources=GameResources_GetInstance();
if(!resources)return 0;
int kind=Script_ReadParameterAsInteger((IntegerParameterView*)p);
int enabled=Script_ReadParameterAsInteger((IntegerParameterView*)(p+8));
switch(kind){
case 0: if(enabled)GameResources_ClearSecondaryFlags((int)resources,8);else GameResources_SetSecondaryFlags((int)resources,8);break;
case 1: if(enabled)GameResources_ClearSecondaryFlags((int)resources,0x400);else GameResources_SetSecondaryFlags((int)resources,0x400);break;
}
return 1;
}
