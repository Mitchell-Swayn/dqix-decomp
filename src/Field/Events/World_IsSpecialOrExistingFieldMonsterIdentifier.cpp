#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" GameResources* GameResources_GetInstance();
extern "C" GameObject* FieldMonster_FindByPersistentRecordIdentifier(int,int);
// Original: arm9/ov017 @ 0x021C5A1C; symbol: func_ov017_021c5a1c; size: 0x70.
// Accepts special identifiers 0x8000..0x8004 or positive signed-halfword identifiers of existing field monsters when resources are available.
extern "C" int World_IsSpecialOrExistingFieldMonsterIdentifier(int identifier) {
 if(identifier>=0x8000 && identifier<=0x8004)return 1;
 if(identifier<1)return 0;
 if(identifier>0x7fff)return 0;
 GameState::GetInstance();
 GameResources* resources=GameResources_GetInstance();
 if(!resources)return 0;
 if(FieldMonster_FindByPersistentRecordIdentifier((int)resources,identifier))return 1;
 return 0;
}
