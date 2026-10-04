#ifndef SYSTEM_RUNTIME_ARCTANGENT_H
#define SYSTEM_RUNTIME_ARCTANGENT_H

struct RuntimeArctangentAngles {
    double low[4];
    double high[4];
};

extern const RuntimeArctangentAngles gRuntimeArctangentAngles;
extern const double gRuntimeArctangentCoefficients[11];

#endif
