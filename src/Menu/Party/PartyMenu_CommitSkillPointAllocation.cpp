#include <globaldefs.h>
ARM
#pragma force_active on
// Preserve stored cursor narrowing and independent state reloads.
#pragma opt_propagation off
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* TextContext_GetSharedInstance();
extern "C" char* GameState_GetObjectWithFlag100(void*, int);
// Link binding at shared address 0x021847C4: this call uses the ov013 allocation ABI.
// The original ov002 relocation names the overlapping ov009 symbol.
extern "C" int CharacterCreation_ClearChoiceGridLayout(void*, int);
extern "C" void CopyFiveIndexedValuesToObject(void*, void*);
extern "C" int PartyMenu_GetSelectableMemberIndex(void*, int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned char SkillTable_UnlockEligibleEntries(void*, void*, void*);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" void Network_QueueCurrentPartyMemberState(int, int, int, int);
extern "C" void PartySync_QueueSkillLinePointTotals(int);
extern "C" void Network_QueueHalfwordListInSevenEntryChunks(int, void*, int);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" char* ResourceStringTable_GetTextByKey(void*, int);
extern "C" char* Filesystem_ExtractLocalizedGp2FileToScratch(const char*, const char*, int*);
extern "C" void MessageTextTable_Reset(void*);
extern "C" void Script_ExecuteCodeWithGlobalContextValues(void*, void*, void*, int, int, int, int);
extern "C" void Text_InitializeNameTableHeader(void*);
extern "C" void Text_CopyNameTableIntoAllocator(void*, void*, void*, int);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*, int);
// Original data: arm9/ov002 @ 0x0216D300; symbol: data_ov002_0216d300.
extern "C" char PartyMenu_CommitSkillPointAllocation_PathDataPrmSklArtGp2[];
// Original data: arm9/ov002 @ 0x0216D315; symbol: data_ov002_0216d315.
extern "C" char PartyMenu_CommitSkillPointAllocation_MarkupSklArtLGNat[];
// Original: arm9/ov002 @ 0x02168354; symbol: func_ov002_02168354; size: 0x268.
// Commits allocated skill points, gathers newly unlocked skills, synchronizes them and loads their message resources.
extern "C" void PartyMenu_CommitSkillPointAllocation(char* self)
{
    WORD(0x247c) |= 4;
    if (CharacterCreation_ClearChoiceGridLayout(self + 0x1d70, WORD(0x1ba0)) == 6) {
        char* state = _ZN9GameState11GetInstanceEv();
        TextContext_GetSharedInstance();
        WORD(0x247c) &= ~4;
        if (BYTE(0x2455) == 0) {
            char* member = GameState_GetObjectWithFlag100(state, PartyMenu_GetSelectableMemberIndex(self, HALF(0x1c08)));
            if (member) CopyFiveIndexedValuesToObject(self + 0x1d70, member);
            if (member) {
                _ZN13SafeAllocator5ResetEv(self + 0x864);
                POINTER(0x2450) = (char*)_ZN13SafeAllocator8AllocateEj(self + 0x864, 110);
                memset(POINTER(0x2450), 0, 110);
                BYTE(0x2455) = SkillTable_UnlockEligibleEntries(self + 0x243c, member, POINTER(0x2450));
                void* connection = Network_GetConnectionManager();
                if (Network_IsSessionActive(connection)) {
                    int index = PartyMenu_GetSelectableMemberIndex(self, HALF(0x1c08));
                    Network_QueueCurrentPartyMemberState(index, 0, 0, 0);
                    PartySync_QueueSkillLinePointTotals(index);
                    Network_QueueHalfwordListInSevenEntryChunks(index, POINTER(0x2450), BYTE(0x2455));
                }
                if (BYTE(0x2455) == 0) {
                    ++WORD(0x1bc0);
                    return;
                }
                _ZN16BackgroundLoader13AddLockGlobalEv();
                _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
                char* path = ResourceStringTable_GetTextByKey(self + 0x20, 101);
                int size;
                char* data = Filesystem_ExtractLocalizedGp2FileToScratch(ResourceStringTable_GetTextByKey(self + 0x20, 100), path, &size);
                POINTER(0x2448) = (char*)_ZN13SafeAllocator8AllocateEj(self + 0x864, 8);
                MessageTextTable_Reset(POINTER(0x2448));
                if (data) Script_ExecuteCodeWithGlobalContextValues(POINTER(0x2448), self + 0x864, data, size, 0, 0, 0);
                data = Filesystem_ExtractLocalizedGp2FileToScratch(PartyMenu_CommitSkillPointAllocation_PathDataPrmSklArtGp2, PartyMenu_CommitSkillPointAllocation_MarkupSklArtLGNat, &size);
                POINTER(0x244c) = (char*)_ZN13SafeAllocator8AllocateEj(self + 0x864, 12);
                Text_InitializeNameTableHeader(POINTER(0x244c));
                if (data) Text_CopyNameTableIntoAllocator(POINTER(0x244c), self + 0x864, data, size);
                _ZN16BackgroundLoader16RemoveLockGlobalEv();
                CharacterState_RecalculateOrPreviewDerivedStats(GameObject_GetLinkedIndexedState(member), 0);
            }
        }
        ++WORD(0x1bc0);
    }
}
