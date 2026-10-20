#include <globaldefs.h>
ARM
// Original: arm9/ov009 @ 0x0218A484; symbol: func_ov009_0218a484; size: 0x44.
extern "C" void CharacterNameFilter_CopyUppercaseAsciiBytes(int character,const signed char* source,signed char* destination) {
 while ((character=*source)!=0) {
 if(character>='a' && character<='z') character=(*destination=character-32);
 else character=(*destination=character);
 if(character) source++;
 destination++;
 }
}
