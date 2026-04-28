#include "arithmetic.hpp"

namespace arithmetic {

// Bus16 indexing convention in this project:
// index 0 = least significant bit
// index 15 = most significant bit

// half adder: adds two bits and returns the sum bit and carry-out
HalfAdderResult half_adder(Bit a, Bit b) {
    return {
        logic::xor_gate(a, b),
        logic::and_gate(a, b)
    };
}

// full adder: adds three bits: a, b, and carry_in
// built from two half adders and an OR gate
// returns the sum bit and carry-out
FullAdderResult full_adder(Bit a, Bit b, Bit carry_in) {
    HalfAdderResult first = half_adder(a, b);
    HalfAdderResult second = half_adder(first.sum, carry_in);

    return {
        second.sum,
        logic::or_gate(first.carry, second.carry)
    };
}

// add16: adds two 16-bit buses
// built from 16 full adders
// uses a ripple-carry chain starting at the least significant bit
Bus16 add16(Bus16 a, Bus16 b) {
    Bus16 out{};
    Bit carry = false;

    // index 0 is the least significant bit
    for (int i = 0; i < 16; ++i) {
        FullAdderResult result = full_adder(a[i], b[i], carry);
        out[i] = result.sum;
        carry = result.carry;
    }

    return out;
}

// inc16: increments a 16-bit bus by 1
// does this by creating a bus that represents 1, then calling add16
Bus16 inc16(Bus16 in) {
    Bus16 one{};
    one[0] = true; // +1 in the least significant bit position

    return add16(in, one);
}

// alu: arithmetic logic unit
// takes in two 16-bit buses, x and y, and control signals
// zx, nx, zy, ny, f, and no are control signals
// zero x if zx
// negate x if nx
// zero y if zy
// negate y if ny
// choose x & y or x + y based on f
// negate the output if no
// compute zr and ng
ALUResult alu(
    Bus16 x,
    Bus16 y,
    Bit zx,
    Bit nx,
    Bit zy,
    Bit ny,
    Bit f,
    Bit no
) {
    Bus16 zero{};

    // if zx == 1, set x = 0
    Bus16 x_zeroed = logic::mux16(x, zero, zx);

    // if nx == 1, set x = !x
    Bus16 x_inverted = logic::not16(x_zeroed);
    Bus16 x_processed = logic::mux16(x_zeroed, x_inverted, nx);

    // if zy == 1, set y = 0
    Bus16 y_zeroed = logic::mux16(y, zero, zy);

    // if ny == 1, set y = !y
    Bus16 y_inverted = logic::not16(y_zeroed);
    Bus16 y_processed = logic::mux16(y_zeroed, y_inverted, ny);

    // if f == 1, out = x + y
    // if f == 0, out = x & y
    Bus16 and_result = logic::and16(x_processed, y_processed);
    Bus16 add_result = add16(x_processed, y_processed);
    Bus16 out_pre_no = logic::mux16(and_result, add_result, f);

    // if no == 1, out = !out
    Bus16 out_inverted = logic::not16(out_pre_no);
    Bus16 out = logic::mux16(out_pre_no, out_inverted, no);

    // zr = 1 iff all bits of out are 0
    logic::Bits8 low8{
        out[0], out[1], out[2], out[3],
        out[4], out[5], out[6], out[7]
    };

    logic::Bits8 high8{
        out[8], out[9], out[10], out[11],
        out[12], out[13], out[14], out[15]
    };

    Bit low_nonzero = logic::or8way(low8);
    Bit high_nonzero = logic::or8way(high8);
    Bit any_nonzero = logic::or_gate(low_nonzero, high_nonzero);
    Bit zr = logic::not_gate(any_nonzero);

    // ng = most significant bit
    Bit ng = out[15];

    return {out, zr, ng};
}

} // namespace arithmetic