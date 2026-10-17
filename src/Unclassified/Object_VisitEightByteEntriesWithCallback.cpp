#include <globaldefs.h>
extern "C" {
ARM struct Table { unsigned short count; char reserved[6]; unsigned char* entries; };
// Original: arm9/main @ 0x020DFA68; symbol: func_020dfa68; size: 0x54.
 int Object_VisitEightByteEntriesWithCallback(Table* self, void (*callback)(Table*,unsigned char*)) { int count; unsigned char* entry=self->entries; if(!entry || !(count=self->count) || !callback) return 0; for(int i=0;i<count;i++,entry+=8) callback(self,entry); return 1; }
}
