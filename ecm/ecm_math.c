long int powi(long int base, short int exponent) {
    long int result = base;

    if (exponent < 0) {
        return 0;
    }

    if (exponent == 0) {
        return base;
    }

    while (--exponent) {
        result *= base;
    }

    return result;
}
