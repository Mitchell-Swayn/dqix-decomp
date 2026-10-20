#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned _ZNK8Object3D23GetTexturePaletteOffsetEv(void*);
extern "C" char* _ZN7Model3D7GetTEX0Ev(void*);
extern "C" void MemoryMapTexturePalette();
extern "C" void LoadToTexturePalette(const void* data, unsigned int offset, unsigned int length);
extern "C" void MemoryUnmapTexturePalette();
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void _Z28LockStagedTextureVRAMCopyingv();
extern "C" void _Z30UnlockStagedTextureVRAMCopyingv();
// Original: arm9/ov003 @ 0x0217CA84; symbol: func_ov003_0217ca84; size: 0xB8.
extern "C" void Graphics_FillModelTexturePalette(char *self, unsigned short color) {
    _ZN9GameState11GetInstanceEv();
    _Z28LockStagedTextureVRAMCopyingv();
    MemoryMapTexturePalette();
    if (*(void**)(self + 0x88)) {
        char *tex = _ZN7Model3D7GetTEX0Ev(*(void**)(self + 0x88));
        if (tex) {
            unsigned offset = *(unsigned*)(tex + 0x2c);
            if (_ZNK8Object3D23GetTexturePaletteOffsetEv(self + 0x80))
                offset = _ZNK8Object3D23GetTexturePaletteOffsetEv(self + 0x80);
            unsigned short *buffer;
            unsigned length = *(unsigned short*)(tex + 0x30) * 8;
            unsigned destination = (unsigned short)offset * 8;
            buffer = (unsigned short*)_ZN13SafeAllocator8AllocateEj(*(unsigned*)self,length);
            if (buffer) {
                for (unsigned i = 0; i < length / 2; i++) buffer[i] = color;
                _Z25CleanInvalidateCacheRangePKvj(buffer,length);
                LoadToTexturePalette(buffer,destination,length);
            }
        }
    }
    MemoryUnmapTexturePalette();
    _Z30UnlockStagedTextureVRAMCopyingv();
}
