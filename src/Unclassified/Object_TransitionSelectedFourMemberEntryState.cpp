#pragma optimize_for_size off
#include <globaldefs.h>
ARM
struct Entry { unsigned char bytes[20]; };extern "C" Entry data_020fdc60[4];extern "C" void Object_ForceOrTransitionByteStateToFour(Entry*,int);
// Original: arm9/main @ 0x02027304; symbol: func_02027304; size: 0x88.
extern "C" void Object_TransitionSelectedFourMemberEntryState(unsigned char* object,int wanted) {if(wanted<0){for(int i=0;i<4;++i)Object_ForceOrTransitionByteStateToFour(data_020fdc60+i,0);return;}if(wanted>=4)return;for(int i=0;i<4;i++)if(wanted==(object+i)[0x758]){Object_ForceOrTransitionByteStateToFour(data_020fdc60+i,0);return;}}
