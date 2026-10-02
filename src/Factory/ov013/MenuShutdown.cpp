#include "MenuText.h"
#include <Filesystem/BackgroundLoader.h>

extern "C" {
void* memset(void*, int, unsigned int);
unsigned char* func_020421a0();
void func_02074bf4(void*);
void func_02074bd0(void*);
void func_0205d6a0(Ov013WidgetGroup*, int);
void func_0205d1e0(Ov013WidgetGroup*);
void func_0205d274(Ov013WidgetGroup*);
void func_0205d2bc(Ov013WidgetGroup*);
void func_0205d048(Ov013WidgetGroup*);
void LoadToMainBG1CharacterData(const void*, int, unsigned int);
}
void CleanInvalidateCacheRange(const void*, unsigned int);

extern "C" void func_ov013_021846a0(Ov013Menu* menu)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (menu->task >= 0) {
        loader->RemoveTask(menu->task);
        menu->task = -1;
    }
    func_020421a0()[0x19be] = 0;
    if (menu->borrowedGroup) {
        func_02074bf4(menu->graphicsState);
        func_0205d6a0(&menu->widgetGroup, 1);
        func_0205d1e0(&menu->widgetGroup);
        func_0205d274(&menu->widgetGroup);
        func_0205d2bc(&menu->widgetGroup);
    } else {
        func_02074bd0(menu->graphicsState);
        func_0205d1e0(&menu->widgetGroup);
        func_0205d274(&menu->widgetGroup);
        func_0205d2bc(&menu->widgetGroup);
        func_0205d048(&menu->widgetGroup);
        if (menu->unknown654) {
            void* characterData = (void*)menu->unknown654;
            memset(characterData, 0, 0x20);
            CleanInvalidateCacheRange((void*)menu->unknown654, 0x20);
            LoadToMainBG1CharacterData((void*)menu->unknown654, 0, 0x20);
        }
        volatile unsigned int* displayControl = (volatile unsigned int*)0x04000000;
        *displayControl = (*displayControl & ~0x1f00) | (menu->savedBackgroundMode << 8);
    }
    if (menu->stringAllocator.GetSignedAllocator())
        menu->stringAllocator.Destroy();
    if (menu->allocator.GetSignedAllocator())
        menu->allocator.Destroy();
    menu->state[4] = 6;
}
