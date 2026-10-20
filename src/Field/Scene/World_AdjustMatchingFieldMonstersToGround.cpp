#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
class Zone3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
extern "C" void* Zone3D_GetMainInstance();
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D* zone,const Vector3i* input);
struct GroupRecord { unsigned short id; unsigned short group : 2; unsigned short reserved : 14; };
extern "C" GroupRecord *ZoneState_FindCurrentTrackedZone(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
// Original: arm9/ov017 @ 0x021A3338; symbol: func_ov017_021a3338; size: 0xA8.
extern "C" void World_AdjustMatchingFieldMonstersToGround(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    Zone3D *zone = (Zone3D *)Zone3D_GetMainInstance();
    unsigned short id = *(unsigned short *)zone;
    GroupRecord *record = ZoneState_FindCurrentTrackedZone(zone);
    if (record) {
        for (int i = 0; i < 12; ++i) {
            char *object = _ZN9GameState27GetMaybeFieldMonsterByIndexEi(state, i + (record->group * 12 + 0x70));
            if (object && id == _ZNK8Object3D10GetField06Ev(object)) {
                Vector3i position = *(Vector3i *)(object + 0x44);
                position.y = Zone3D_FindGroundHeightBelowPosition(zone, &position);
                *(Vector3i *)(object + 0x44) = position;
            }
        }
    }
}
