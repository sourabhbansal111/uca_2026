/*
 * getByte - Extract byte n from word x
 * Bytes numbered from 0 (LSB) to 3 (MSB)
 * Legal ops: ! ~ & ^ | + << >>
 */
int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}