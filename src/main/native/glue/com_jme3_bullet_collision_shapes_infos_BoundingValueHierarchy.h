/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy */

#ifndef _Included_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
#define _Included_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
 * Method:    deSerialize
 * Signature: ([B)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy_deSerialize
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
 * Method:    finalizeNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy_finalizeNative
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
 * Method:    getOptimizedBvh
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy_getOptimizedBvh
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy
 * Method:    serialize
 * Signature: (J)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_jme3_bullet_collision_shapes_infos_BoundingValueHierarchy_serialize
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif