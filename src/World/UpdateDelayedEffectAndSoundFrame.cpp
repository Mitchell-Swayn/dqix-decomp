#include <globaldefs.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

struct EffectRecord : Object3D {
    int alternateUpdate;
    short delay, effectId, soundId, lifetime;
    int sound, soundFrame;
    Vector3fix velocity;
    unsigned char flagsLow : 4;
    unsigned char input0 : 1;
    unsigned char input1 : 1;
    unsigned char flagsHigh : 2;
    unsigned char padding[7];
};
struct InputFlags { unsigned char padding[0x130]; unsigned int flags; };
extern "C" {
InputFlags* GameState_GetFieldVisualObject(GameState*);
InputFlags* GameState_GetAuxiliaryFieldObject(GameState*);
void GameState_ClearObjectByIndex(GameState*, int);
void ObjectPool_ResetDisplayEntry(EffectRecord*);
void Object3D_CopyPosition(EffectRecord*, const Vector3fix*);
int EffectEmitter_TestCompletionIncludingChildren(void*);
void ResourceTracks_AdvanceBoundPlayback(EffectRecord*);
void SoundSfx_StartCurrentSequenceArchiveEntry(void*, int, int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/main @ 0x02059CFC; symbol: func_02059cfc; size: 0x23C.
extern "C" void UpdateDelayedEffectAndSoundFrame(EffectRecord* effect, int ticks, int index) {
    GameState* state = GameState::GetInstance();
    if (effect->delay > 0) {
        effect->delay -= ticks;
    } else if (!effect->alternateUpdate) {
        if (state->GetGameObjectByIndex(index)) {
            if (effect->sound > 0 && effect->prevFrameNormalizedAnimationTime_ <= effect->soundFrame && effect->soundFrame < effect->normalizedAnimationTime_)
                SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, effect->sound, 0);
            Vector3fix position = effect->position_;
            unsigned int flags = 0;
            if (effect->input0) {
                InputFlags* input = GameState_GetFieldVisualObject(state);
                if (input) flags = input->flags;
            } else if (effect->input1) {
                InputFlags* input = GameState_GetAuxiliaryFieldObject(state);
                if (input) flags = input->flags;
            }
            if ((effect->input0) || (effect->input1)) {
                if ((flags & 1) && position.x > 0) position.x -= 0x120000;
                else if ((flags & 2) && position.x < 0) position.x += 0x120000;
                if ((flags & 4) && position.z > 0) position.z -= 0xe0000;
                else if ((flags & 8) && position.z < 0) position.z += 0xe0000;
            }
            Vector3fix delta;
            Vector3fixMultiplyScalar(&effect->velocity, ticks << 12, &delta);
            Vector3fix_Add(&position, &delta, &position);
            Object3D_CopyPosition(effect, &position);
            effect->AdvanceEffects();
            if ((effect->animationFlags_ & 1) && effect->HasAnimationStopped()) {
                GameState_ClearObjectByIndex(state, index);
                ObjectPool_ResetDisplayEntry(effect);
            }
            if (effect->lifetime > 0) {
                effect->lifetime -= ticks;
                if (effect->lifetime <= 0) {
                    GameState_ClearObjectByIndex(state, index);
                    ObjectPool_ResetDisplayEntry(effect);
                }
            }
        }
    } else if (state->GetGameObjectByIndex(index)) {
        if (EffectEmitter_TestCompletionIncludingChildren(*(void**)((unsigned char*)effect + 4)) == 1) {
            GameState_ClearObjectByIndex(state, index);
            ObjectPool_ResetDisplayEntry(effect);
        } else ResourceTracks_AdvanceBoundPlayback(effect);
    }
}
