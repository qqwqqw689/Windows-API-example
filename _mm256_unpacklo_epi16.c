#include <stdio.h>
#include <immintrin.h>

void print_m256i(__m256i data)
{
    // Create an array to hold the data
    short temp[16]; // __m256i holds 16 short (16-bit) integers
    _mm256_storeu_si256((__m256i*)temp, data);

    // Print the contents
    printf("__m256i contents: ");
    for (int i = 0; i < 16; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

void interlace(short* out, const short* in)
{
    __m256i first = _mm256_loadu_si256((__m256i const*) in);
    print_m256i(first);
    __m256i second = _mm256_loadu_si256((__m256i const*) (in + 16));
    print_m256i(second);
    __m256i ac = _mm256_unpacklo_epi16(first, second);
    print_m256i(ac);
    __m256i bd = _mm256_unpackhi_epi16(first, second);
    print_m256i(bd);
    __m256i low = _mm256_inserti128_si256(ac, _mm256_castsi256_si128(bd), 1);
    print_m256i(low);
    __m256i high = _mm256_permute2x128_si256(ac, bd, _MM_SHUFFLE(0, 3, 0, 1));
    print_m256i(high);
    _mm256_storeu_si256((__m256i*) out, low);
    _mm256_storeu_si256((__m256i*) (out + 16), high);
}

int main()
{
    // Input array
    short input[32];
    for (int i = 0; i < 32; ++i) {
        input[i] = i + 1; // Fill with numbers 1 to 32
    }

    // Output array
    short output[32];

    // Call the interlace function
    interlace(output, input);

    // Print the input and output
    printf("Input:\n");
    for (int i = 0; i < 32; ++i) {
        printf("%d ", input[i]);
    }
    printf("\n");

    printf("Output:\n");
    for (int i = 0; i < 32; ++i) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
