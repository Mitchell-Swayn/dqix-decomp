#include <globaldefs.h>
ARM
extern "C" char* ReadGlobalValueAt020FB3F0();bool IsGrottoBossFloorZone(int);class ActiveGrottoClass{public:int GetFloorCount() const;};
// Original: arm9/main @ 0x0209FD00; symbol: func_0209fd00; size: 0x64.
extern "C" int ReadZoneFloorOrActiveGrottoBossFloor(char* p){unsigned short* zone=*(unsigned short**)(*(char**)(p+4)+0x8e18);if(!zone)return -1;int floor=*zone%20;ActiveGrottoClass* grotto=(ActiveGrottoClass*)(ReadGlobalValueAt020FB3F0()+0x23ec);if(!grotto)floor=0;else if(IsGrottoBossFloorZone(*zone))floor=grotto->GetFloorCount()+1;return floor;}
