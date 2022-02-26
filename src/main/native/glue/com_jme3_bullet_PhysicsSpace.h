/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_PhysicsSpace */

#ifndef _Included_com_jme3_bullet_PhysicsSpace
#define _Included_com_jme3_bullet_PhysicsSpace
#ifdef __cplusplus
extern "C" {
#endif
#undef com_jme3_bullet_PhysicsSpace_AXIS_X
#define com_jme3_bullet_PhysicsSpace_AXIS_X 0L
#undef com_jme3_bullet_PhysicsSpace_AXIS_Y
#define com_jme3_bullet_PhysicsSpace_AXIS_Y 1L
#undef com_jme3_bullet_PhysicsSpace_AXIS_Z
#define com_jme3_bullet_PhysicsSpace_AXIS_Z 2L
/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    getWorldType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_PhysicsSpace_getWorldType
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    addAction
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addAction
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    addCharacterObject
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addCharacterObject
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    addConstraintC
 * Signature: (JJZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addConstraintC
  (JNIEnv *, jclass, jlong, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    addRigidBody
 * Signature: (JJII)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addRigidBody
  (JNIEnv *, jclass, jlong, jlong, jint, jint);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    createPhysicsSpace
 * Signature: (Lcom/jme3/math/Vector3f;Lcom/jme3/math/Vector3f;II)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_PhysicsSpace_createPhysicsSpace
  (JNIEnv *, jobject, jobject, jobject, jint, jint);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    getGravity
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_getGravity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    getNumConstraints
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_PhysicsSpace_getNumConstraints
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    getSolverInfo
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_PhysicsSpace_getSolverInfo
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    isSpeculativeContactRestitution
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jme3_bullet_PhysicsSpace_isSpeculativeContactRestitution
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    removeAction
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeAction
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    removeCharacterObject
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeCharacterObject
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    removeConstraint
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeConstraint
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    removeRigidBody
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeRigidBody
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    setGravity
 * Signature: (JLcom/jme3/math/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_setGravity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    setSolverType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_setSolverType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    setSpeculativeContactRestitution
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_setSpeculativeContactRestitution
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_PhysicsSpace
 * Method:    stepSimulation
 * Signature: (JFIFZZZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_stepSimulation
  (JNIEnv *, jclass, jlong, jfloat, jint, jfloat, jboolean, jboolean, jboolean);

#ifdef __cplusplus
}
#endif
#endif
