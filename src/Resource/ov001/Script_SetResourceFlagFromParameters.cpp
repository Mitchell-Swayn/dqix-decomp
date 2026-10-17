#include <globaldefs.h>
ARM
struct GameResources; struct IntegerParameterView;
extern "C" void Object_SetUnsignedIntAtOffset4(int self,unsigned int mask);
extern "C" void ClearWordAtOffset4MaskedBits(int self,unsigned int mask);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
// Original: arm9/ov001 @ 0x0215EE2C; symbol: func_ov001_0215ee2c; size: 0x84.
extern "C" int Script_SetResourceFlagFromParameters(char* p) {
GameResources* resources=GameResources_GetInstance();
if(!resources)return 0;
int kind=ReadScriptParameterAsInteger((IntegerParameterView*)p);
int enabled=ReadScriptParameterAsInteger((IntegerParameterView*)(p+8));
switch(kind){
case 0: if(enabled)ClearWordAtOffset4MaskedBits((int)resources,8);else Object_SetUnsignedIntAtOffset4((int)resources,8);break;
case 1: if(enabled)ClearWordAtOffset4MaskedBits((int)resources,0x400);else Object_SetUnsignedIntAtOffset4((int)resources,0x400);break;
}
return 1;
}
