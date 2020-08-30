/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_joints_New6Dof */

#ifndef _Included_com_jme3_bullet_joints_New6Dof
#define _Included_com_jme3_bullet_joints_New6Dof
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    createDoubleEnded
 * Signature: (JJLcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;Lcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;I)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_New6Dof_createDoubleEnded
  (JNIEnv *, jclass, jlong, jlong, jobject, jobject, jobject, jobject, jint);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    createSingleEnded
 * Signature: (JLcom/jme3/math/Vector3f;Lcom/jme3/math/Matrix3f;I)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_New6Dof_createSingleEnded
  (JNIEnv *, jclass, jlong, jobject, jobject, jint);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    enableSpring
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_enableSpring
  (JNIEnv *, jclass, jlong, jint, jboolean);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getAngles
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getAngles
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getAxis
 * Signature: (JILcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getAxis
  (JNIEnv *, jclass, jlong, jint, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getCalculatedOriginA
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getCalculatedOriginA
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getCalculatedOriginB
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getCalculatedOriginB
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getFrameOffsetA
 * Signature: (JLcom/jme3/math/Transform;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getFrameOffsetA
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getFrameOffsetB
 * Signature: (JLcom/jme3/math/Transform;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getFrameOffsetB
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getPivotOffset
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_getPivotOffset
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getRotationalMotor
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_New6Dof_getRotationalMotor
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getRotationOrder
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_joints_New6Dof_getRotationOrder
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    getTranslationalMotor
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_joints_New6Dof_getTranslationalMotor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setAllEquilibriumPointsToCurrent
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setAllEquilibriumPointsToCurrent
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setDamping
 * Signature: (JIFZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setDamping
  (JNIEnv *, jclass, jlong, jint, jfloat, jboolean);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setEquilibriumPoint
 * Signature: (JIF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setEquilibriumPoint
  (JNIEnv *, jclass, jlong, jint, jfloat);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setEquilibriumPointToCurrent
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setEquilibriumPointToCurrent
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setRotationOrder
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setRotationOrder
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jme3_bullet_joints_New6Dof
 * Method:    setStiffness
 * Signature: (JIFZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_joints_New6Dof_setStiffness
  (JNIEnv *, jclass, jlong, jint, jfloat, jboolean);

#ifdef __cplusplus
}
#endif
#endif
