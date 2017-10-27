//GAME 230 - Project 3 - Poker
//author:Yongtao Chu
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ ,__LINE__)
#define new DBG_NEW
#endif
#endif

int money = 10;
//bool check[5] = { false, false, false, false, false };
void restart_round() {
	money = money - 1;
	cout << "You pay a $1 ante and now have $" << money << endl;
}
void message() {

	cout << "Welcome to Video Poker!" << endl;
	cout << "You have start with $" << money << endl;
	restart_round();
	cout << "Your hand contains :" << endl;
	

}
void check_money() {
	if (money == 0) {
		cout << "GAME OVER!" << endl;
		exit(0);
	}
}

struct card {
	int faces;
	int suits;
};

struct node
{
	card c;
	node* next;
};

struct linked_list
{
	node* head;
};



linked_list* create_linked_list()
{
	linked_list* list = new linked_list;
	list->head = nullptr;
	return list;
}



void add_first(linked_list* list, card c)
{
	node* n = new node;
	n->c = c;
	n->next = list->head;
	list->head = n;
}

void add_last(linked_list* list, card c)
{
	if (list->head == nullptr)
	{
		add_first(list, c);
		return;
	}

	node* temp = list->head;
	while (temp->next != nullptr)
		temp = temp->next;
		
	node* n = new node;
	n->c = c;
	n->next = nullptr;
	temp->next = n;
}

void print_items(linked_list* list)
{
	node* n = list->head;
	while (n != nullptr)
	{
		cout << n->c.faces<<"of"<< n->c.suits << endl;
		n = n->next;
	}
}
int count_items(linked_list* list)
{
	int count = 0;
	node* n = list->head;
	while (n != NULL)
	{
		++count;
		n = n->next;
	}
	return count;
}

card get_item(linked_list* list, int index)
{
	node* n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	//cout << n->c.faces << "of" << n->c.suits << endl;
	//return n->c.faces;
	//return n -> c.suits;
	return n->c;
	
}

void remove_first(linked_list* list)
{
	if (list->head == nullptr)
	{
		cout << "Error!" << endl;
		return;
	}

	node* n = list->head;
	list->head = n->next;
	delete n;
}

void remove_item(linked_list* list, int index)
{
	if (index == 0)
	{
		remove_first(list);
		return;
	}

	node* temp = list->head;
	while (index > 1)
	{
		temp = temp->next;
		--index;
	}

	node* n = temp->next;
	temp->next = n->next;
	delete n;
}

void del_linked_list(linked_list* list)
{
	node* n = list->head;
	while (n != nullptr)
	{
		node* temp = n;
		n = n->next;
		delete temp;
	}

	delete list;
}



linked_list*list = create_linked_list();
linked_list*hand = create_linked_list();
//linked_list*temp = create_linked_list();
//card hand[5];
card c;
card temp;
//card hand;
void create_poker() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			c.faces = i;
			c.suits = j;
			add_first(list, c);
		}
	}
}
int num = 0;

void print_card(card c) {
	switch (c.faces) {
	case 0:
		cout << "Ace";
		break;
	case 10:
		cout << "Jack";
		break;
	case 11:
		cout << "Queen";
		break;
	case 12:
		cout << "King";
		break;
	case 13:
		cout << "Ace";
	default:
		cout << (c.faces + 1);
		break;
	}
	switch (c.suits) {
	case 0:
		cout << " of Clubs" << endl;
		break;

	case 1:
		cout << " of Diamond" << endl;
		break;

	case 2:
		cout << " of Hearts" << endl;
		break;

	case 3:
		cout << " of Spades" << endl;
		break;
	default:
		break;
	}
	//cout << c.faces << c.suits << endl;
	
}
void print_hand() {
	
		cout << "A:"; print_card(get_item(hand, 0));
		cout << "B:"; print_card(get_item(hand, 1));
		cout << "C:"; print_card(get_item(hand, 2));
		cout << "D:"; print_card(get_item(hand, 3));
		cout << "E:"; print_card(get_item(hand, 4));

}
void print_list() {
	for (int i = 0; i < count_items(list); i++) {
		print_card(get_item(list, i));
	}
}
	

void draw_card() {
	int index = count_items(list);
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		//if (check[i] == false) {

			int in = rand() % (index - i);
			//get_item(list, in);
			add_first(hand, get_item(list, in));
			remove_item(list, in);
			//print_items(hand);

			//num++;

			//}
		//}
	}
}

void hand_card() {
	
	//print_items(hand);
	cout << endl;
	cout << "The deck contains " << count_items(list) << " cards " << endl;
	cout << endl;
}

char letter;
int value;
char suit;

void check_letter() {
	switch (letter) {

	case 'a':
			temp = get_item(hand, 0);
			add_first(list,temp);
			remove_item(hand, 0);
			break;
	case 'b':
		temp = get_item(hand, 1);
		add_first(list, temp);
		remove_item(hand, 1);
		break;
	case 'c':
		temp = get_item(hand, 2);
		add_first(list, temp);
		remove_item(hand, 2);
		break;
	case 'd':
		temp = get_item(hand, 3);
		add_first(list, temp);
		remove_item(hand, 3);
		break;
	case 'e':
		temp = get_item(hand, 4);
		add_first(list, temp);
		remove_item(hand, 4);
		break;

	default:
		cout << "Invalid hand card!" << endl;
		break;
		break;
	}
}

void check_value() {

	if (value >= 1 && value <= 14) {
		temp.faces = value - 1;
	}
	else if (value == 14){
		temp.faces = 0;
	}
	else cout << "Invalid card value!" << endl;
	//exit(0);
}

void check_suit() {
	if (suit == 'c') {
		temp.suits = 0;
	}
	else if (suit == 'd') {
		temp.suits = 1;
	}
	else if (suit == 'h') {
		temp.suits = 2;
	}
	else if (suit == 's') {
		temp.suits = 3;
	}
	else cout << "Invalid hand suit!" << endl;
	//exit(0);
}

void swap() {

	cout << "Enter the letter of the card in hand:";
	cin >> letter;
	check_letter();
	cout << "Enter the value of the card in the deck to swap with:";
	cin >> value;
	check_value();
	cout << "Enter the suit (c,d,h,s) of the card in the deck to swap with:";
	cin >> suit;
	check_suit();
	
	remove_item(list,(52 - ((temp.faces + 1)  * (temp.suits + 1))));
	add_last(hand,temp);

}
int check[15] = {0};
int checksuit[5] = {0};
int counter;
int check_same_suit(int y) {
	//int counter = 0;
	//int y;
	//cin >> y;
	for (int i = 0; i < 5; i++) {
		if (get_item(hand, i).suits == (y)) {
			counter++;
		}
	}
//return 0;
	//counter = 0;
	return counter;
	//counter = NULL;
	//cout << coux = nter << endl;
}
int check_same_face(int x) {
	
	for (int i = 0; i < 5; i++) {
		if (get_item(hand, i).faces == (x)) {
			counter++;
		}
	}
	return counter;

}
int pairs;

bool fourofakind;
bool threeofakind;
bool twopair;
bool onepair;
bool flus;
void poker_hand_suit() {

	for (int x = 0; x < 5; x++) {
		checksuit[(get_item(hand, x).suits)]++;
	}
	for (int i = 0; i < 4; i++) {
		//counter = 0;
		//check_same_suit(i);
		if (checksuit[i] == 5) {
			flus = true;
			//pokerfacecheck = true;
			cout << "You get a Flush and earned $6!" << endl;
			money = money + 6;
			//cout << "now you have $" << money << endl;
		}

		//pokerfacecheck = false;
		//cout << "You don't have poker hand!" << endl;
	//money = money - 1;
	//cout << "now you have $" << money << endl;
	//t << counter << endl;
	}
}
void poker_hand_face() {
	//int counter = 0;
	for (int x = 0; x < 5; x++) {
		check[(get_item(hand, x).faces)] ++;
	}
	for (int j = 0; j < 13; j++) {
		//counter = 0;
		//check_same_face(j);
		//count_pair(counter);
		if (check[j] == 4) {
			//pokerfacecheck = false;
			fourofakind = true;
			threeofakind = false;
			twopair = false;
			onepair = false;
			cout << "You get Four of a Kind and earned $25!" << endl;
			money = money + 25;
			//cout << "now you have $" << money << endl;

			//break;
		}

		else if (check[j] == 3) {
			threeofakind = true;
			twopair = false;
			onepair = false;
			//pokerfacecheck = false;
			cout << "You get Three of a Kind and earned $3!" << endl;
			money = money + 3;
			//cout << "now you have $" << money << endl;

			//;
		}
		else if (check[j] == 2) {
			pairs++;
			if (pairs == 2) {
				twopair = true;
				onepair = false;
				//pokerfacecheck = false;
				cout << "You get two pair and earned $2!" << endl;
				money = money + 2;
				//cout << "now you have $" << money << endl;
				//break;
			}
			else if (pairs == 1) {
				onepair = true;
				twopair = false;
				cout << "You get one pair and earned $1!" << endl;
				money = money + 1;


			}
		}
	}
}
		//else 
			//pokerfacecheck = true;
			//cout << "You don't have poker hand!" << endl;

		//break;

	//cout << counter << endl;

void options() {
	check_money();
	string option;
	cout << "OPTIONS..." << endl;
	cout << "- Type the letters for the cards you wish to delete. (i.e., 'acd')" << endl;
	cout << "- Type 'deck' to view the cards remaining in the deck." << endl;
	cout << "- Type 'none' to discard all cards in your hand." << endl;
	cout << "- Type 'all' to keep all cards in your hand." << endl;
	cout << "- Type 'exit' to exit the game." << endl;
	cout << "- Type 'swap' to CHEAT and swap a card in your hand with one in the deck." << endl;
	cout << "YOUR CHOICE:";
	cin >> option;

	if (option == "exit") {
		cout << "quit the game" << endl;
		system("pause");
		//exit(0);

	}
	else if (option == "none") {
		//linked_list*hand = create_linked_list();
		for (int i = 0; i < 5; i++) {
			remove_first(hand);
		}
		draw_card();
			hand_card();
			poker_hand_face();
			poker_hand_suit();
			//poker_hand_face();
			restart_round();
		
			options();
	}
	else if (option == "all") {
		
		hand_card();
		poker_hand_face();
		poker_hand_suit();
		restart_round();

		options();
	}
	else if (option == "deck") {
		//print_items(list);
		print_list();
		options();
	}
	else if (option == "swap") {
		swap();
		//print_items(hand);
		print_hand();
		poker_hand_face();
		poker_hand_suit();
		restart_round();
		cout << endl;
		
		cout << "The deck contains " << count_items(list) << " cards " << endl;
		//draw_card();
		//hand_card();
		options();
	}
	else if (option != "none" && option != "exit" && option != "all" && option != "deck" && option != "swap") {
		int index = count_items(list);
		srand(time(NULL));
		for (int x = 0; x < option.length(); x++) {
			int in = rand() % (index - x);
			if (option[x] > 96 && option[x] < 102)
			{
				switch (option[x]) {
				case 97:
					check[0] = true;
					/*if (check[0] = false){
					remove_item(hand, 0);
					add_first(hand, get_item(list, in));
					}*/
					remove_item(hand, 0);
					add_first(hand, get_item(list, in));
					break;
				case 98:
					check[1] = true;
					/*if (check[1] = false) {
						remove_item(hand, 1);
						add_first(hand, get_item(list, in));
					}*/
					remove_item(hand, 1);
					add_first(hand, get_item(list, in));
					break;
				case 99:
					check[2] = true;
					/*if (check[2] = false) {
						remove_item(hand, 2);
						add_first(hand, get_item(list, in));
					}*/
					remove_item(hand, 2);
					add_first(hand, get_item(list, in));
					break;
				case 100:
					check[3] = true;
					/*if (check[3] = false) {
						remove_item(hand, 3);
						add_first(hand, get_item(list, in));
					}*/
					remove_item(hand, 3);
					add_first(hand, get_item(list, in));
					break;
				case 101:
					check[4] = true;
					/*if (check[4] = false) {
						remove_item(hand, 4);
						add_first(hand, get_item(list, in));
					}*/
					remove_item(hand, 4);
					add_first(hand, get_item(list, in));
					break;
				default:
					cout << "error! enter correct option" << endl;
					break;
				}
			}
		}
		
		print_hand();
		options();

	}
	
	else cout << "error! enter correct option" << endl; option;
}




//void check_pair() {
//	//d = get_item(hand, a);
//	int pair = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int a = 0; a < 4; a++) {
//			if (a != i) {
//				if ((get_item(hand, a)).faces == (get_item(hand, i + 1)).faces) {
//					pair = pair + 1;
//				}
//			}
//		}
//	}
//	if (pair == 1) {
//		//cout
//	}
//}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	message();
	create_poker();
	draw_card();
	//print_items(hand);
	//print_items(list);
	//hand_card();
	print_hand();
	hand_card();
	//check_same_face();
	//check_same_suit();
	//cout << print_card(get_item(hand, 0)) << endl;
	options();

}
