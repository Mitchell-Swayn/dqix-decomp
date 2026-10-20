#include <globaldefs.h>
#include <Graphics/NSBXX/NSBXX.h>
ARM

extern "C" {
void* _ZN7Model3D7GetTEX0Ev(void*);
int Memory_ClaimFirstAvailablePoolSlot(void*);
void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned);
int _Z23StageTexFilePaletteDataPV8NSBXXTexb(volatile void*, bool);
void _ZN8Object3D23SetTexturePaletteOffsetEj(void*, unsigned);
}
// Original: arm9/ov000 @ 0x02166784; symbol: func_ov000_02166784; size: 0x80.
// Assigns and stages a texture palette for records in the accepted signed-index range.
extern "C" void Graphics_AssignPaletteToEligibleTextureRecord(void* self, char* modelOwner, char* record) {
    short recordIndex = *(short*)(record + 4);
    int relativeIndex = recordIndex - 0xc0;
    if (relativeIndex < 0 || relativeIndex > 0xc7) return;

    void* model = *(void**)(modelOwner + 8);
    if (!model) return;
    NSBXXTex* texture = (NSBXXTex*)_ZN7Model3D7GetTEX0Ev(model);
    if (!texture) return;

    unsigned paletteOffset = (unsigned)Memory_ClaimFirstAvailablePoolSlot(self);
    unsigned paletteSize = (unsigned)*(unsigned short*)((char*)texture + 0x30) << 3;
    const void* paletteData = (char*)texture + *(unsigned*)((char*)texture + 0x38);
    _Z25CleanInvalidateCacheRangePKvj(paletteData, paletteSize);
    NSBXX_Tex_WritePaletteVRAMOffset(texture, (int)paletteOffset);
    _Z23StageTexFilePaletteDataPV8NSBXXTexb((volatile void*)texture, true);
    _ZN8Object3D23SetTexturePaletteOffsetEj(record, paletteOffset);
}
