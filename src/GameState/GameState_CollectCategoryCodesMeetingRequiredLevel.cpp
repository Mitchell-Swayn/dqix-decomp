#pragma thumb off
#pragma optimization_level 2

extern "C" char* GameObject_GetLinkedIndexedState(void*);
// Original: arm9/main @ 0x0209AB7C; symbol: func_0209ab7c; size: 0xAC.
extern "C" int GameState_CollectCategoryCodesMeetingRequiredLevel(char* volatile* state,void* key,unsigned char* output){char* initial=*state;if(!(initial+0x10c))return 0;if(!(initial+0x51c))return 0;char* person=GameObject_GetLinkedIndexedState(key);if(!person)return 0;int category=*(int*)(person+0x950);int i;int result=0;i=result;for(;i<*(int*)(*state+category*4+0x51c);++i){char* entry=*state+category*0x50+i*4;int required=*(unsigned short*)(entry+0x10e);int code=*(unsigned short*)(entry+0x10c);if((int)*(unsigned short*)(person+*(int*)(person+0x950)*2+0x16c)>=required){output[result]=code;++result;}}return result;}
