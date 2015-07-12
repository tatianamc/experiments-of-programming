#include "TestJNI.h"

int main( )
{
	return 1;
}

JNIEXPORT jint JNICALL Java_TestJNI_testJNI(JNIEnv * je, jobject jo)
{
	printf( "!!! In the native method !!!\n" );
	return 32;
}
