#include <globaldefs.h>
#include <GameState/GameState.h>
struct Source {char pad[0x38];unsigned char cursor;};struct Types {char pad[0x18];unsigned short values[6];};struct Object {char pad[0x138];Source* source;char rest[12];Types* types;};struct Owner {void* root;};
extern "C" Object* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);extern "C" int BattleAI_TryActionSlotAndBuildTargets(Owner*,unsigned,unsigned,void**,unsigned);extern "C" void* Combat_SelectAutomaticActionTargets(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0208A52C; symbol: func_0208a52c; size: 0xAC.
extern "C" unsigned Object_TrySixCyclicTypesThenFallback(Owner* self,unsigned id,void** output,unsigned arg) {Object* object=GameState_FindIndexedObjectWithFlag400(GameState::GetInstance(),id);Types* types=object->types;Source* source=object->source;for(unsigned char i=0;i<6;++i) {unsigned old=source->cursor;source->cursor=old+1;source->cursor=(int)source->cursor%6;if(BattleAI_TryActionSlotAndBuildTargets(self,old,id,output,arg))return types->values[old];}*output=0;*output=Combat_SelectAutomaticActionTargets(self->root,id,2,arg);return 2;}
