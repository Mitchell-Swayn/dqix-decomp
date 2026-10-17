// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
typedef int (*ItemPropertyCallback)(void *, void *, void *, int);
struct PropertyHandler { short id; unsigned short padding; ItemPropertyCallback target; int adjustmentAndVirtual; };
struct PropertyDispatchTail { ItemPropertyCallback firstTarget; int firstAdjustmentAndVirtual; PropertyHandler remaining[11]; };
extern "C" {
extern int func_ov002_02153ccc(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_02153ea4(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_02154020(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_02154230(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_021544f4(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_021546c8(void *object, void *selection, void *itemRecord, int propertyKind);
extern int GameState_ApplyPartyFlagInEligibleZone(void *object, void *selection, void *itemRecord, int propertyKind);
extern int func_ov002_021548b8(void *object, void *selection, void *itemRecord, int propertyKind);
PropertyDispatchTail data_ov002_0216cce8 = { 0, 0, {
    { 2, 0, func_ov002_02153ccc, 0 },
    { 7, 0, func_ov002_02153ea4, 0 },
    { 79, 0, func_ov002_02154020, 0 },
    { 80, 0, func_ov002_02154020, 0 },
    { 18, 0, func_ov002_02154230, 0 },
    { 26, 0, func_ov002_021544f4, 0 },
    { 29, 0, func_ov002_021546c8, 0 },
    { 54, 0, GameState_ApplyPartyFlagInEligibleZone, 0 },
    { 85, 0, func_ov002_021548b8, 0 },
    { 43, 0, func_ov002_02153ea4, 0 },
    { -1, 0, 0, 0 },
} };
}
