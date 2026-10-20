#include <globaldefs.h>
ARM
extern "C" int Filesystem_LoadNamedFileAndProcessUnderLoaderLock(void*,void*);
struct LoadedTriples { unsigned short unknown0; unsigned short values[3]; unsigned short bytes[3]; unsigned char unknown14[6]; };
struct TripleOutput { unsigned short values[3]; unsigned short unknown6; unsigned char bytes[3]; };
// Original: arm9/ov017 @ 0x021B8ABC; symbol: FieldBattle_TryLoadScriptedMonsterFormation; size: 0x78.
// Processes a nonnegative script token and copies three halfwords and three low bytes to output.
extern "C" bool FieldBattle_TryLoadScriptedMonsterFormation(int token,TripleOutput* output)
{
 LoadedTriples temporary;
 if(token>-1 && Filesystem_LoadNamedFileAndProcessUnderLoaderLock(&temporary,(void*)token)){
  for(int i=0;i<3;i++){
   output->values[i]=temporary.values[i];
   output->bytes[i]=temporary.bytes[i];
  }
  return true;
 }
 return false;
}
