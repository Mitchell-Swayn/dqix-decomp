#include <globaldefs.h>
// func_0205a234: 0x0205a234–0x0205a244, arm; 16 bytes
// Original: arm9/main @ 0x0205A234; symbol: func_0205a234; size: 0x10.
extern "C" void SpriteAnimation_ResetTrackList(unsigned int* output) {
    output[0] = 0;
        *(unsigned short*)((char*)output + 4) = 0;
}
