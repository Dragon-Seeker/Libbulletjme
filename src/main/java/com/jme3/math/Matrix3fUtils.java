/*
 * Copyright (c) 2009-2022 jMonkeyEngine
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

import org.joml.Matrix3f;
import org.joml.Quaternionf;
import org.joml.Vector3f;

/**
 * A 3x3 matrix composed of 9 single-precision elements, used to represent
 * linear transformations of 3-D coordinates, such as rotations, reflections,
 * and scaling.
 *
 * <p>Element numbering is (row, column), so m01 is the element in row 0,
 * column 1.
 *
 * <p>For pure rotations, the {@link Quaternionf} class provides a
 * more efficient representation.
 *
 * <p>With one exception, the methods with names ending in "Local" modify the
 * current instance. They are used to avoid creating garbage.
 *
 * @author Mark Powell
 * @author Joshua Slack
 */
public final class Matrix3fUtils implements Cloneable, java.io.Serializable {

    /**
     * Shared instance of the all-zero matrix. Do not modify!
     */
    public static final Matrix3f ZERO = new Matrix3f(0, 0, 0, 0, 0, 0, 0, 0, 0);
    /**
     * Shared instance of the identity matrix (diagonals = 1, other elements =
     * 0). Do not modify!
     */
    public static final Matrix3f IDENTITY = new Matrix3f();

    /**
     * Tests for exact identity. The matrix is unaffected.
     *
     * @return true if all diagonals = 1 and all other elements = 0 or -0,
     * otherwise false
     */
    public static boolean isIdentity(Matrix3f matrix3f) {
        return (matrix3f.m00 == 1 && matrix3f.m01 == 0 && matrix3f.m02 == 0)
                && (matrix3f.m10 == 0 && matrix3f.m11 == 1 && matrix3f.m12 == 0)
                && (matrix3f.m20 == 0 && matrix3f.m21 == 0 && matrix3f.m22 == 1);
    }

    public static Matrix3f fromAxes(Vector3f xAxis, Vector3f yAxis, Vector3f zAxis) {
        return fromAxes(new Matrix3f(), xAxis, yAxis, zAxis);
    }

    public static Matrix3f fromAxes(Matrix3f matrix3f, Vector3f xAxis, Vector3f yAxis, Vector3f zAxis) {
        Matrix3f frameInW = new Matrix3f();

        frameInW.setRow(0, xAxis);
        frameInW.setRow(1, yAxis);
        frameInW.setRow(2, zAxis);

        return frameInW;
    }

    public static Vector3f mult(Matrix3f matrix3f, Vector3f vec, Vector3f product) {
        if (null == product) {
            product = new Vector3f();
        }

        float x = vec.x;
        float y = vec.y;
        float z = vec.z;

        product.x = matrix3f.m00() * x + matrix3f.m01() * y + matrix3f.m02() * z;
        product.y = matrix3f.m10() * x + matrix3f.m11() * y + matrix3f.m12() * z;
        product.z = matrix3f.m20() * x + matrix3f.m21() * y + matrix3f.m22() * z;
        return product;
    }

    public static Matrix3f mult(Matrix3f matrix3f, Matrix3f mat, Matrix3f product) {
        float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;

        if (product == null) {
            product = new Matrix3f();
        }
        temp00 = matrix3f.m00() * mat.m00 + matrix3f.m01() * mat.m10 + matrix3f.m02() * mat.m20;
        temp01 = matrix3f.m00() * mat.m01 + matrix3f.m01() * mat.m11 + matrix3f.m02() * mat.m21;
        temp02 = matrix3f.m00() * mat.m02 + matrix3f.m01() * mat.m12 + matrix3f.m02() * mat.m22;
        temp10 = matrix3f.m10() * mat.m00 + matrix3f.m11() * mat.m10 + matrix3f.m12() * mat.m20;
        temp11 = matrix3f.m10() * mat.m01 + matrix3f.m11() * mat.m11 + matrix3f.m12() * mat.m21;
        temp12 = matrix3f.m10() * mat.m02 + matrix3f.m11() * mat.m12 + matrix3f.m12() * mat.m22;
        temp20 = matrix3f.m20() * mat.m00 + matrix3f.m21() * mat.m10 + matrix3f.m22() * mat.m20;
        temp21 = matrix3f.m20() * mat.m01 + matrix3f.m21() * mat.m11 + matrix3f.m22() * mat.m21;
        temp22 = matrix3f.m20() * mat.m02 + matrix3f.m21() * mat.m12 + matrix3f.m22() * mat.m22;

        product.m00 = temp00;
        product.m01 = temp01;
        product.m02 = temp02;
        product.m10 = temp10;
        product.m11 = temp11;
        product.m12 = temp12;
        product.m20 = temp20;
        product.m21 = temp21;
        product.m22 = temp22;

        return product;
    }
}
