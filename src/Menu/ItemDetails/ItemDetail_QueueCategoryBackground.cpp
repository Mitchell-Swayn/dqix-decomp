#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct ZoneState2754;
class BackgroundLoader {
public:
    static BackgroundLoader* GetInstance();
};
extern "C" {
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void* __clear(void* destination, unsigned int count);
unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
void Menu_ResetTimedPointEffects(unsigned char *p, unsigned char value);
int ItemDetail_GetCategoryBackgroundVariant(volatile unsigned int *value);
int ItemDetail_ConfigureCategoryLayout(...);
void ItemDetail_RenderPendingItemName(char* self);
unsigned char ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage[];
const char ItemDetail_QueueCategoryBackground_PathDataAniBgIidcPac[];
const char ItemDetail_QueueCategoryBackground_PathDataAniBgIilistPac[];
const char ItemDetail_QueueCategoryBackground_PathDataAniBglii2DGp2[];
const char ItemDetail_QueueCategoryBackground_FormatBglii2DLGPac[];
const char ItemDetail_QueueCategoryBackground_PathDataAniBgii2DGp2[];
const char ItemDetail_QueueCategoryBackground_FormatBgii2DLGPac[];
}
// Original: arm9/ov023 @ 0x021DFC90; symbol: func_ov023_021dfc90; size: 0x23c.
// Resolves the current item record, then either reapplies the cached category background or queues the matching GP2/PAC load.
extern "C" int ItemDetail_QueueCategoryBackground(unsigned char* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (*(void**)(self + 0x48))
        *(void**)(self + 0x50) = ZoneState2754_FindPrimaryRecordByKey(
            *(ZoneState2754**)(self + 0x48), *(short*)(self + 0x770));
    unsigned char extra = 0;
    if (*(void**)(self + 0x50)) {
        unsigned word = *(unsigned*)((char*)*(void**)(self + 0x50) + 8);
        if (((word << 20) >> 29) == 5)
            extra = 1;
    }
    Menu_ResetTimedPointEffects(ItemDetailDispatchDisplayState_UnknownRoleZeroInitializedStorage, extra);
    int variant = ItemDetail_GetCategoryBackgroundVariant((volatile unsigned int*)*(void**)(self + 0x50));
    if (variant == *(signed char*)(self + 0x779)) {
        *(int*)(self + 0x75c) = 0x3800;
        if (*(signed char*)(self + 0x77b) == 1)
            *(int*)(self + 0x75c) = 0x2800;
        *(int*)(self + 0x760) = 0;
        *(int*)(self + 0x768) = 0;
        ItemDetail_RenderPendingItemName((char*)self);
        ItemDetail_ConfigureCategoryLayout(self + 0xcc, *(void**)(self + 0x50));
        *(void**)(self + 0x4c) = *(void**)(self + 0x50);
        *(void**)(self + 0x50) = 0;
        if (*(signed char*)(self + 0x77c) == 1) {
            volatile unsigned* dispcnt = (volatile unsigned*)0x04001000;
            unsigned bits = 0x12;
            if (variant != 0)
                bits |= 1;
            *dispcnt = (*dispcnt & ~0x1f00) | (bits << 8);
        }
        *(unsigned short*)(self + 0x774) |= 0x2000;
        return 2;
    }
    char path[0x40];
    char markup[0x40];
    __clear(path, 0x40);
    __clear(markup, 0x40);
    int useGp2 = 0;
    if (variant == 0) {
        unsigned char mode = self[0x778];
        if (mode != 0) {
            switch (mode) {
            case 1:
                sprintf(path, ItemDetail_QueueCategoryBackground_PathDataAniBgIidcPac);
                break;
            case 2:
                sprintf(path, ItemDetail_QueueCategoryBackground_PathDataAniBgIilistPac);
                break;
            }
            goto queue;
        }
    }
    if ((*(unsigned short*)(self + 0x774) & 4) && (self[0x778] == 0 || *(int*)(self + 0x734) > 0)) {
        sprintf(path, ItemDetail_QueueCategoryBackground_PathDataAniBglii2DGp2, variant);
        sprintf(markup, ItemDetail_QueueCategoryBackground_FormatBglii2DLGPac, variant);
        useGp2 = 1;
    } else {
        sprintf(path, ItemDetail_QueueCategoryBackground_PathDataAniBgii2DGp2, variant);
        sprintf(markup, ItemDetail_QueueCategoryBackground_FormatBgii2DLGPac, variant);
        useGp2 = 1;
    }
queue:
    unsigned task;
    if (useGp2)
        task = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, path, markup, 0);
    else
        task = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
    *(unsigned*)(self + 0x734) = task;
    return 1;
}
