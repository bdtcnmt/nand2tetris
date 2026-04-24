#include "multiway.hpp"

namespace logic {

Bit or8way(Bits8 in) {
    Bit out = false;

    for (int i = 0; i < 8; i++) {
        out = or_gate(out, in[i]);
    }

    return out;
}

Bus16 mux4way16(Bus16 a, Bus16 b, Bus16 c, Bus16 d, Bits2 sel) {
    Bus16 ab = mux16(a, b, sel[0]);
    Bus16 cd = mux16(c, d, sel[0]);

    return mux16(ab, cd, sel[1]);
}

Bus16 mux8way16(Bus16 a, Bus16 b, Bus16 c, Bus16 d, 
                Bus16 e, Bus16 f, Bus16 g, Bus16 h, 
                Bits3 sel
) {
    Bits2 low_sel{sel[0], sel[1]};

    Bus16 left = mux4way16(a, b, c, d, low_sel);
    Bus16 right = mux4way16(e, f, g, h, low_sel);

    return mux16(left, right, sel[2]);
}

DMux4WayResult dmux4way(Bit in, Bits2 sel) {
    DMuxResult first = dmux(in, sel[1]);
    DMuxResult left = dmux(first.a, sel[0]);
    DMuxResult right = dmux(first.b, sel[0]);

    return {left.a, left.b, right.a, right.b};
}

DMux8WayResult dmux8way(Bit in, Bits3 sel) {
    DMuxResult first = dmux(in, sel[2]);
    Bits2 low_sel{sel[0], sel[1]};

    DMux4WayResult left = dmux4way(first.a, low_sel);
    DMux4WayResult right = dmux4way(first.b, low_sel);

    return {left.a, left.b, left.c, left.d, right.a, right.b, right.c, right.d};
}

} // namespace logic