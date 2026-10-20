struct Triple{unsigned x,y,z;};extern "C" void __clear(void*,unsigned);
// Original: arm9/main @ 0x02049B54; symbol: func_02049b54; size: 0x58.
extern "C" Triple CombatantMotion_GetHomePosition(char* owner){Triple result;__clear(&result,12);unsigned* data=*(unsigned**)(owner+0x13c);if(!data)return result;{unsigned z=data[3];unsigned x=data[1];result.x=x;result.y=0xcc;result.z=z;}return result;}
