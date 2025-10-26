#include <stdio.h>
#include <string.h>
int matchAt(char *a, char *word, int pos) {
    int i = 0;
    while (word[i] != '\0') {
        if (a[pos + i] != word[i])
            return 0;
        i++;
    }
    return 1;
}

void main() {
    FILE *fp;
    char a[100], result[100];
    char oldWord[100], newWord[100];
    int i = 0, j = 0;

   
    fp = fopen("Sample.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    while (!feof(fp)) {
		
			a[i++] = fgetc(fp);
    }
    a[i] = '\0';
    fclose(fp);

    
    printf("Enter word to find: ");
    scanf("%s", oldWord);
    printf("Enter word to replace with: ");
    scanf("%s", newWord);

    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);
    i = 0;
    
    while (a[i] != '\0') {
        if (matchAt(a, oldWord, i)) {
            for (int k = 0; k < newLen; k++)
				
			
                result[j++] = newWord[k];
            i += oldLen;
        } else {
			
            result[j++] = a[i++];
        }
    }
    result[j] = '\0';

    
    fp = fopen("Sample.txt", "w");
    fputs(result, fp);
    fclose(fp);

    
}