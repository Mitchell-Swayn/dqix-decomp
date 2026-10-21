#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <System/BGBases.h>
#include <std_library_functions.h>
ARM
struct Record { signed char active; char reserved[0x47]; int stride; inline int isActive() const { return active != 0; } };
struct Flags { unsigned char low:4; unsigned char high:4; };
struct Owner { char pad[0x1c]; Flags flags; };
struct State { unsigned char pad[28]; unsigned char first:4; unsigned char second:4; };
struct Layout;
struct Input;
class BackgroundLoader {
public:
    static BackgroundLoader* GetInstance();
    int GetTaskStatus(int id);
    void GetLoadedFileByID(int, void**, unsigned*);
    void RemoveTask(int);
};
extern "C" {
int ItemDetail_GetCategoryBackgroundVariant(volatile unsigned int *value);
void Graphics_InitializeCanvasTransferState(char* p);
void Graphics_SetBackgroundColorMode(Owner* self, unsigned int mode);
void Graphics_SetTextBackgroundScreenSize(int self, unsigned int value);
int Graphics_InvokeTwoIndexTransferCallback(State *p, void *a, void *b);
int ResourceFile_CountActiveStrideRecords(Record* p);
char* ResourceFile_GetPayloadByIndex(char* p, int index, char** out, unsigned int* size);
void Graphics_ParseTaggedLayerResource(char* p, const void* src);
void Graphics_DispatchResourceByFourByteMagic(unsigned char* object, void* data);
int LoadRelativeLayoutRecords(Layout* self, unsigned allocator, Input* input, void* required);
void Menu_ResetLayout(char* obj);
int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(const void* narc, const char* substring, const void** out, unsigned* sizes, unsigned flag);
void ItemDetail_RenderPendingItemName(char* self);
int ItemDetail_ConfigureCategoryLayout(...);
extern const char* ItemDetailConsumeCategoryBackground_UnknownRoleDataReferences[];
}
// Original: arm9/ov023 @ 0x021DFECC; symbol: func_ov023_021dfecc; size: 0x378.
// Consumes the queued category-background NARC, installs layout/tiles, then clears the load task.
extern "C" int ItemDetail_ConsumeCategoryBackground(unsigned char* self)
{
    char canvas[0x20];
    void* file;
    void* payload;
    unsigned size;
    unsigned payloadSize;
    char* scratch;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(*(int*)(self + 0x734)))
        goto not_ready;
    int variant = ItemDetail_GetCategoryBackgroundVariant((volatile unsigned int*)*(void**)(self + 0x50));
    loader->GetLoadedFileByID(*(int*)(self + 0x734), &file, &size);
    if (file && size) {
        Graphics_InitializeCanvasTransferState(canvas);
        signed char engine = *(signed char*)(self + 0x77c);
        if (engine == 1) {
            unsigned char packed = canvas[0x1c];
            packed = (packed & ~0xf) | ((unsigned char)engine & 0xf);
            packed = (packed & ~0xf0) | 0x10;
            canvas[0x1c] = packed;
        } else {
            unsigned char packed = canvas[0x1c];
            packed = (packed & ~0xf) | ((unsigned char)engine & 0xf);
            packed = (packed & ~0xf0) | 0x30;
            canvas[0x1c] = packed;
        }
        Graphics_SetBackgroundColorMode((Owner*)canvas, 3);
        Graphics_SetTextBackgroundScreenSize((int)canvas, 0);
        Graphics_InvokeTwoIndexTransferCallback((State*)canvas, 0, 0);
        if (*(signed char*)(self + 0x77c) == 1) {
            volatile unsigned* dispcnt = (volatile unsigned*)0x04001000;
            unsigned bits = 0x12;
            if (variant)
                bits |= 1;
            *dispcnt = (*dispcnt & ~0x1f00) | (bits << 8);
        }
        if (variant == 0 && self[0x778]) {
            int count = ResourceFile_CountActiveStrideRecords((Record*)file);
            unsigned char i = 0;
            while (i < count) {
                payload = ResourceFile_GetPayloadByIndex((char*)file, i, &scratch, &payloadSize);
                if (payload) {
                    Graphics_ParseTaggedLayerResource(canvas, payload);
                    Graphics_DispatchResourceByFourByteMagic((unsigned char*)canvas, payload);
                    LoadRelativeLayoutRecords((Layout*)(self + 0xcc), (unsigned)self, (Input*)payload, (void*)payloadSize);
                }
                i = (unsigned char)(i + 1);
            }
        } else {
            Menu_ResetLayout((char*)self + 0xcc);
            ((SafeAllocator*)self)->Reset();
            unsigned char n = 0;
            while (n < 4) {
                if (_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(file, ItemDetailConsumeCategoryBackground_UnknownRoleDataReferences[n], (const void**)&payload, &payloadSize, 1)) {
                    if (n != 3) {
                        Graphics_ParseTaggedLayerResource(canvas, payload);
                        Graphics_DispatchResourceByFourByteMagic((unsigned char*)canvas, payload);
                    } else
                        LoadRelativeLayoutRecords((Layout*)(self + 0xcc), (unsigned)self, (Input*)payload, (void*)payloadSize);
                }
                n = (unsigned char)(n + 1);
            }
        }
        *(unsigned*)(self + 0x75c) = 0x3800;
        if (*(signed char*)(self + 0x77b) == 1)
            *(unsigned*)(self + 0x75c) = 0x2800;
        *(unsigned*)(self + 0x760) = 0;
        *(unsigned*)(self + 0x768) = 0;
        if (*(signed char*)(self + 0x77c) == 1) {
            memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
            if (*(void**)(self + 0x50)) {
                ItemDetail_RenderPendingItemName((char*)self);
                volatile unsigned* dispcnt = (volatile unsigned*)0x04001000;
                *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;
            }
        } else {
            memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
            if (*(void**)(self + 0x50))
                ItemDetail_RenderPendingItemName((char*)self);
        }
        ItemDetail_ConfigureCategoryLayout(self + 0xcc, *(void**)(self + 0x50));
    }
    self[0x779] = (unsigned char)variant;
    loader->RemoveTask(*(int*)(self + 0x734));
    *(int*)(self + 0x734) = -1;
    *(void**)(self + 0x4c) = *(void**)(self + 0x50);
    *(void**)(self + 0x50) = 0;
    unsigned short flags = *(unsigned short*)(self + 0x774);
    if (flags & 0x40) {
        if (!(flags & 4)) {
            flags |= 0x20;
            *(unsigned short*)(self + 0x774) = flags;
        }
    }
    int slot = 0;
    int none = -1;
    while (slot < 7) {
        *(int*)(self + 0x738 + slot * 4) = none;
        slot++;
    }
    *(unsigned short*)(self + 0x774) = (unsigned short)(*(unsigned short*)(self + 0x774) | 4 | 0x2000);
    if (*(void**)(self + 0x4c) == 0)
        return -1;
    return 2;
not_ready:
    return 1;
}
