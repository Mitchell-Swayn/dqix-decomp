#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <Memory/AllocatorUnion.h>

struct PlacementRecord { unsigned char pad[8]; union { unsigned int raw; struct { unsigned int type : 4; unsigned int rest : 28; } bits; }; };
struct PlacementCharacter { unsigned char pad[0x130]; void* slotInfo; unsigned char pad134[4]; unsigned short* enabled; };
struct ActorIndexList { unsigned char pad[0xf78]; signed char ids[4]; unsigned char count; };
struct PlacementAllocator { SafeAllocator allocator; unsigned char pad14[0x18]; void* contents; };

extern "C" void AllocatePerCountBufferAndBuildGP2State(SafeAllocator*, short*, int);
extern "C" PlacementRecord* ZoneState2754_FindPrimaryRecordByKey(void*, int);
extern "C" void Inventory_AddGroupedItemQuantityAndCacheResult(SafeAllocator*, int, int);
extern "C" void Inventory_AddSpecialItemQuantityAndCacheResult(SafeAllocator*, int, int);
extern "C" int GameState_AddItemsAndDistributeOverflow(SafeAllocator*, int, int, int);
extern "C" int GameState_GetIndexList(void);
extern "C" PlacementCharacter* GameState_GetObjectWithFlag100(GameState*, int);
extern "C" int GameObject_HasLinkedStatusNibble(void);
extern "C" void* GameObject_GetLinkedIndexedState(void*);
extern "C" int CharacterState_CountCarriedItems(void*);
extern "C" int Inventory_AddItemsToMemberAndDistributeRemainder(SafeAllocator*, int, int, int, int, int, int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
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
    PlacementRecord* record = ZoneState2754_FindPrimaryRecordByKey(context->contents, id);
    if (record == 0)
        result = -2;
    else
    {
        unsigned int kind = record->bits.type;
        int simpleKind = (kind <= 7);
        if (simpleKind != 0)
        {
            Inventory_AddGroupedItemQuantityAndCacheResult(allocator, id, count);
            result = 3;
        }
        else if (kind == 9)
        {
            Inventory_AddSpecialItemQuantityAndCacheResult(allocator, id, count);
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
                if (character == 0 || GameObject_HasLinkedStatusNibble() != 0) continue;
                if (requireEnabled != 0)
                {
                    int slots = *(volatile unsigned short*)((unsigned char*)character->slotInfo + 4);
                    if (slots <= 0) continue;
                    if (character->enabled != 0 && *character->enabled == 0) continue;
                }

                void* target = GameObject_GetLinkedIndexedState(character);
                if (target != 0)
                {
                    while (count != 0)
                    {
                        if (CharacterState_CountCarriedItems(target) == 8) break;
                        result = Inventory_AddItemsToMemberAndDistributeRemainder(allocator, id, 1, actorId, 0, 0, 0);
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
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, signedAllocator);
        context->contents = 0;
    }
    return result;
}
