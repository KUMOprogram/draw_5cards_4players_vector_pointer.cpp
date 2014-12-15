#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int card;

void player_hand(vector <int>& vplayer, vector <int>& deck);
void print_hand(vector <int> vplayer, int* player);
void change_card(vector <int>& vplayer, vector <int>& deck, int* player);

int main()
{
system("color f1");
srand(time(0));

	vector <int> deck(52);
	vector <int> vplayer1;
	vector <int> vplayer2;
	vector <int> vplayer3;
	vector <int> vplayer4;
	
	for (card=0; card<deck.size(); ++card)
	{
		deck[card]=card+1;
	}
	
	//other option to write that, is:
	//vector <int> deck;
	//for (card=0; card<52; ++card)
	//{
	//	deck.push_back(card+1);
	//}
	
	random_shuffle(deck.begin(),deck.end());
	
	player_hand(vplayer1, deck);
	player_hand(vplayer2, deck);
	player_hand(vplayer3, deck);
	player_hand(vplayer4, deck);
	
	cout<<" *** DRAW PHASE #1 ***"<<endl<<endl;
	int player=1;
	print_hand(vplayer1, &player);
	print_hand(vplayer2, &player);
	print_hand(vplayer3, &player);
	print_hand(vplayer4, &player);
	
	system("pause");

    	cout<<" *** CHANGE PHASE ***"<<endl<<endl;
    	player=1;
	change_card(vplayer1, deck, &player);
	change_card(vplayer2, deck, &player);
	change_card(vplayer3, deck, &player);
	change_card(vplayer4, deck, &player);
	
	system("pause");

    	cout<<" *** DRAW PHASE #2 ***"<<endl<<endl;
	player=1;
	print_hand(vplayer1, &player);
	print_hand(vplayer2, &player);
	print_hand(vplayer3, &player);
	print_hand(vplayer4, &player);

system("pause");
}

void player_hand(vector <int>& vplayer, vector <int>& deck)
{
	for (card=0; card<5; ++card)
	{
		vplayer.push_back(deck[deck.size()-1]);
		deck.pop_back();
	}
}

void change_card(vector <int>& vplayer, vector <int>& deck, int* player)
{
	cout<<"player "<<*player<<endl;
	for (card=0; card<5; ++card)
	{
		while(true)
		{
			string chose;
			cout<<"if you want to change card "<<(card+1)<<" press + ( if not press - ): ";
			cin>>chose;
			if (chose=="+")
			{
				vplayer[card]=deck[deck.size()-1];
				deck.pop_back();
				break;
			}else if(chose=="-")
			{
				break;
			}else
			{
				cout<<" ERROR: chose + or -"<<endl;
			}
		}
	}
	*player+=1;
}

void print_hand(vector <int> vplayer, int* player)
{
	cout<<"player "<<*player<<endl;
	for (card=0; card<5; ++card)
	{
			if ((vplayer[card]>=1)&&(vplayer[card]<14))
			{
				if (vplayer[card]==11)
				{
                    			cout<<" K ";
				}else if (vplayer[card]==12)
				{
					cout<<" Q ";
				}else if (vplayer[card]==13)
				{
					cout<<" J ";
				}else if (vplayer[card]==1)
				{
					cout<<" A ";
				}else{
					cout<<" "<<vplayer[card]<<" ";
				}
				cout<<"<3-"<<endl;
			}else if ((vplayer[card]>=14)&&(vplayer[card]<27))
			{
                		if (vplayer[card]==24)
				{
					cout<<" K ";
				}else if (vplayer[card]==25)
				{
					cout<<" Q ";
				}else if (vplayer[card]==26)
				{
					cout<<" J ";
				}else if (vplayer[card]==14)
				{
					cout<<" A ";
				}else{
					cout<<" "<<vplayer[card]-13<<" ";
				}
				cout<<"<3"<<endl;
			}else if ((vplayer[card]>=27)&&(vplayer[card]<40))
			{
                		if (vplayer[card]==37)
				{
					cout<<" K ";
				}else if (vplayer[card]==38)
				{
					cout<<" Q ";
				}else if (vplayer[card]==39)
				{
					cout<<" J ";
				}else if (vplayer[card]==27)
				{
					cout<<" A ";
				}else{
					cout<<" "<<vplayer[card]-26<<" ";
				}
				cout<<"c3-"<<endl;
			}else if (vplayer[card]>=40)
			{
                		if (vplayer[card]==50)
				{
					cout<<" K ";
				}else if (vplayer[card]==51)
				{
					cout<<" Q ";
				}else if (vplayer[card]==52)
				{
					cout<<" J ";
				}else if (vplayer[card]==40)
				{
					cout<<" A ";
				}else{
                    			cout<<" "<<vplayer[card]-39<<" ";
				}
				cout<<"<>"<<endl;
			}
	}
	cout<<endl;
	*player+=1;
}
