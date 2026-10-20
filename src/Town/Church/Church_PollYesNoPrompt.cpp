#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct GameState;struct GameResources;struct Object3D;extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(unsigned*);struct A;struct Obj;extern "C" unsigned Window_IsVisible(A**);extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);extern "C" void Window_UpdateOptionSelectionAndEntry(Obj*,int);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void Window_SetInitialOption(char*,int);extern "C" void Window_CreateOptionLayoutAndResetSelection(unsigned char*,int);extern "C" int Window_GetConfirmedOptionForActiveInput(signed char*);extern "C" void Window_HideAndResetOptionSelection(void**);extern "C" bool Input_TestPressedKeyBitOne();
// Original: arm9/ov003 @ 0x0215BF18; symbol: Input_PollLinkedSelectionWithTickRefresh; size: 0x104.
extern "C" int Church_PollYesNoPrompt(char* self,int value){if(P(self,0x570)&&Window_IsVisible((A**)P(self,0x570))){unsigned tick=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());Window_UpdateOptionSelectionAndEntry((Obj*)P(self,0x570),tick);}unsigned state=B(self,0x581);if(state==0){SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);Window_SetInitialOption(P(self,0x570),(signed char)value);Window_CreateOptionLayoutAndResetSelection((unsigned char*)P(self,0x570),-1);B(self,0x581)++;}if(state==1){B(self,0x59f)|=1;int selected=Window_GetConfirmedOptionForActiveInput((signed char*)P(self,0x570));if(selected>=0){B(self,0x581)=0;B(self,0x59f)&=~1;Window_HideAndResetOptionSelection((void**)P(self,0x570));return selected;}/* Canonical zero-argument input helper; caller carries unused linked owner in r0. */if(((bool(*)(void*))Input_TestPressedKeyBitOne)(P(self,0x570))){B(self,0x581)=0;B(self,0x59f)&=~1;Window_HideAndResetOptionSelection((void**)P(self,0x570));return -2;}}return -1;}
