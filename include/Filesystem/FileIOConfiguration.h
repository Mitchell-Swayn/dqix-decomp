#pragma once

// Adjacent storage is grouped to preserve original layout, not to assert the
// original declarations. The language pointer order is observed in the binary.
struct FileIOConfiguration
{
    char german[3];
    char italian[3];
    char french[3];
    char spanish[3];
    char english[3];
    char japanese[3];
    unsigned char padding[2];
    const char* revision;
    const char* revisionNumber;
    char revisionText[20];
    char* languages[6];
    char archiveSignature[4];
    char archiveRoot[6];
    char languageTag[6];
};

extern FileIOConfiguration gFileIOConfiguration;
