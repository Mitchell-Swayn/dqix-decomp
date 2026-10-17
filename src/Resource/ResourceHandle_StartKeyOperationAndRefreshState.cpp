#include <globaldefs.h>
ARM
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(void*,unsigned,unsigned,unsigned);extern "C" void InvokeHandleStateWhenPresent(void*,int);extern "C" int ResourceHandle_UpdateAndReadOrClose(void*,int,void*);extern "C" bool TestValueOnAlternateOrEmbeddedResource(void*,int,void*);extern "C" void UpdateByteLevelTransitionAndThreeChannels(void*,unsigned char,int);extern "C" void Object_Invokewhile();
// Original: arm9/main @ 0x0209C6D8; symbol: func_0209c6d8; size: 0x64.
extern "C" void ResourceHandle_StartKeyOperationAndRefreshState(char* p,int key,unsigned a,unsigned b) {DispatchObjectStateOneOrTwoUnlessFlag4(p,0,a,b);int state=*(int*)(p+0xb4);if(state>0)InvokeHandleStateWhenPresent(p,state);*(short*)(p+0xce)=key;ResourceHandle_UpdateAndReadOrClose(p,key,0);TestValueOnAlternateOrEmbeddedResource(p,key,p+0xc4);UpdateByteLevelTransitionAndThreeChannels(p,(unsigned char)p[0xcd],0);Object_Invokewhile(); }
