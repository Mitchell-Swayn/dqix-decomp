#include <globaldefs.h>
#include <System/Cache.h>
ARM
extern "C" void Object_InvokeLockMutex();
extern "C" void SoundCommand_UnlockMutex();
struct CommandLink { void* first;CommandLink* next; };
struct CommandNode { unsigned char pad[0x18]; CommandLink* link; };
// Original: arm9/main @ 0x020D2B34; symbol: SND_AssignWaveArc; size: 0xCC.
// Rebinds an indexed command slot under the global mutex, repairing the former link and cleaning affected cache ranges.
extern "C" void SND_AssignWaveArc(char* owner,int index,CommandNode* node)
{
    Object_InvokeLockMutex();
    CommandNode* old=*(CommandNode**)(owner+index*8+0x18);
    if(old) {
        if(node==old) { SoundCommand_UnlockMutex();return; }
        CommandLink* slot=(CommandLink*)(owner+0x18)+index;
        CommandLink* link=old->link;
        if(slot==link) {
            old->link=*(CommandLink**)(owner+index*8+0x1c);
            CleanCacheRange(*(CommandNode**)(owner+index*8+0x18),0x3c);
        } else {
            while(link) {
                if(slot==link->next)break;
                link=link->next;
            }
            link->next=((CommandLink*)(owner+0x18)+index)->next;
            CleanCacheRange(link,8);
        }
    }
    CommandLink* saved=node->link;
    node->link=(CommandLink*)(owner+0x18)+index;
    ((CommandLink*)(owner+0x18)+index)->next=saved;
    ((CommandLink*)(owner+0x18)+index)->first=node;
    SoundCommand_UnlockMutex();
    CleanCacheRange(owner,0x3c);
    CleanCacheRange(node,0x3c);
}
