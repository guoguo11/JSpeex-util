#include "util_speex_SpeexUtils.h"
#include "SpeexDecode.h"
JNIEXPORT jboolean JNICALL Java_util_speex_SpeexUtils_decode
(JNIEnv * env, jobject p2, jstring p3, jstring p4){
    const char *str3 = (*env)->GetStringUTFChars(env, p3, 0);
    const char *str4 = (*env)->GetStringUTFChars(env, p4, 0);
    return decode(str3,str4);
}