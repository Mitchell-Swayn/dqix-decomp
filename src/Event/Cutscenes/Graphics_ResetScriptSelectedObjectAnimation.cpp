#include <globaldefs.h>
ARM
struct Entry { unsigned kind,pad[2]; unsigned char* object; };
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" { void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int); void ActorSprite_SetMovingAnimationOverride(unsigned*,int); bool ActorSprite_SetPositiveAnimationPlaybackRate(char*,float); int Script_ReadParameterAsInteger(void*); extern Entry* EventGetObjectSession_UnknownRoleZeroInitializedStorage[]; extern char Graphics_ResetScriptSelectedObjectAnimation_TextStand[]; }
// Original: arm9/ov001 @ 0x0216013C; symbol: func_ov001_0216013c; size: 0xBC.
extern "C" int Graphics_ResetScriptSelectedObjectAnimation(void* parameter) {
 unsigned char* other;
 int index=Script_ReadParameterAsInteger(parameter);
 Entry* entries=EventGetObjectSession_UnknownRoleZeroInitializedStorage[1];
 unsigned kind=entries[index].kind;
 if(kind==2 || kind==6) {
  unsigned char* object=0;
  if(entries) object=entries[index].object;
  if(!object) return 0;
  if(*(void**)(object+0x14)) ActorSprite_SetMovingAnimationOverride(*(unsigned**)(object+0x14),0);
  if(*(void**)(object+0x14)) ActorSprite_SetPositiveAnimationPlaybackRate(*(char**)(object+0x14),1.0f);
 } else if(kind==1 || kind==0 || kind-4<=1) {
  other=0;
  if(entries) other=entries[index].object;
  if(!other) return 0;
  _ZN8Object3D18SetAnimationByNameEPKci(other,Graphics_ResetScriptSelectedObjectAnimation_TextStand,0);
 }
 return 1;
}
