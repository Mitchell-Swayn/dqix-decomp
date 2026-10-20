#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
struct Input{unsigned short id;short value;Vector3i position;unsigned short field10,field12;unsigned char option;signed char field15;short field16,field18,field1a;};
extern "C" {char*GameState_ReadUnkF8(GameState*);Zone3D*Zone3D_GetMainInstance();}
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Option{unsigned char a:3,flag:1,b:4;};struct Global{char pad[200];Option options;};extern "C" Global Main_UnknownRoleZeroInitializedStorage_Variant2;struct Tail{short a,b,c;signed char d;};
// Original: arm9/main @ 0x020A9D78; symbol: func_020a9d78; size: 0xB8.
extern "C" ARM int GameState_ApplySavedZonePositionAndOptions(const Input*p){GameState*state=GameState::GetInstance();char*q=GameState_ReadUnkF8(state);*(unsigned short*)q=p->id;*(Vector3i*)(q+16)=p->position;*(short*)(q+28)=p->value;q[7]=1;Zone3D*z=Zone3D_GetMainInstance();z->SetUnknown27d8(p->field12);z->SetUnknown27da(p->field10);Main_UnknownRoleZeroInitializedStorage_Variant2.options.flag=p->option!=0;Tail*t=(Tail*)((char*)state+0x7e78);t->a=p->field16;t->b=p->field18;t->c=p->field1a;t->d=p->field15;return 1;}
