/*
 * bang - Compute !x without using !
 * Legal ops: ~ & ^ | + << >>
 */
int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;
}