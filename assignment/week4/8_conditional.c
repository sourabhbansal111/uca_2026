/*
 * conditional - same as x ? y : z
 * Legal ops: ! ~ & ^ | + << >>
 */
int conditional(int x, int y, int z) {
    int mask = ~(!x) + 1;
    return (mask & y) | (~mask & z);
}