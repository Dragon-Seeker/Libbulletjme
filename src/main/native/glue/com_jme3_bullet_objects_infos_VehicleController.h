/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_objects_infos_VehicleController */

#ifndef _Included_com_jme3_bullet_objects_infos_VehicleController
#define _Included_com_jme3_bullet_objects_infos_VehicleController
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    addWheel
 * Signature: (JLorg/joml/Vector3f;Lorg/joml/Vector3f;Lorg/joml/Vector3f;FFJZ)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_addWheel
  (JNIEnv *, jclass, jlong, jobject, jobject, jobject, jfloat, jfloat, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    applyEngineForce
 * Signature: (JIF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_applyEngineForce
  (JNIEnv *, jclass, jlong, jint, jfloat);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    brake
 * Signature: (JIF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_brake
  (JNIEnv *, jclass, jlong, jint, jfloat);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    createRaycastVehicle
 * Signature: (JJJ)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_createRaycastVehicle
  (JNIEnv *, jclass, jlong, jlong, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    finalizeNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_finalizeNative
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getCurrentVehicleSpeedKmHour
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getCurrentVehicleSpeedKmHour
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getForwardAxisIndex
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getForwardAxisIndex
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getForwardVector
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getForwardVector
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getNumWheels
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getNumWheels
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getRightAxisIndex
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getRightAxisIndex
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    getUpAxisIndex
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_getUpAxisIndex
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    rayCast
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_rayCast
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    resetSuspension
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_resetSuspension
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    setCoordinateSystem
 * Signature: (JIII)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_setCoordinateSystem
  (JNIEnv *, jclass, jlong, jint, jint, jint);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    setupCoordinateSystem
 * Signature: (JLorg/joml/Vector3f;Lorg/joml/Vector3f;Lorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_setupCoordinateSystem
  (JNIEnv *, jclass, jlong, jobject, jobject, jobject);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    steer
 * Signature: (JIF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_steer
  (JNIEnv *, jclass, jlong, jint, jfloat);

/*
 * Class:     com_jme3_bullet_objects_infos_VehicleController
 * Method:    updateWheelTransform
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_infos_VehicleController_updateWheelTransform
  (JNIEnv *, jclass, jlong, jint, jboolean);

#ifdef __cplusplus
}
#endif
#endif
