/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_joints_SoftLinearJoint */

#ifndef _Included_com_jme3_bullet_joints_SoftLinearJoint
#define _Included_com_jme3_bullet_joints_SoftLinearJoint
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_joints_SoftLinearJoint
 * Method:    createJointSoftRigid
 * Signature: (JIJFFFLorg/joml/Vector3f;)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_SoftLinearJoint_createJointSoftRigid
  (JNIEnv *, jclass, jlong, jint, jlong, jfloat, jfloat, jfloat, jobject);

/*
 * Class:     com_jme3_bullet_joints_SoftLinearJoint
 * Method:    createJointSoftSoft
 * Signature: (JIJIFFFLorg/joml/Vector3f;)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_SoftLinearJoint_createJointSoftSoft
  (JNIEnv *, jclass, jlong, jint, jlong, jint, jfloat, jfloat, jfloat, jobject);

/*
 * Class:     com_jme3_bullet_joints_SoftLinearJoint
 * Method:    setPosition
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_SoftLinearJoint_setPosition
  (JNIEnv *, jclass, jlong, jobject);

#ifdef __cplusplus
}
#endif
#endif
