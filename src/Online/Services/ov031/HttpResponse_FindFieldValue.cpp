#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct NameValue {const char* name; void* value;};
struct NameTableOwner {char prefix[0x1a38];NameValue pairs[32];};
// Original: arm9/ov031 @ 0x02218E2C; symbol: HttpResponse_FindFieldValue; size: 0x58.
// Searches at most 32 name/value pairs, stopping at the first null name.
extern "C" void* HttpResponse_FindFieldValue(NameTableOwner* owner,const char* name) {
 int i=0;
 do {
  const char* key=owner->pairs[i].name;
  if(!key) break;
  if(!strcmp(name,key)) return owner->pairs[i].value;
 } while(++i<32);
 return 0;
}
