/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 * Legal ops: ! ~ & ^ | + << >>
 */
int sign(int x) {
    return (x >> 31) | (!!x);
}