#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
ARM
struct Grid;
struct Owner;
struct ThreeWords { unsigned first, second, third; };
struct StateRecord;
extern "C" {
unsigned int ReadSelectedCoordinatePair(const StateRecord* state, unsigned int* first, unsigned int* second);
unsigned EquipmentMenu_PickProjectedEquipmentSlot(void* unused, int x, int y);
int Grid_UpdateDirectionalSelection(Grid* self, int ticks);
int Grid_ComputeSelectedLinearIndex(int* p);
int EquipmentMenu_IsConfirmPressed(void* unused);
unsigned Field_GetSharedSubscreenInstance(void* self);
void World_SetRecordStateAndDispatchMode(void* self, unsigned char value, int mode);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
void EquipmentMenu_RefreshInventoryPage(unsigned char* p);
void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char* p, unsigned char mode);
void EquipmentMenu_CopyRenderPartPosition(Owner* self, const ThreeWords* value);
// Original data: arm9/main @ 0x2114e54; symbol: Main_UnknownRoleZeroInitializedStorage_Variant4.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}
#define B(o) (*(unsigned char*)(p + (o)))
#define S(o) (*(signed char*)(p + (o)))
#define H(o) (*(short*)(p + (o)))
#define W(o) (*(unsigned*)(p + (o)))
// Original: arm9/ov005 @ 0x0215B2BC; symbol: func_ov005_0215b2bc; size: 0x264.
// Updates overview slot selection from projected touch, header rows, or the directional grid.
extern "C" void EquipmentMenu_UpdateOverviewSelection(unsigned char* p)
{
    if (B(0x3dba) == 0) {
        if (!IsBrightnessTransitionActive(GameResources_GetInstance()))
            ++B(0x3dba);
    } else if (B(0x3dba) == 1) {
        int changed = 0, confirm = 0;
        unsigned index = 255;
        int touch = 0;
        unsigned int x, y;
        if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
            touch = 1;
            ReadSelectedCoordinatePair((const StateRecord*)Main_UnknownRoleZeroInitializedStorage_Variant4, &x, &y);
            index = EquipmentMenu_PickProjectedEquipmentSlot(p, x, y);
            if (index != 255) {
                changed = touch;
                confirm = changed;
            } else if ((int)x > 128) {
                for (int i = 0; i < 8; i++) {
                    int top = i * 24;
                    int bottom = top + 24;
                    if ((int)y > top && (int)y < bottom) {
                        changed = 1;
                        confirm = changed;
                        index = (unsigned char)i;
                        break;
                    }
                }
            }
        }
        if (!touch) {
            changed = 1;
            unsigned ticks = GameState::GetInstance()->GetTickCount();
            if (!ticks) ticks = 1;
            Grid_UpdateDirectionalSelection((Grid*)(p + 0x19f4), ticks);
            index = (unsigned char)Grid_ComputeSelectedLinearIndex((int*)(p + 0x19f4));
            if (EquipmentMenu_IsConfirmPressed(p)) confirm = 1;
        }
        if (changed && B(0x3dbc) != index) {
            B(0x3dbe) = B(0x3dbc);
            B(0x3dbf) = S(0x3dbd);
            *(signed char*)((p + B(0x3dbc)) + 0x3dfc) = S(0x3dbd);
            S(0x3dbc) = index;
            B(0x3dbd) = *(unsigned char*)((p + (unsigned char)index) + 0x3dfc);
        }
        B(0x3dbb) = B(0x3dbc);
        char* res = (char*)GameResources_GetInstance();
        char* obj = (char*)Field_GetSharedSubscreenInstance(*(void**)(res + 0x3708));
        ((void (*)(void*, int, int))World_SetRecordStateAndDispatchMode)(p, *(int*)(obj + 0x4fc), 0);
        if (confirm) {
            SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 1, 0);
            EquipmentMenu_RefreshInventoryPage(p);
            W(0x3dcc) |= 0x40;
            B(0x3daa) = 0;
            Grid_ChangeDisplayModeAndTransitionFlags(p, 1);
            for (int i = 0; i < 8; i++) {
                char* row = (char*)p + 0x2d90 + i * 28;
                if (i == H(0x3d78)) continue;
                if (*(short*)row < 0) continue;
                char* owner = *(char**)(row + 8);
                ThreeWords position = *(ThreeWords*)(owner + 28);
                position.second = 0x17000;
                EquipmentMenu_CopyRenderPartPosition((Owner*)owner, &position);
            }
        }
    }
}
