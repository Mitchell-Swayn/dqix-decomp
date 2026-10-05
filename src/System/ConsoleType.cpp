#include "System/ConsoleType.h"

unsigned int g_consoleType = 0xffffffff;

// USA: 0x020c7dcc
unsigned int GetConsoleType()
{
    g_consoleType = 0x82000001;
    return 0x82000001;
}
