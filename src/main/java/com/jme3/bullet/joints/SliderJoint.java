/*
 * Copyright (c) 2009-2018 jMonkeyEngine
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
package com.jme3.bullet.joints;

import com.jme3.bullet.objects.PhysicsRigidBody;
import com.jme3.math.Matrix3f;
import com.jme3.math.Transform;
import com.jme3.math.Vector3f;
import java.util.logging.Logger;

/**
 * A 2 degree-of-freedom joint based on Bullet's btSliderConstraint. The axis of
 * the joint always parallels the physics-space X axis.
 * <p>
 * <i>From the Bullet manual:</i><br>
 * The slider constraint allows the body to rotate around one axis and translate
 * along this axis.
 *
 * @author normenhansen
 */
public class SliderJoint extends Constraint {
    // *************************************************************************
    // constants and loggers

    /**
     * message logger for this class
     */
    final public static Logger logger2
            = Logger.getLogger(SliderJoint.class.getName());
    // *************************************************************************
    // fields

    /**
     * true&rarr;limits give the allowable range of movement of frameB in frameA
     * space, false&rarr;limits give the allowable range of movement of frameA
     * in frameB space
     */
    final private boolean useLinearReferenceFrameA;
    /**
     * copy of the joint orientation: in physics-space coordinates if bodyA is
     * null, or else in A's local coordinates (rotation matrix)
     */
    final private Matrix3f rotA;
    /**
     * copy of the joint orientation in B's local coordinates (rotation matrix)
     */
    final private Matrix3f rotB;
    // *************************************************************************
    // constructors

    /**
     * Instantiate a single-ended SliderJoint.
     * <p>
     * To be effective, the joint must be added to the body's PhysicsSpace and
     * the body must be dynamic.
     *
     * @param rigidBodyB the body to constrain (not null, alias created)
     * @param pivotInB the pivot location in B's scaled local coordinates (not
     * null, unaffected)
     * @param pivotInWorld the pivot location in physics-space coordinates (not
     * null, unaffected)
     * @param linearReferenceFrame which end to use as the linear reference (not
     * null)
     */
    public SliderJoint(PhysicsRigidBody rigidBodyB, Vector3f pivotInB,
            Vector3f pivotInWorld, JointEnd linearReferenceFrame) {
        super(rigidBodyB, JointEnd.B, pivotInB, pivotInWorld);
        rotA = new Matrix3f();
        rotB = new Matrix3f();

        useLinearReferenceFrameA = (linearReferenceFrame == JointEnd.A);
        createJoint();
    }

    /**
     * Instantiate a double-ended SliderJoint.
     * <p>
     * To be effective, the joint must be added to the PhysicsSpace of both
     * bodies. Also, the bodies must be distinct and at least one of them must
     * be dynamic.
     *
     * @param rigidBodyA the body for the A end (not null, alias created)
     * @param rigidBodyB the body for the B end (not null, alias created)
     * @param pivotInA the pivot location in A's scaled local coordinates (not
     * null, unaffected)
     * @param pivotInB the pivot location in B's scaled local coordinates (not
     * null, unaffected)
     * @param rotInA the joint orientation in A's local coordinates (not null,
     * alias unaffected)
     * @param rotInB the joint orientation in B's local coordinates (not null,
     * alias unaffected)
     * @param useLinearReferenceFrameA true&rarr;use body A, false&rarr;use body
     * B
     */
    public SliderJoint(PhysicsRigidBody rigidBodyA, PhysicsRigidBody rigidBodyB,
            Vector3f pivotInA, Vector3f pivotInB, Matrix3f rotInA,
            Matrix3f rotInB, boolean useLinearReferenceFrameA) {
        super(rigidBodyA, rigidBodyB, pivotInA, pivotInB);

        this.useLinearReferenceFrameA = useLinearReferenceFrameA;
        rotA = rotInA.clone();
        rotB = rotInB.clone();
        createJoint();
    }

    /**
     * Instantiate a double-ended SliderJoint.
     * <p>
     * To be effective, the joint must be added to the body's PhysicsSpace and
     * the body must be dynamic.
     *
     * @param rigidBodyA the first body to constrain (not null, alias created)
     * @param rigidBodyB the 2nd body to constrain (not null, alias created)
     * @param pivotInA the pivot location in A's scaled local coordinates (not
     * null, unaffected)
     * @param pivotInB the pivot location in B's scaled local coordinates (not
     * null, unaffected)
     * @param useLinearReferenceFrameA true&rarr;use body A, false&rarr;use body
     * B
     */
    public SliderJoint(PhysicsRigidBody rigidBodyA, PhysicsRigidBody rigidBodyB,
            Vector3f pivotInA, Vector3f pivotInB,
            boolean useLinearReferenceFrameA) {
        super(rigidBodyA, rigidBodyB, pivotInA, pivotInB);

        this.useLinearReferenceFrameA = useLinearReferenceFrameA;
        rotA = new Matrix3f();
        rotB = new Matrix3f();
        createJoint();
    }
    // *************************************************************************
    // new methods exposed

    /**
     * Read the joint's damping for on-axis rotation between the limits.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingDirAng() {
        long constraintId = nativeId();
        return getDampingDirAng(constraintId);
    }

    /**
     * Read the joint's damping for on-axis translation between the limits.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingDirLin() {
        long constraintId = nativeId();
        return getDampingDirLin(constraintId);
    }

    /**
     * Read the joint's damping for on-axis rotation hitting the limits.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingLimAng() {
        long constraintId = nativeId();
        return getDampingLimAng(constraintId);
    }

    /**
     * Read the joint's damping for on-axis translation hitting the limits.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingLimLin() {
        long constraintId = nativeId();
        return getDampingLimLin(constraintId);
    }

    /**
     * Read the joint's damping for off-axis rotation.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingOrthoAng() {
        long constraintId = nativeId();
        return getDampingOrthoAng(constraintId);
    }

    /**
     * Read the joint's damping for off-axis translation.
     *
     * @return the viscous damping ratio (0&rarr;no damping, 1&rarr;critically
     * damped)
     */
    public float getDampingOrthoLin() {
        long constraintId = nativeId();
        return getDampingOrthoLin(constraintId);
    }

    /**
     * Copy the joint's frame transform relative to the specified end.
     *
     * @param end which end (not null)
     * @param storeResult storage for the result (modified if not null)
     * @return the transform of the constraint space relative to the end
     */
    public Transform getFrameTransform(JointEnd end, Transform storeResult) {
        Transform result
                = (storeResult == null) ? new Transform() : storeResult;

        long constraintId = nativeId();
        switch (end) {
            case A:
                getFrameOffsetA(constraintId, result);
                break;
            case B:
                getFrameOffsetB(constraintId, result);
                break;
            default:
                String message = "end = " + end;
                throw new IllegalArgumentException(message);
        }

        return result;
    }

    /**
     * Read the joint's lower limit for on-axis rotation.
     *
     * @return the lower limit angle (in radians)
     */
    public float getLowerAngLimit() {
        long constraintId = nativeId();
        return getLowerAngLimit(constraintId);
    }

    /**
     * Read the joint's lower limit for on-axis translation.
     *
     * @return the lower limit
     */
    public float getLowerLinLimit() {
        long constraintId = nativeId();
        return getLowerLinLimit(constraintId);
    }

    /**
     * Read the maximum force of the rotation motor.
     *
     * @return the maximum force
     */
    public float getMaxAngMotorForce() {
        long constraintId = nativeId();
        return getMaxAngMotorForce(constraintId);
    }

    /**
     * Read the maximum force of the translation motor.
     *
     * @return the maximum force
     */
    public float getMaxLinMotorForce() {
        long constraintId = nativeId();
        return getMaxLinMotorForce(constraintId);
    }

    /**
     * Read the joint's restitution for on-axis rotation between the limits.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionDirAng() {
        long constraintId = nativeId();
        return getRestitutionDirAng(constraintId);
    }

    /**
     * Read the joint's restitution for on-axis translation between the limits.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionDirLin() {
        long constraintId = nativeId();
        return getRestitutionDirLin(constraintId);
    }

    /**
     * Read the joint's restitution for on-axis rotation hitting the limits.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionLimAng() {
        long constraintId = nativeId();
        return getRestitutionLimAng(constraintId);
    }

    /**
     * Read the joint's restitution for on-axis translation hitting the limits.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionLimLin() {
        long constraintId = nativeId();
        return getRestitutionLimLin(constraintId);
    }

    /**
     * Read the joint's restitution for off-axis rotation.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionOrthoAng() {
        long constraintId = nativeId();
        return getRestitutionOrthoAng(constraintId);
    }

    /**
     * Read the joint's restitution for off-axis translation.
     *
     * @return the restitution (bounce) factor
     */
    public float getRestitutionOrthoLin() {
        long constraintId = nativeId();
        return getRestitutionOrthoLin(constraintId);
    }

    /**
     * Read the joint's softness for on-axis rotation between the limits.
     *
     * @return the softness
     */
    public float getSoftnessDirAng() {
        long constraintId = nativeId();
        return getSoftnessDirAng(constraintId);
    }

    /**
     * Read the joint's softness for on-axis translation between the limits.
     *
     * @return the softness
     */
    public float getSoftnessDirLin() {
        long constraintId = nativeId();
        return getSoftnessDirLin(constraintId);
    }

    /**
     * Read the joint's softness for on-axis rotation hitting the limits.
     *
     * @return the softness
     */
    public float getSoftnessLimAng() {
        long constraintId = nativeId();
        return getSoftnessLimAng(constraintId);
    }

    /**
     * Read the joint's softness for on-axis translation hitting the limits.
     *
     * @return the softness
     */
    public float getSoftnessLimLin() {
        long constraintId = nativeId();
        return getSoftnessLimLin(constraintId);
    }

    /**
     * Read the joint's softness for off-axis rotation.
     *
     * @return the softness
     */
    public float getSoftnessOrthoAng() {
        long constraintId = nativeId();
        return getSoftnessOrthoAng(constraintId);
    }

    /**
     * Read the joint's softness for off-axis translation.
     *
     * @return the softness
     */
    public float getSoftnessOrthoLin() {
        long constraintId = nativeId();
        return getSoftnessOrthoLin(constraintId);
    }

    /**
     * Read the velocity target of the rotation motor.
     *
     * @return the velocity target (in radians per second)
     */
    public float getTargetAngMotorVelocity() {
        long constraintId = nativeId();
        return getTargetAngMotorVelocity(constraintId);
    }

    /**
     * Read the velocity target of the translation motor.
     *
     * @return the velocity target
     */
    public float getTargetLinMotorVelocity() {
        long constraintId = nativeId();
        return getTargetLinMotorVelocity(constraintId);
    }

    /**
     * Read the joint's upper limit for on-axis rotation.
     *
     * @return the upper limit angle (in radians)
     */
    public float getUpperAngLimit() {
        long constraintId = nativeId();
        return getUpperAngLimit(constraintId);
    }

    /**
     * Read the joint's upper limit for on-axis translation.
     *
     * @return the upper limit
     */
    public float getUpperLinLimit() {
        long constraintId = nativeId();
        return getUpperLinLimit(constraintId);
    }

    /**
     * Test whether the rotation motor is powered.
     *
     * @return true if powered, otherwise false
     */
    public boolean isPoweredAngMotor() {
        long constraintId = nativeId();
        return isPoweredAngMotor(constraintId);
    }

    /**
     * Test whether the translation motor is powered.
     *
     * @return true if powered, otherwise false
     */
    public boolean isPoweredLinMotor() {
        long constraintId = nativeId();
        return isPoweredLinMotor(constraintId);
    }

    /**
     * Alter the joint's damping for on-axis rotation between the limits.
     *
     * @param dampingDirAng the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=0)
     */
    public void setDampingDirAng(float dampingDirAng) {
        long constraintId = nativeId();
        setDampingDirAng(constraintId, dampingDirAng);
    }

    /**
     * Alter the joint's damping for on-axis translation between the limits.
     *
     * @param dampingDirLin the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=0)
     */
    public void setDampingDirLin(float dampingDirLin) {
        long constraintId = nativeId();
        setDampingDirLin(constraintId, dampingDirLin);
    }

    /**
     * Alter the joint's damping for on-axis rotation hitting the limits.
     *
     * @param dampingLimAng the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=1)
     */
    public void setDampingLimAng(float dampingLimAng) {
        long constraintId = nativeId();
        setDampingLimAng(constraintId, dampingLimAng);
    }

    /**
     * Alter the joint's damping for on-axis translation hitting the limits.
     *
     * @param dampingLimLin the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=1)
     */
    public void setDampingLimLin(float dampingLimLin) {
        long constraintId = nativeId();
        setDampingLimLin(constraintId, dampingLimLin);
    }

    /**
     * Alter the joint's damping for off-axis rotation.
     *
     * @param dampingOrthoAng the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=1)
     */
    public void setDampingOrthoAng(float dampingOrthoAng) {
        long constraintId = nativeId();
        setDampingOrthoAng(constraintId, dampingOrthoAng);
    }

    /**
     * Alter the joint's damping for off-axis translation.
     *
     * @param dampingOrthoLin the desired viscous damping ratio (0&rarr;no
     * damping, 1&rarr;critically damped, default=1)
     */
    public void setDampingOrthoLin(float dampingOrthoLin) {
        long constraintId = nativeId();
        setDampingOrthoLin(constraintId, dampingOrthoLin);
    }

    /**
     * Alter the joint's lower limit for on-axis rotation.
     *
     * @param lowerAngLimit the desired lower limit angle (in radians,
     * default=0)
     */
    public void setLowerAngLimit(float lowerAngLimit) {
        long constraintId = nativeId();
        setLowerAngLimit(constraintId, lowerAngLimit);
    }

    /**
     * Alter the joint's lower limit for on-axis translation.
     *
     * @param lowerLinLimit the desired lower limit (default=1)
     */
    public void setLowerLinLimit(float lowerLinLimit) {
        long constraintId = nativeId();
        setLowerLinLimit(constraintId, lowerLinLimit);
    }

    /**
     * Alter the maximum force of the rotation motor.
     *
     * @param maxAngMotorForce the desired maximum force (default=0)
     */
    public void setMaxAngMotorForce(float maxAngMotorForce) {
        long constraintId = nativeId();
        setMaxAngMotorForce(constraintId, maxAngMotorForce);
    }

    /**
     * Alter the maximum force of the translation motor.
     *
     * @param maxLinMotorForce the desired maximum force (default=0)
     */
    public void setMaxLinMotorForce(float maxLinMotorForce) {
        long constraintId = nativeId();
        setMaxLinMotorForce(constraintId, maxLinMotorForce);
    }

    /**
     * Alter whether the rotation motor is powered.
     *
     * @param poweredAngMotor true to power the motor, false to de-power it
     * (default=false)
     */
    public void setPoweredAngMotor(boolean poweredAngMotor) {
        long constraintId = nativeId();
        setPoweredAngMotor(constraintId, poweredAngMotor);
    }

    /**
     * Alter whether the translation motor is powered.
     *
     * @param poweredLinMotor true to power the motor, false to de-power it
     * (default=false)
     */
    public void setPoweredLinMotor(boolean poweredLinMotor) {
        long constraintId = nativeId();
        setPoweredLinMotor(constraintId, poweredLinMotor);
    }

    /**
     * Alter the joint's restitution for on-axis rotation between the limits.
     *
     * @param restitutionDirAng the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionDirAng(float restitutionDirAng) {
        long constraintId = nativeId();
        setRestitutionDirAng(constraintId, restitutionDirAng);
    }

    /**
     * Alter the joint's restitution for on-axis translation between the limits.
     *
     * @param restitutionDirLin the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionDirLin(float restitutionDirLin) {
        long constraintId = nativeId();
        setRestitutionDirLin(constraintId, restitutionDirLin);
    }

    /**
     * Alter the joint's restitution for on-axis rotation hitting the limits.
     *
     * @param restitutionLimAng the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionLimAng(float restitutionLimAng) {
        long constraintId = nativeId();
        setRestitutionLimAng(constraintId, restitutionLimAng);
    }

    /**
     * Alter the joint's restitution for on-axis translation hitting the limits.
     *
     * @param restitutionLimLin the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionLimLin(float restitutionLimLin) {
        long constraintId = nativeId();
        setRestitutionLimLin(constraintId, restitutionLimLin);
    }

    /**
     * Alter the joint's restitution for off-axis rotation.
     *
     * @param restitutionOrthoAng the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionOrthoAng(float restitutionOrthoAng) {
        long constraintId = nativeId();
        setRestitutionOrthoAng(constraintId, restitutionOrthoAng);
    }

    /**
     * Alter the joint's restitution for off-axis translation.
     *
     * @param restitutionOrthoLin the desired restitution (bounce) factor
     * (default=0.7)
     */
    public void setRestitutionOrthoLin(float restitutionOrthoLin) {
        long constraintId = nativeId();
        setRestitutionOrthoLin(constraintId, restitutionOrthoLin);
    }

    /**
     * Alter the joint's softness for on-axis rotation between the limits.
     *
     * @param softnessDirAng the desired softness (default=1)
     */
    public void setSoftnessDirAng(float softnessDirAng) {
        long constraintId = nativeId();
        setSoftnessDirAng(constraintId, softnessDirAng);
    }

    /**
     * Alter the joint's softness for on-axis translation between the limits.
     *
     * @param softnessDirLin the desired softness (default=1)
     */
    public void setSoftnessDirLin(float softnessDirLin) {
        long constraintId = nativeId();
        setSoftnessDirLin(constraintId, softnessDirLin);
    }

    /**
     * Alter the joint's softness for on-axis rotation hitting the limits.
     *
     * @param softnessLimAng the desired softness (default=1)
     */
    public void setSoftnessLimAng(float softnessLimAng) {
        long constraintId = nativeId();
        setSoftnessLimAng(constraintId, softnessLimAng);
    }

    /**
     * Alter the joint's softness for on-axis translation hitting the limits.
     *
     * @param softnessLimLin the desired softness (default=1)
     */
    public void setSoftnessLimLin(float softnessLimLin) {
        long constraintId = nativeId();
        setSoftnessLimLin(constraintId, softnessLimLin);
    }

    /**
     * Alter the joint's softness for off-axis rotation.
     *
     * @param softnessOrthoAng the desired softness (default=1)
     */
    public void setSoftnessOrthoAng(float softnessOrthoAng) {
        long constraintId = nativeId();
        setSoftnessOrthoAng(constraintId, softnessOrthoAng);
    }

    /**
     * Alter the joint's softness for off-axis translation.
     *
     * @param softnessOrthoLin the desired softness (default=1)
     */
    public void setSoftnessOrthoLin(float softnessOrthoLin) {
        long constraintId = nativeId();
        setSoftnessOrthoLin(constraintId, softnessOrthoLin);
    }

    /**
     * Alter the velocity target of the rotation motor.
     *
     * @param targetAngMotorVelocity the desired velocity target (in radians per
     * second, default=0)
     */
    public void setTargetAngMotorVelocity(float targetAngMotorVelocity) {
        long constraintId = nativeId();
        setTargetAngMotorVelocity(constraintId, targetAngMotorVelocity);
    }

    /**
     * Alter the velocity target of the translation motor.
     *
     * @param targetLinMotorVelocity the desired velocity target (default=0)
     */
    public void setTargetLinMotorVelocity(float targetLinMotorVelocity) {
        long constraintId = nativeId();
        setTargetLinMotorVelocity(constraintId, targetLinMotorVelocity);
    }

    /**
     * Alter the joint's upper limit for on-axis rotation.
     *
     * @param upperAngLimit the desired upper limit angle (in radians,
     * default=0)
     */
    public void setUpperAngLimit(float upperAngLimit) {
        long constraintId = nativeId();
        setUpperAngLimit(constraintId, upperAngLimit);
    }

    /**
     * Alter the joint's upper limit for on-axis translation.
     *
     * @param upperLinLimit the desired upper limit (default=-1)
     */
    public void setUpperLinLimit(float upperLinLimit) {
        long constraintId = nativeId();
        setUpperLinLimit(constraintId, upperLinLimit);
    }
    // *************************************************************************
    // private methods

    /**
     * Create the configured joint in Bullet.
     */
    private void createJoint() {
        PhysicsRigidBody a = getBodyA();
        assert pivotA != null;
        assert rotA != null;

        PhysicsRigidBody b = getBodyB();
        long bId = b.nativeId();
        assert pivotB != null;
        assert rotB != null;

        long constraintId;
        if (a == null) {
            /*
             * Create a single-ended joint.  Bullet assumes single-ended
             * btSliderConstraints are satisfied at creation, so we
             * temporarily re-position the body to satisfy the constraint.
             */
            Vector3f saveLocation = b.getPhysicsLocation(null);

            Vector3f offset = pivotA.subtract(pivotB);
            b.setPhysicsLocation(offset);
            constraintId
                    = createJoint1(bId, pivotB, rotB, useLinearReferenceFrameA);

            b.setPhysicsLocation(saveLocation);

        } else {
            /*
             * Create a double-ended joint.
             */
            long aId = a.nativeId();
            constraintId = createJoint(aId, bId, pivotA, rotA, pivotB, rotB,
                    useLinearReferenceFrameA);
        }
        setNativeId(constraintId);
    }
    // *************************************************************************
    // native methods

    native private long createJoint(long bodyIdA, long bodyIdB,
            Vector3f pivotInA, Matrix3f rotInA, Vector3f pivotInB,
            Matrix3f rotInB, boolean useLinearReferenceFrameA);

    native private long createJoint1(long bodyIdB, Vector3f pivotInB,
            Matrix3f rotInB, boolean useLinearReferenceFrameA);

    native private float getDampingDirAng(long jointId);

    native private float getDampingDirLin(long jointId);

    native private float getDampingLimAng(long jointId);

    native private float getDampingLimLin(long jointId);

    native private float getDampingOrthoAng(long jointId);

    native private float getDampingOrthoLin(long jointId);

    native private void getFrameOffsetA(long jointId, Transform frameInA);

    native private void getFrameOffsetB(long jointId, Transform frameInB);

    native private float getLowerAngLimit(long jointId);

    native private float getLowerLinLimit(long jointId);

    native private float getMaxAngMotorForce(long jointId);

    native private float getMaxLinMotorForce(long jointId);

    native private float getRestitutionDirAng(long jointId);

    native private float getRestitutionDirLin(long jointId);

    native private float getRestitutionLimAng(long jointId);

    native private float getRestitutionLimLin(long jointId);

    native private float getRestitutionOrthoAng(long jointId);

    native private float getRestitutionOrthoLin(long jointId);

    native private float getSoftnessDirAng(long jointId);

    native private float getSoftnessDirLin(long jointId);

    native private float getSoftnessLimAng(long jointId);

    native private float getSoftnessLimLin(long jointId);

    native private float getSoftnessOrthoAng(long jointId);

    native private float getSoftnessOrthoLin(long jointId);

    native private float getTargetAngMotorVelocity(long jointId);

    native private float getTargetLinMotorVelocity(long jointId);

    native private float getUpperAngLimit(long jointId);

    native private float getUpperLinLimit(long jointId);

    native private boolean isPoweredAngMotor(long jointId);

    native private boolean isPoweredLinMotor(long jointId);

    native private void setDampingDirAng(long jointId, float value);

    native private void setDampingDirLin(long jointId, float value);

    native private void setDampingLimAng(long jointId, float value);

    native private void setDampingLimLin(long jointId, float value);

    native private void setDampingOrthoAng(long jointId, float value);

    native private void setDampingOrthoLin(long jointId, float value);

    native private void setLowerAngLimit(long jointId, float value);

    native private void setLowerLinLimit(long jointId, float value);

    native private void setMaxAngMotorForce(long jointId, float value);

    native private void setMaxLinMotorForce(long jointId, float value);

    native private void setPoweredAngMotor(long jointId, boolean value);

    native private void setPoweredLinMotor(long jointId, boolean value);

    native private void setRestitutionDirAng(long jointId, float value);

    native private void setRestitutionDirLin(long jointId, float value);

    native private void setRestitutionLimAng(long jointId, float value);

    native private void setRestitutionLimLin(long jointId, float value);

    native private void setRestitutionOrthoAng(long jointId, float value);

    native private void setRestitutionOrthoLin(long jointId, float value);

    native private void setSoftnessDirAng(long jointId, float value);

    native private void setSoftnessDirLin(long jointId, float value);

    native private void setSoftnessLimAng(long jointId, float value);

    native private void setSoftnessLimLin(long jointId, float value);

    native private void setSoftnessOrthoAng(long jointId, float value);

    native private void setSoftnessOrthoLin(long jointId, float value);

    native private void setTargetAngMotorVelocity(long jointId, float value);

    native private void setTargetLinMotorVelocity(long jointId, float value);

    native private void setUpperAngLimit(long jointId, float value);

    native private void setUpperLinLimit(long objectId, float value);
}
