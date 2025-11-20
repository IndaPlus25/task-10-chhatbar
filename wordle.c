#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{

char word[500];
char v[5];
printf("Enter a 5-letter word\n");
scanf("%s", word);

int wordLength = strlen(word);
for (int i = 0; i < wordLength; i++)
{
    v[i] = word[i];
}

if (wordLength == 5)
{

    bool win = false;

    for (int i = 0; i < 6; i++)
    {
        char guess[500];
        printf("Enter a word\n");
        scanf("%s", guess);
        int guessLength = strlen(guess);
        if (guessLength != 5)
        {
            printf("Enter a 5-letter word!\n");
            i--;
            continue;
        }
        else
        {
            char vec[5];
            for (int p = 0; p < 5; p++)
            {
                vec[p] = guess[p];
            }
            char ans[6];
            for (int k = 0; k < 5; k++)
            {
                ans[k] = 'X';
            }

            ans[5] = '\0';

            for (int j = 0; j < 5; j++)
            {
                
                if (vec[j] == v[j])
                {
                    ans[j] = 'G';
                    continue;
                }

                else 
                {
                    bool letterExists = false;
                    for (int k = 0; k < 5; k++)
                    {
                        if (v[k] == vec[j])
                        {
                            letterExists = true;
                            break;
                        }
                    }
                    if (letterExists && vec[j] != v[j])
                    {
                        ans[j] = 'Y';
                        continue;
                    }
                }
                
            }

            for (int c = 0; c < 5; c++) 
            {
                printf("%c", ans[c]);
            }

            printf("\n");
            
            if (strcmp(ans, "GGGGG") == 0)
            {
                printf("You win!");
                win = true;
                break;
            }

            if (i == 5 && win == false)
            {
                printf("Game over");
                break;
            }

        }
    }
}
else 
{
    printf("Please enter a 5-letter word!\n");
}


return 0;
}