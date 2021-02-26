#include<iostream>
#include<string.h>
using namespace std;
double calcLikenessScore(string seq1, string seq2) {
	int i, scount=0, srcount=0;
	double score;
	if(seq1.size()!=seq2.size())
		score=-1.00;
	else {
		for(i=0;seq1[i]!='\0';i=i+2) {
			if(seq1[i]==seq2[i]) {
				scount++;
				if(seq1[i+1]==seq2[i+1])
					srcount++;
			}
		}
		score=((double)scount/((double)seq1.size()/2))+(double)srcount;
	}
	return score;
}	
double bestLikenessScore(string seq1, string gold_seq) {
	double max=0, temp;
	int offset=gold_seq.size();
	int i;
	string subs;
	if(seq1.size()<gold_seq.size())
		max=-1.00;
	else {
		for(i=0;i+offset-1<seq1.size();i=i+2) {
			subs=seq1.substr(i, offset);
			temp=calcLikenessScore(subs, gold_seq);
			if(max<temp)
				max=temp;
		}
	}
	return max;
}	
void findWinner(string seq1, string seq2, string seq3, string gold_seq) {
		double player1=bestLikenessScore(seq1, gold_seq);
		double player2=bestLikenessScore(seq2, gold_seq);
		double player3=bestLikenessScore(seq3, gold_seq);
		if(player1==0 && player2==0 and player3==0)
			cout<<"Better luck next time everyone!"<<endl;
		else if(player1==player2 && player2==player3)
			cout<<"Congratulations everyone! You have all won!"<<endl;
		else if(player1==player2)
			cout<<"Congratulations Players 1 and 2!"<<endl;
		else if(player2==player3)
			cout<<"Congratulations Players 2 and 3!"<<endl;
		else if(player1==player3)
			cout<<"Congratulations Players 1 and 3!"<<endl;
		else if(player1 > player2 && player1 > player3)
			cout<<"Congratulations Player 1! You have won!"<<endl;
		else if(player2 > player3 && player2 > player1)
			cout<<"Congratulations Player 2! You have won!"<<endl;
		else
			cout<<"Congratulations Player 3! You have won!"<<endl;
}		
int main() {
	int choice;
	string str1, str2, str3, str4;
	while(true) {
		cout<<"----Menu!----"<<endl;
		cout<<"Choice 1: Calculate the Likeness Score between 2 strings of equal length."<<endl;
		cout<<"Choice 2: Calculate the Best Likeness Score between 2 sequences of possibly different length."<<endl;
		cout<<"Choice 3: Find winner among sequences of 3 players and a Golden Sequence."<<endl;
		cout<<"Choice 4: Exit."<<endl;
		cout<<"Enter your choice (1-4):"<<endl;
		cin>>choice;
		if(choice>=1 && choice<=4)
			break;
		else
			cout<<"Invalid Input. Choices between 1-4."<<endl;
	}
	switch(choice) {
		case 1:
			cout<<"Enter Sequence 1"<<endl;
			cin>>str1;
			cout<<"Enter Sequence 2"<<endl;
			cin>>str2;
			cout<<"Likeness Score: "<<calcLikenessScore(str1, str2)<<endl;
			break;
		case 2:
			cout<<"Enter Sequence 1"<<endl;
			cin>>str1;
			cout<<"Enter Sequence 2"<<endl;
			cin>>str2;
			cout<<"Best Likeness Score: "<<bestLikenessScore(str1, str2)<<endl;
			break;
		case 3:
			cout<<"Enter Sequence of player 1"<<endl;
			cin>>str1;
			cout<<"Enter Sequence of player 2"<<endl;
			cin>>str2;
			cout<<"Enter Sequence of player 3"<<endl;
			cin>>str3;
			cout<<"Enter Golden sequence"<<endl;
			cin>>str4;
			findWinner(str1, str2, str3, str4);
			break;
		case 4:
			cout<<"Exiting."<<endl;
			break;
	}
	return 0;
}
