/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 * Legal ops: ! ~ & ^ | + << >>
 */
int isPower2(int x) {
    return !!x & !(x >> 31) & !(x & (x + ~0));
}