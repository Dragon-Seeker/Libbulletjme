/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_objects_PhysicsRigidBody */

#ifndef _Included_com_jme3_bullet_objects_PhysicsRigidBody
#define _Included_com_jme3_bullet_objects_PhysicsRigidBody
#ifdef __cplusplus
extern "C" {
#endif
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_NONE
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_NONE 0L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_01
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_01 1L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_02
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_02 2L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_03
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_03 4L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_04
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_04 8L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_05
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_05 16L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_06
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_06 32L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_07
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_07 64L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_08
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_08 128L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_09
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_09 256L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_10
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_10 512L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_11
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_11 1024L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_12
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_12 2048L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_13
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_13 4096L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_14
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_14 8192L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_15
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_15 16384L
#undef com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_16
#define com_jme3_bullet_objects_PhysicsRigidBody_COLLISION_GROUP_16 32768L
#undef com_jme3_bullet_objects_PhysicsRigidBody_massForStatic
#define com_jme3_bullet_objects_PhysicsRigidBody_massForStatic 0.0f
/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyCentralForce
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyCentralForce
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyCentralImpulse
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyCentralImpulse
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyForce
 * Signature: (JLorg/joml/Vector3f;Lorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyForce
  (JNIEnv *, jclass, jlong, jobject, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyImpulse
 * Signature: (JLorg/joml/Vector3f;Lorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyImpulse
  (JNIEnv *, jclass, jlong, jobject, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyTorque
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyTorque
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    applyTorqueImpulse
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_applyTorqueImpulse
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    clearForces
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_clearForces
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    createRigidBody
 * Signature: (FJJ)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_createRigidBody
  (JNIEnv *, jclass, jfloat, jlong, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getAngularDamping
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getAngularDamping
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getAngularFactor
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getAngularFactor
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getAngularSleepingThreshold
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getAngularSleepingThreshold
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getAngularVelocity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getAngularVelocity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getAngularVelocityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getAngularVelocityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getGravity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getGravity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getGravityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getGravityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getInverseInertiaLocal
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getInverseInertiaLocal
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getInverseInertiaWorld
 * Signature: (JLorg/joml/Matrix3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getInverseInertiaWorld
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getLinearDamping
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getLinearDamping
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getLinearFactor
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getLinearFactor
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getLinearSleepingThreshold
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getLinearSleepingThreshold
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getLinearVelocity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getLinearVelocity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getLinearVelocityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getLinearVelocityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getMass
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getMass
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getSquaredSpeed
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getSquaredSpeed
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getTotalForce
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getTotalForce
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getTotalTorque
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getTotalTorque
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    getUseSpaceGravity
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_getUseSpaceGravity
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setAngularDamping
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setAngularDamping
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setAngularFactor
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setAngularFactor
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setAngularSleepingThreshold
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setAngularSleepingThreshold
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setAngularVelocity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setAngularVelocity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setAngularVelocityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setAngularVelocityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setCollisionShape
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setCollisionShape
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setDamping
 * Signature: (JFF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setDamping
  (JNIEnv *, jclass, jlong, jfloat, jfloat);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setGravity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setGravity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setGravityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setGravityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setInverseInertiaLocal
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setInverseInertiaLocal
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setKinematic
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setKinematic
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setLinearFactor
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setLinearFactor
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setLinearSleepingThreshold
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setLinearSleepingThreshold
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setLinearVelocity
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setLinearVelocity
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setLinearVelocityDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setLinearVelocityDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsLocation
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsLocation
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsLocationDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsLocationDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsRotation
 * Signature: (JLorg/joml/Matrix3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsRotation__JLorg_joml_Matrix3f_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsRotation
 * Signature: (JLorg/joml/Quaternionf;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsRotation__JLorg_joml_Quaternionf_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsRotationDp
 * Signature: (JLorg/joml/Matrix3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsRotationDp__JLorg_joml_Matrix3d_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setPhysicsRotationDp
 * Signature: (JLorg/joml/Quaterniond;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setPhysicsRotationDp__JLorg_joml_Quaterniond_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setSleepingThresholds
 * Signature: (JFF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setSleepingThresholds
  (JNIEnv *, jclass, jlong, jfloat, jfloat);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    setUseSpaceGravity
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_setUseSpaceGravity
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_jme3_bullet_objects_PhysicsRigidBody
 * Method:    updateMassProps
 * Signature: (JJF)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsRigidBody_updateMassProps
  (JNIEnv *, jclass, jlong, jlong, jfloat);

#ifdef __cplusplus
}
#endif
#endif
