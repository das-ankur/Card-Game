#include<iostream>
#include<stdlib.h>
using namespace std;
string cardsShuffle(string str) {
	int n=rand()%10+1;
	int i, pos1, pos2;
	char temp;
	for(i=0;i<n;i++) {
		pos1=rand()%str.size();
		if(pos1%2!=0) 
			pos1--;
		pos2=rand()%str.size();
		if(pos2%2!=0) 
			pos2--;
		temp=str[pos1];
		str[pos1]=str[pos2];
		str[pos2]=temp;
		temp=str[pos1+1];
		str[pos1+1]=str[pos2+1];
		str[pos2+1]=temp;
	}
	return str;
}
