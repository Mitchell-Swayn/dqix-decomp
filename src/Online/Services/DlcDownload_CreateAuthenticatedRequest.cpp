#include <globaldefs.h>
ARM
#pragma opt_rebuildconditionals off
#pragma opt_rebuildlogicals off
#pragma opt_generateconditionalassignments off

extern "C" int DlcDownload_EncodeUserAndCartridgeIdentifiers(void *code, void *identifier);
extern "C" void DlcDownload_DestroyUnsubmittedRequest(void *state, void *object);
extern "C" int Graphics_TrySetSharedProcessingFlag(void);
extern "C" void NasAuth_ReleaseRequestProcessingGuard(void);
extern "C" unsigned int Util_CountStringBytesViaSharedRoutine(const char *p);
extern "C" void Memory_ZeroBytes(void *dst, unsigned int length);
extern "C" int Network_RegisterOrUpdateKeyedRecordIfStateEmpty(unsigned int *p, unsigned int a, unsigned int b);
extern "C" int Http_AddStringPostField(void *request, const char *key, const char *value);
extern "C" int Util_SetFieldsIfFirstWordZero(int a0, int a1, int a2);
extern "C" void *Http_CreateRequestFromUrl(void *url, int method, void *storage, int length, void *callback, void *context);
extern "C" void DlcDownload_EncodeBase64String(void *dst, const void *src, unsigned length);
extern "C" void DlcDownload_HandleHttpCompletion(int status, void *http, void *ctx);

extern "C" void *(*DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage)(unsigned size, unsigned align);
extern "C" int DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant2;
#define ERR (*(int volatile *)&DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant2)
extern "C" void (*DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3)(void *);
extern "C" void *DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant4;
extern "C" void *DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" unsigned char DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant5[];
extern "C" unsigned char DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" unsigned char DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant7[];
extern "C" char *DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" unsigned char DlcDownloadCreateAuthenticatedRequest_UnknownRoleDataReferences[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextUserAgent[];
extern "C" unsigned char DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant5[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextGamecd[];
extern "C" unsigned char DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextRhgamecd[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextPasswd[];
extern "C" unsigned char DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextToken[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextUserid[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextMacadr[];
extern "C" unsigned char DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextAction[];
extern "C" void *DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[3];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextAttr1[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextAttr2[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextAttr3[];
extern "C" int DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage;
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextApinfo[];
extern "C" unsigned char DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" char DlcDownload_CreateAuthenticatedRequest_TextOptionallogdata[];

// Original: arm9/ov031 @ 0x0223EDE0; symbol: func_ov031_0223ede0; size: 0x3a8.
// Allocates a DLC request, builds authenticated POST fields, and returns the HTTP handle.
extern "C" int DlcDownload_CreateAuthenticatedRequest(int **outObject, unsigned *outRequest, void *action, void *storage, int length, const char *optionalLog) {
    if (!DlcDownload_EncodeUserAndCartridgeIdentifiers(DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant5, DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant6)) {
        ERR = 8;
        return 0;
    }
    void *object = DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage(0x24, 4);
    if (!object) {
        ERR = 1;
        return 0;
    }
    ((void **)object)[2] = DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant4;
    ((void **)object)[3] = 0;
    if (!Graphics_TrySetSharedProcessingFlag()) {
        DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3(object);
        ERR = 2;
        return 0;
    }
    void *request = Http_CreateRequestFromUrl(DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant3, 1, storage, length, (void *)DlcDownload_HandleHttpCompletion, object);
    if (!request) {
        NasAuth_ReleaseRequestProcessingGuard();
        DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3(object);
        ERR = 3;
        return 0;
    }
    *outObject = (int *)object;
    *outRequest = (unsigned)request;
    if (!Util_SetFieldsIfFirstWordZero((int)request, (int)DlcDownloadCreateAuthenticatedRequest_UnknownRoleDataReferences, 1)) {
        goto fail;
    }
    if (!Network_RegisterOrUpdateKeyedRecordIfStateEmpty((unsigned int *)request, (unsigned)DlcDownload_CreateAuthenticatedRequest_TextUserAgent, (unsigned)DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant5)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextGamecd, (const char *)DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextRhgamecd, (const char *)DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant5)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextPasswd, (const char *)DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant4)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextToken, DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant2)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextUserid, (const char *)DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant6)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextMacadr, (const char *)DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant2)) {
        goto fail;
    }
    if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextAction, (const char *)action)) {
        goto fail;
    }
    if (DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[0]) {
        if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextAttr1, (const char *)DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[0])) {
            goto fail;
        }
    }
    if (DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[1]) {
        if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextAttr2, (const char *)DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[1])) {
            goto fail;
        }
    }
    if (DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[2]) {
        if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextAttr3, (const char *)DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[2])) {
            goto fail;
        }
    }
    if (DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage) {
        if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextApinfo, (const char *)DlcDownloadInitializeClient_UnknownRoleZeroInitializedStorage_Variant3)) {
            goto fail;
        }
    }
    if (optionalLog) {
        unsigned int n = Util_CountStringBytesViaSharedRoutine(optionalLog);
        if ((int)n > 0x40) {
            ERR = 7;
            DlcDownload_DestroyUnsubmittedRequest(object, request);
            return 0;
        }
        Memory_ZeroBytes(DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant7, 0x59);
        DlcDownload_EncodeBase64String(DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant7, optionalLog, n);
        if (!Http_AddStringPostField(request, DlcDownload_CreateAuthenticatedRequest_TextOptionallogdata, (const char *)DlcDownloadCreateAuthenticatedRequest_UnknownRoleZeroInitializedStorage_Variant7)) {
            goto fail;
        }
    }
    return 1;
fail:
    DlcDownload_DestroyUnsubmittedRequest(object, request);
    ERR = 1;
    return 0;
}
