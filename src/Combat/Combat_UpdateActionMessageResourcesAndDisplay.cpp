#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
ARM

struct LoadRequest;
struct Node { unsigned char pad[0x20]; Node* next; };
struct Lists { Node* heads[6]; unsigned char counts[6]; };

extern "C" {
char* ResourceStringTable_CopyTextByKey(char* out, int input, int unused, int index);
void Combat_SetMessageItemNameText(void *p, const char *src);
void Combat_UpdateQueuedBattleMessages(char*);
int Ov000_IsBackgroundTaskComplete(char *task);
unsigned BattleScene_GetActiveInstance();
char* BattleScene_ResolveCurrentActionRecord(char* p);
void Object_AddUniquePositiveHalfword(void* object, int value);
void* Combat_GetCommandActorSnapshot(void* object, int index);
void* Combat_GetIndexedActionTarget(void* object, int index);
void* Util_GetNestedListNodeAtIndex(void *base, int index, int offset);
void* Util_GetListNodeAtIndex(void *list, int index);
Node* Combat_GetTargetResultByCategoryAndPosition(Lists* lists, int position, int index);
void CompleteBackgroundFileLoad(LoadRequest* request, unsigned argument);
}

#define Slot(v) (((v)>=0&&(v)<=3)?1:0)
#pragma always_inline on
static inline int IsPrimarySlot(int id)
{
    int result = 0;
    if (id >= 0)
        result = (id <= 3);
    return result;
}

// Original: arm9/ov025 @ 0x021E9FC4; symbol: func_ov025_021e9fc4; size: 0x4a8.
// Resolves loaded presentation text and collects unique resource keys from primary/secondary records before starting a load.
extern "C" void Combat_UpdateActionMessageResourcesAndDisplay(unsigned char* self)
{
    void* file;
    unsigned size;
    if (!self[0x87c]) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (*(int*)(self + 0x880) >= 0) {
            if (loader->GetTaskStatus(*(int*)(self + 0x880))) {
                file = 0;
                size = 0;
                loader->GetLoadedFileByID(*(int*)(self + 0x880), &file, &size);
                if (file)
                    ResourceStringTable_CopyTextByKey((char*)self + 0x83c, (int)file, size, (short)*(int*)(self + 0x884));
                Combat_SetMessageItemNameText(self + 0x5e8, (char*)self + 0x83c);
                *(short*)(self + 0x794) = *(int*)(self + 0x884);
                loader->RemoveTask(*(int*)(self + 0x880));
                *(int*)(self + 0x880) = -1;
                self[0x87c] = 1;
            }
        } else
            self[0x87c] = 1;
    }
    if (self[0x839]) {
        if (self[0x87c])
            Combat_UpdateQueuedBattleMessages((char*)self + 0x5e8);
        return;
    }
    if (!((void**)(self + 0x10))[self[0x30]])
        return;
    if (!Ov000_IsBackgroundTaskComplete((char*)self + 0x798))
        return;
    char* record = BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 24));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 26));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 28));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 30));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 32));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 34));
    Object_AddUniquePositiveHalfword(self + 0x798, *(short*)(record + 36));
    Object_AddUniquePositiveHalfword(self + 0x798, 126);
    Object_AddUniquePositiveHalfword(self + 0x798, 127);
    if (*(unsigned short*)(record + 24) == 250)
        Object_AddUniquePositiveHalfword(self + 0x798, 480);
    for (int i = 0; i < (unsigned char)record[8]; i++) {
        char* primary = (char*)Combat_GetCommandActorSnapshot(record, i);
        if (!primary)
            continue;
        for (int kind = 0; kind < 6; kind++)
            for (int j = 0; j < (unsigned char)(primary + kind)[38]; j++) {
                char* item = (char*)Util_GetNestedListNodeAtIndex(primary, j, (unsigned char)kind);
                if (!item)
                    continue;
                for (int k = 0; k < (unsigned char)item[31]; k++) {
                    short* key = (short*)Util_GetListNodeAtIndex(item, k);
                    if (key)
                        Object_AddUniquePositiveHalfword(self + 0x798, *key);
                }
            }
    }
    for (int i = 0; i < (unsigned char)record[9]; i++) {
        char* secondary = (char*)Combat_GetIndexedActionTarget(record, i);
        if (!secondary)
            continue;
        for (int j = 1; j < (unsigned char)secondary[23]; j++) {
            unsigned char* selectors = (unsigned char*)secondary + 20;
            if (selectors[j] == 3)
                Object_AddUniquePositiveHalfword(self + 0x798, 440);
            else if (selectors[j] == 1) {
                int id = ((short*)(secondary + 14))[j - 1];
                int key = 170;
                if (IsPrimarySlot(id))
                    key = 169;
                Object_AddUniquePositiveHalfword(self + 0x798, (short)key);
            } else if (selectors[j] == 8 || selectors[j] == 7 || selectors[j] == 6)
                Object_AddUniquePositiveHalfword(self + 0x798, 126);
            else if (selectors[j] == 4 || selectors[j] == 5)
                Object_AddUniquePositiveHalfword(self + 0x798, 322);
            else if (selectors[j] == 10)
                Object_AddUniquePositiveHalfword(self + 0x798, 323);
            else if (selectors[j] == 2) {
                int id = ((short*)(secondary + 14))[j - 1];
                int key = 41;
                if (IsPrimarySlot(id))
                    key = 40;
                Object_AddUniquePositiveHalfword(self + 0x798, (short)key);
            }
        }
        for (int kind = 0; kind < 3; kind++)
            for (int j = 0; j < (unsigned char)(secondary + kind)[24]; j++) {
                char* item = (char*)Combat_GetTargetResultByCategoryAndPosition((Lists*)secondary, j, (unsigned char)kind);
                if (!item)
                    continue;
                for (int k = 0; k < (unsigned char)item[31]; k++) {
                    short* key = (short*)Util_GetListNodeAtIndex(item, k);
                    if (key)
                        Object_AddUniquePositiveHalfword(self + 0x798, *key);
                }
            }
    }
    CompleteBackgroundFileLoad((LoadRequest*)(self + 0x798), (unsigned)((void**)(self + 16))[self[48]]);
}
