#include <globaldefs.h>
ARM
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(...);
extern "C" int Input_IsKeyMaskNewlyPressed(...);
extern "C" int Window_IsVisible(...);
extern "C" int ReadSelectedCoordinatePair(...);
extern "C" int Window_GetConfirmedOptionForActiveInput(...);
extern "C" int TextCanvas_SelectEntryAtPoint(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x021550DC; symbol: UpdateSelectionFromInputOrTouchAndReportChange.
extern "C" int Alltrades_PollSelectionConfirmation(char*self){
unsigned char changed=0;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401))changed=1;if(P(self,28)&&Window_IsVisible(P(self,28))){int selected=Window_GetConfirmedOptionForActiveInput(P(self,28));if(selected>=0){changed=1;H(P(self,8),0)=selected+6;}}else if(B(Main_UnknownRoleZeroInitializedStorage_Variant4,85)&&P(self,8)){int x;int y;char*object=P(self,24);ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);S(self+256,232)=S(P(self,8),0);int selected=TextCanvas_SelectEntryAtPoint(object,S(self+256,230),(short)x,(short)y,&changed,1);if(selected<0)return 0;S(P(self,8),0)=selected;if(S(self+256,232)!=S(P(self,8),0)){S(object,54)=S(P(self,8),0);TextCanvas_CreateAndConfigureDisplayPart(object,S(self+256,230));}}return changed;
}
