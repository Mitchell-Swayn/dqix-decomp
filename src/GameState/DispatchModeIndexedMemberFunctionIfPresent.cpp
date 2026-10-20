#include <globaldefs.h>
#include "GameState/GameState.h"
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e907c; symbol: data_020e907c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 9c620a0200000000f8630a0200000000a4640a02000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Handler { unsigned char pad[10]; unsigned char mode; }; typedef void (Handler::*Action)();struct Table { Action actions[4]; }; extern "C" Table DispatchModeIndexedMemberFunctionIfPresent_UnknownRoleProcedureReferenceRecords;extern "C" Action ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original: arm9/main @ 0x020A620C; symbol: func_020a620c; size: 0x90.
extern "C" int DispatchModeIndexedMemberFunctionIfPresent(Handler *p) { GameState::GetInstance()->GetTickCount();Table table=DispatchModeIndexedMemberFunctionIfPresent_UnknownRoleProcedureReferenceRecords;table.actions[3]=ShopUpdateInterface_UnknownRoleInitializedBytes;if(!table.actions[p->mode])return 0;(p->*table.actions[p->mode])();return 1; }
