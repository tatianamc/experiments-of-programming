#include <windows.h>
#include "TestJNI.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                      DWORD ul_reason_for_call, LPVOID lpReserved)
{
return TRUE;
}

JNIEXPORT jint JNICALL _Java_TestJNI_tn
  (JNIEnv * je, jobject jo)
{
	printf( "!!! In the native method !!!\n" );
	return 32;
}
