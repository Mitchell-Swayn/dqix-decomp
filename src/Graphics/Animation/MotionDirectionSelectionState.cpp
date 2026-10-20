// Original data: arm9/main @ 0x020EFC18; symbol: data_020efc18; size: 1.
// Last selected motion-direction sector. Motion_SelectAnimationFromAngleAndTickState
// reads the signed value to keep the current sector and writes 0, 1, 2 or -1
// after selecting a direction or completing a return animation. Initial -1
// represents no retained sector. The legacy external identity remains unchanged.
extern "C" signed char MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes = -1;
