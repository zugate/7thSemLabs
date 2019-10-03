#include<bits/stdc++.h>
using namespace std;

int permchoice[]={
	57, 49, 41, 33, 25, 17, 9,
	 1, 58, 50, 42, 34, 26, 18,
	10, 2 , 59, 51, 43, 35, 27,
	19, 11, 3 , 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7 , 62, 54, 46, 38, 30, 22,
	14, 6 , 61, 53, 45, 37, 29,
	21, 13, 5 , 28, 20, 12, 4 
};

int permchoice2[]={
	14, 17, 11, 24, 1, 5, 3, 28,
	15, 6, 21, 10, 23, 19, 12, 4,
	26, 8 , 16, 7 , 27, 20, 13, 2 ,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32 
};
int leftshifttable[]={1,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
string firstpermute(string input){

	string res="";
	for(int i=0;i<56;i++){
		res+=input[permchoice[i]-1];
	}
	return res;
}

string rotatearr(string str,int rot)
{
	return(str.substr(rot,str.length()-rot)+str.substr(0,rot));
}

string secondpermute(string str){

	string res="";
	for(int i=0;i<48;i++){

		res+=str[permchoice2[i]-1];
	}
	return res;
}
void genkeys(string left,string right){
	
	
	for(int i=0;i<16;i++){
		
		left=rotatearr(left,leftshifttable[i]);
		right=rotatearr(right,leftshifttable[i]);
		string key=secondpermute(left+right);

		cout<<"KEY "<<(i+1)<<" : "<<key<<endl;

	}
}
int main()
{
	unsigned long long hexkey;
	cout<<"\nEnter the key in hex form"<<endl;
	cin>>hex>>hexkey;

	string key=bitset<64>(hexkey).to_string();
	cout<<"Binary key "<<key<<endl;
	key=firstpermute(key);
	cout<<"Key after permutaion :"<<key<<endl;

	cout<<"subkeys"<<endl;
	genkeys(key.substr(0,28),key.substr(28,28));
	cout<<endl;
}