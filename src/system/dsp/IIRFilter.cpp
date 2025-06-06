#include "dsp/IIRFilter.h"
#include "IIRFilter.h"

IIR4PoleFilter::IIR4PoleFilter(float* f1, float* f2){



    for(int i = 0; i < 4; i++) {
        f1[i] = 0.0f;
        f1 = &f1[i];
        f1[4] = f2[i];
        f1[12] = -mB0[i];
        f1[8] = -*f2 * mB0[i];
        f1[16] = 0.0f;
    }
}

float IIR4PoleFilter::FilterSlow(float f1){
    mV[0] = mV[1] + (mB[1] * f1) + (mA[1] * ((mB0[0] * f1) + mV[0]));
    mV[1] = mV[2] + (mB[2] * f1) + (mA[2] * ((mB0[0] * f1) + mV[0]));
    mV[2] = mV[3] + (mB[3] * f1) + (mA[3] * ((mB0[0] * f1) + mV[0]));
    mV[3] = (mB[0] * f1) + (mA[0] * ((mB0[0] * f1) + mV[0]));

    return (mB0[0] * f1) + mV[0];
}

IIR4PoleFilter IIR4PoleFilter::Begin() {

}

IIR4PoleFilter IIR4PoleFilter::End() {

}
