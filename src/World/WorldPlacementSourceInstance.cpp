#include "World/WorldPlacementSource.h"

extern "C" WorldPlacementSource data_02108fe4;

WorldPlacementSource* WorldPlacementSource::GetInstance()
{
    return &data_02108fe4;
}
