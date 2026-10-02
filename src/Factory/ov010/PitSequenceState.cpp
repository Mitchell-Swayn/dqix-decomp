#include "PitSequenceState.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct PitEffectManager;

extern "C" {
    void func_020727d8(PitTextTable* table);
    PitEffectManager* func_02057924();
    void func_02057f00(PitEffectManager* manager, int resourceID);
    void func_02012da4(AllocatorUnion* allocator, void* allocation);
    void func_020397c0(GameObject* object);
    extern AllocatorUnion data_02114e20;
}

void func_ov010_021842a0(PitSequenceState* state)
{
    state->phase_ = 0;
    state->delay_ = 0;
    state->loadTask_ = -1;
    func_020727d8(&state->text_);
    state->allocator_.ResetAllocatorPointer();
    state->effectEnabled_ = 0;
}

void func_ov010_021842d8(PitSequenceState* state)
{
    func_02057f00(func_02057924(), 17);
    SignedAllocatorHeader* allocation = state->allocator_.GetSignedAllocator();
    if (allocation) {
        state->allocator_.Destroy();
        func_02012da4(&data_02114e20, allocation);
    }
    if (state->loadTask_ >= 0) {
        BackgroundLoader::GetInstance()->RemoveTask(state->loadTask_);
        state->loadTask_ = -1;
    }
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    if (object) {
        func_020397c0(object);
    }
    func_ov010_021842a0(state);
}
