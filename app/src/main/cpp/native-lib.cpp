#include <jni.h>
#include <string>

#include <jni.h>
#include <string>
#define __ARM_NEON "OK"
#include <arm_neon.h>
#include <android/log.h>
#define LOG_TAG "TEST_NEON"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {
void test()
{
    int16_t result[8];
    int8x8_t a = vdup_n_s8(121);
    int8x8_t b = vdup_n_s8(2);
    int16x8_t c;
    c = vmull_s8(a,b);
    vst1q_s16(result,c);
    for(int i=0;i<8;i++){
        LOGD("data[%d] is %d ",i,result[i]);
    }
}

JNIEXPORT jstring JNICALL
Java_com_example_nonedemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    test();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
}