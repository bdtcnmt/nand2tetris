#pragma once

#include "logic/multiway.hpp"

namespace arithmetic {

using logic::Bit;
using logic::Bus16;

struct HalfAdderResult {
    Bit sum;
    Bit carry;
};

struct FullAdderResult {
    Bit sum;
    Bit carry;
};

struct ALUResult {
    Bus16 out;
    Bit zr;
    Bit ng;
};

HalfAdderResult half_adder(Bit a, Bit b);
FullAdderResult full_adder(Bit a, Bit b, Bit carry_in);
Bus16 add16(Bus16 a, Bus16 b);
Bus16 inc16(Bus16 in);

ALUResult alu(
    Bus16 x,
    Bus16 y,
    Bit zx,
    Bit nx,
    Bit zy,
    Bit ny,
    Bit f,
    Bit no
);

} // namespace arithmetic