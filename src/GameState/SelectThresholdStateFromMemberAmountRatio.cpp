#include <globaldefs.h>
#include <GameState/GameState.h>
struct Base {char pad[0x30];unsigned short maximum;};struct Current {char pad[4];unsigned short amount;};struct Object {char pad[0x130];Current* current;Base* base;};
// Original: arm9/main @ 0x020DCC98; symbol: func_020dcc98; size: 0xA8.
extern "C" int SelectThresholdStateFromMemberAmountRatio(int index) {int result=15;Object* object=(Object*)GameState::GetInstance()->GetPartyMemberByIndex(index);if(object){unsigned short maximum=object->base->maximum;float ratio;if(0.0f==(float)(int)maximum)ratio=0.0f;else ratio=(float)(int)object->current->amount/(float)(int)maximum;if(ratio<=0.25f)result=13;if(ratio<=0.08f)result=11;if(0.0f==ratio)result=9;}return result;}
