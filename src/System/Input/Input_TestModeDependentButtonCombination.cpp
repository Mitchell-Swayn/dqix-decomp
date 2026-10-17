#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
extern char data_02114e30[];int Input_TestKeyMask(void *,int);
// Original: arm9/main @ 0x0202AA94; symbol: func_0202aa94; size: 0xA0.
bool Input_TestModeDependentButtonCombination(int *p){switch(p[16]){case 0:if(Input_TestKeyMask(data_02114e30,128))return true;case 1:if(Input_TestKeyMask(data_02114e30,128)&&Input_TestKeyMask(data_02114e30,1024))return true;case 2:if(Input_TestKeyMask(data_02114e30,128)&&Input_TestKeyMask(data_02114e30,2048))return true;}return false;}
}
