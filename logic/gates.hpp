#pragma once
#include "primitive/primitive.hpp"

namespace logic {

Bit not_gate(Bit in);
Bit and_gate(Bit a, Bit b);
Bit or_gate_nand(Bit a, Bit b);
Bit or_gate(Bit a, Bit b);
Bit xor_gate_nand(Bit a, Bit b);
Bit xor_gate(Bit a, Bit b);

} // namespace logic