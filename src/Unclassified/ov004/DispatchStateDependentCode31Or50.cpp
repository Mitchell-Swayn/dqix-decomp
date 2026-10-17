#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" int SumIndexedValuesAcrossPresentPartyIds(void*,int);
extern "C" void func_ov011_021848a0(void*,int);
// Original: arm9/ov004 @ 0x02167E6C; symbol: func_ov004_02167e6c; size: 0x44.
extern "C" ARM int DispatchStateDependentCode31Or50(void* self) { if(SumIndexedValuesAcrossPresentPartyIds(GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0x5617)>0) func_ov011_021848a0(self,31); else func_ov011_021848a0(self,50); return 0; }
