// ARM range reviewed; all named globals checked against exact relocations.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char data_020e8ebc[];extern "C" char data_02107850[];extern "C" unsigned int data_02101640[];
// Original: arm9/main @ 0x02046968; symbol: func_02046968; size: 0x4C.
extern "C" void LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(unsigned char** p){while(*p){unsigned char* node=*p;if(node[1]){node[2]=0;(*p)[3]=0;*p=*(unsigned char**)(*p+4);}else{node[3]=1;return;}}}
