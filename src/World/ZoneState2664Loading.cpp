#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"

struct EntranceArchivePath { char text[40]; };
extern "C" {
    Zone3D* Zone3D_GetMainInstance();
    void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
    void Object_InvokeSaveTextureImageVRAMState(void*);
// Original data: arm9/main @ 0x20e8d54; symbol: data_020e8d54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 646174612f63686172615f7375622f733230322e63687200000000000000000000000000000000009200000002000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern const EntranceArchivePath ZoneState2664LoadEntranceObject_UnknownRoleInitializedBytes;
}

// Original: arm9/main @ 0x0208F588; symbol: _ZN13ZoneState266418LoadEntranceObjectER13SafeAllocatorPv; size: 0x104.
bool ZoneState2664::LoadEntranceObject(SafeAllocator& allocator, void* textureContext)
{
    unknown_b4 = 0;
    object.Destroy();
    object.Initialize();
    if (Zone3D_GetMainInstance()->pUnknownStruct_8_->unknown_c_low_) return false;
    EntranceArchivePath path = ZoneState2664LoadEntranceObject_UnknownRoleInitializedBytes;
    unsigned int size;
    void* file = LoadFileIntoNewAllocation(path.text, allocator, &size);
    if (!file) return false;
    unsigned int length = size;
    archive = file;
    archiveSize = length;
    unknown_b4 = 1;
    unknown_b5 = 1;
    ObjectArchiveLoadInfo info;
    info.unk_0 = 0;
    info.fileData = 0;
    info.unk_8 = 0;
    info.unk_10 = 0;
    info.unk_14 = 0;
    info.unk_18 = 0;
    info.packageID = 0;
    info.allocator = &allocator;
    info.fileData = archive;
    info.unk_8 = archiveSize;
    Graphics_RestoreTextureImageAndPaletteVRAMState(textureContext);
    object.Initialize();
    object.LoadFromCHRArchive(&info);
    object.MakeHidden();
    Object_InvokeSaveTextureImageVRAMState(textureContext);
    return true;
}
