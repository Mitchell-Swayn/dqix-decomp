#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {
unsigned int RuntimeTextConversion_CountWideCharacters(const unsigned short*);
void Text_FormatBoundedVariadicString(void*,unsigned,unsigned,...);
int HttpRequest_InsertHeader(char*,const char*,const char*);
bool HttpRequest_AppendBase64FormField(char*,const char*,const unsigned char*,unsigned);
extern char NasAuth_AppendDeviceMetadataFields_Format03D03D[];
extern char NasAuth_AppendDeviceMetadataFields_TextSdkver[];
extern char NasAuth_AppendDeviceMetadataFields_TextUserid[];
extern char NasAuth_AppendDeviceMetadataFields_TextPasswd[];
extern char NasAuth_AppendDeviceMetadataFields_TextBssid[];
extern char NasAuth_AppendDeviceMetadataFields_TextApinfo[];
extern char NasAuth_AppendDeviceMetadataFields_TextGamecd[];
extern char NasAuth_AppendDeviceMetadataFields_TextMakercd[];
extern char NasAuth_AppendDeviceMetadataFields_TextUnitcd[];
extern char NasAuth_AppendDeviceMetadataFields_TextMacadr[];
extern char NasAuth_AppendDeviceMetadataFields_TextLang[];
extern char NasAuth_AppendDeviceMetadataFields_TextBirth[];
extern char NasAuth_AppendDeviceMetadataFields_TextDevtime[];
extern char NasAuth_AppendDeviceMetadataFields_TextDevname[];
extern char NasAuth_AppendDeviceMetadataFields_TextSsid[];
extern char NasAuth_AppendDeviceMetadataFields_FormatNitroWiFiSDKDD[];
extern char NasAuth_AppendDeviceMetadataFields_TextUserAgent[];
extern char NasAuth_AppendDeviceMetadataFields_TextHTTPXGAMECD[];
}
// Original: arm9/ov031 @ 0x022178B4; symbol: NasAuth_AppendDeviceMetadataFields; size: 0x34C.
// Appends SDK version and packed client fields as named six-bit encoded fields.
// devname is UTF-16; ssid is included only when optional == 1. Inserts
// User-Agent and HTTP_X_GAMECD headers, returning zero on the first failure.
extern "C" int NasAuth_AppendDeviceMetadataFields(char* self,const unsigned char* record,int optional)
{
 char version[33];
 Text_FormatBoundedVariadicString(version,33,(unsigned)NasAuth_AppendDeviceMetadataFields_Format03D03D,3,1);
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextSdkver,(const unsigned char*)version,strlen(version)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextUserid,record+0,strlen((const char*)record+0)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextPasswd,record+14,strlen((const char*)record+14)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextBssid,record+65,strlen((const char*)record+65)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextApinfo,record+111,strlen((const char*)record+111)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextGamecd,record+21,strlen((const char*)record+21)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextMakercd,record+26,strlen((const char*)record+26)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextUnitcd,record+29,strlen((const char*)record+29)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextMacadr,record+31,strlen((const char*)record+31)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextLang,record+44,strlen((const char*)record+44)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextBirth,record+47,strlen((const char*)record+47)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextDevtime,record+52,strlen((const char*)record+52)))return 0;
 if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextDevname,record+126,RuntimeTextConversion_CountWideCharacters((const unsigned short*)(record+126))*2))return 0;
 if(optional==1){
  if(HttpRequest_AppendBase64FormField(self,NasAuth_AppendDeviceMetadataFields_TextSsid,record+78,strlen((const char*)record+78)))return 0;
 }
 Text_FormatBoundedVariadicString(version,33,(unsigned)NasAuth_AppendDeviceMetadataFields_FormatNitroWiFiSDKDD,3,1);
 if(HttpRequest_InsertHeader(self,NasAuth_AppendDeviceMetadataFields_TextUserAgent,version))return 0;
 return HttpRequest_InsertHeader(self,NasAuth_AppendDeviceMetadataFields_TextHTTPXGAMECD,(const char*)record+21)==0;
}
