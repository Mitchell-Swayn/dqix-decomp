#include <globaldefs.h>
ARM
struct Object { unsigned char pad[0x776]; unsigned char state; };
typedef void (Object::*Callback)();
struct InitFlags { unsigned pad[7]; unsigned flags; };
struct CallbackOwner { unsigned char pad[0x40]; Callback callback; };
extern "C" unsigned char data_ov023_021ffa0c[];
extern "C" InitFlags data_ov023_021ff9e0;
extern "C" Callback data_020e6d5c;
extern "C" CallbackOwner data_ov023_021fda60;
extern "C" Callback data_ov023_021fda88[];
extern "C" void Util_UpdateRandomPointTimers(void*);
// Original: arm9/ov023 @ 0x021DC488; symbol: func_ov023_021dc488; size: 0x98.
extern "C" int DispatchInitializedObjectStateMemberCallback(Object* self) {
 Util_UpdateRandomPointTimers(data_ov023_021ffa0c);
 if(!(data_ov023_021ff9e0.flags&1)) {
  data_ov023_021fda60.callback=data_020e6d5c;
  data_ov023_021ff9e0.flags|=1;
 }
 if(data_ov023_021fda88[self->state]==0) return 1;
 (self->*data_ov023_021fda88[self->state])();
 return 0;
}
