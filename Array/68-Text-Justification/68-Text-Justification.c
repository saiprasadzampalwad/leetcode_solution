/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) 
{
    char** result = (char**)malloc(1000 * sizeof(char*));
    *returnSize = 0;
    int i = 0;

    while (i < wordsSize) 
    {
        int lineLength = 0;
        int j = i;
        
        while (j < wordsSize && lineLength + strlen(words[j]) + (j - i) <= maxWidth) 
        {
            lineLength += strlen(words[j]);
            j++;
        }

        int spaceCount = maxWidth - lineLength;
        int gaps = j - i - 1;
        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        
        if (j == wordsSize || gaps == 0) 
        {
            // Last line or a line with only one word (left justified)
            int pos = 0;
            for (int k = i; k < j; k++)
             {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if (k < j - 1) 
                {
                    line[pos] = ' ';
                    pos++;
                }
            }
            memset(line + pos, ' ', maxWidth - pos);
            line[maxWidth] = '\0';
        }
         else
         {
            // Fully justify the line
            int spaces = spaceCount / gaps;
            int extraSpaces = spaceCount % gaps;
            int pos = 0;
            
            for (int k = i; k < j; k++)
             {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if (k < j - 1)
                 {
                    int spaceWidth = spaces + (k - i < extraSpaces ? 1 : 0);
                    memset(line + pos, ' ', spaceWidth);
                    pos += spaceWidth;
                }
            }
            line[maxWidth] = '\0';
        }

        result[*returnSize] = line;
        (*returnSize)++;
        i = j;
    }
    return result;
}