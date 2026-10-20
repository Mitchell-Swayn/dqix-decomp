#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ModsDecoder_DecodeNextAudioBlock(char*,void*);
inline int DecodeBlock(char* decoder,void* output){return ModsDecoder_DecodeNextAudioBlock(decoder,output);}
// Original: arm9/ov016 @ 0x0218E768; symbol: func_ov016_0218e768; size: 0x24.
// Rejects a null decoder and reports whether decoding into the output succeeds.
extern "C" int TryDecodeAudioBlock(char* decoder,void* output) {
 if(!decoder)return 0;
 return DecodeBlock(decoder,output)==1;
}
