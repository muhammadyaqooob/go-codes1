#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int charRepeated(char *key)
{

    printf("the requested key is %s\n",key);

    for(int i=0;i<strlen(key);i++)
    {
        for(int j=i+1;j<strlen(key);j++)
        {
            if(key[i]==key[j])
            {
                return 1;
            }
        }
    }

    return 0;


}


int alreadyEntered(char **keys,char * key, int pos)
{
    int numberOfnotMatch=0;
    for(int i=0;i<pos;i++)
    {
        for(int j=0;j<strlen(key);j++)
        {
            if(keys[i][j]!=key[j])
            {
                numberOfnotMatch++;
                break;
            }
            
        }
        
    }

    if(pos==0 || numberOfnotMatch==(pos))
    {
        return 0;
    }
    else
    {
        return 1;
    }


}

int main()
{

	char plainText[1000]="";
	int numberOfKeys=0;
	printf("Enter the Plain Text\n");
	scanf("%s",plainText);

	printf("Enter the number of Keys you want\n");
	scanf("%d",&numberOfKeys);

	int nrows=numberOfKeys;
	int ncolumns=26;

	char **keys = malloc(nrows * sizeof(char *)); // Allocate row pointers
	for(int i = 0; i < nrows; i++)
	{
		keys[i] = malloc(ncolumns * sizeof(char));  // Allocate each row separately
	}



	for(int i=0;i<numberOfKeys;i++)
	{
		printf("Enter the key# :%d\n",i+1);
		scanf("%s",keys[i]);

        while(charRepeated(keys[i]) || strlen(keys[i])!=26 || alreadyEntered(keys,keys[i],i))
        {
            printf("Either the length is not 26 or some characters are repeating in the array,or you entered two or more same keys. Please Re-Enter the key\n");
            printf("Enter the key# :%d\n",i+1);
		    scanf("%s",keys[i]);

        }
	}



	for(int i=0;i<numberOfKeys;i++)
	{
		printf("The key # is  :%d\n",i+1);
		printf("%s\n",keys[i]);
       
	}


    int arrchars[26];
    for(int i=0;i<26;i++)
    {
        arrchars[i]=0;
    }
    char cipherText[1000]="";

    for (int i=0;i<strlen(plainText);i++)
    {

        int a=plainText[i]-65;
        strncat(cipherText, &keys[arrchars[a]%numberOfKeys][a], 1);
        ++arrchars[a];
        
    }
    printf("%s \n",cipherText);

}