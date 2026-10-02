#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "Graphics/VRAMAllocations.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern char data_020ef260[]; // T00GDS02.nsbmd, adjacent to the recovered path pool.

void Zone3D::LoadChestModels(SafeAllocator* temporaryAllocator)
{
    unsigned int vramState[10];
    SaveTextureImageVRAMState(vramState);
    char path[80];
    Model3D alternateBase;
    alternateBase.Clear();
    unsigned int length;
    sprintf(path, gZone3DPaths.archivePath, gZone3DPaths.dungeonModel03);
    void* raw = LoadFileIntoNewAllocation(path, *temporaryAllocator, &length);
    if (raw) alternateBase.SetAndProcessRawFile(raw, length, Model3D::TextureStagingMode_Normal);
    Model3D alternateLid;
    alternateLid.Clear();
    sprintf(path, gZone3DPaths.archivePath, gZone3DPaths.dungeonModel04);
    raw = LoadFileIntoNewAllocation(path, *temporaryAllocator, &length);
    if (raw) alternateLid.SetAndProcessRawFile(raw, length, Model3D::TextureStagingMode_Normal);
    Model3D* alternateModels[] = { &alternateBase, &alternateLid, NULL };
    unsigned int* palette = alternateChestPaletteOffsets_;
    for (Model3D** model = alternateModels; *model; ++model, ++palette)
    {
        NSBXXTex* texture = (*model)->GetTEX0();
        if (texture) *palette = texture->block4VRAMLoadOffset_;
    }
    temporaryAllocator->Reset();
    RestoreTextureImageVRAMState(vramState);
    sprintf(path, gZone3DPaths.archivePath, gZone3DPaths.dungeonModel01);
    raw = LoadFileIntoNewAllocation(path, *temporaryAllocator, &length);
    if (raw) models_498_[0].SetAndProcessRawFile(raw, length, Model3D::TextureStagingMode_Normal);
    sprintf(path, gZone3DPaths.archivePath, data_020ef260);
    raw = LoadFileIntoNewAllocation(path, *temporaryAllocator, &length);
    if (raw) models_498_[1].SetAndProcessRawFile(raw, length, Model3D::TextureStagingMode_Normal);
    Model3D* mainModels[] = { &models_498_[0], &models_498_[1], NULL };
    unsigned int* mainPalette = chestPaletteOffsets_;
    for (Model3D** model = mainModels; *model; ++model, ++mainPalette)
    {
        NSBXXTex* texture = (*model)->GetTEX0();
        if (texture) *mainPalette = texture->block4VRAMLoadOffset_;
    }
    UpdateChestDiffuseColor();
}
