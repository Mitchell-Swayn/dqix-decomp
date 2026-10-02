#include "TextOwner.h"
extern "C" {
void* func_020d6c00();
void func_020466f4(void*, int);
void func_ov023_021e4f18(void*);
void* func_020421a0();
void func_02045cac();
void func_02043204(void*);
void func_02043124(void*);
void func_0205a494(void*);
void func_0203bd14();
void func_0203c4c4();
void func_0204b010(void*, int);
void func_0204b04c(void*, int);
void func_0204b088(void*, int);
void func_0204afb4(void*);
void func_0205d048(void*);
}

extern "C" void func_ov009_02184848(TextOwner* owner)
{
    if (owner->mode == 1) func_020466f4(func_020d6c00(), 15);
    func_ov023_021e4f18(owner->handles[0]);
    func_ov023_021e4f18(owner->handles[1]);
    void* manager = func_020421a0();
    func_02045cac();
    func_02043204(manager);
    func_02043124(manager);
    if (owner->buffers[0]) func_0205a494(owner->buffers[0]);
    if (owner->buffers[3]) func_0205a494(owner->buffers[3]);
    func_0203bd14();
    func_0203c4c4();
    void* widgets[] = { owner->widgets[0], owner->widgets[1], owner->widgets[2],
                        owner->widgets[3], owner->widgets[4], owner->widgets[5] };
    for (int i = 0; i < 6; ++i) {
        void* widget = widgets[i];
        func_0204b010(widget, 0);
        func_0204b04c(widget, 0);
        func_0204b088(widget, 0);
        func_0204afb4(widget);
    }
    func_0205d048(owner->controllers[0]);
    func_0205d048(owner->controllers[1]);
    owner->unknown_f8 = 0;
    owner->unknown_7d0 = 0;
    owner->unknown_7d4 = 0;
    if (owner->pairArenas) {
        owner->pairArenas[0].Destroy();
        owner->pairArenas[1].Destroy();
    }
    if (owner->auxiliaryArena) owner->auxiliaryArena->Destroy();
    SafeAllocator* arenas[10] = {0};
    arenas[0] = &owner->arenas[8];
    arenas[1] = &owner->arenas[7];
    arenas[2] = &owner->arenas[6];
    arenas[3] = &owner->arenas[5];
    arenas[4] = &owner->arenas[4];
    arenas[5] = &owner->arenas[3];
    arenas[6] = &owner->arenas[2];
    arenas[7] = &owner->arenas[1];
    arenas[8] = &owner->arenas[0];
    for (int i = 0; arenas[i]; ++i)
        if (arenas[i]->GetSignedAllocator()) arenas[i]->Destroy();
}
