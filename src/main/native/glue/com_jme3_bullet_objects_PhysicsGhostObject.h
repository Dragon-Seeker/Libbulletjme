/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_objects_PhysicsGhostObject */

#ifndef _Included_com_jme3_bullet_objects_PhysicsGhostObject
#define _Included_com_jme3_bullet_objects_PhysicsGhostObject
#ifdef __cplusplus
extern "C" {
#endif
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_NONE
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_NONE 0L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_01
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_01 1L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_02
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_02 2L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_03
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_03 4L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_04
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_04 8L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_05
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_05 16L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_06
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_06 32L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_07
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_07 64L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_08
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_08 128L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_09
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_09 256L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_10
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_10 512L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_11
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_11 1024L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_12
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_12 2048L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_13
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_13 4096L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_14
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_14 8192L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_15
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_15 16384L
#undef com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_16
#define com_jme3_bullet_objects_PhysicsGhostObject_COLLISION_GROUP_16 32768L
/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    createGhostObject
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_createGhostObject
  (JNIEnv *, jclass);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    getOverlappingCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_getOverlappingCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    getOverlappingObjects
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_getOverlappingObjects
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setGhostFlags
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setGhostFlags
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsLocation
 * Signature: (JLorg/joml/Vector3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsLocation
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsLocationDp
 * Signature: (JLorg/joml/Vector3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsLocationDp
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsRotation
 * Signature: (JLorg/joml/Matrix3f;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsRotation__JLorg_joml_Matrix3f_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsRotation
 * Signature: (JLorg/joml/Quaternionf;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsRotation__JLorg_joml_Quaternionf_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsRotationDp
 * Signature: (JLorg/joml/Matrix3d;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsRotationDp__JLorg_joml_Matrix3d_2
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_jme3_bullet_objects_PhysicsGhostObject
 * Method:    setPhysicsRotationDp
 * Signature: (JLorg/joml/Quaterniond;)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_objects_PhysicsGhostObject_setPhysicsRotationDp__JLorg_joml_Quaterniond_2
  (JNIEnv *, jclass, jlong, jobject);

#ifdef __cplusplus
}
#endif
#endif
