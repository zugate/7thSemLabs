#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char st[50];   //assuming the maximum size of the plain text to not exceed 50
	printf("Enter the Plain text : ");
	scanf("%s[^ ]",st);
	
	int l=strlen(st); //length of the plain text
	//modifying the plain text and creating digraph

	char modst[50];
	int i,k=0;
	for(i=0;i<(l-1);i++)
	{
		if(st[i]==st[i+1])
		{
			modst[k++]=st[i];
			modst[k++]='x';
		}
		else
		{
			modst[k++]=st[i];
		}
	}
	modst[k]=st[i];        // adds the last character of the string to the modified text
	printf("%s\n",modst);  //prints the modified string
    
    //if the modified string is not even
    
    if(strlen(modst)%2!=0)
        modst[k+1]='x';

    char key[26];
    printf("Enter the key : ");
    scanf("%s[^ ]",key);
    
    //immitatintg hash key feature by creating an array of alphabets
    
    int arr[26]={0};
    printf("%d",arr[25]);
    
    //creating key matrix
    char keymat[5][5];
    int j,m=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(m!=strlen(modst)){   //following this untill the length of modified text
                if(arr[97-modst[m]]!=0)
                    keymat[i][j]=modst[m];
                
            }            
        }
    }
    
    return 0;
}
