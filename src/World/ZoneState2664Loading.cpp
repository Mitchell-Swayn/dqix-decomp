#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"

struct EntranceArchivePath { char text[40]; };
extern "C" {
    Zone3D* ReadGlobalValueAt020FB3F0();
    void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
    void Object_InvokeSaveTextureImageVRAMState(void*);
    extern const EntranceArchivePath data_020e8d54;
}

// Original: arm9/main @ 0x0208F588; symbol: _ZN13ZoneState266418LoadEntranceObjectER13SafeAllocatorPv; size: 0x104.
bool ZoneState2664::LoadEntranceObject(SafeAllocator& allocator, void* textureContext)
{
    unknown_b4 = 0;
    object.Destroy();
    object.Initialize();
    if (ReadGlobalValueAt020FB3F0()->pUnknownStruct_8_->unknown_c_low_) return false;
    EntranceArchivePath path = data_020e8d54;
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
