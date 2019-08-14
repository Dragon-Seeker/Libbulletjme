/*
 * Copyright (c) 2009-2012 jMonkeyEngine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of 'jMonkeyEngine' nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "com_jme3_bullet_PhysicsSpace.h"
#include "jmePhysicsSpace.h"
#include "jmeBulletUtil.h"

/*
 * Author: Normen Hansen
 */
#ifdef __cplusplus
extern "C" {
#endif

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    addAction
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addAction
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btActionInterface* actionObject = reinterpret_cast<btActionInterface*> (objectId);
        NULL_CHECK(actionObject, "The action object does not exist.",)

        space->getDynamicsWorld()->addAction(actionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    addCharacterObject
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addCharacterObject
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btCollisionObject* collisionObject = reinterpret_cast<btCollisionObject*> (objectId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = space;

        space->getDynamicsWorld()->addCollisionObject(collisionObject,
                btBroadphaseProxy::CharacterFilter,
                btBroadphaseProxy::StaticFilter | btBroadphaseProxy::DefaultFilter
                );
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    addCollisionObject
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addCollisionObject
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btCollisionObject* collisionObject = reinterpret_cast<btCollisionObject*> (objectId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = space;

        space->getDynamicsWorld()->addCollisionObject(collisionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    addConstraintC
     * Signature: (JJZ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addConstraintC
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId, jboolean collision) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btTypedConstraint* constraint = reinterpret_cast<btTypedConstraint*> (objectId);
        NULL_CHECK(constraint, "The btTypedConstraint does not exist.",)

        space->getDynamicsWorld()->addConstraint(constraint, collision);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    addRigidBody
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_addRigidBody
    (JNIEnv * env, jobject object, jlong spaceId, jlong rigidBodyId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btRigidBody* collisionObject = reinterpret_cast<btRigidBody*> (rigidBodyId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)
        btAssert(collisionObject->getInternalType()
                & btCollisionObject::CO_RIGID_BODY);

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = space;

        space->getDynamicsWorld()->addRigidBody(collisionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    createPhysicsSpace
     * Signature: (FFFFFFI)J
     */
    JNIEXPORT jlong JNICALL Java_com_jme3_bullet_PhysicsSpace_createPhysicsSpace
    (JNIEnv * env, jobject object, jfloat minX, jfloat minY, jfloat minZ,
            jfloat maxX, jfloat maxY, jfloat maxZ, jint broadphase,
            jboolean threading) {
        jmeClasses::initJavaClasses(env);

        jmePhysicsSpace* space = new jmePhysicsSpace(env, object);

        space->createPhysicsSpace(minX, minY, minZ, maxX, maxY, maxZ,
                broadphase, threading);
        return reinterpret_cast<jlong> (space);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    finalizeNative
     * Signature: (J)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_finalizeNative
    (JNIEnv * env, jobject object, jlong spaceId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        if (space != NULL) {
            delete space;
        }
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    getGravity
     * Signature: (JLcom/jme3/math/Vector3f;)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_getGravity
    (JNIEnv *env, jobject object, jlong spaceId, jobject storeVector) {
        jmePhysicsSpace *pSpace = reinterpret_cast<jmePhysicsSpace *> (spaceId);
        NULL_CHECK(pSpace, "The physics space does not exist.",);

        NULL_CHECK(storeVector, "The store vector does not exist.",)

        btDynamicsWorld *pWorld = pSpace->getDynamicsWorld();
        btVector3 gravity = pWorld->getGravity();
        jmeBulletUtil::convert(env, &gravity, storeVector);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    getNumConstraints
     * Signature: (J)I
     */
    JNIEXPORT jint JNICALL Java_com_jme3_bullet_PhysicsSpace_getNumConstraints
    (JNIEnv * env, jobject object, jlong spaceId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.", 0);

        int count = space->getDynamicsWorld()->getNumConstraints();
        return count;
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    rayTest_1native
     * Signature: (Lcom/jme3/math/Vector3f;Lcom/jme3/math/Vector3f;JLjava/util/List;I)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_rayTest_1native
    (JNIEnv * env, jobject object, jobject from, jobject to, jlong spaceId, jobject resultlist, jint flags) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",);

        struct AllRayResultCallback : public btCollisionWorld::RayResultCallback {

            AllRayResultCallback(const btVector3& rayFromWorld, const btVector3 & rayToWorld) : m_rayFromWorld(rayFromWorld), m_rayToWorld(rayToWorld) {
            }
            jobject resultlist;
            JNIEnv* env;
            btVector3 m_rayFromWorld; //used to calculate hitPointWorld from hitFraction
            btVector3 m_rayToWorld;

            btVector3 m_hitNormalWorld;
            btVector3 m_hitPointWorld;

            virtual btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult, bool normalInWorldSpace) {
                if (normalInWorldSpace) {
                    m_hitNormalWorld = rayResult.m_hitNormalLocal;
                } else {
                    m_hitNormalWorld = m_collisionObject->getWorldTransform().getBasis() * rayResult.m_hitNormalLocal;
                }
                m_hitPointWorld.setInterpolate3(m_rayFromWorld, m_rayToWorld, rayResult.m_hitFraction);

                jmeBulletUtil::addResult(env, resultlist, &m_hitNormalWorld, &m_hitPointWorld, rayResult.m_hitFraction, rayResult.m_collisionObject);

                return 1.f;
            }
        };

        btVector3 native_to;
        jmeBulletUtil::convert(env, to, &native_to);

        btVector3 native_from;
        jmeBulletUtil::convert(env, from, &native_from);

        AllRayResultCallback resultCallback(native_from, native_to);
        resultCallback.env = env;
        resultCallback.resultlist = resultlist;
        resultCallback.m_flags = flags;
        space->getDynamicsWorld()->rayTest(native_from, native_to, resultCallback);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    removeAction
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeAction
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btActionInterface* actionObject = reinterpret_cast<btActionInterface*> (objectId);
        NULL_CHECK(actionObject, "The action object does not exist.",)

        space->getDynamicsWorld()->removeAction(actionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    removeCharacterObject
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeCharacterObject
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btCollisionObject* collisionObject = reinterpret_cast<btCollisionObject*> (objectId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = NULL;

        space->getDynamicsWorld()->removeCollisionObject(collisionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    removeCollisionObject
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeCollisionObject
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btCollisionObject* collisionObject = reinterpret_cast<btCollisionObject*> (objectId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)

        space->getDynamicsWorld()->removeCollisionObject(collisionObject);

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = NULL;
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    removeConstraint
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeConstraint
    (JNIEnv * env, jobject object, jlong spaceId, jlong objectId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btTypedConstraint* constraint = reinterpret_cast<btTypedConstraint*> (objectId);
        NULL_CHECK(constraint, "The constraint does not exist.",)

        space->getDynamicsWorld()->removeConstraint(constraint);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    removeRigidBody
     * Signature: (JJ)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_removeRigidBody
    (JNIEnv * env, jobject object, jlong spaceId, jlong rigidBodyId) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btRigidBody* collisionObject = reinterpret_cast<btRigidBody*> (rigidBodyId);
        NULL_CHECK(collisionObject, "The collision object does not exist.",)
        btAssert(collisionObject->getInternalType()
                & btCollisionObject::CO_RIGID_BODY);

        jmeUserPointer *userPointer = (jmeUserPointer*) collisionObject->getUserPointer();
        userPointer -> space = NULL;

        space->getDynamicsWorld()->removeRigidBody(collisionObject);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    setGravity
     * Signature: (JLcom/jme3/math/Vector3f;)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_setGravity
    (JNIEnv * env, jobject object, jlong spaceId, jobject vector) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btVector3 gravity;
        jmeBulletUtil::convert(env, vector, &gravity);

        space->getDynamicsWorld()->setGravity(gravity);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    setSolverNumIterations
     * Signature: (JI)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_setSolverNumIterations
    (JNIEnv *env, jobject object, jlong spaceId, jint value) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        space->getDynamicsWorld()->getSolverInfo().m_numIterations = value;
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    stepSimulation
     * Signature: (JFIF)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_stepSimulation
    (JNIEnv * env, jobject object, jlong spaceId, jfloat tpf, jint maxSteps,
            jfloat accuracy) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        space->stepSimulation(tpf, maxSteps, accuracy);
    }

    /*
     * Class:     com_jme3_bullet_PhysicsSpace
     * Method:    sweepTest_native
     * Signature: (JLcom/jme3/math/Transform;Lcom/jme3/math/Transform;JLjava/util/List;F)V
     */
    JNIEXPORT void JNICALL Java_com_jme3_bullet_PhysicsSpace_sweepTest_1native
    (JNIEnv * env, jobject object, jlong shapeId, jobject from, jobject to, jlong spaceId, jobject resultlist, jfloat allowedCcdPenetration) {
        jmePhysicsSpace* space = reinterpret_cast<jmePhysicsSpace*> (spaceId);
        NULL_CHECK(space, "The physics space does not exist.",)

        btCollisionShape* shape = reinterpret_cast<btCollisionShape*> (shapeId);
        NULL_CHECK(shape, "The shape does not exist.",);

        struct AllConvexResultCallback : public btCollisionWorld::ConvexResultCallback {

            AllConvexResultCallback(const btTransform& convexFromWorld, const btTransform & convexToWorld) : m_convexFromWorld(convexFromWorld), m_convexToWorld(convexToWorld) {
            }
            jobject resultlist;
            JNIEnv* env;
            btTransform m_convexFromWorld; //used to calculate hitPointWorld from hitFraction
            btTransform m_convexToWorld;

            btVector3 m_hitNormalWorld;
            btVector3 m_hitPointWorld;

            virtual btScalar addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace) {
                if (normalInWorldSpace) {
                    m_hitNormalWorld = convexResult.m_hitNormalLocal;
                } else {
                    m_hitNormalWorld = convexResult.m_hitCollisionObject->getWorldTransform().getBasis() * convexResult.m_hitNormalLocal;
                }
                m_hitPointWorld.setInterpolate3(m_convexFromWorld.getBasis() * m_convexFromWorld.getOrigin(), m_convexToWorld.getBasis() * m_convexToWorld.getOrigin(), convexResult.m_hitFraction);

                jmeBulletUtil::addSweepResult(env, resultlist, &m_hitNormalWorld, &m_hitPointWorld, convexResult.m_hitFraction, convexResult.m_hitCollisionObject);

                return 1.f;
            }
        };

        btTransform native_to;
        btVector3 scale; // scales are ignored
        jmeBulletUtil::convert(env, to, &native_to, &scale);

        btTransform native_from;
        jmeBulletUtil::convert(env, from, &native_from, &scale);

        btScalar native_allowed_ccd_penetration = btScalar(allowedCcdPenetration);

        AllConvexResultCallback resultCallback(native_from, native_to);
        resultCallback.env = env;
        resultCallback.resultlist = resultlist;
        space->getDynamicsWorld()->convexSweepTest((btConvexShape *) shape, native_from, native_to, resultCallback, native_allowed_ccd_penetration);
    }

#ifdef __cplusplus
}
#endif
