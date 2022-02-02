#include <assert.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int hamming_weight = 0;
    while (n != 0) {
        hamming_weight += (n & 1);
        n >>= 1;
    }
    
    return hamming_weight;
}

int main(void) {
    assert(hammingWeight(0b00000000000000000000000000001011) == 3);
    assert(hammingWeight(0b00000000000000000000000010000000) == 1);
    assert(hammingWeight(0b11111111111111111111111111111101) == 31);

    return 0;
}
