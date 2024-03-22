/*
 * Copyright (c) 2009-2024 jMonkeyEngine
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
package com.jme3.math;

import com.jme3.util.TempVars;
import org.joml.Matrix3f;
import org.joml.Matrix4f;
import org.joml.Quaternionf;
import org.joml.Vector3f;

/**
 * Used to efficiently represent rotations and orientations in 3-dimensional
 * space, without risk of gimbal lock. Each instance has 4 single-precision
 * components: 3 imaginary components (X, Y, and Z) and a real component (W).
 *
 * <p>Mathematically, quaternions are an extension of complex numbers. In
 * mathematics texts, W often appears first, but in JME it always comes last.
 *
 * @author Mark Powell
 * @author Joshua Slack
 */
public final class QuaternionfUtils implements Cloneable, java.io.Serializable {

    static final long serialVersionUID = 1;

    //private static final Logger logger = Logger.getLogger(Quaternion.class.getName());
    /**
     * Shared instance of the identity quaternion (0, 0, 0, 1). Do not modify!
     *
     * <p>This is the usual representation for a null rotation.
     */
    public static final Quaternionf IDENTITY = new Quaternionf();
    /**
     * Another shared instance of the identity quaternion (0, 0, 0, 1). Do not
     * modify!
     */
    public static final Quaternionf DIRECTION_Z = new Quaternionf();
    /**
     * Shared instance of the zero quaternion (0, 0, 0, 0). Do not modify!
     *
     * <p>The zero quaternion doesn't represent any valid rotation.
     */
    public static final Quaternionf ZERO = new Quaternionf(0, 0, 0, 0);

    static {
        fromAxes(DIRECTION_Z, Vector3fUtils.UNIT_X, Vector3fUtils.UNIT_Y, Vector3fUtils.UNIT_Z);
    }

    public static Quaternionf fromAxes(Quaternionf quaternionf,Vector3f xAxis, Vector3f yAxis, Vector3f zAxis) {
        return fromRotationMatrix(quaternionf, xAxis.x, yAxis.x, zAxis.x, xAxis.y, yAxis.y, zAxis.y, xAxis.z, yAxis.z, zAxis.z);
    }

    /**
     * Converts to an equivalent rotation matrix. The current instance is
     * unaffected.
     *
     * <p>Note: the result is created from a normalized version of the current
     * instance.
     *
     * @return a new 3x3 rotation matrix
     */
    public static Matrix3f toRotationMatrix(Quaternionf quaternionf) {
        Matrix3f matrix = new Matrix3f();
        return toRotationMatrix(quaternionf, matrix);
    }

    /**
     * Converts to an equivalent rotation matrix. The current instance is
     * unaffected.
     *
     * <p>Note: the result is created from a normalized version of the current
     * instance.
     *
     * @param result storage for the result (not null)
     * @return {@code result}, configured as a 3x3 rotation matrix
     */
    public static Matrix3f toRotationMatrix(Quaternionf quaternionf, Matrix3f result) {

        float norm = norm(quaternionf);
        // we explicitly test norm against one here, saving a division
        // at the cost of a test and branch.  Is it worth it?
        float s = (norm == 1f) ? 2f : (norm > 0f) ? 2f / norm : 0;

        // compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        // will be used 2-4 times each.
        float xs = quaternionf.x * s;
        float ys = quaternionf.y * s;
        float zs = quaternionf.z * s;
        float xx = quaternionf.x * xs;
        float xy = quaternionf.x * ys;
        float xz = quaternionf.x * zs;
        float xw = quaternionf.w * xs;
        float yy = quaternionf.y * ys;
        float yz = quaternionf.y * zs;
        float yw = quaternionf.w * ys;
        float zz = quaternionf.z * zs;
        float zw = quaternionf.w * zs;

        // using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        result.m00 = 1 - (yy + zz);
        result.m01 = (xy - zw);
        result.m02 = (xz + yw);
        result.m10 = (xy + zw);
        result.m11 = 1 - (xx + zz);
        result.m12 = (yz - xw);
        result.m20 = (xz - yw);
        result.m21 = (yz + xw);
        result.m22 = 1 - (xx + yy);

        return result;
    }

    /**
     * Sets the rotation component of the specified transform matrix. The
     * current instance is unaffected.
     *
     * <p>Note: preserves the translation component of {@code store} but not
     * its scaling component.
     *
     * <p>Note: the result is created from a normalized version of the current
     * instance.
     *
     * @param store storage for the result (not null)
     * @return {@code store}, with 9 of its 16 elements modified
     */
    public static Matrix4f toTransformMatrix(Quaternionf quaternionf, Matrix4f store) {

        float norm = norm(quaternionf);
        // we explicitly test norm against one here, saving a division
        // at the cost of a test and branch.  Is it worth it?
        float s = (norm == 1f) ? 2f : (norm > 0f) ? 2f / norm : 0;

        // compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        // will be used 2-4 times each.
        float xs = quaternionf.x * s;
        float ys = quaternionf.y * s;
        float zs = quaternionf.z * s;
        float xx = quaternionf.x * xs;
        float xy = quaternionf.x * ys;
        float xz = quaternionf.x * zs;
        float xw = quaternionf.w * xs;
        float yy = quaternionf.y * ys;
        float yz = quaternionf.y * zs;
        float yw = quaternionf.w * ys;
        float zz = quaternionf.z * zs;
        float zw = quaternionf.w * zs;

        // using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        store.m00( 1 - (yy + zz));
        store.m01( (xy - zw));
        store.m02( (xz + yw));
        store.m10( (xy + zw));
        store.m11( 1 - (xx + zz));
        store.m12( (yz - xw));
        store.m20( (xz - yw));
        store.m21( (yz + xw));
        store.m22( 1 - (xx + yy));

        return store;
    }

    /**
     * Sets the rotation component of the specified transform matrix. The
     * current instance is unaffected.
     *
     * <p>Note: preserves the translation and scaling components of
     * {@code result} unless {@code result} includes reflection.
     *
     * <p>Note: the result is created from a normalized version of the current
     * instance.
     *
     * @param result storage for the result (not null)
     * @return {@code result}, with 9 of its 16 elements modified
     */
    public static Matrix4f toRotationMatrix(Quaternionf quaternionf, Matrix4f result) {
        TempVars tempv = TempVars.get();
        Vector3f originalScale = tempv.vect1;

        Matrix4fUtils.toScaleVector(result, originalScale);
        result.scale(1, 1, 1);
        float norm = norm(quaternionf);
        // we explicitly test norm against one here, saving a division
        // at the cost of a test and branch.  Is it worth it?
        float s = (norm == 1f) ? 2f : (norm > 0f) ? 2f / norm : 0;

        // compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        // will be used 2-4 times each.
        float xs = quaternionf.x * s;
        float ys = quaternionf.y * s;
        float zs = quaternionf.z * s;
        float xx = quaternionf.x * xs;
        float xy = quaternionf.x * ys;
        float xz = quaternionf.x * zs;
        float xw = quaternionf.w * xs;
        float yy = quaternionf.y * ys;
        float yz = quaternionf.y * zs;
        float yw = quaternionf.w * ys;
        float zz = quaternionf.z * zs;
        float zw = quaternionf.w * zs;

        // using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        result.m00(1 - (yy + zz));
        result.m01((xy - zw));
        result.m02((xz + yw));
        result.m10((xy + zw));
        result.m11(1 - (xx + zz));
        result.m12((yz - xw));
        result.m20((xz - yw));
        result.m21((yz + xw));
        result.m22(1 - (xx + yy));

        result.scale(originalScale);

        tempv.release();

        return result;
    }

    /**
     * Returns the norm, defined as the dot product of the quaternion with
     * itself. The current instance is unaffected.
     *
     * @return the sum of the squared components (not negative)
     */
    public static float norm(Quaternionf quaternionf) {
        return quaternionf.w * quaternionf.w + quaternionf.x * quaternionf.x + quaternionf.y * quaternionf.y + quaternionf.z * quaternionf.z;
    }

    /**
     * Sets the quaternion from the specified Tait-Bryan angles, applying the
     * rotations in x-z-y extrinsic order or y-z'-x" intrinsic order.
     *
     * @see
     * <a href="http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/index.htm">http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/index.htm</a>
     *
     * @param xAngle the X angle (in radians)
     * @param yAngle the Y angle (in radians)
     * @param zAngle the Z angle (in radians)
     * @return the (modified) current instance (for chaining)
     */
    public static Quaternionf fromAngles(Quaternionf quaternionf, float xAngle, float yAngle, float zAngle) {
        float angle;
        float sinY, sinZ, sinX, cosY, cosZ, cosX;
        angle = zAngle * 0.5f;
        sinZ = FastMath.sin(angle);
        cosZ = FastMath.cos(angle);
        angle = yAngle * 0.5f;
        sinY = FastMath.sin(angle);
        cosY = FastMath.cos(angle);
        angle = xAngle * 0.5f;
        sinX = FastMath.sin(angle);
        cosX = FastMath.cos(angle);

        // variables used to reduce multiplication calls.
        float cosYXcosZ = cosY * cosZ;
        float sinYXsinZ = sinY * sinZ;
        float cosYXsinZ = cosY * sinZ;
        float sinYXcosZ = sinY * cosZ;

        quaternionf.w = (cosYXcosZ * cosX - sinYXsinZ * sinX);
        quaternionf.x = (cosYXcosZ * sinX + sinYXsinZ * cosX);
        quaternionf.y = (sinYXcosZ * cosX + cosYXsinZ * sinX);
        quaternionf.z = (cosYXsinZ * cosX - sinYXcosZ * sinX);

        quaternionf.normalize();
        return quaternionf;
    }

    /**
     * Sets the quaternion from the specified rotation matrix.
     *
     * <p>Does not verify that the argument is a valid rotation matrix.
     * Positive scaling is compensated for, but not reflection or shear.
     *
     * @param matrix the input matrix (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public static Quaternionf fromRotationMatrix(Quaternionf quaternionf, Matrix3f matrix) {
        return fromRotationMatrix(quaternionf, matrix.m00, matrix.m01, matrix.m02, matrix.m10,
                matrix.m11, matrix.m12, matrix.m20, matrix.m21, matrix.m22);
    }

    /**
     * Sets the quaternion from a rotation matrix with the specified elements.
     *
     * <p>Does not verify that the arguments form a valid rotation matrix.
     * Positive scaling is compensated for, but not reflection or shear.
     *
     * @param m00 the matrix element in row 0, column 0
     * @param m01 the matrix element in row 0, column 1
     * @param m02 the matrix element in row 0, column 2
     * @param m10 the matrix element in row 1, column 0
     * @param m11 the matrix element in row 1, column 1
     * @param m12 the matrix element in row 1, column 2
     * @param m20 the matrix element in row 2, column 0
     * @param m21 the matrix element in row 2, column 1
     * @param m22 the matrix element in row 2, column 2
     * @return the (modified) current instance (for chaining)
     */
    public static Quaternionf fromRotationMatrix(Quaternionf quaternionf, float m00, float m01, float m02,
                                         float m10, float m11, float m12, float m20, float m21, float m22) {
        // first normalize the forward (F), up (U) and side (S) vectors of the rotation matrix
        // so that positive scaling does not affect the rotation
        float lengthSquared = m00 * m00 + m10 * m10 + m20 * m20;
        if (lengthSquared != 1f && lengthSquared != 0f) {
            lengthSquared = 1.0f / FastMath.sqrt(lengthSquared);
            m00 *= lengthSquared;
            m10 *= lengthSquared;
            m20 *= lengthSquared;
        }
        lengthSquared = m01 * m01 + m11 * m11 + m21 * m21;
        if (lengthSquared != 1f && lengthSquared != 0f) {
            lengthSquared = 1.0f / FastMath.sqrt(lengthSquared);
            m01 *= lengthSquared;
            m11 *= lengthSquared;
            m21 *= lengthSquared;
        }
        lengthSquared = m02 * m02 + m12 * m12 + m22 * m22;
        if (lengthSquared != 1f && lengthSquared != 0f) {
            lengthSquared = 1.0f / FastMath.sqrt(lengthSquared);
            m02 *= lengthSquared;
            m12 *= lengthSquared;
            m22 *= lengthSquared;
        }

        // Use the Graphics Gems code, from
        // ftp://ftp.cis.upenn.edu/pub/graphics/shoemake/quatut.ps.Z
        // *NOT* the "Matrix and Quaternions FAQ", which has errors!

        // the trace is the sum of the diagonal elements; see
        // http://mathworld.wolfram.com/MatrixTrace.html
        float t = m00 + m11 + m22;

        // we protect the division by s by ensuring that s>=1
        if (t >= 0) { // |w| >= .5
            float s = FastMath.sqrt(t + 1); // |s|>=1 ...
            quaternionf.w = 0.5f * s;
            s = 0.5f / s;                 // so this division isn't bad
            quaternionf.x = (m21 - m12) * s;
            quaternionf.y = (m02 - m20) * s;
            quaternionf.z = (m10 - m01) * s;
        } else if ((m00 > m11) && (m00 > m22)) {
            float s = FastMath.sqrt(1.0f + m00 - m11 - m22); // |s|>=1
            quaternionf.x = s * 0.5f; // |x| >= .5
            s = 0.5f / s;
            quaternionf.y = (m10 + m01) * s;
            quaternionf.z = (m02 + m20) * s;
            quaternionf.w = (m21 - m12) * s;
        } else if (m11 > m22) {
            float s = FastMath.sqrt(1.0f + m11 - m00 - m22); // |s|>=1
            quaternionf.y = s * 0.5f; // |y| >= .5
            s = 0.5f / s;
            quaternionf.x = (m10 + m01) * s;
            quaternionf.z = (m21 + m12) * s;
            quaternionf.w = (m02 - m20) * s;
        } else {
            float s = FastMath.sqrt(1.0f + m22 - m00 - m11); // |s|>=1
            quaternionf.z = s * 0.5f; // |z| >= .5
            s = 0.5f / s;
            quaternionf.x = (m02 + m20) * s;
            quaternionf.y = (m21 + m12) * s;
            quaternionf.w = (m10 - m01) * s;
        }

        return quaternionf;
    }

    public static Quaternionf fromAngleNormalAxis(Quaternionf quaternionf, float angle, Vector3f axis) {
        if (axis.x == 0 && axis.y == 0 && axis.z == 0) {
            quaternionf.identity();
        } else {
            float halfAngle = 0.5f * angle;
            float sin = FastMath.sin(halfAngle);
            quaternionf.w = FastMath.cos(halfAngle);
            quaternionf.x = sin * axis.x;
            quaternionf.y = sin * axis.y;
            quaternionf.z = sin * axis.z;
        }
        return quaternionf;
    }
}
