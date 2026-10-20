#include <globaldefs.h>
typedef struct {int x,y,z;} Vector;typedef struct GameState GameState;typedef struct GameObject GameObject;typedef struct Object3D Object3D;
#define GameState_GetInstance _ZN9GameState11GetInstanceEv
#define GameState_GetPartyMemberByIndex _ZN9GameState21GetPartyMemberByIndexEi
#define Object3D_EnableFlag _ZN8Object3D10EnableFlagEi
extern GameState *GameState_GetInstance(void);extern GameObject *GameState_GetPartyMemberByIndex(GameState *,int);extern void Object3D_EnableFlag(Object3D *,int);
extern void GameObject_SetMotionState(Object3D *,int);extern void GameObject_GetAuthorityPosition(Vector *,GameObject *);extern void SetObjectAngleAndClearFlagC48000(Object3D *,int);extern void GameObject_SetCameraDisplacementPulse(Object3D *,int,int);extern void Vector3fix_Subtract(const Vector *,const Vector *,Vector *);extern void Vector3fix_Normalize(const Vector *,Vector *);extern int fix32_Atan2(int,int);
// Original: arm9/main @ 0x02078CC0; symbol: func_02078cc0; size: 0xC4.
int FieldMonster_EnterPartyFacingReaction(Object3D *p){struct Scratch {Vector position,direction,copy;} scratch;unsigned char *raw=(unsigned char *)p;GameObject *member=GameState_GetPartyMemberByIndex(GameState_GetInstance(),*(unsigned short *)(raw+0x166));if(!member)return 0;GameObject_SetMotionState(p,0);*(short *)(raw+0xb0)=0x328;*(short *)(raw+0xb2)=0;GameObject_GetAuthorityPosition(&scratch.position,member);scratch.copy=scratch.position;Vector3fix_Subtract(&scratch.copy,(Vector *)(raw+0x44),&scratch.direction);Vector3fix_Normalize(&scratch.direction,&scratch.direction);SetObjectAngleAndClearFlagC48000(p,fix32_Atan2(scratch.direction.x,scratch.direction.z));Object3D_EnableFlag(p,0x80);GameObject_SetCameraDisplacementPulse(p,0xcc,0xaf0);raw[0x17a]=0;return 1;}
