/*
 * fitsBits - return 1 if x can be represented as an
 * n-bit, two's complement integer.
 * Legal ops: ! ~ & ^ | + << >>
 */
int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !(((x << shift) >> shift) ^ x);
}