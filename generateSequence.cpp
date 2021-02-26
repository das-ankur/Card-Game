#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
string generateSequence(int n) {
	char ch[4]={'C','D','H','S'};
	char no[13]={'A','2','3','4','5','6','7','8','9','T','J','K','Q'};
	string str;
	string s;
	int r,i;
	for(i=0;i<n;i++) {
		r=rand()%4;
		s=ch[r];
		str=str+s;
		r=rand()%13;
		s=no[r];
		str=str+s;
	}
	return str;
}
