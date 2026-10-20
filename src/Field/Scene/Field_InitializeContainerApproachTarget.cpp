#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned GameObject_ChangeMotionStateAndRefreshAnimation(...);
extern "C" unsigned Camera_DisableOrbitInput(...);
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned GameState_GetFieldOrbitCamera(...);
extern "C" unsigned GameObject_DisableMovementInput(...);
extern "C" unsigned Object_SetHalfwordC6AndVectorC8(...);
extern "C" unsigned GameResources_SetSecondaryFlags(...);
extern "C" unsigned SetObjectAngleAndClearFlagC48000(...);
extern "C" unsigned _Z22fix32ReduceAngle0To2Pii(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState20GetUnknownGameObjectEv(...);
// Original: arm9/ov017 @ 0x021bf628; symbol: InitializePlayerAngleAndHorizontalTransitionTarget.
extern "C" int Field_InitializeContainerApproachTarget(char* p){void* game=(void*)_ZN9GameState11GetInstanceEv();char* player=(char*)_ZN9GameState20GetUnknownGameObjectEv(game);char* request=(char*)U(p,0xc);U(p,0x28)=U(request,8);U(p,0x2c)=U(request,12);U(p,0x30)=U(request,16);GameObject_DisableMovementInput(player,1);void* resources=(void*)GameResources_GetInstance();void* field=(void*)GameState_GetFieldOrbitCamera(game);if(field)Camera_DisableOrbitInput(field);if(resources)GameResources_SetSecondaryFlags(resources,0x80);SetObjectAngleAndClearFlagC48000(player,_Z22fix32ReduceAngle0To2Pii(*(short*)(request+0x20)));struct Vector{int x,y,z;};Vector position=*(Vector*)(player+0x44);position.x=U(request,8);position.z=U(request,16);Object_SetHalfwordC6AndVectorC8(player,&position,0xcc);GameObject_ChangeMotionStateAndRefreshAnimation(player,1);H(p,0x14)=5;return 1;}
