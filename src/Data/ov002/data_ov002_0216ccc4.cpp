// Item property dispatch table. func_ov002_021536ec scans 12-byte
// records using signed 16-bit property IDs (-1 terminates), then calls
// the member target with object, selection, item record and property kind.
typedef int (*ItemPropertyCallback)(void *, void *, void *, int);
struct PropertyHandler { short id; unsigned short padding; ItemPropertyCallback target; int adjustmentAndVirtual; };
struct PropertyDispatchTail { ItemPropertyCallback firstTarget; int firstAdjustmentAndVirtual; PropertyHandler remaining[2]; };
extern "C" {
extern int func_ov002_02153ea4(void *object, void *selection, void *itemRecord, int propertyKind);
PropertyDispatchTail data_ov002_0216ccc4 = { 0, 0, {
    { 5, 0, func_ov002_02153ea4, 0 },
    { -1, 0, 0, 0 },
} };
}
