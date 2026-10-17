// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x02072E34; symbol: func_02072e34; size: 0x60.
extern "C" void GameState_BuildRelatedObjectIdList(int index,int* out){int base=index*12;out[0]=index;out[1]=base+19;out[2]=base+20;out[3]=base+21;out[4]=base+22;out[5]=base+23;out[6]=base+25;out[7]=base+27;out[8]=base+28;out[9]=base+29;out[10]=-1;}
