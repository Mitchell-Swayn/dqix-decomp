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
InputFlags* ReadSignedWordField32C(GameState*);
InputFlags* Object_ReadWordAtOffset330(GameState*);
void GameState_ClearObjectByIndex(GameState*, int);
void Object_ClearD4ByteDisplayEntryAndSetDefaults(EffectRecord*);
void CopyThreeWordsToVectorAt44(EffectRecord*, const Vector3fix*);
int TestNodeAndChildrenWithinLimits(void*);
void InvokePresentOwnerHandle(EffectRecord*);
void DispatchStoredHalfwordIndexWithTwoArguments(void*, int, int);
extern unsigned char data_02108760[];
}
// Original: arm9/main @ 0x02059CFC; symbol: func_02059cfc; size: 0x23C.
extern "C" void UpdateDelayedEffectAndSoundFrame(EffectRecord* effect, int ticks, int index) {
    GameState* state = GameState::GetInstance();
    if (effect->delay > 0) {
        effect->delay -= ticks;
    } else if (!effect->alternateUpdate) {
        if (state->GetGameObjectByIndex(index)) {
            if (effect->sound > 0 && effect->prevFrameNormalizedAnimationTime_ <= effect->soundFrame && effect->soundFrame < effect->normalizedAnimationTime_)
                DispatchStoredHalfwordIndexWithTwoArguments(data_02108760, effect->sound, 0);
            Vector3fix position = effect->position_;
            unsigned int flags = 0;
            if (effect->input0) {
                InputFlags* input = ReadSignedWordField32C(state);
                if (input) flags = input->flags;
            } else if (effect->input1) {
                InputFlags* input = Object_ReadWordAtOffset330(state);
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
            CopyThreeWordsToVectorAt44(effect, &position);
            effect->AdvanceEffects();
            if ((effect->animationFlags_ & 1) && effect->HasAnimationStopped()) {
                GameState_ClearObjectByIndex(state, index);
                Object_ClearD4ByteDisplayEntryAndSetDefaults(effect);
            }
            if (effect->lifetime > 0) {
                effect->lifetime -= ticks;
                if (effect->lifetime <= 0) {
                    GameState_ClearObjectByIndex(state, index);
                    Object_ClearD4ByteDisplayEntryAndSetDefaults(effect);
                }
            }
        }
    } else if (state->GetGameObjectByIndex(index)) {
        if (TestNodeAndChildrenWithinLimits(*(void**)((unsigned char*)effect + 4)) == 1) {
            GameState_ClearObjectByIndex(state, index);
            Object_ClearD4ByteDisplayEntryAndSetDefaults(effect);
        } else InvokePresentOwnerHandle(effect);
    }
}
