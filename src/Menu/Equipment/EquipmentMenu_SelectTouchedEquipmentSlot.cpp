#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
ARM
struct Words3;
struct S;
struct Object;
struct GridSelection;
extern "C" {
GameResources* GameResources_GetInstance();
unsigned Field_GetSharedSubscreenInstance(void* self);
void* GameState_ReadUnknownB0(GameState* state);
void *Menu_GetActiveCharacterPreviewObject(void *self);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*, const Words3 *input, int *out1, int *out2);
int GameState_IsObjectAssociatedWithProtagonistWhenConnected(void* unused, int index);
int EquipmentMenu_HitTestInventoryGrid(void* unused, int x, int y);
int GameObject_GetLinkedStatOrInvalid(char* p, int i);
int SwitchIndexedStateAndSavePreviousPhase(Object* p, int index, int silent);
void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char* p, unsigned char mode);
void EquipmentMenu_SetCursorForDisplayMode(char* self, unsigned mode, int index);
void EquipmentMenu_RefreshInventoryPage(unsigned char *p);
void* GameState_GetIndexList(GameState* state);
unsigned int Inventory_GetGroupItemIds(S* p, unsigned int i);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection *selection, int index);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
// Original data: arm9/ov005 @ 0x215cc84; symbol: data_ov005_0215cc84.
extern Vector3fix EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov005 @ 0x215cc14; symbol: data_ov005_0215cc14.
extern signed char EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes[];
// Original data: arm9/ov005 @ 0x215cd58; symbol: data_ov005_0215cd58.
extern unsigned char EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/ov005 @ 0x215cd50; symbol: data_ov005_0215cd50.
extern unsigned char EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
extern "C" double _dsqrt(double);
#define B(o) (*(unsigned char*)(p+(o)))
#define S8(o) (*(signed char*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x0215690C; symbol: func_ov005_0215690c; size: 0x510.
// Projects eight member points, prefers populated hits, chooses greatest transformed depth, locates entry/page or first empty slot, and starts drag.
extern "C" void EquipmentMenu_SelectTouchedEquipmentSlot(unsigned char* p, int x, int y) {
 GameState* game; void* camera; char* actor; int member;
 game = GameState::GetInstance();
 char* resources = (char*)GameResources_GetInstance();
 char* object = (char*)Field_GetSharedSubscreenInstance(*(void**)(resources + 0x3708));
 member = *(int*)(object + 0x4fc);
 if (!GameState_IsObjectAssociatedWithProtagonistWhenConnected(p, member)) return;
 char* transform = (char*)Menu_GetActiveCharacterPreviewObject(object);
 EquipmentMenu_HitTestInventoryGrid(p, x, y);
 int item = -1; unsigned category = 255;
 if (x > 0 && x < 128) {
  camera = GameState_ReadUnknownB0(game);
  Vector3fix points[8]; int screenX[8], screenY[8];
  Matrix4x3 rotation = RotationMatrixY(*(int*)(transform + 0x54));
  for (int i = 0; i < 8; i++) {
   Mat4x3_ApplyToVector(&EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant2[i], &rotation, &points[i]);
   Graphics_ConvertCopiedWorldVectorToScreenCoordinates(camera, (Words3*)&points[i], &screenX[i], &screenY[i]);
  }
  actor = (char*)GameState_GetObjectWithFlag100(game, member);
  float radii[8]; int hits[8]; int count = 0;
  for (int i = 0; i < 8; i++) {
   radii[i] = 20.0f;
   int dy = y - screenY[i], dx = x - screenX[i];
   if ((float)_dsqrt((double)(dx * dx + dy * dy)) < radii[i]) hits[count++] = i;
  }
  int populated[8];
  if (count > 0) {
   // Screen coordinates are dead here; their slots become populated-count and found-any.
   y = 0; x = 0;
   for (int i = 0; i < count; i++) {
    int point = hits[i];
    if (GameObject_GetLinkedStatOrInvalid(actor, EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes[point]) > 0) {
     populated[y++] = point; x = 1;
    }
   }
   if (x) {
    int point = populated[0]; item = points[point].z;
    for (int i = 1; i < y; i++) {
     int candidate = populated[i]; int depth = points[candidate].z;
     if (item < depth) { point = candidate; item = depth; }
    }
    category = EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant4[point];
    item = GameObject_GetLinkedStatOrInvalid(actor, EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes[point]);
   } else {
    int point = hits[0]; int depth = points[point].z;
    for (int i = 1; i < count; i++) {
     int candidate = hits[i]; int z = points[candidate].z;
     if (depth < z) { point = candidate; depth = z; }
    }
    category = EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant4[point];
    if (B(0x3dbc) != category) {
     SwitchIndexedStateAndSavePreviousPhase((Object*)p, category, 1);
     B(0x3dbb) = 8;
     Grid_ChangeDisplayModeAndTransitionFlags(p, 4);
     EquipmentMenu_SetCursorForDisplayMode((char*)p, B(0x3db8), B(0x3dbb));
     W(0x3dcc) |= 0x100;
     EquipmentMenu_RefreshInventoryPage(p);
     return;
    }
   }
  }
 } else if (x > 132 && x < 157 && y > 22 && y < 45) {
  category = B(0x3dbc);
  item = *(short*)(p + category * 28 + 0x2d90);
 }
 if (item <= 0) return;
 int changed = 0;
 if (B(0x3dbc) != category) {
  changed = 1;
  SwitchIndexedStateAndSavePreviousPhase((Object*)p, category, changed);
  W(0x3dcc) |= 0x100;
 }
 unsigned char* list = (unsigned char*)GameState_GetIndexList(game);
 short* entries = (short*)Inventory_GetGroupItemIds((S*)(list + 0x1d4), EquipmentMenuSelectTouchedEquipmentSlot_UnknownRoleInitializedBytes_Variant3[B(0x3dbc)]);
 int empty = -1, found = -1;
 for (short i = 0; i < *(short*)((p + (B(0x3dbc) << 1)) + 0x3d98); i++) {
  short value = entries[i];
  if (item == value) { found = i; break; }
  if (empty < 0 && value == -1) empty = i;
 }
 if (found < 0) found = empty;
 unsigned char page = found / 16;
 if (S8(0x3dbd) != page) {
  B(0x3dbf) = S8(0x3dbd);
  B(0x3dbd) = page;
  *(signed char*)((p + B(0x3dbc)) + 0x3dfc) = S8(0x3dbd);
  changed = 1;
 }
 if (changed) {
  EquipmentMenu_RefreshInventoryPage(p);
  W(0x3dcc) |= 0x40;
  B(0x3daa) = 0;
 }
 Grid_ChangeDisplayModeAndTransitionFlags(p, 3);
 H(0x3d78) = B(0x3dbc);
 S8(0x3dbb) = H(0x3d78);
 Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p + 0x19f4), H(0x3d78));
 B(0x3dc0) = 1;
 W(0x3dcc) |= 0x80;
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 2, 0);
 *(unsigned short*)(object + 0x634) &= ~1;
 *(unsigned short*)(object + 0x634) &= ~0x80;
 W(0x3dcc) &= ~4;
 W(0x3dcc) &= ~8;
}
