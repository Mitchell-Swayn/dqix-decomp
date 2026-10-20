#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fdcb8; symbol: data_020fdcb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Stats{int value;int rest[7];};extern Stats GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[],GameStateClassifyPartyMemberValueRatio_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02027BD0; symbol: func_02027bd0; size: 0xD4.
extern "C" int GameState_ClassifyPartyMemberValueRatio(int index){bool valid;if(index>=0&&index<=3)valid=true;else valid=false;if(!valid)return 1;int current=GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[index].value;int maximum=GameStateClassifyPartyMemberValueRatio_UnknownRoleZeroInitializedStorage[index].value;if(current<0)return 1;if(maximum<=0)return 1;if(!GameState::GetInstance()->GetPartyMemberByIndex(index))return 1;float ratio=(float)current/(float)maximum;if(ratio<=0.0f)return 2;if(ratio<=0.08f)return 3;if(ratio<=0.25f)return 4;return 1;}
