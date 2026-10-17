#include <globaldefs.h>
ARM
class GameState; class Object3D; struct Record;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" int _ZN6Zone3D32HasMapFlag10OutsideExcludedZonesEv(void*);
extern "C" void func_020541a4(Object3D*, int);
extern "C" void ClearByteHalfwordByteRecord(Record* p);
// Original: arm9/ov002 @ 0x02154824; symbol: func_ov002_02154824; size: 0x94.
extern "C" int GameState_ApplyPartyFlagInEligibleZone(void *unused, char *self, int enabled) {
    if (!self) return 0;
    if (!enabled) return 0;
    int result = 0;
    ClearByteHalfwordByteRecord((Record *)(self + 8));
    if (_ZN6Zone3D32HasMapFlag10OutsideExcludedZonesEv(ReadGlobalValueAt020FB3F0())) {
        GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
        unsigned char *indices = (unsigned char *)GameState_GetIndexList(state);
        for (int i = 0; i < indices[0xf7c]; ++i) {
            Object3D *member = _ZN9GameState21GetPartyMemberByIndexEi(state, *(indices + i + 0xf78));
            func_020541a4(member, 1);
        }
        *(unsigned char *)(self + 8) = 3;
        result = 1;
        *(int *)(self + 0x38) = result;
    }
    return result;
}
