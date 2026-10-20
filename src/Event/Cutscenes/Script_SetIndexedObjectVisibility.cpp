#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original: arm9/ov001 @ 0x0215BD5C; symbol: func_ov001_0215bd5c; size: 0x74.
// Shows or hides the indexed game object; omitted visibility parameters default to visible.
extern "C" int Script_SetIndexedObjectVisibility(char* parameters, int count) {
    GameState* game = GameState::GetInstance();
    if (!game) return 0;
    int visible = 1;
    int index = Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
    if (count >= 2) visible = Script_ReadParameterAsInteger((IntegerParameterView*)(parameters + 8));
    GameObject* object = game->GetGameObjectByIndex(index);
    if (!object) return 0;
    if (visible) object->obj3D_.MakeVisible();
    else object->obj3D_.MakeHidden();
    return 1;
}
