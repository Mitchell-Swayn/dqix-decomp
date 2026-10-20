#include <globaldefs.h>
extern "C" char* GameObject_GetLinkedIndexedState(unsigned);
// Original: arm9/main @ 0x0209AC28; symbol: func_0209ac28; size: 0xB4.
extern "C" ARM bool SpellTable_CanLearnSpellAtCurrentLevel(char** p,unsigned owner,unsigned key)
{
    if(!(*p+0x10c))return false;
    if(!(*p+0x51c))return false;
    char* object=GameObject_GetLinkedIndexedState(owner);
    if(!object)return false;
    int i=0;
    unsigned index=*(unsigned*)(object+0x950)&255;
    int level=*(unsigned short*)(object+index*2+0x16c)&255;
    for(;i<*(int*)(*p+index*4+0x51c);++i)
    {
        char* row=*p+index*0x50+i*4;
        if(key==*(unsigned short*)(row+0x10c))return (int)*(unsigned short*)(row+0x10e)<=level;
    }return false;
}
