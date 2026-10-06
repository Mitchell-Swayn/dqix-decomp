struct ZoneRecordNibbleData
{
    unsigned int unknown_0 : 11;
    unsigned int lowerGroupLowerPair : 4;
    unsigned int lowerGroupUpperPair : 4;
    unsigned int upperGroupLowerPair : 4;
    unsigned int upperGroupUpperPair : 4;
    unsigned int unknown_1b : 5;
};

struct ZoneRecordNibbleReference
{
    ZoneRecordNibbleData* data;
    unsigned int unknown_4;
    unsigned int type : 4;
    unsigned int unknown_8 : 28;
};

extern "C" int func_020de2a4(ZoneRecordNibbleReference* reference, int upperPair, int upperGroup)
{
    unsigned int type = reference->type;
    int standardType;
    if (type <= 7)
        standardType = 1;
    else
        standardType = 0;
    if (!standardType)
    {
        if (type != 11)
            return 0;
    }

    ZoneRecordNibbleData* data = reference->data;
    if (!data)
        return 0;

    if (upperGroup)
    {
        if (upperPair)
            return data->upperGroupUpperPair;
        return data->upperGroupLowerPair;
    }

    if (upperPair)
        return data->lowerGroupUpperPair;
    return data->lowerGroupLowerPair;
}
