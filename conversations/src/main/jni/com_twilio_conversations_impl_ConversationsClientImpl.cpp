/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <talk/app/webrtc/java/jni/jni_helpers.h>
/* Header for class com_twilio_conversations_impl_ConversationsClientImpl */

#include "com_twilio_conversations_impl_ConversationsClientImpl.h"

#include "TSCoreSDK.h"
#include "TSCoreSDKTypes.h"
#include "TSCEndpoint.h"
#include "TSCSession.h"
#include "TSCLogger.h"

static TwilioCommon::AccessManager* getNativeAccessMgrFromJava(JNIEnv* jni, jobject j_accessMgr) ;

using namespace twiliosdk;
using namespace webrtc_jni;

JNIEXPORT jlong JNICALL Java_com_twilio_conversations_impl_ConversationsClientImpl_createEndpoint
        (JNIEnv *env, jobject obj, jobject j_accessMgr, jobjectArray optionsArray, jlong nativeEndpointObserver) {
    TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelDebug, "createEndpoint");

    TSCOptions options;

    int size = env->GetArrayLength(optionsArray);
    int i = 0;
    while (i < size) {
        jstring jKey = (jstring)env->GetObjectArrayElement(optionsArray, i); i++;
        jstring jValue = (jstring)env->GetObjectArrayElement(optionsArray, i); i++;
        std::string key = JavaToStdString(env, jKey);
        std::string value = JavaToStdString(env, jValue);
        options[key] = value;
        env->DeleteLocalRef(jKey);
        env->DeleteLocalRef(jValue);
    }

    if (!nativeEndpointObserver) {
        TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelError, "nativeEndpointObserver is null");
        return 0;
    }

    TSCEndpointObserverPtr *endpointObserver = reinterpret_cast<TSCEndpointObserverPtr *>(nativeEndpointObserver);
    TwilioCommon::AccessManager* accessManager = getNativeAccessMgrFromJava(env, j_accessMgr);

    if (accessManager == NULL) {
        TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelError, "AccessManager is null");
        return 0;
    }

    if (accessManager->getToken().empty()) {
        TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelError, "token is null");
        return 0;
    }

    TS_CORE_LOG_DEBUG("access token is:%s", accessManager->getToken().c_str());

    TSCEndpointPtr *endpoint = new TSCEndpointPtr();
    *endpoint = TSCSDK::instance()->createEndpoint(options, accessManager, *endpointObserver);

    return jlongFromPointer(endpoint);
}

static TwilioCommon::AccessManager* getNativeAccessMgrFromJava(JNIEnv* jni, jobject j_accessMgr) {
    jclass j_accessManagerClass = GetObjectClass(jni, j_accessMgr);
    jmethodID getNativeHandleId = GetMethodID(jni, j_accessManagerClass, "getNativeHandle", "()J");

    jlong j_am = jni->CallLongMethod(j_accessMgr, getNativeHandleId);
    return reinterpret_cast<TwilioCommon::AccessManager*>(j_am);
}

/*
 * Class:     com_twilio_conversations_impl_ConversationsClientImpl
 * Method:    listen
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_twilio_conversations_impl_ConversationsClientImpl_listen
        (JNIEnv *env, jobject obj, jlong nativeEndpoint) {
    TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelDebug, "listen");
    reinterpret_cast<TSCEndpointPtr *>(nativeEndpoint)->get()->registerEndpoint(true, true);
}

/*
 * Class:     com_twilio_conversations_impl_ConversationsClientImpl
 * Method:    unlisten
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_twilio_conversations_impl_ConversationsClientImpl_unlisten
        (JNIEnv *env, jobject obj, jlong nativeEndpoint) {
    TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelDebug, "unlisten");
    reinterpret_cast<TSCEndpointPtr *>(nativeEndpoint)->get()->unregisterEndpoint();
}


/*
 * Class:     com_twilio_conversations_impl_ConversationsClientImpl
 * Method:    reject
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_twilio_conversations_impl_ConversationsClientImpl_reject
        (JNIEnv *env, jobject obj, jlong nativeEndpoint, jlong nativeSession) {
    TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelDebug, "reject");
    TSCSessionPtr *session = reinterpret_cast<TSCSessionPtr *>(nativeSession);
    reinterpret_cast<TSCEndpointPtr *>(nativeEndpoint)->get()->reject(*session);
}

/*
 * Class:     com_twilio_conversations_impl_ConversationsClientImpl
 * Method:    freeNativeHandle
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_twilio_conversations_impl_ConversationsClientImpl_freeNativeHandle
        (JNIEnv *env, jobject obj, jlong nativeEndpoint) {
    TS_CORE_LOG_MODULE(kTSCoreLogModuleSignalSDK, kTSCoreLogLevelDebug, "freeNativeHandle");
    TSCEndpointPtr *endpoint = reinterpret_cast<TSCEndpointPtr *>(nativeEndpoint);
    if (endpoint != nullptr) {
        TSCSDK::instance()->destroyEndpoint(*endpoint);
        endpoint->reset();
        delete endpoint;
    }
}
