#pragma once

class IIR4PoleFilter {
public:
    IIR4PoleFilter(float*, float*);
    float FilterSlow(float);
    IIR4PoleFilter Begin();
    IIR4PoleFilter End();


private:
    float mB0[4]; // 0x0
    float mB[4]; // 0x10
    float mC[4]; // 0x20
    float mA[4]; // 0x30
    float mV[4]; // 0x40
};
