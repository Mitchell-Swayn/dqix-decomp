#pragma once

struct GPCImplementationData
{
    const char* pRevisionNumberString; // "17659 $", assigned during startup
    const char* pRevisionString; // "$Revision: 17659 $"
    unsigned int gpc0Signature;
    unsigned int gpc1Signature;
    unsigned int gpc2Signature;
};

#if defined(usa)
// A layout carrier for adjacent source-owned storage; the original declaration
// boundaries are unknown. Startup writes only the five runtime fields.
struct GPCStaticData
{
    GPCImplementationData runtime;
    char revision[20];
    char signature0[8];
    char signature1[8];
    char signature2[8];
};
extern GPCStaticData gpcData;
#endif
