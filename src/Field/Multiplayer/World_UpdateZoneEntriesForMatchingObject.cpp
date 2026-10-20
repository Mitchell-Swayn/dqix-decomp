#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void UpdateMatchingZoneOpcode6AEntries(void*,int,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char,unsigned);
// Original: arm9/ov017 @ 0x021D18D8; symbol: func_ov017_021d18d8; size: 0x94.
extern "C" void World_UpdateZoneEntriesForMatchingObject(int index,const unsigned char* data,void* state) {
void* object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
int equal=1;
void* unknown=_ZN9GameState20GetUnknownGameObjectEv(state);
unsigned short id=_ZNK8Object3D10GetField06Ev(object);
if(id!=_ZNK8Object3D10GetField06Ev(unknown)) equal=0;
UpdateMatchingZoneOpcode6AEntries((void*)index,equal,data[4],data[5],data[6],data[7],data[8],data[9],*(const unsigned*)(data+12));
}
