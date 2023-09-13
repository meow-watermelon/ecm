short int integer_length(long int integer) {
    short int counter = 1;
    long int multiplier = 1;

    while (1) {
        if (integer / multiplier >= 0 && integer / multiplier < 10) {
            break;
        }

        ++counter;
        multiplier *= 10;
    }

    return counter;
}
