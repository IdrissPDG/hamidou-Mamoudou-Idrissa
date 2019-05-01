#define _XOPEN_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("Usage: crack<hash>\n");
        return 1;
    }
    int idriss= 53;
    string letters ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash =argv[1];
    char salt[3];
    memcpy(salt,hash,2);
    salt[2] ='\0';
    char MDP[6]= "\0\0\0\0\0\0";
    for(int fifth = 0; fifth < idriss; fifth++)
    {
        for(int fourth = 0; fourth < idriss; fourth++)
        {
            for(int third = 0; third < idriss; third++)
            {
                for( int second = 0; second < idriss; second++)
                {
                    for( int first = 1; first < idriss; first++)
                    {
                        MDP[0]= letters[first];
                        MDP[1]= letters[second];
                        MDP[2]= letters[third];
                        MDP[3]= letters[fourth];
                        MDP[4]= letters[fifth];

                        if(strcmp(crypt( MDP, salt), hash ) ==0)
                        {
                            printf("%s\n", MDP);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf(" LE MDP NE PEUT PAS ETRE CRACKER");
    return 2;
}

