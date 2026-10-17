#include <globaldefs.h>
#include <GameState/GameState.h>
struct MenuAnimationRecord { unsigned char pad[4]; short x,y; unsigned char pad2[13]; unsigned char flags; };
struct Overlay19State { unsigned char pad[76]; unsigned flags; unsigned pad2; unsigned char animation[60]; void* element; };
extern "C" {
void Object_ResetSelectedEntryCoordinatesAndFlags(void*,int);
MenuAnimationRecord* FindRecordPointerByKey(void*,int);
void ApplyValueToAllHalfwordCountedEntries(void*,unsigned);
void Object_WriteSelectedEntryByte14(void*,int,int);
void Object_UpdateAllCountedResourceEntries(void*);
}
// Original: arm9/ov019 @ 0x0218C178; symbol: func_ov019_0218c178; size: 0xC8.
extern "C" void func_ov019_0218c178(Overlay19State* state) {
    GameState* game=GameState::GetInstance();
    if (state->flags&1) {
        void* element=state->element;
        if (element) {
            Object_ResetSelectedEntryCoordinatesAndFlags(element,1);
            MenuAnimationRecord* record=FindRecordPointerByKey(element,1);
            if (record) record->flags |= 8;
            ApplyValueToAllHalfwordCountedEntries(element,game->GetTickCount());
            record=FindRecordPointerByKey(element,1);
            if (record) { record->x=215; record->y=150; }
            Object_WriteSelectedEntryByte14(element,1,36);
        }
        Object_UpdateAllCountedResourceEntries(state->animation);
    } else if (state->element) {
        MenuAnimationRecord* record=FindRecordPointerByKey(state->element,1);
        if (record) record->flags &= ~8;
    }
}
