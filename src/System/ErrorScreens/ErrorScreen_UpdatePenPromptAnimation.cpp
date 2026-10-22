#include <globaldefs.h>
#include <GameState/GameState.h>
struct MenuAnimationRecord { unsigned char pad[4]; short x,y; unsigned char pad2[13]; unsigned char flags; };
struct Overlay19State { unsigned char pad[76]; unsigned flags; unsigned pad2; unsigned char animation[60]; void* element; };
extern "C" {
void SpriteAnimation_StartTrack(void*, unsigned);
MenuAnimationRecord* SpriteAnimation_FindTrackByKey(void*,int);
void SpriteAnimation_AdvanceAllTracks(void*,unsigned);
void SpriteAnimation_SetTrackOamStartIndex(void*,int,int);
void SpriteAnimation_SubmitAllTrackFrames(void*);
}
// Original: arm9/ov019 @ 0x0218C178; symbol: func_ov019_0218c178; size: 0xC8.
extern "C" void ErrorScreen_UpdatePenPromptAnimation(Overlay19State* state) {
    GameState* game=GameState::GetInstance();
    if (state->flags&1) {
        void* element=state->element;
        if (element) {
            SpriteAnimation_StartTrack(element,1);
            MenuAnimationRecord* record=SpriteAnimation_FindTrackByKey(element,1);
            if (record) record->flags |= 8;
            SpriteAnimation_AdvanceAllTracks(element,game->GetTickCount());
            record=SpriteAnimation_FindTrackByKey(element,1);
            if (record) { record->x=215; record->y=150; }
            SpriteAnimation_SetTrackOamStartIndex(element,1,36);
        }
        SpriteAnimation_SubmitAllTrackFrames(state->animation);
    } else if (state->element) {
        MenuAnimationRecord* record=SpriteAnimation_FindTrackByKey(state->element,1);
        if (record) record->flags &= ~8;
    }
}
