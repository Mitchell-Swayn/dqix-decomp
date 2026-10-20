#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" void Field_CopyMonsterIdentitySnapshot(void*,const void*);extern "C" void Field_ApplyAssembledMonsterSpawn(void*,void*);
// Original: arm9/ov017 @ 0x021D451C; symbol: UpsertPackedFourteenByteRecord; size: 0xC4.
// Updates a matching key or first empty thirty-byte slot and marks packed field4 present.
extern "C" void Field_UpsertMonsterDescriptorFragment(unsigned char* records,unsigned short* input){unsigned char* found=0;unsigned char* empty=found;unsigned char* record;for(int i=0;i<48;i++){unsigned key=*input;record=records+i*30;if(key==*(unsigned short*)(record+2)){found=record;break;}if(!empty && !record[0])empty=record;}if(found){Field_CopyMonsterIdentitySnapshot(found+4,input);*(unsigned short*)(found+2)=*input;found[0]|=1;Field_ApplyAssembledMonsterSpawn(records,found);}else if(empty){Field_CopyMonsterIdentitySnapshot(empty+4,input);*(unsigned short*)(empty+2)=*input;empty[0]|=1;Field_ApplyAssembledMonsterSpawn(records,empty);}}
