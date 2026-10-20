#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#pragma force_active on
ARM
extern "C" void InitializeTypeFourStateAndBuffers(unsigned char*,int);
extern "C" unsigned GameState_GetProgressChapter(GameState*);
extern "C" unsigned GameState_ReadUnknown5cb4(GameState*);
// Original data: arm9/ov017 @ 0x021D7D7E; symbol: data_ov017_021d7d7e.
// The 12-byte archive member name is "inevent.stb" with terminating padding.
extern "C" char FieldEvent_InitializeInEventScriptRequest_TextIneventStb[12];
// Original: arm9/ov017 @ 0x021BBA08; symbol: func_ov017_021bba08; size: 0xDC.
// Initializes an in-event script request from a packed event identifier/name descriptor.
extern "C" void FieldEvent_InitializeInEventScriptRequest(unsigned char* request,const unsigned char* descriptor)
{
    InitializeTypeFourStateAndBuffers(request,1);
    request[0x9c]=1;
    GameState* game=GameState::GetInstance();
    request[0xc]=GameState_GetProgressChapter(game);
    request[0xe]=GameState_GetProgressChapter(game);
    request[0xd]=GameState_ReadUnknown5cb4(game);
    request[0xf]=GameState_ReadUnknown5cb4(game);
    *(short*)(request+0x16)=3;
    request[0x10]=1;
    request[0x11]=0;
    *(unsigned short*)(request+0x1a)=*(const unsigned short*)descriptor;
    memcpy(request+0x1e,descriptor+5,7);
    memcpy(request+0x3e,FieldEvent_InitializeInEventScriptRequest_TextIneventStb,12);
    *(short*)(request+0x4a)=100;
    *(short*)(request+0x4c)=200;
    *(short*)(request+0x4e)=300;
    *(short*)(request+0x50)=64;
    *(short*)(request+0x52)=-1;
    request[0x12]=0;
    memset(request+0x54,0,12);
    *(short*)(request+0x60)=0;
}
