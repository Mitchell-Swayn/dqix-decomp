#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

struct MenuResourceState {
    void* owner;
    unsigned char* view;
    SafeAllocator* allocators;
    unsigned char unknown0c[8];
    void* buffer;
    unsigned int bufferSize;
    unsigned char kind;
    unsigned char unknown1d[3];
    int* ids;
    Object3D* objects;
    void* auxiliary;
};
struct PairedResourceSizes { unsigned int sizes[11][2]; };
struct ResourceSizes { unsigned int sizes[7]; };

extern "C" {
extern PairedResourceSizes data_ov015_02193df0;
extern ResourceSizes data_ov015_02193d80;
extern AllocatorUnion data_02114e20;
void* func_02012d88(AllocatorUnion*, unsigned int);
void func_ov015_0218f0c4(MenuResourceState*);
unsigned char* func_ov015_021931f8(void*);
unsigned char* func_ov015_0219322c(void*);
unsigned char* func_ov015_02193260(void*);
void func_0205563c(void*);

int func_ov015_0218bcb0(MenuResourceState* state)
{
    if (state->kind == 0 || state->kind == 1) {
        PairedResourceSizes sizes = data_ov015_02193df0;
        state->allocators = (SafeAllocator*)func_02012d88(&data_02114e20, 200);
        if (!state->allocators) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        state->objects = (Object3D*)func_02012d88(&data_02114e20, 0x6b8);
        if (!state->objects) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        for (int i = 0; i < 10; i++) {
            state->allocators[i].ResetAllocatorPointer();
            void* buffer = func_02012d88(&data_02114e20, sizes.sizes[i][state->kind]);
            if (!buffer) return 0;
            state->allocators[i].CreateTypeA(buffer, sizes.sizes[i][state->kind]);
            state->allocators[i].Reset();
            state->objects[i].Initialize();
        }
        state->ids = (int*)func_02012d88(&data_02114e20, 40);
        if (!state->ids) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        memset(state->ids, -1, 40);
        state->ids[0] = 0x32cf;
        state->ids[1] = 0x3f57;
        state->ids[2] = 0x233c;
        state->ids[3] = 0x2328;
        state->ids[4] = 0x2328;
        state->ids[5] = 0x36b7;
        state->ids[6] = 0x42e0;
        if (state->kind == 0) state->view = func_ov015_021931f8(state->owner);
        else state->view = func_ov015_0219322c(state->owner);
        if (!state->view) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        state->view[4] = 1;
        state->bufferSize = sizes.sizes[10][state->kind];
        state->buffer = func_02012d88(&data_02114e20, state->bufferSize);
        if (!state->buffer) {
            func_ov015_0218f0c4(state);
            return 0;
        }
    } else {
        ResourceSizes sizes = data_ov015_02193d80;
        state->allocators = (SafeAllocator*)func_02012d88(&data_02114e20, 20);
        if (!state->allocators) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        state->allocators->ResetAllocatorPointer();
        void* buffer = func_02012d88(&data_02114e20, sizes.sizes[state->kind]);
        if (!buffer) return 0;
        state->allocators->CreateTypeA(buffer, sizes.sizes[state->kind]);
        state->allocators->Reset();
        state->view = func_ov015_02193260(state->owner);
        if (!state->view) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        state->view[4] = 1;
        if (state->kind == 2 || state->kind == 3) {
            state->bufferSize = 0xc000;
            state->buffer = func_02012d88(&data_02114e20, state->bufferSize);
            if (!state->buffer) {
                func_ov015_0218f0c4(state);
                return 0;
            }
        }
        state->objects = (Object3D*)func_02012d88(&data_02114e20, 0xac);
        if (!state->objects) {
            func_ov015_0218f0c4(state);
            return 0;
        }
        state->objects->Initialize();
        if (state->kind == 4) {
            state->auxiliary = func_02012d88(&data_02114e20, 0x1c);
            if (!state->auxiliary) {
                func_ov015_0218f0c4(state);
                return 0;
            }
            func_0205563c(state->auxiliary);
        }
    }
    return 1;
}
}
