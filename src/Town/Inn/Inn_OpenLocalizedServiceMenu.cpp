struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Record { char pad[0xc4]; unsigned char id; char rest[0x1b]; };
struct Owner { char pad[0x98]; void* ready; Record* records; char pad2[0x13]; unsigned char count,stop; };
struct SelectedRecord {
    unsigned char pad00[8];
    int selectionState;
    unsigned char pad0c[0x4c];
    int value58;
    unsigned char pad5c[0x38];
    unsigned char state94;
    unsigned char state95;
    unsigned char pad96[0x0a];
    short languageWidth;
    short rowCount;
    short rightInset;
    short orientation;
    short selectedId;
    short top;
    short width;
    short height;
    unsigned char padb0;
    unsigned char stateb1;
    unsigned char padb2[3];
    unsigned char flagsb5;
};
struct ReadyRecord {
    unsigned char pad00[0xa8];
    short sourceWidth;
    short padAA;
    short targetWidth;
    short sourceHeight;
};
extern "C" {
void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
ARM void Selection_EnableTouchInput(int);
void* _ZN9GameState11GetInstanceEv();
unsigned int GameState_ReadSupportedFirmwareLanguage(GameState*);
// Original data: arm9/ov003 @ 0x217f560; symbol: data_ov003_0217f560.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0c000f0011000d0013000f00.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern short InnOpenLocalizedServiceMenu_UnknownRoleInitializedBytes[];
void* __clear(void*,unsigned);
int Selection_ReadEnabledIndexFromControl(void*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
int Text_AppendFormatString(char*,const char*);
void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
void Grid_SetEntryCountAndClampSelection(int*,int);
}
// Original: arm9/ov003 @ 0x0216DA90; symbol: func_ov003_0216da90; size: 0x1C8.
// Initializes a language-sized selected record, formats its label, checks readiness, and configures its paired grids.
extern "C" void Inn_OpenLocalizedServiceMenu(unsigned char* self) {
    SelectedRecord* record = *(SelectedRecord**)(self + 0x12c0);
    Window_BindNextCanvasResourceByFormatAndLayer((char*)record,0,1);
    ((SelectedRecord*)*(unsigned char**)(self + 0x12c0))->stateb1 = 0;
    record = *(SelectedRecord**)(self + 0x12c0);
    record->selectedId = 13;
    record->top = 5;
    record = *(SelectedRecord**)(self + 0x12c0);
    record->width = 10;
    record->height = 12;
    ((SelectedRecord*)*(unsigned char**)(self + 0x12c0))->flagsb5 = 1;
    record = *(SelectedRecord**)(self + 0x12c0);
    Selection_EnableTouchInput((int)record);
    GameState* game = (GameState*)_ZN9GameState11GetInstanceEv();
    int language = GameState_ReadSupportedFirmwareLanguage(game);
    short languageWidth = InnOpenLocalizedServiceMenu_UnknownRoleInitializedBytes[language];
    record = *(SelectedRecord**)(self + 0x12c0);
    record->languageWidth = languageWidth;
    record->rowCount = 7;
    record = *(SelectedRecord**)(self + 0x12c0);
    record->rightInset = (short)(0x1f - languageWidth);
    record->orientation = 1;
    char formatted[0x100];
    char scratch[0x40];
    __clear(formatted,0x100);
    __clear(scratch,0x40);
    if (*(int*)(self + 0x10) == 2) {
        int selected = Selection_ReadEnabledIndexFromControl(*(unsigned char**)(self + 0x12c0));
        TextMarkup_AppendFrameTag(formatted,selected,8,5,5,5);
    }
    const char* suffix = (const char*)ResourceStringTable_GetTextByKey(self + 0x1324,(void*)0x5c);
    Text_AppendFormatString(formatted,suffix);
    Window_PushTextCanvas(*(unsigned char**)(self + 0x12c0),formatted,0,0,0,1,0,0);
    Record* readyRecord = (Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)*(unsigned char**)(self + 0x12c0)),0);
    ReadyRecord* ready = (ReadyRecord*)readyRecord;
    if (ready) {
        short sourceWidth = ready->sourceWidth;
        short sourceHeight = *(volatile short*)((unsigned char*)ready + 0xae);
        ready->targetWidth = (short)(0x1f - sourceWidth);
        *(volatile short*)((unsigned char*)ready + 0xae) = sourceHeight;
    }
    record = *(SelectedRecord**)(self + 0x12c0);
    record->selectionState = 1;
    record->value58 = 1;
    Grid_SetOrientationAndCoordinatePointers((unsigned char*)record + 4,1,4,0);
    Grid_SetOrientationAndCoordinatePointers((unsigned char*)record + 0x54,1,4,0);
    Grid_SetEntryCountAndClampSelection((int*)((unsigned char*)record + 4),4);
    Grid_SetEntryCountAndClampSelection((int*)((unsigned char*)record + 0x54),4);
    record->state94 = 1;
    record->state95 = 1;
}
