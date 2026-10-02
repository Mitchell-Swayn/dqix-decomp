#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C"
{
    void* func_0202ae18();
    void* func_02010828(GameState*);
    bool func_02046b08(void*);
    bool func_0203b5f8(GameResources*, int);
    void func_ov017_021a9bc4(void*, int);
    void func_ov017_021a9a9c(void*, int, int, int, int);
    void func_020469b4(void*, void*);
    void func_020d9850(void*);
    void func_020ae53c(int);
    bool func_0202b7d8(void*);
    bool func_02086b98(void*);
    void func_ov017_021aa4cc(GameResources*, int);
}

void Zone3D::ProcessTransitionRequests()
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    void* controller = resources->unknown_ptr_array_36fc[0];
    void* context = func_0202ae18();
    void* gameContext = func_02010828(game);
    if (!func_02046b08(controller)) return;
    if (!func_0203b5f8(resources, 0)) return;
    if (!func_0203b5f8(resources, 1)) return;
    // Requests have priority in bit order and only their own bit is consumed.
    if (transitionRequests_ & 1)
    {
        game->GetGrottoStruct()->unknown_9 = 2;
        void* target = resources->unknown_ptr_array_3afc[27];
        func_ov017_021a9bc4(target, 0);
        func_ov017_021a9a9c(target, transitionParameter1_, transitionParameter2_, transitionParameter3_, 0);
        func_020469b4(controller, target);
        transitionRequests_ &= ~1;
        return;
    }
    if (transitionRequests_ & 2)
    {
        void* target = resources->unknown_ptr_array_3afc[47];
        func_020d9850(target);
        func_020469b4(controller, target);
        transitionRequests_ &= ~2;
        return;
    }
    if (transitionRequests_ & 4)
    {
        func_020ae53c(0);
        transitionRequests_ &= ~4;
        return;
    }
    if (func_0202b7d8(context))
    {
        if (func_02086b98(gameContext) || (transitionRequests_ & 8))
            func_ov017_021aa4cc(resources, 1);
    }
    transitionRequests_ = 0;
}
