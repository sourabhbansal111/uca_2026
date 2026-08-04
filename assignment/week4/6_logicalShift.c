/*
 * logicalShift - shift x to the right by n, using a logical shift
 * Legal ops: ~ & ^ | + << >>
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}