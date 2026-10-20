#include <globaldefs.h>
ARM
struct Group {short key;unsigned short count;short* values;char rest[16];};
struct Owner {char pad[8];Group* groups;char gap[8];unsigned short count;};
// Original: arm9/ov023 @ 0x021E27F8; symbol: func_ov023_021e27f8; size: 0x70.
// Returns the first 24-byte group whose signed halfword list contains the requested value.
extern "C" Group* FindGroupContainingSignedHalfword(Owner* self,int value){
 Group* groups;unsigned short count;unsigned short i;
 i=0;groups=self->groups;count=self->count;
 for(;i<count;i++){
 Group* group=groups+i;unsigned short entries=group->count;
 for(unsigned short j=0;j<entries;j++)if(value==group->values[j])return group;
 }
 return 0;
}
