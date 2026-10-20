#include <globaldefs.h>
extern "C" {
void* _ZN9GameState11GetInstanceEv();
int GameState_FindIndexedObjectWithFlag400(void*,short);
}

// Original: arm9/ov000 @ 0x0215EC1C; symbol: func_ov000_0215ec1c; size: 0x64.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int Combat_CollectPresentEnemyIndices(void*, short* output, int capacity)
{
    int count=0;
    for(int i=0;i<8;++i)
    {
        short id=(short)(i+0xc0);
        if(GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),id))
        {
            output[count++]=id;
            if(count==capacity) return count;
        }
    }
    return count;
}
