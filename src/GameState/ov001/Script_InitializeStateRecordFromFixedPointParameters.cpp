#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadUnkF8(void*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" float ReadScriptParameterAsFloat(void*);
extern "C" void InitializeRecordWithEnabledAndInvalidIndices(char*);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" char* GameResources_GetInstance();
extern "C" void* GameState_CopyChunkAtOffset3F8(void*,const void*);
// ARM9 ov001 0x02161f80 func_ov001_02161f80
// Original: arm9/ov001 @ 0x02161F80; symbol: func_ov001_02161f80; size: 0x13C.
extern "C" int Script_InitializeStateRecordFromFixedPointParameters(char* params,int count) {
    void* state=_ZN9GameState11GetInstanceEv();
    char* record=GameState_ReadUnkF8(state);
    ReadGlobalValueAt020FB3F0();
    int optional=-1;
    int value;
    int id=ReadScriptParameterAsInteger(params);
    int v[3];
    v[0]=(int)(4096.0f*ReadScriptParameterAsFloat(params+8));
    v[1]=(int)(4096.0f*ReadScriptParameterAsFloat(params+16));
    v[2]=(int)(4096.0f*ReadScriptParameterAsFloat(params+24));
    value=(int)(4096.0f*ReadScriptParameterAsFloat(params+32));
    if(count>5) optional=ReadScriptParameterAsInteger(params+40);
    InitializeRecordWithEnabledAndInvalidIndices(record);
    record[2]=1; record[7]=1;
    *(short*)record=id;
    _ZN8Vector3iaSERKS_(record+16,v);
    *(short*)(record+28)=value;
    *(int*)(record+32)=optional;
    char* resource=*(char**)(GameResources_GetInstance()+0x3734);
    if(resource && ((unsigned char*)resource)[3]) {
        unsigned short id=*(unsigned short*)(resource+8);
        if(id==0x733d || id==0x7340) record[0x69]=1;
    }
    GameState_CopyChunkAtOffset3F8(state,record);
    return 1;
}
