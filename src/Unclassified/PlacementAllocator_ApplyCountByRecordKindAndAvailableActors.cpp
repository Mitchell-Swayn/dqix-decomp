#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Memory/AllocatorUnion.h>

struct PlacementRecord { unsigned char pad[8]; union { unsigned int raw; struct { unsigned int type : 4; unsigned int rest : 28; } bits; }; };
struct PlacementCharacter { unsigned char pad[0x130]; void* slotInfo; unsigned char pad134[4]; unsigned short* enabled; };
struct ActorIndexList { unsigned char pad[0xf78]; signed char ids[4]; unsigned char count; };
struct PlacementAllocator { SafeAllocator allocator; unsigned char pad14[0x18]; void* contents; };

extern "C" void AllocatePerCountBufferAndBuildGP2State(SafeAllocator*, short*, int);
extern "C" PlacementRecord* FindSerializedPrimaryRecordByKey(void*, int);
extern "C" void ApplyCountToPlacementRecordAndCacheResult(SafeAllocator*, int, int);
extern "C" void GameState_TestKeyRecordAndReleaseTemporaryAllocator(SafeAllocator*, int, int);
extern "C" int GameState_AddItemsAndDistributeOverflow(SafeAllocator*, int, int, int);
extern "C" int GameState_GetIndexList(void);
extern "C" PlacementCharacter* GameState_GetObjectWithFlag100(GameState*, int);
extern "C" int TestIndirectField150FlagsNonzero(void);
extern "C" void* ReadWordFieldAtOffset150(void*);
extern "C" int CountEightPositiveHalfwordSlots(void*);
extern "C" int Resource_ApplyRecordCountToPartyMember(SafeAllocator*, int, int, int, int, int, int);
extern "C" AllocatorUnion data_02114e20;
extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*, void*);

// Original: arm9/main @ 0x0207D300; symbol: func_0207d300; size: 0x238.
extern "C" int PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(PlacementAllocator* context, short id, int count, int requireEnabled)
{
    SafeAllocator* allocator = &context->allocator;
    int created = 0;
    if (context->contents == 0)
    {
        AllocatePerCountBufferAndBuildGP2State(allocator, &id, 1);
        created = 1;
    }

    int result = -1;
    PlacementRecord* record = FindSerializedPrimaryRecordByKey(context->contents, id);
    if (record == 0)
        result = -2;
    else
    {
        unsigned int kind = record->bits.type;
        int simpleKind = (kind <= 7);
        if (simpleKind != 0)
        {
            ApplyCountToPlacementRecordAndCacheResult(allocator, id, count);
            result = 3;
        }
        else if (kind == 9)
        {
            GameState_TestKeyRecordAndReleaseTemporaryAllocator(allocator, id, count);
            result = 5;
        }
        else if ((((unsigned int)(record->raw << 6)) >> 31) != 0)
        {
            if (GameState_AddItemsAndDistributeOverflow(allocator, id, count, 0)) result = 2;
        }
        else
        {
            GameState* gameState = GameState::GetInstance();
            ActorIndexList* actorList = (ActorIndexList*)GameState_GetIndexList();
            unsigned int index = 0;
            for (; index < actorList->count; index = (index + 1) & 0xff)
            {
                int actorId = actorList->ids[index];
                PlacementCharacter* character = GameState_GetObjectWithFlag100(gameState, actorId);
                if (character == 0 || TestIndirectField150FlagsNonzero() != 0) continue;
                if (requireEnabled != 0)
                {
                    int slots = *(volatile unsigned short*)((unsigned char*)character->slotInfo + 4);
                    if (slots <= 0) continue;
                    if (character->enabled != 0 && *character->enabled == 0) continue;
                }

                void* target = ReadWordFieldAtOffset150(character);
                if (target != 0)
                {
                    while (count != 0)
                    {
                        if (CountEightPositiveHalfwordSlots(target) == 8) break;
                        result = Resource_ApplyRecordCountToPartyMember(allocator, id, 1, actorId, 0, 0, 0);
                        if (result != 0) break;
                        count = (short)(count - 1);
                        }
                }
            }
            if (count > 0 && GameState_AddItemsAndDistributeOverflow(allocator, id, count, 0))
                result = 2;
        }
    }

    if (created)
    {
        void* signedAllocator = allocator->GetSignedAllocator();
        allocator->Destroy();
        Memory_FreeThroughAllocatorUnion(&data_02114e20, signedAllocator);
        context->contents = 0;
    }
    return result;
}
