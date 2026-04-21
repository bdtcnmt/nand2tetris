#include "gates.hpp"

namespace logic {

Bit not_gate(Bit in) {
    return nand_gate(in, in);
}

Bit and_gate(Bit a, Bit b) {
    Bit x = nand_gate(a, b);
    return nand_gate(x, x);
    // return nand_gate(nand_gate(a, b), nand_gate(a, b));
}

// nand only version
Bit or_gate_nand(Bit a, Bit b) {
    return nand_gate(nand_gate(a, a), nand_gate(b, b));
}

Bit or_gate(Bit a, Bit b) {
    return nand_gate(not_gate(a), not_gate(b));
}

// nand only version
Bit xor_gate_nand(Bit a, Bit b) {
    Bit x = nand_gate(a, b);
    Bit y = nand_gate(a, x);
    Bit z = nand_gate(b, x);
    return nand_gate(y, z);
    // return nand_gate(nand_gate(a, nand_gate(a, b)), nand_gate(b, nand_gate(a, b)));
}

Bit xor_gate(Bit a, Bit b) {
    Bit x = and_gate(not_gate(a), b);
    Bit y = and_gate(a, not_gate(b));
    return or_gate(x, y);
}

// multiplexer 
Bit mux(Bit a, Bit b, Bit sel) {
    // (a AND NOT(sel)) OR (b AND sel)
    return or_gate(and_gate(a, not_gate(sel)), and_gate(b, sel));
}

// demultiplexer
DMuxResult dmux(Bit in, Bit sel) {
    return {and_gate(in, not_gate(sel)), and_gate(in, sel)};
}

} // namespace logic