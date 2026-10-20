#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN9GameState11GetInstanceEv();
    char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
    char* _ZN9GameState15GetGrottoStructEv(void*);
    unsigned short* Zone3D_GetMainInstance();
    int _Z21IsGrottoBossFloorZonei(int);
    int _ZNK19TreasureMapMetadata10GetMapTypeEv(void*);
}
// Original: arm9/ov017 @ 0x021B6E70; symbol: func_ov017_021b6e70; size: 0xA8.
// Field purposes remain uncertain; operation and call sequence follow original instructions.
extern "C" int FieldBattle_ResolveMonsterAndTreasureMapFlags(unsigned char* p,int i) {
    void* state=_ZN9GameState11GetInstanceEv();
    char* monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(state,i);
    if(monster) {
        if(((unsigned char*)monster)[0x17d]&2)p[12]=1;
        else if(((unsigned char*)monster)[0x17d]&4)p[13]=1;
    }
    unsigned short* zone=Zone3D_GetMainInstance();
    int type=_ZNK19TreasureMapMetadata10GetMapTypeEv(_ZN9GameState15GetGrottoStructEv(state)+0x6c);
    if(_Z21IsGrottoBossFloorZonei(*zone)) {
        if(type==1)p[12]=1;
        else if(type==2)p[13]=1;
    }
    return p[12]!=0||p[13]!=0;
}
