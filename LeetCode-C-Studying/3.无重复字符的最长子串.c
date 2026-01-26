int lengthOfLongestSubstring(char* s) {
    int ch_own_len = 1;
    char* ch_own = (char*)calloc(ch_own_len, sizeof(char));
    int len_max = 0;
    for (int i = 0, contin = 0; s[i] != '\0'; i++) {
        for (int j = 0; ch_own[j] != '\0'; j++)
            if (s[i] == ch_own[j]) {
                len_max = ch_own_len - 1 > len_max ? ch_own_len - 1 : len_max, ch_own_len = 1;
                ch_own = (char*)calloc(ch_own_len, sizeof(char));
                i = contin + 1, contin = i;
                break;
            }
        ch_own = (char*)realloc(ch_own, ++ch_own_len);
        ch_own[ch_own_len - 1] = '\0', ch_own[ch_own_len - 2] = s[i];
    }
    len_max = ch_own_len - 1 > len_max ? ch_own_len - 1 : len_max;
    free(ch_own);
    return len_max;
}