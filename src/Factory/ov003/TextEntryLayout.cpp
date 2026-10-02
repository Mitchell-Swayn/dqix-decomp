#include "globaldefs.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "TextEntryTypes.h"

struct TextEntryBuildContext {
    SafeAllocator* allocator;
    TextEntryLayout* layout;
};

extern "C" {
    // Shared by the original script opcode handlers, which remain fallback.
    TextEntryBuildContext data_ov003_02180cb8;
    extern Script::OpcodeLookupEntry data_ov003_0217ff40[];

    void func_ov003_0215e6d8(TextEntryLayout* layout)
    {
        layout->keys = NULL;
        layout->keyCapacity = 0;
        layout->keyCount = 0;
        layout->grids = NULL;
        layout->gridCapacity = 0;
        layout->gridCount = 0;
    }

    void func_ov003_0215e6f8(TextEntryLayout* layout, SafeAllocator* allocator, const void* code, unsigned int length)
    {
        data_ov003_02180cb8.layout = layout;
        data_ov003_02180cb8.allocator = allocator;
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(data_ov003_0217ff40);
        script.Load(code, length);
        script.Execute();
    }

    void func_ov003_0215e750(TextEntryLayout* layout, SafeAllocator* allocator, short capacity)
    {
        if (allocator == NULL || capacity < 0) {
            return;
        }
        layout->keys = (TextEntryKey*)allocator->Allocate(capacity * sizeof(TextEntryKey));
        layout->keyCapacity = capacity;
        layout->keyCount = 0;
    }

    void func_ov003_0215e790(TextEntryLayout* layout, const TextEntryKey* key)
    {
        if (layout->keys == NULL || layout->keyCapacity <= layout->keyCount) {
            return;
        }
        TextEntryKey* destination = &layout->keys[layout->keyCount];
        destination->x = key->x;
        destination->y = key->y;
        destination->text = key->text;
        destination->alternateText = key->alternateText;
        destination->modeMask = key->modeMask;
        destination->action = key->action;
        destination->extentIndex = key->extentIndex;
        destination->disabled = key->disabled;
        destination->navigationIndex = key->navigationIndex;
        destination->unknown12 = key->unknown12;
        destination->unknown13 = key->unknown13;
        layout->keyCount++;
    }

    TextEntryKey* func_ov003_0215e824(TextEntryLayout* layout, int navigationIndex)
    {
        TextEntryKey* key = layout->keys;
        int count = layout->keyCount;
        for (int i = 0; i < count; i++, key++) {
            if (key->navigationIndex == navigationIndex) {
                return key;
            }
        }
        return NULL;
    }

    void func_ov003_0215e85c(TextEntryLayout* layout, SafeAllocator* allocator, short capacity)
    {
        if (allocator == NULL || capacity < 0) {
            return;
        }
        layout->grids = (TextEntryGrid*)allocator->Allocate(capacity * sizeof(TextEntryGrid));
        layout->gridCapacity = capacity;
        layout->gridCount = 0;
    }

    void func_ov003_0215e898(TextEntryLayout* layout, const TextEntryGrid* grid)
    {
        if (layout->grids == NULL || layout->gridCapacity <= layout->gridCount) {
            return;
        }
        TextEntryGrid* destination = &layout->grids[layout->gridCount];
        destination->modeMask = grid->modeMask;
        destination->columns = grid->columns;
        destination->rows = grid->rows;
        destination->cellCount = grid->cellCount;
        destination->keyIndices = grid->keyIndices;
        layout->gridCount++;
    }

    TextEntryGrid* func_ov003_0215e8f4(TextEntryState* state)
    {
        TextEntryLayout* layout = state->layout;
        unsigned char mode = state->mode;
        TextEntryGrid* grid = layout->grids;
        int count = layout->gridCount;
        for (int i = 0; i < count; i++, grid++) {
            if (grid->modeMask & mode) {
                return grid;
            }
        }
        return NULL;
    }

    int func_ov003_0215e930(TextEntryGrid* grid, int navigationIndex, signed char* column, signed char* row)
    {
        int count = grid->cellCount;
        short* indices = grid->keyIndices;
        for (short i = 0; i < count; i++, indices++) {
            if (*indices == navigationIndex) {
                *column = i % grid->columns;
                *row = i / grid->columns;
                return 0;
            }
        }
        return 1;
    }

    int func_ov003_0215e9a4(TextEntryGrid* grid, int column, int row)
    {
        if (column >= 0 && column < grid->columns && row >= 0 && row < grid->rows) {
            short* indices = grid->keyIndices + grid->columns * row;
            return indices[column];
        }
        return -1;
    }
}
