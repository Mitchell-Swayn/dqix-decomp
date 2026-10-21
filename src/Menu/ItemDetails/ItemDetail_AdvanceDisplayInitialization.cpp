#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
typedef unsigned int undefined4;
ARM
struct Record { signed char active; char reserved[0x47]; int stride; inline int isActive() const { return active != 0; } };
struct State;
class BackgroundLoader {
public:
    static BackgroundLoader* GetInstance();
    void RemoveTask(int);
};
extern "C" {
GameResources* GameState_ReadPResources(GameState* state);
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion* a, unsigned size);
unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void *loader, unsigned id);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned*);
void _ZN13SafeAllocator5ResetEv(void*);
char* ResourceFile_GetPayloadByIndex(char* p, int index, char** out, unsigned int* size);
int ResourceFile_CountActiveStrideRecords(Record* p);
int Graphics_DispatchDataByResourceMagic(int a, void* data, int b, int c);
void Graphics_CacheFourMainBackgroundControlsOnce(volatile State* p);
void Graphics_SnapshotSubBackgroundControlRegistersOnce(State* p);
unsigned int DisplayContext_GetGlobalInstance();
void DisplayContext_IgnoreRequest(void* context, int request, int argument);
undefined4 DisplayContext_ReportRequestComplete(void);
void GameState_EnableGlobalFlag64();
int ResourceStringTable_CopySerializedData(unsigned *self, void *allocator, unsigned char *input, unsigned size);
void Menu_RemoveStoredBackgroundTask(int* task);
void Graphics_ConfigureSubBackgroundsForModeOne(unsigned char* self);
void Graphics_SetMainOrSubBrightness(void *state, int brightness, int duration);
int Graphics_IsSelectedBrightnessTransitionActive(void *obj);
unsigned MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
const char ItemDetail_QueueQuantityModeArchive_PathDataAniOiirGp2[];
const char ItemDetail_QueueQuantityModeArchive_MarkupOiirLGPac[];
const char ItemDetail_AdvanceDisplayInitialization_PathDataBinMenuStrIiGp2[];
const char ItemDetail_AdvanceDisplayInitialization_MarkupStrIiLGNat[];
}
struct Owner {
    char pad[0x14];
    char allocator[0x30];
    void* resourceAllocator;
    char pad48[0x6e8];
    unsigned displayMode;
    int task;
    int tasks[7];
    unsigned zero754;
    char pad758[0x1c];
    unsigned short flags;
    unsigned char ready, stage;
    char pad778[3];
    signed char mode, engine;
    unsigned char loaded;
};
// Original: arm9/ov023 @ 0x021DD59C; symbol: func_ov023_021dd59c; size: 0x3d8.
// Advances a nine-stage item-detail display init: brightness, overlay request, background snapshots, two GP2 loads, and task cleanup.
extern "C" void ItemDetail_AdvanceDisplayInitialization(Owner* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameState_ReadPResources(GameState::GetInstance());
    if (self->stage == 0) {
        if (!MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1])
            MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[1] =
                (unsigned)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3, 0x1800);
        if (!(self->flags & 0x40)) {
            self->stage = 2;
            return;
        }
        if (self->mode != 1)
            Graphics_SetMainOrSubBrightness(self, -16, 8);
        self->stage++;
    }
    if (self->stage == 1 && !Graphics_IsSelectedBrightnessTransitionActive(self)) {
        if (self->mode != 1)
            GameState_EnableGlobalFlag64();
        self->stage++;
    }
    if (self->stage == 2) {
        if (self->flags & 0x10) {
            self->stage = 4;
            return;
        }
        DisplayContext_IgnoreRequest((void*)DisplayContext_GetGlobalInstance(), 0x1fa, 0);
        self->stage++;
    } else if (self->stage == 3) {
        DisplayContext_GetGlobalInstance();
        if (DisplayContext_ReportRequestComplete())
            self->stage++;
    }
    if (self->stage == 4) {
        if (self->engine == 1)
            Graphics_SnapshotSubBackgroundControlRegistersOnce((State*)((char*)self + 0x118));
        else
            Graphics_CacheFourMainBackgroundControlsOnce((State*)((char*)self + 0x118));
        *(unsigned char*)((char*)self + 0x17c) = self->engine;
        *(void**)((char*)self + 0x16c) = (char*)self + 0x180;
        *(unsigned short*)((char*)self + 0x178) = 30;
        self->task = (int)_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, ItemDetail_QueueQuantityModeArchive_PathDataAniOiirGp2,
            ItemDetail_QueueQuantityModeArchive_MarkupOiirLGPac, 0);
        self->stage++;
    } else if (self->stage == 5 && _ZN16BackgroundLoader13GetTaskStatusEi(loader, self->task)) {
        _ZN13SafeAllocator5ResetEv(self->resourceAllocator);
        char* output;
        void* data;
        unsigned size;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->task, &data, &size);
        if (data && size) {
            int count = ResourceFile_CountActiveStrideRecords((Record*)data);
            for (int i = 0; i < count; i++) {
                unsigned blockSize;
                char* block = ResourceFile_GetPayloadByIndex((char*)data, i, &output, &blockSize);
                Graphics_DispatchDataByResourceMagic((int)((char*)self + 0x12c), block, blockSize, (int)self->resourceAllocator);
            }
        }
        self->loaded = 1;
        loader->RemoveTask(self->task);
        self->task = -1;
        self->stage++;
    }
    if (self->stage == 6) {
        self->task = (int)_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, ItemDetail_AdvanceDisplayInitialization_PathDataBinMenuStrIiGp2,
            ItemDetail_AdvanceDisplayInitialization_MarkupStrIiLGNat, 0);
        self->stage++;
    } else if (self->stage == 7 && _ZN16BackgroundLoader13GetTaskStatusEi(loader, self->task)) {
        void* data;
        unsigned size;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->task, &data, &size);
        _ZN13SafeAllocator5ResetEv(self->allocator);
        if (data && size)
            ResourceStringTable_CopySerializedData((unsigned*)((char*)self + 0x54), self->allocator, (unsigned char*)data, size);
        loader->RemoveTask(self->task);
        self->task = -1;
        self->stage++;
    }
    if (self->stage == 8) {
        unsigned display = self->engine == 1 ? *(volatile unsigned*)0x04001000 : *(volatile unsigned*)0x04000000;
        self->displayMode = (display & 0x1f00) >> 8;
        if (self->mode != 1)
            Graphics_ConfigureSubBackgroundsForModeOne((unsigned char*)self);
        self->ready = 1;
        self->stage = 0;
        Menu_RemoveStoredBackgroundTask(&self->task);
        for (int i = 0; i < 7; i++)
            Menu_RemoveStoredBackgroundTask(self->tasks + i);
        self->zero754 = 0;
        self->flags |= 1;
    }
}
