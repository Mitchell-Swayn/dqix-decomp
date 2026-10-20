#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" unsigned Network_GetWirelessWorkspace();
struct OverlayEntry {unsigned unknown;void* key;void* value;OverlayEntry* next;};
struct EntryList {unsigned unknown;OverlayEntry* first;};
// Original: arm9/ov031 @ 0x0220EE50; symbol: func_ov031_0220ee50; size: 0x50.
// Looks up a key in the shared linked list when the published size exceeds twelve.
// Shared-state and node field roles are partial.
extern "C" OverlayEntry* FindOverlayLinkedEntryByKey(void* key) {
 char* shared=(char*)Network_GetWirelessWorkspace();
 EntryList* list=*(EntryList**)(shared+0x2270);
 OverlayEntry* entry=0;
 if(list) {
  if(*(unsigned*)(shared+0x2274)>12) {
   entry=list->first;
   if(entry)do {if(entry->key==key)break;entry=entry->next;}while(entry);
  }
 }
 return entry;
}
