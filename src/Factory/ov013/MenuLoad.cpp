#include "MenuText.h"
#include <Filesystem/BackgroundLoader.h>
#include <System/ColorEffects.h>
#include <System/Graphics.h>

struct Ov013ResourceSlot {
    unsigned char unknown00[0x1c];
    unsigned char mode : 4;
    unsigned char layer : 4;
    unsigned char unknown1D[3];
};

extern "C" {
unsigned char* func_020421a0();
void func_020dfec0(Ov013StringCatalog*, SafeAllocator*, void*, unsigned int);
void func_0205cef8(Ov013WidgetGroup*);
void func_0205cf04(Ov013WidgetGroup*);
void func_ov013_02185310(Ov013Menu*);
void func_ov013_02185cc0(Ov013Menu*);
void* func_02094a00();
void func_02094b3c(void*, int);
void func_02094b30(void*, int, int);
int func_02094b4c(void*);
void func_0204b11c(Ov013ResourceSlot*, int);
void func_0204b5b4(Ov013ResourceSlot*, unsigned char);
void func_0204b12c(Ov013ResourceSlot*, SafeAllocator*);
void func_0204b5e8(Ov013ResourceSlot*, int, int);
int func_02046900(void*);
void* func_020467f0(void*, int, int*, unsigned int*);
void func_0204b174(void*, void*, SafeAllocator*, unsigned int);
void func_0204bc74(void*, int, int, int, int, int, int);
void func_0204b0e8(void*, int);
void func_0204c7a8(Ov013Widget*, SafeAllocator*, void*, int);
void func_0205cf78(Ov013WidgetGroup*, Ov013Widget*, int);
extern const char data_ov013_02187e00[];
extern const char data_ov013_02187e19[];
extern const char data_ov013_02187e29[];
extern const unsigned char data_ov013_02187d88[];
extern const unsigned char data_ov013_02187d8a[];
}

#pragma force_active on
extern "C" void func_ov013_02184d80(Ov013Menu* menu)
{
    if (menu->state[4] != 0)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (menu->borrowedGroup) {
        if (menu->state[6] == 0) {
            menu->task = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, 0);
            ++menu->state[6];
        } else if (menu->state[6] == 1) {
            if (!loader->GetTaskStatus(menu->task))
                return;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(menu->task, &data, &size);
            menu->stringAllocator.Reset();
            func_020dfec0(&menu->strings, &menu->stringAllocator, data, size);
            loader->RemoveTask(menu->task);
            menu->task = -1;
            ++menu->state[6];
        } else if (menu->state[6] == 2) {
            menu->textBuffer = *(Ov013TextBuffer**)(func_020421a0() + 0x5c);
            BG2CNTSUB = (BG2CNTSUB & ~3) | 1;
            BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
            BG1CNTSUB = (BG1CNTSUB & ~3) | 3;
            DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
            func_0205cef8(&menu->widgetGroup);
            func_0205cf04(&menu->widgetGroup);
            func_ov013_02185310(menu);
            func_ov013_02185cc0(menu);
            menu->state[6] = 0;
            menu->state[4] = 1;
        }
    } else {
        if (menu->state[6] == 0) {
            void* transition = func_02094a00();
            func_02094b3c(transition, 12);
            func_02094b30(transition, 0x1f7, 0);
            ++menu->state[6];
        } else if (menu->state[6] == 1) {
            if (!func_02094b4c(func_02094a00()))
                return;
            menu->textBuffer = *(Ov013TextBuffer**)(func_020421a0() + 0x5c);
            Ov013ResourceSlot* slot = (Ov013ResourceSlot*)menu->resourceSlots;
            for (int i = 0; i < 2; ++i) {
                func_0204b11c(slot, 0);
                slot->mode = 0;
                slot->layer = data_ov013_02187d8a[i];
                func_0204b5b4(slot, data_ov013_02187d88[i]);
                func_0204b12c(slot, &menu->allocator);
                func_0204b5e8(slot, 0, 0);
                ++slot;
            }
            volatile unsigned short* backgrounds = (volatile unsigned short*)0x0400000a;
            backgrounds[0] = (backgrounds[0] & 0x43) | 0x1d00;
            backgrounds[1] = (backgrounds[1] & 0x43) | 0x1e00;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
            menu->task = loader->QueueLoadFile(data_ov013_02187e29, 0);
            ++menu->state[6];
        } else if (menu->state[6] == 2) {
            if (!loader->GetTaskStatus(menu->task))
                return;
            int directory = 0;
            void* data;
            unsigned int size;
            void* files[2];
            unsigned int sizes[2];
            loader->GetLoadedFileByID(menu->task, &data, &size);
            int count = func_02046900(data);
            for (int i = 0; i < count; ++i)
                files[i] = func_020467f0(data, i, &directory, &sizes[i]);
            for (int i = 0; i < count; ++i) {
                if (files[i])
                    func_0204b174(menu->resourceSlots[1], files[i], &menu->allocator, sizes[i]);
            }
            loader->RemoveTask(menu->task);
            menu->task = -1;
            func_0204bc74(menu->resourceSlots[0], 0, 0, 0, 32, 25, 0);
            func_0204b0e8(menu->resourceSlots[0], 0);
            func_0204bc74(menu->resourceSlots[1], 0, 0, 0, 32, 25, 0);
            func_0204b0e8(menu->resourceSlots[1], 0);
            menu->unknown654 = menu->allocator.Allocate(0x3c00);
            for (int i = 0; i < 3; ++i) {
                func_0204c7a8(&menu->widgets[i], &menu->allocator, menu->unknown654, 0x380);
                menu->widgets[i].resourceSlot = menu->resourceSlots[1];
            }
            menu->widgetGroup.resources = menu->resourceSlots[0];
            menu->widgetGroup.state[2] = 2;
            func_0205cf78(&menu->widgetGroup, menu->widgets, 3);
            menu->task = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, 0);
            ++menu->state[6];
        } else if (menu->state[6] == 3) {
            if (!loader->GetTaskStatus(menu->task))
                return;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(menu->task, &data, &size);
            menu->stringAllocator.Reset();
            func_020dfec0(&menu->strings, &menu->stringAllocator, data, size);
            loader->RemoveTask(menu->task);
            menu->task = -1;
            ++menu->state[6];
        } else if (menu->state[6] == 4) {
            volatile unsigned short* backgrounds = (volatile unsigned short*)0x04000008;
            backgrounds[0] = (backgrounds[0] & ~3) | 2;
            backgrounds[1] = (backgrounds[1] & ~3) | 1;
            backgrounds[2] = backgrounds[2] & ~3;
            volatile unsigned int* control = (volatile unsigned int*)0x04000000;
            *control = (*control & ~0x1f00) | 0x1700;
            func_0205cef8(&menu->widgetGroup);
            func_0205cf04(&menu->widgetGroup);
            func_ov013_02185310(menu);
            func_ov013_02185cc0(menu);
            menu->state[6] = 0;
            menu->state[4] = 1;
        }
    }
}
