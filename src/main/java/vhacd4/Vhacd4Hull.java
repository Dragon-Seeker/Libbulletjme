/*
 Copyright (c) 2016, Riccardo Balbo
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the copyright holder nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
package vhacd4;

import com.jme3.util.BufferUtils;
import jme3utilities.math.MyVector3f;

import java.nio.FloatBuffer;
import java.util.logging.Logger;

/**
 * A 3-D convex hull based on a V-HACD version 4 ConvexHull. Immutable.
 */
public class Vhacd4Hull {
    // *************************************************************************
    // constants and loggers

    /**
     * message logger for this class
     */
    final public static Logger logger
            = Logger.getLogger(Vhacd4Hull.class.getName());
    // *************************************************************************
    // fields

    /**
     * vertex locations (not empty, length a multiple of 3)
     */
    final private float[] positions;
    // *************************************************************************
    // constructors

    /**
     * Instantiate a hull based on the identified ConvexHull.
     *
     * @param hullId the native ID of a ConvexHull (not zero)
     */
    Vhacd4Hull(long hullId) {
        assert hullId != 0L;

        int numFloats = getNumFloats(hullId);
        assert numFloats > 0 : numFloats;
        assert numFloats % MyVector3f.numAxes == 0 : numFloats;

        FloatBuffer floatBuffer = BufferUtils.createFloatBuffer(numFloats);
        getPositions(hullId, floatBuffer);
        positions = new float[numFloats];
        for (int floatIndex = 0; floatIndex < numFloats; ++floatIndex) {
            positions[floatIndex] = floatBuffer.get(floatIndex);
        }
    }
    // *************************************************************************
    // new methods exposed

    /**
     * Copy the vertex positions to a new array.
     *
     * @return the new array (not empty, length a multiple of 3)
     */
    public float[] clonePositions() {
        int numFloats = positions.length;
        assert numFloats > 0 : numFloats;
        assert numFloats % MyVector3f.numAxes == 0 : numFloats;

        float[] result = new float[numFloats];
        System.arraycopy(positions, 0, result, 0, numFloats);

        return result;
    }
    // *************************************************************************
    // native private methods

    native private static int getNumFloats(long hullId);

    native private static void getPositions(long hullId,
            FloatBuffer storeBuffer);
}
