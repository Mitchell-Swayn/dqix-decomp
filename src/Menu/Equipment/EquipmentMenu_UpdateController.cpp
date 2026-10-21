#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Coordinates;
struct Object;
struct Owner {};
typedef void (Owner::*Handler)();
extern "C" {
void EquipmentMenu_AnimateCursorRectangle(Coordinates* self, int ticks);
int ItemDetail_DispatchDisplayState(Object* self);
int EquipmentMenu_PollTemporaryMusic(unsigned char* p);
void EquipmentMenu_StagePendingItemResources(unsigned char* p);
void AdvanceSelectedRecordTextPanel(unsigned char* p, unsigned value);
// Original data: arm9/ov005 @ 0x215cd74; symbol: EquipmentMenuUpdateController_UnknownRoleProcedureReferenceRecords.
extern Handler EquipmentMenuUpdateController_UnknownRoleProcedureReferenceRecords[];
}
#define W(p,o) (*(int*)((p)+(o)))
#pragma always_inline on
inline int TimerValue(unsigned char* p){ return ((signed char*)p)[6]; }
inline void SetTimer(unsigned char* p, int v){ p[0xe06] = v; }
inline void SetStatus(unsigned char* p, int v){ ((signed char*)p)[0xe07] = v; }
// Original: arm9/ov005 @ 0x02154DE8; symbol: func_ov005_02154de8; size: 0x108.
// Updates tick-driven mode state and dispatches an optional native member-function callback.
extern "C" void EquipmentMenu_UpdateController(unsigned char* self)
{
    unsigned ticks = GameState::GetInstance()->GetTickCount();
    if (!ticks) ticks = 1;
    W(self, 0x3de4) = ticks;
    EquipmentMenu_AnimateCursorRectangle((Coordinates*)(self + 0x1a34), 1);
    ItemDetail_DispatchDisplayState((Object*)(self + 0x1244));
    if (EquipmentMenu_PollTemporaryMusic(self)) {
        EquipmentMenu_StagePendingItemResources(self);
        return;
    }
    unsigned kind = self[0x3dd1];
    if (kind != 0 && kind != 8 && kind != 9) {
        AdvanceSelectedRecordTextPanel(self, ticks);
        EquipmentMenu_StagePendingItemResources(self);
        return;
    }
    if (TimerValue(self + 0x3e00) > 0) {
        SetTimer(self + 0x3000, TimerValue(self + 0x3e00) - ticks);
        if (TimerValue(self + 0x3e00) <= 0) {
            SetTimer(self + 0x3000, 0);
            SetStatus(self + 0x3000, -2);
        }
    }
    if (!EquipmentMenuUpdateController_UnknownRoleProcedureReferenceRecords[self[0x3db8]]) return;
    (((Owner*)self)->*EquipmentMenuUpdateController_UnknownRoleProcedureReferenceRecords[self[0x3db8]])();
    EquipmentMenu_StagePendingItemResources(self);
}
