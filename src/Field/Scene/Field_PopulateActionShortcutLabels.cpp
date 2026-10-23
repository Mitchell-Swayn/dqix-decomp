#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct ShortcutShorts { short values[4]; };
struct ShortcutBytes { unsigned char values[4]; };
struct ShortcutWords { unsigned values[7]; };
struct ShortcutWindow {
    char unknown0[0xa0]; short x,paddingX,y,width,paddingY,paddingBottom,valueA,valueB;
    unsigned char unknownB0,category,unknownB2[3],enabled;
};
extern "C" {
// Original data: arm9/ov017 @ 0x021D6458, 0x021D6450, 0x021D6448, 0x021D6444, 0x021D6484.
// Four shortcut layout arrays and seven assignment keys; extents follow the recorded copies.
extern ShortcutShorts FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant4;
extern ShortcutShorts FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant3;
extern ShortcutShorts FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant2;
extern ShortcutBytes FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes;
extern ShortcutWords FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant5;
void __clear(void*,unsigned);
int GameState_GetActionShortcutAssignment(GameObject*,unsigned);
void Field_AppendActionShortcutLabel(void*,char*,unsigned,int);
void Window_PushTextCanvas(ShortcutWindow*,const char*,int,int,int,int,int,int);
void Window_UpdateCanvasesAndSelection(ShortcutWindow*,unsigned);
void Field_ClearActionShortcutCanvasStatus(void*,int);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0219A388; symbol: func_ov017_0219a388; size: 0x1BC.
// Applies four shortcut layouts and resolves the protagonist's action labels into text canvases.
extern "C" void Field_PopulateActionShortcutLabels(char* self) {
    GameState* game=GameState::GetInstance();
    GameObject* protagonist=game->GetProtagonist();
    ShortcutShorts x=FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant4;
    ShortcutShorts y=FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant3;
    ShortcutShorts width=FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant2;
    ShortcutBytes category=FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes;
    ShortcutWords keys=FieldPopulateActionShortcutLabels_UnknownRoleInitializedBytes_Variant5;
    char text[128];
    ShortcutWindow* window=*(ShortcutWindow**)(self+0x3cb0);
    for(int i=0;i<4;++i) {
        window->x=x.values[i]; window->paddingX=2;
        window->y=y.values[i]; window->width=width.values[i];
        window->paddingY=2;window->paddingBottom=2;window->valueA=10;window->valueB=11;
        unsigned char type=category.values[i];window->category=type;window->enabled=1;
        __clear(text,128);
        Field_AppendActionShortcutLabel(self,text,type,(signed char)GameState_GetActionShortcutAssignment(protagonist,keys.values[i]));
        Window_PushTextCanvas(window,text,0,0,0,1,0,0);
        Window_UpdateCanvasesAndSelection(window,game->GetTickCount());
    }
    Field_ClearActionShortcutCanvasStatus(self,255);
}
#pragma force_active off
