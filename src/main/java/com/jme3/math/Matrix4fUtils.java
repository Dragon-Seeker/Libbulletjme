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

import org.joml.Matrix4f;
import org.joml.Quaternionf;
import org.joml.Vector3f;

/**
 * A 4x4 matrix composed of 16 single-precision elements, used to represent
 * linear or perspective transformations of 3-D coordinates.
 *
 * <p>The rightmost column (column 3) stores the translation vector. Element
 * numbering is (row,column), so m03 is the row 0, column 3, which is the X
 * translation.
 *
 * <p>Methods with names ending in "Local" modify the current instance. They are
 * used to avoid creating garbage.
 *
 * @author Mark Powell
 * @author Joshua Slack
 */
public final class Matrix4fUtils implements Cloneable {

    /**
     * Determines the scale component of the coordinate transform.
     *
     * <p>All components of the result will be non-negative, even if the
     * coordinate transform includes reflection.
     *
     * @param store storage for the result (not null, modified)
     * @return the scale factors (in {@code store}) for chaining
     */
    public static Vector3f toScaleVector(Matrix4f matrix4f, Vector3f store) {
        float scaleX = (float) Math.sqrt(matrix4f.m00() * matrix4f.m00() + matrix4f.m10() * matrix4f.m10() + matrix4f.m20() * matrix4f.m20());
        float scaleY = (float) Math.sqrt(matrix4f.m01() * matrix4f.m01() + matrix4f.m11() * matrix4f.m11() + matrix4f.m21() * matrix4f.m21());
        float scaleZ = (float) Math.sqrt(matrix4f.m02() * matrix4f.m02() + matrix4f.m12() * matrix4f.m12() + matrix4f.m22() * matrix4f.m22());
        store.set(scaleX, scaleY, scaleZ);
        return store;
    }

    /**
     * Returns the rotation component of the coordinate transform.
     *
     * <p>Assumes (but does not verify) that the transform consists entirely of
     * translation, rotation, and positive scaling -- no reflection or shear.
     *
     * @param q storage for the result (not null, modified)
     * @return the rotation component (in {@code q}) for chaining
     */
    public static Quaternionf toRotationQuat(Matrix4f matrix4f, Quaternionf q) {
        return QuaternionfUtils.fromRotationMatrix(q, matrix4f.m00(), matrix4f.m01(), matrix4f.m02(), matrix4f.m10(), matrix4f.m11(), matrix4f.m12(), matrix4f.m20(), matrix4f.m21(), matrix4f.m22());
    }
}
