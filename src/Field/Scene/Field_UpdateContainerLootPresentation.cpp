#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct Words3 { int x, y, z; };
typedef unsigned char undefined1;

extern "C" {
unsigned _ZNK9GameState12GetTickCountEv(void*);
unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
int _Z8fix32sini(int);
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
bool Field_HasSpawnedSharedPresentationEffect(void* object);
undefined1 GameObject_GetMovementInputEnabled(int param_1);
void GameObject_RequestMovementInputEnable(int param_1);
void* GameState_GetFieldOrbitCamera(GameState* state);
void Camera_EnableOrbitInput(int param_1);
void GameResources_ClearSecondaryFlags(int self, unsigned int mask);
void* GameState_ReadUnknownB0(GameState* state);
int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*, const Words3* input, int* out1, int* out2);
void Graphics_DrawSelectedResource(char* self, unsigned flags);
unsigned int TextContext_GetSharedInstance();
}

// Original: arm9/ov017 @ 0x021BFC40; symbol: func_ov017_021bfc40; size: 0x220.
// Bobs and draws the container-loot sprite, or restores field input/camera when
// the presentation is finished or a shared overlay effect is already spawned.
extern "C" int Field_UpdateContainerLootPresentation(unsigned char* p)
{
    GameState* game = GameState::GetInstance();
    int ticks = _ZNK9GameState12GetTickCountEv(game);
    GameResources* resources = GameResources_GetInstance();
    if (p[0x48]) {
        GameResources* current = GameResources_GetInstance();
        if (Field_HasSpawnedSharedPresentationEffect(current))
            return 4;
        void* player = _ZN9GameState20GetUnknownGameObjectEv(game);
        if (player && !GameObject_GetMovementInputEnabled((int)player))
            GameObject_RequestMovementInputEnable((int)player);
        void* object = GameState_GetFieldOrbitCamera(game);
        if (object)
            Camera_EnableOrbitInput((int)object);
        if (current)
            GameResources_ClearSecondaryFlags((int)current, 0x80);
        *(short*)(p + 0x16) = 0;
        *(short*)(p + 8) = 0;
        return 6;
    }
    GameState* other = GameState::GetInstance();
    void* camera = GameState_ReadUnknownB0(other);
    Words3 pos = *(Words3*)(p + 0x28);
    if (*(short*)(p + 0x18) < 0x191e)
        *(short*)(p + 0x18) = *(short*)(p + 0x18) + _ZNK9GameState12GetTickCountEv(other) * 0x199;
    pos.y += _Z8fix32sini(*(short*)(p + 0x18));
    int y, x;
    if (camera)
        Graphics_ConvertCopiedWorldVectorToScreenCoordinates(camera, &pos, &x, &y);
    int sx = (x - 12) << 12;
    int sy = (y - 40) << 12;
    char* graphic = *(char**)(p + 0x10);
    *(int*)(graphic + 0x1c) = sx;
    *(int*)(graphic + 0x20) = sy;
    *(int*)(graphic + 0x24) = 0;
    Graphics_DrawSelectedResource(graphic, 1);
    int alpha = *(short*)(p + 0x16);
    if (alpha > 31)
        alpha = 31;
    *(short*)(graphic + 0x82) = alpha;
    unsigned elapsed = _ZNK9GameState21GetEffectiveDeltaTimeEv(game);
    unsigned timer = *(unsigned short*)(p + 8);
    *(unsigned short*)(p + 8) = elapsed < timer ? timer - elapsed : 0;
    if (!*(unsigned short*)(p + 8)) {
        void* player = _ZN9GameState20GetUnknownGameObjectEv(game);
        if (player && !GameObject_GetMovementInputEnabled((int)player))
            GameObject_RequestMovementInputEnable((int)player);
        void* object = GameState_GetFieldOrbitCamera(game);
        if (object)
            Camera_EnableOrbitInput((int)object);
        if (resources)
            GameResources_ClearSecondaryFlags((int)resources, 0x80);
    }
    TextContext_GetSharedInstance();
    if (ticks < *(short*)(p + 0x16)) {
        *(short*)(p + 0x16) -= ticks;
    } else {
        *(short*)(p + 0x16) = 0;
        *(short*)(p + 8) = 300;
        return 6;
    }
    return 4;
}
