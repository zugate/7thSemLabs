#include<bits/stdc++.h>
using namespace std;

int main(){
	int keylen;
	cout<<"Enter the length of the key"<<endl;
	cin>>keylen;
	int k=0,i=0;
	int key[keylen];
	//generating a random key
	while((k++)!=keylen){
		key[i++]=rand()%keylen+1;
	}
	//first taking the string as input and modifying the text
	char str[100];
	cout<<"Enter the text to encrypt :"<<endl;
	cin>>str;
	int l=strlen(str);
	if(l%keylen!=0)
	{
		while(l%keylen!=0)
		{
			str[l++]='x'; //adding filler
		}
		str[l]='\0';
	} 
	// cout<<str<<endl; //modified text
	//creating  the matrix
	k=0;
	int row=strlen(str)/keylen;
	char mat[row][keylen];
	for(int i=0;i<row;i++){
		for(int j=0;j<keylen;j++){
			mat[i][j]=str[k++];
		}
	}
	//printing the matrix for encryption
	for(int i=0;i<keylen;i++)
		cout<<key[i]<<" ";
	cout<<endl;

	for(int i=0;i<row;i++){
		for(int j=0;j<keylen;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	//setting the order of reading
	int order[keylen];
	for(int i=0;i<keylen;i++)
	{
		order[key[i]-1]=i;//basically reading the index of the keys
	}
	//order = 3,0,2,1
	// reading the matrix according to the key
	char enc[l];
	k=0;
	for(int i=0;i<keylen;i++)
	{
		for(int j=0;j<row;j++){
			enc[k++]=mat[j][order[i]];
		}
	}
	//the encrypted text
	cout<<"Encryped text:"<<endl;
	for(int j=0;j<l;j++){
		cout<<enc[j];
	}
	//Now for decryption we have to again put encrypted text in the matrix columnwise
	k=0;
	for(int i=0;i<keylen;i++){
		for(int j=0;j<row;j++){
			mat[j][order[i]]=enc[k++];
		}
	}
	// decrypted text reading it one by one
	cout<<endl<<"decrypted text"<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<keylen;j++){
			cout<<mat[i][j];
		}
	}
	return 0;
}