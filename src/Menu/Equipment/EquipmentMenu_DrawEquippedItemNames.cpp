#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
ARM
extern "C" {
unsigned int TextContext_GetSharedInstance();
unsigned Field_GetSharedSubscreenInstance(void* self);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
void* GameObject_GetLinkedStatsOrNull(char* p);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void TextLayout_DrawCachedGlyphRun(unsigned,void*,int,int,unsigned,int,int,int,int,int);
extern unsigned char EquipmentMenuDrawEquippedItemNames_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov005 @ 0x0215B0A0; symbol: func_ov005_0215b0a0; size: 0x21C.
// Draws equipped-item member labels with availability and selected-member colors.
extern "C" void EquipmentMenu_DrawEquippedItemNames(unsigned char* p)
{
    unsigned renderer = TextContext_GetSharedInstance();
    GameState* game = GameState::GetInstance();
    char* resources = (char*)GameResources_GetInstance();
    char* object = (char*)Field_GetSharedSubscreenInstance(*(void**)(resources + 0x3708));
    GameObject* actor = GameState_GetObjectWithFlag100(game, *(int*)(object + 0x4fc));
    if (!actor) return;
    short* values = (short*)GameObject_GetLinkedStatsOrNull((char*)actor);
    volatile unsigned* port = (volatile unsigned*)0x04000444;
    int y = 28;
    if (p[0x3db8] == 0) {
        for (int i = 0; i < 8; i++) {
            unsigned color = ZoneState2754_FindPrimaryRecordByKey(
                *(ZoneState2754**)(p + 0xdf4),
                values[EquipmentMenuDrawEquippedItemNames_UnknownRoleInitializedBytes[i]]) ? 0x7fff : 0x3def;
            if (i == p[0x3dbc]) color = 0xf0a;
            int row = i * 24;
            if (*(unsigned char*)((p + i) + 0x4284)) row -= 5;
            port[0] = 0;
            port[47] = 1;
            port[11] = 0;
            port[11] = 0;
            port[11] = 0xffc01000;
            TextLayout_DrawCachedGlyphRun(renderer, p + 0x3e84 + i * 128, 160, row + 6, color, 10, 0, 0, 0, 9);
            *(volatile unsigned*)0x04000504 = 0;
            *(volatile unsigned*)0x04000448 = 1;
        }
    } else {
        unsigned color = ZoneState2754_FindPrimaryRecordByKey(
            *(ZoneState2754**)(p + 0xdf4),
            values[EquipmentMenuDrawEquippedItemNames_UnknownRoleInitializedBytes[p[0x3dbc]]]) ? 0x7fff : 0x3def;
        if (p[0x3db8] == 3) color = 0xf0a;
        if (*(unsigned char*)((p + p[0x3dbc]) + 0x4284)) y -= 5;
        port[0] = 0;
        port[47] = 1;
        port[11] = 0;
        port[11] = 0;
        port[11] = 0xffc01000;
        TextLayout_DrawCachedGlyphRun(renderer, p + 0x3e84 + p[0x3dbc] * 128, 160, y, color, 10, 0, 0, 0, 9);
        *(volatile unsigned*)0x04000504 = 0;
        *(volatile unsigned*)0x04000448 = 1;
    }
}
