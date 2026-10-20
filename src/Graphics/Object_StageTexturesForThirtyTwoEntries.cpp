#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"
struct Item{char pad[0x14];void* first;void* second;};struct Obj{char pad[12];Item* items[32];};extern "C" void Texture_FlushAndStageImageSegmentsAndPalette(void*);
// Original: arm9/main @ 0x0203DE2C; symbol: func_0203de2c; size: 0x58.
extern "C" ARM void Object_StageTexturesForThirtyTwoEntries(Obj* p){GameState::GetInstance();for(int i=0;i<32;i++){Item* item=p->items[i];if(item){if(item->first)Texture_FlushAndStageImageSegmentsAndPalette(item->first);else if(item->second)((Object3D*)item->second)->StageTextureData();}}}
