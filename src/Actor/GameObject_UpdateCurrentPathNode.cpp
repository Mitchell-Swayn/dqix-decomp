#include <globaldefs.h>
#include <System/Matrix.h>
#include <World/Object3D.h>
ARM
#pragma always_inline on

union Vector {
    struct {
        int x, y, z;
    };
    int words[3];
};
struct E {
    unsigned short key;
    char pad[790];
};
struct IndexedRecordTable;

extern "C" {
void *ZoneState_GetTrackedZoneCache();
E *ZoneState_FindTrackedZoneByIdentifier(E *p, int key);
unsigned char *ActorPathGraph_GetNodeByIndex(unsigned char *p, int i);
void GameObject_GetAuthorityPosition(Vector *out, unsigned char *p);
unsigned ActorPathGraph_FindNearestNodeIndexByManhattanDistance(unsigned char *self, int *point);
int IndexedRecordTable_FindRecordIndexByValue(const IndexedRecordTable *table, int value);
}

// Original: arm9/main @ 0x020339C8; symbol: func_020339c8; size: 0x190.
// Updates the object's current path-graph node from authority position, either by nearest-node lookup or by a closer linked candidate.
extern "C" void GameObject_UpdateCurrentPathNode(unsigned char *object)
{
    Vector position, center, candidate, nearestPosition, readPosition;
    if (!(((unsigned)object[0xc2] << 25) >> 31))
        return;
    E *global = (E *)ZoneState_GetTrackedZoneCache();
    unsigned char *owner = (unsigned char *)ZoneState_FindTrackedZoneByIdentifier(
        global, ((Object3D *)object)->GetField06());
    if (!owner || !*(unsigned *)(owner + 0x34))
        return;
    unsigned char *record = ActorPathGraph_GetNodeByIndex(owner + 0x18, *(unsigned short *)(object + 0xb8));
    if (!record)
        return;
    if (*(unsigned short *)object & 0x1200) {
        GameObject_GetAuthorityPosition(&nearestPosition, object);
        int index = (int)ActorPathGraph_FindNearestNodeIndexByManhattanDistance(owner + 0x18, (int *)&nearestPosition);
        if (index > -1)
            *(unsigned short *)(object + 0xb8) = (unsigned short)index;
    } else if (record[2]) {
        GameObject_GetAuthorityPosition(&readPosition, object);
        position = readPosition;
        center.x = *(short *)(record + 4) << 12;
        center.y = *(short *)(record + 6) << 12;
        center.z = *(short *)(record + 8) << 12;
        int threshold = Vector3fix_Distance((const Vector3fix *)&position, (const Vector3fix *)&center);
        int selected = -1;
        for (int i = 0; i < record[2]; ++i) {
            candidate.x = *(short *)((*(unsigned char ***)(record + 12))[i] + 4) << 12;
            candidate.y = *(short *)((*(unsigned char ***)(record + 12))[i] + 6) << 12;
            candidate.z = *(short *)((*(unsigned char ***)(record + 12))[i] + 8) << 12;
            if (Vector3fix_Distance((const Vector3fix *)&candidate, (const Vector3fix *)&position) < threshold)
                selected = (*(unsigned char ***)(record + 12))[i][0];
        }
        if (selected >= 0) {
            int index = IndexedRecordTable_FindRecordIndexByValue((IndexedRecordTable *)(owner + 0x18), selected);
            if (index > -1)
                *(unsigned short *)(object + 0xb8) = (unsigned short)index;
        }
    }
}
