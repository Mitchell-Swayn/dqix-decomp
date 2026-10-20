#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void GameResources_SetPrimaryFlags(void*,unsigned int);
// Original: arm9/ov017 @ 0x021B7104; symbol: func_ov017_021b7104; size: 0xD4.
extern "C" ARM void FieldBattle_ConfigureEncounterRequest(unsigned char* p, unsigned char* source)
{
    GameState* state=GameState::GetInstance();
    unsigned char* resource=(unsigned char*)GameResources_GetInstance();
    unsigned int index=source[1];
    *(unsigned short*)(p+0x22)=index;
    *(unsigned short*)(p+0x24)=*(unsigned short*)(source+4);
    *(unsigned short*)(p+0x26)=*(unsigned short*)(source+2);
    p[0x20]=source[0];
    p[0x46]=source[0]?GameState_ReadProtagonistObjectIndex(state):-1;
    *(unsigned int*)(p+0x28)=*(unsigned int*)(source+8);
    p[0x41]=source[13];
    p[0x40]=source[12];
    p[0x42]=source[14];
    *(short*)(p+0x44)=*(short*)(source+16);
    p[0x51]=source[15];
    *(unsigned int*)(p+0x48)=*(unsigned int*)(source+20);
    p[0x21]=source[18];
    if(source[0] && !*(unsigned int*)(source+20)) GameResources_SetPrimaryFlags(resource,0x800);
    resource[0x42e8]=0;
    *(unsigned short*)(resource+0x44c2)=0;
}
