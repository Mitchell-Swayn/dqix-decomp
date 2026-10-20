#include <globaldefs.h>
ARM
extern "C" void ResourceHandle_InitializeArchiveAndPlaybackState(void*); extern "C" void SoundSfx_SetScaledPlayerVolumes(void*,unsigned); extern "C" void SoundSfx_SetVolumeSetting(void*,int);
struct Slot { unsigned value; short index,pad; }; struct Object { unsigned char padding[0xb0]; Slot slots[3]; };
// Original: arm9/main @ 0x0205E88C; symbol: func_0205e88c; size: 0x48.
extern "C" void ResourceHandle_InitializeThreeValueIndexSlots(Object* object) { ResourceHandle_InitializeArchiveAndPlaybackState(object); object->slots[0].value=0; object->slots[0].index=-1; object->slots[1].value=0; object->slots[1].index=-1; object->slots[2].value=0; object->slots[2].index=-1; SoundSfx_SetScaledPlayerVolumes(object,0x7f); SoundSfx_SetVolumeSetting(object,3); }
