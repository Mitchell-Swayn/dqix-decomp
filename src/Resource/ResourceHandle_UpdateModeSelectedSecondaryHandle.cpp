#include <globaldefs.h>
ARM
extern "C" int GameState_TestInstanceListAndListedObjectReadiness();
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(void *,int);
extern "C" void ResourceHandle_UpdateAndInvokeObjectCommand(void *,void *,int);
extern "C" void TestValueOnAlternateOrEmbeddedResource(void *,int,void *);
struct Flags { unsigned char pad:2; unsigned char disabled:1; };
// Original: arm9/main @ 0x0209C5E8; symbol: func_0209c5e8; size: 0x90.
extern "C" void ResourceHandle_UpdateModeSelectedSecondaryHandle(char *self) { if(((Flags *)(self+200))->disabled) return; if(GameState_TestInstanceListAndListedObjectReadiness()) { DispatchObjectStateOneOrTwoUnlessFlag4(self,0); return; } int mode=*(int *)(self+0xb0); if(mode==1) { ResourceHandle_UpdateAndInvokeObjectCommand(self,self+0xbc,0); TestValueOnAlternateOrEmbeddedResource(self,*(short *)(self+0xb8),self+0xbc); return; } if(mode!=2) return; ResourceHandle_UpdateAndInvokeObjectCommand(self,self+0xc0,0); TestValueOnAlternateOrEmbeddedResource(self,*(short *)(self+0xba),self+0xc0); }
