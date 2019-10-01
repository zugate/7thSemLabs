#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int s;
	char str[100];
	cout<<"Enter the string"<<endl;
	cin>>str;

	cout<<"Enter the size of the key matrix"<<endl;
	cin>>s;

	//taking the key matrix as input

	cout<<"Enter the key matrix "<<endl;

	int key[s][s];
	for(int i=0;i<s;i++)
		for(int j=0;j<s;j++)
			cin>>key[i][j];
 
	int l=strlen(str);  // size of the atring to be encrypted
	// adding fillers as to make the char length in the text multiple of the size of the matrix
	int templ=l;
	while(templ%s!=0){
			str[templ++]='x';
	}

	str[templ]='\0';  // for string you need to do this to terminate the string

	// dividing the string  in s equal  parts ..if number of the characters are not in the multiple of s then divide them 
		// declaring a temporary storage variable for the s characters

	char selS[s]; // for storing s characters temporarily
	int enc[s]; // for storing s encrypted text
	int enclen=0;	
	for(int i=0;i<l;i+=s){
		int k=i;
		while(k!=s){  // staging the s characters for encrption
			selS[k++]=str[i];
		}

		// now we need to multiply the selS with the key matrix and store it in enc

		for(int j=0;j<s;j++,enclen++){
			for(int m=0;m<s;m++){
				for(int n=0;n<s;n++)
					enc[enclen]+=key[j][n]*((int)selS[n]-97);
			}
		}
		
	}   
	for(int i=0;i<enclen;i++)
		cout<<enc[i]<<" ";
	


	return 0;
}