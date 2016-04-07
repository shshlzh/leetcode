#include <stdio.h>
#include <malloc.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
	int i;
    for(i=0; s[i] != '\0'; i++){
        if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen; 
}

int main(int argc, char* argv[]) {
	char s[] = "abcbef";
	int len = lengthOfLongestSubstring(s);
	printf("%d\n", len);

	return 0;
}
