int modPow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod; // Handle large base
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

int superPow(int a, int* b, int bSize) {
    int mod = 1337;
    int exp = 0;
    for(int i = 0; i < bSize; i++) {
        exp = (exp * 10 + b[i]);
        if(exp>1140)
        exp%=1140; // Euler's theorem reduction
    }
    return modPow(a, exp, mod);
}

