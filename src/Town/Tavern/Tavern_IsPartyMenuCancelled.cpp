#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" int Input_IsKeyMaskNewlyPressed(void*,int);
extern "C" int FieldInput_IsPostCommandCooldownExpired(void*);
extern "C" int Window_IsVisible(void*);
extern "C" int Input_TestPressedKeyBitOne(void*);
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
// Original: arm9/ov003 @ 0x02160A68; symbol: Input_TestCancelKeyOrPointOutsideSelectedRectangle; size: 0xc4.
extern "C" int Tavern_IsPartyMenuCancelled(char* self) {
 int result=0;void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2) && FieldInput_IsPostCommandCooldownExpired(resources))result=1;
 if(Window_IsVisible(P(self,0x390))){if(Input_TestPressedKeyBitOne(P(self,0x390)))result=1;}
 else if(B(Main_UnknownRoleZeroInitializedStorage_Variant4,85)){int x,y;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);if(!Geometry_TestPointWithinScaledTextureRectangle(P(self,0x324),H(self,0x488),(short)x,(short)y))result=1;}
 return result;
}
