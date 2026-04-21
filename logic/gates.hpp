#pragma once
#include "primitive/primitive.hpp"

namespace logic {

struct DMuxResult {
    Bit a;
    Bit b;
};

Bit not_gate(Bit in);
Bit and_gate(Bit a, Bit b);
Bit or_gate_nand(Bit a, Bit b);
Bit or_gate(Bit a, Bit b);
Bit xor_gate_nand(Bit a, Bit b);
Bit xor_gate(Bit a, Bit b);
Bit mux(Bit a, Bit b, Bit sel);
DMuxResult dmux(Bit in, Bit sel);

} // namespace logic