#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct State;
struct GridSelection;
extern "C" {
int TextCanvas_HasActiveTilemap(char* p);
void TextCanvas_AdvanceDisplayAndFillTileIndices(void* object);
void Memory_CopyConstantBlock16(void *, void *dest);
void Window_PopCanvasesAndResetSelection(State* p, int flag);
void Selection_EnableDirectionalInput(int);
void Selection_EnableTouchInput(int);
void Selection_SetTwoGridDimensionsAndEntryCounts(char* p, int width, int height, int value);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection *selection, int index);
void Window_SetEnabledSelectionIndices(unsigned char* p, int index);
unsigned int TextContext_GetSharedInstance();
void BattleMenu_AppendPartyCommandOptions(char* owner, char* output);
int Window_PushTextCanvas(...);
void BattleMenu_RepositionCommandWindowsAroundActor(void*);
}
// Original: arm9/ov000 @ 0x02177184; symbol: func_ov000_02177184; size: 0x1AC.
// Opens the party command panel, copying four command slots, configuring the selection grid, and pushing command text.
extern "C" void BattleMenu_OpenPartyCommandPanel(char* self, int ready) {
 if (!ready) return;
 char* panel = self + 0x188;
 char* canvas = *(char**)(panel + 0x9c);
 if (TextCanvas_HasActiveTilemap(canvas)) {
  TextCanvas_AdvanceDisplayAndFillTileIndices(canvas);
  *(unsigned short*)(self + 0x1d72) &= ~2;
  return;
 }
 int slots[4];
 Memory_CopyConstantBlock16(self, slots);
 int count = 0;
 for (int i = 0; i < 4; i++) if (slots[i] >= 0) count++;
 self[0x1d69] = 0;
 Window_PopCanvasesAndResetSelection((State*)panel, 1);
 Selection_EnableDirectionalInput((int)panel);
 Selection_EnableTouchInput((int)panel);
 Selection_SetTwoGridDimensionsAndEntryCounts(panel, 1, count, 0);
 *(int*)(panel + 0x58) = 1;
 Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(panel + 0x54), 0);
 if (count == 3) {
  *(unsigned short*)(panel + 0xa0) = 8;
  *(unsigned short*)(panel + 0xa2) = 6;
 }
 if (count == 4) {
  *(unsigned short*)(panel + 0xa0) = 8;
  *(unsigned short*)(panel + 0xa2) = 1;
 }
 *(unsigned short*)(panel + 0xa4) = 9;
 *(unsigned short*)(panel + 0xa6) = 1;
 if (count == 3) {
  *(unsigned short*)(panel + 0xa8) = 0xc;
  *(unsigned short*)(panel + 0xaa) = 8;
 }
 if (count == 4) {
  *(unsigned short*)(panel + 0xa8) = 0xc;
  *(unsigned short*)(panel + 0xaa) = 4;
 }
 *(unsigned short*)(panel + 0xac) = 0xa;
 *(unsigned short*)(panel + 0xae) = 0xb;
 panel[0xb1] = 1;
 Window_SetEnabledSelectionIndices((unsigned char*)panel, *(signed char*)(self + 0x1d69));
 char* text = *(char**)((char*)TextContext_GetSharedInstance() + 0x5c);
 memset(text, 0, 0x960);
 BattleMenu_AppendPartyCommandOptions(self, text);
 Window_PushTextCanvas(panel, text, 0, 1, 0, 1, 0, 0);
 BattleMenu_RepositionCommandWindowsAroundActor(self);
}
