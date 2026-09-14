int romanToInt(char* s) {
    int val[256] = {0};
    int total = 0;

    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    for (int i = 0; s[i]; i++) {
        if (val[(unsigned char)s[i]] < val[(unsigned char)s[i + 1]])
            total -= val[(unsigned char)s[i]];
        else
            total += val[(unsigned char)s[i]];
    }

    return total;
}