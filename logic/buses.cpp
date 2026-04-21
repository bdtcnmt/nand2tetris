#include "buses.hpp"

namespace logic {
    
// FOR LOOP VERSION OF EACH IS AT THE BOTTOM
Bus16 not16(Bus16 in) {
    Bus16 out{};

    out[0] = not_gate(in[0]);
    out[1] = not_gate(in[1]);
    out[2] = not_gate(in[2]);
    out[3] = not_gate(in[3]);
    out[4] = not_gate(in[4]);
    out[5] = not_gate(in[5]);
    out[6] = not_gate(in[6]);
    out[7] = not_gate(in[7]);
    out[8] = not_gate(in[8]);
    out[9] = not_gate(in[9]);
    out[10] = not_gate(in[10]);
    out[11] = not_gate(in[11]);
    out[12] = not_gate(in[12]);
    out[13] = not_gate(in[13]);
    out[14] = not_gate(in[14]);
    out[15] = not_gate(in[15]);

    return out;
}

Bus16 and16(Bus16 a, Bus16 b) {
    Bus16 out{};

    out[0] = and_gate(a[0], b[0]);
    out[1] = and_gate(a[1], b[1]);
    out[2] = and_gate(a[2], b[2]);
    out[3] = and_gate(a[3], b[3]);
    out[4] = and_gate(a[4], b[4]);
    out[5] = and_gate(a[5], b[5]);
    out[6] = and_gate(a[6], b[6]);
    out[7] = and_gate(a[7], b[7]);
    out[8] = and_gate(a[8], b[8]);
    out[9] = and_gate(a[9], b[9]);
    out[10] = and_gate(a[10], b[10]);
    out[11] = and_gate(a[11], b[11]);
    out[12] = and_gate(a[12], b[12]);
    out[13] = and_gate(a[13], b[13]);
    out[14] = and_gate(a[14], b[14]);
    out[15] = and_gate(a[15], b[15]);

    return out;
}

Bus16 or16(Bus16 a, Bus16 b) {
    Bus16 out{};

    out[0] = or_gate(a[0], b[0]);
    out[1] = or_gate(a[1], b[1]);
    out[2] = or_gate(a[2], b[2]);
    out[3] = or_gate(a[3], b[3]);
    out[4] = or_gate(a[4], b[4]);
    out[5] = or_gate(a[5], b[5]);
    out[6] = or_gate(a[6], b[6]);
    out[7] = or_gate(a[7], b[7]);
    out[8] = or_gate(a[8], b[8]);
    out[9] = or_gate(a[9], b[9]);
    out[10] = or_gate(a[10], b[10]);
    out[11] = or_gate(a[11], b[11]);
    out[12] = or_gate(a[12], b[12]);
    out[13] = or_gate(a[13], b[13]);
    out[14] = or_gate(a[14], b[14]);
    out[15] = or_gate(a[15], b[15]);

    return out;
}

Bus16 mux16(Bus16 a, Bus16 b, Bit sel) {
    Bus16 out{};

    out[0] = mux(a[0], b[0], sel);
    out[1] = mux(a[1], b[1], sel);
    out[2] = mux(a[2], b[2], sel);
    out[3] = mux(a[3], b[3], sel);
    out[4] = mux(a[4], b[4], sel);
    out[5] = mux(a[5], b[5], sel);
    out[6] = mux(a[6], b[6], sel);
    out[7] = mux(a[7], b[7], sel);
    out[8] = mux(a[8], b[8], sel);
    out[9] = mux(a[9], b[9], sel);
    out[10] = mux(a[10], b[10], sel);
    out[11] = mux(a[11], b[11], sel);
    out[12] = mux(a[12], b[12], sel);
    out[13] = mux(a[13], b[13], sel);
    out[14] = mux(a[14], b[14], sel);
    out[15] = mux(a[15], b[15], sel);

    return out;
}

} // namespace logic


/* FOR LOOP VERSION */
/*

Bus16 not16(Bus16 in) {
    Bus16 out{};

    for (int i = 0; i < 16; ++i) {
        out[i] = not_gate(in[i]);
    }

    return out;
}

Bus16 and16(Bus16 a, Bus16 b) {
    Bus16 out{};

    for (int i = 0; i < 16; ++i) {
        out[i] = and_gate(a[i], b[i]);
    }

    return out;
}

Bus16 or16(Bus16 a, Bus16 b) {
    Bus16 out{};

    for (int i = 0; i < 16; ++i) {
        out[i] = or_gate(a[i], b[i]);
    }

    return out;
}

Bus16 mux16(Bus16 a, Bus16 b, Bit sel) {
    Bus16 out{};

    for (int i = 0; i < 16; ++i) {
        out[i] = mux(a[i], b[i], sel);
    }

    return out;
}

*/