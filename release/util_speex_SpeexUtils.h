#include <jni.h>

#ifndef _Included_util_speex_SpeexUtils
#define _Included_util_speex_SpeexUtils
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jboolean JNICALL Java_util_speex_SpeexUtils_decode
  (JNIEnv * p1, jobject p2, jstring p3, jstring p4);

#ifdef __cplusplus
}
#endif
#endif
