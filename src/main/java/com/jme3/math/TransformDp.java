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

import jme3utilities.Validate;
import org.joml.Quaterniond;
import org.joml.Vector3d;

import java.util.logging.Logger;

/**
 * A 3-D coordinate transform composed of translation, rotation, and scaling.
 * The order of application is: scale, then rotate, then translate.
 *
 * @author Stephen Gold sgold@sonic.net
 */
final public class TransformDp {
    // *************************************************************************
    // constants and loggers

    /**
     * message logger for this class
     */
    final public static Logger logger
            = Logger.getLogger(TransformDp.class.getName());
    // *************************************************************************
    // fields

    /**
     * Rotation component.
     */
    final private Quaterniond rotation = new Quaterniond();
    /**
     * Scaling component: a scale factor for each local axis.
     */
    final private Vector3d scaling = new Vector3d(1.0, 1.0, 1.0);
    /**
     * Translation component: an offset for each local axis.
     */
    final private Vector3d translation = new Vector3d();
    // *************************************************************************
    // constructors

    /**
     * Instantiates an identity transform: no translation, no rotation, and no
     * scaling.
     */
    public TransformDp() {
        // do nothing
    }

    /**
     * Instantiates a coordinate transform without scaling.
     *
     * @param translate the desired translation (not null, unaffected)
     * @param rotate the desired rotation (not null, unaffected)
     */
    public TransformDp(Vector3d translate, Quaterniond rotate) {
        Validate.nonNull(translate, "translate");
        Validate.nonNull(rotate, "rotate");

        rotation.set(rotate);
        translation.set(translate);
    }

    /**
     * Instantiates a coordinate transform with scaling.
     *
     * @param translate the desired translation (not null, unaffected)
     * @param rotate the desired rotation (not null, unaffected)
     * @param scale the desired scaling (not null, unaffected)
     */
    public TransformDp(Vector3d translate, Quaterniond rotate, Vector3d scale) {
        Validate.nonNull(translate, "translation");
        Validate.nonNull(rotate, "rotate");
        Validate.nonNull(scale, "scale");

        rotation.set(rotate);
        scaling.set(scale);
        translation.set(translate);
    }

    /**
     * Instantiates a copy of the specified transform.
     *
     * @param original the instance to copy (not null, unaffected)
     */
    public TransformDp(TransformDp original) {
        Validate.nonNull(original, "original");
        set(original);
    }
    // *************************************************************************
    // new methods exposed

    /**
     * Combines with the argument and returns the (modified) current instance.
     * <p>
     * It IS NOT safe for {@code this} and {@code parent} to be the same object.
     *
     * @param parent the parent transform (not null, unaffected unless it's
     * {@code this})
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp combineWithParent(TransformDp parent) {
        Vector3d parentScaling = parent.getScale(); // alias
        scaling.mul(parentScaling);

        Quaterniond parentRotation = parent.getRotation(); // alias
        parentRotation.mul(rotation, rotation);

        translation.mul(parentScaling);
        parentRotation.transform(translation, translation);
        translation.add(parent.translation);

        return this;
    }

    /**
     * Accesses the rotation component.
     *
     * @return the pre-existing instance (not null)
     */
    public Quaterniond getRotation() {
        return rotation;
    }

    /**
     * Accesses the scaling component.
     *
     * @return the pre-existing instance (not null)
     */
    public Vector3d getScale() {
        return scaling;
    }

    /**
     * Accesses the translation component.
     *
     * @return the pre-existing instance (not null)
     */
    public Vector3d getTranslation() {
        return translation;
    }

    /**
     * Sets the current instance to the identity transform: translation=(0,0,0)
     * scaling=(1,1,1) rotation=(0,0,0,1).
     *
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp loadIdentity() {
        rotation.set(0.0, 0.0, 0.0, 1.0);
        scaling.set(1.0, 1.0, 1.0);
        translation.set(0.0, 0.0, 0.0);

        return this;
    }

    /**
     * Copies all 3 components from the argument.
     *
     * @param original the TransformDp to copy (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp set(TransformDp original) {
        Validate.nonNull(original, "original");

        rotation.set(original.getRotation());
        scaling.set(original.getScale());
        translation.set(original.getTranslation());

        return this;
    }

    /**
     * Sets all 3 components to the specified values.
     *
     * @param translate the desired translation (not null, unaffected)
     * @param rotate the desired rotation (not null, unaffected)
     * @param scale the desired scaling (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp set(Vector3d translate, Quaterniond rotate, Vector3d scale) {
        Validate.nonNull(translate, "translate");
        Validate.nonNull(rotate, "rotate");
        Validate.nonNull(scale, "scale");

        rotation.set(rotate);
        scaling.set(scale);
        translation.set(translate);

        return this;
    }

    /**
     * Sets the rotation component to the argument.
     *
     * @param rotate the desired rotation value (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp setRotation(Quaterniond rotate) {
        Validate.nonNull(rotate, "rotate");
        rotation.set(rotate);
        return this;
    }

    /**
     * Sets all components of the scaling component to the argument.
     *
     * @param factor the desired scale factor
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp setScale(double factor) {
        Validate.nonNull(factor, "factor");
        scaling.set(factor, factor, factor);
        return this;
    }

    /**
     * Sets the scaling component to the argument.
     *
     * @param scale the desired scaling (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp setScale(Vector3d scale) {
        Validate.nonNull(scale, "scale");
        scaling.set(scale);
        return this;
    }

    /**
     * Sets the translation component to the argument.
     *
     * @param translate the desired translation (not null, unaffected)
     * @return the (modified) current instance (for chaining)
     */
    public TransformDp setTranslation(Vector3d translate) {
        Validate.nonNull(translate, "translate");
        translation.set(translate);
        return this;
    }

    /**
     * Applies the inverse transform to the specified coordinates and returns
     * the result in {@code storeResult}. If the {@code storeResult} is null, a
     * new Vec3d is created to hold the value. Either way, the current instance
     * is unaffected, unless {@code storeResult} is its translation or scaling.
     * <p>
     * It IS safe for {@code in} and {@code storeResult} to be the same object.
     *
     * @param in the coordinates to transform (not null, unaffected unless it's
     * {@code storeResult})
     * @param storeResult storage for the result (modified if not null)
     * @return the transformed coordinates (either {@code storeResult} or a new
     * Vec3d)
     */
    public Vector3d transformInverseVector(Vector3d in, Vector3d storeResult) {
        Vector3d result;
        if (storeResult == null) {
            result = new Vector3d(in);
        } else {
            result = storeResult.set(in);
        }

        result.sub(translation);
        rotation.invert(new Quaterniond()).transformUnit(result, result);
        result.div(scaling);

        return result;
    }

    /**
     * Transforms the specified coordinates and returns the result in
     * {@code storeResult}. If the {@code storeResult} is null, a new Vec3d is
     * created to hold the value. Either way, the current instance is
     * unaffected, unless {@code storeResult} is its scaling component or its
     * translation component.
     * <p>
     * It IS safe for {@code in} and {@code storeResult} to be the same object.
     *
     * @param in the coordinates to transform (not null, unaffected unless it's
     * {@code storeResult})
     * @param storeResult storage for the result (modified if not null)
     * @return the transformed coordinates (either {@code storeResult} or a new
     * Vec3d)
     */
    public Vector3d transformVector(final Vector3d in, Vector3d storeResult) {
        Vector3d result;
        if (storeResult == null) {
            result = new Vector3d(in);
        } else {
            result = storeResult.set(in);
        }

        result.mul(scaling);
        rotation.transform(result, result);
        result.add(translation);

        return result;
    }
    // *************************************************************************
    // Object methods

    /**
     * Tests for exact equality with the argument, distinguishing -0 from 0. If
     * {@code otherObject} is null, false is returned. Either way, the current
     * instance is unaffected.
     *
     * @param otherObject the object to compare (may be null, unaffected)
     * @return true if {@code this} and {@code otherObject} have identical
     * values, otherwise false
     */
    @Override
    public boolean equals(Object otherObject) {
        boolean result;
        if (otherObject == this) {
            result = true;
        } else if (otherObject != null
                && otherObject.getClass() == getClass()) {
            TransformDp other = (TransformDp) otherObject;
            result = rotation.equals(other.rotation)
                    && translation.equals(other.translation)
                    && scaling.equals(other.scaling);
        } else {
            result = false;
        }

        return result;
    }

    /**
     * Returns a hash code. If two transforms have identical values, they will
     * have the same hash code. The current instance is unaffected.
     *
     * @return a 32-bit value for use in hashing
     */
    @Override
    public int hashCode() {
        int hash = 7;
        hash = 89 * hash + rotation.hashCode();
        hash = 89 * hash + translation.hashCode();
        hash = 89 * hash + scaling.hashCode();
        return hash;
    }

    /**
     * Returns a string representation of the transform, which is unaffected.
     * For example, the identity transform is represented by:
     * <pre>
     * TransformDp[ 0.0, 0.0, 0.0]
     * [ 0.0, 0.0, 0.0, 1.0]
     * [ 1.0 , 1.0, 1.0]
     * </pre>
     *
     * @return the string representation (not null, not empty)
     */
    @Override
    public String toString() {
        return getClass().getSimpleName()
                + "[ " + translation.x + ", " + translation.y + ", " + translation.z + "]\n"
                + "[ " + rotation.x + ", " + rotation.y + ", " + rotation.z + ", " + rotation.w + "]\n"
                + "[ " + scaling.x + " , " + scaling.y + ", " + scaling.z + "]";
    }
}
