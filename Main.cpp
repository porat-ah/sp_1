
#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <array>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define print(x) cout << x << endl

string nospace(string input){
    string out ;
    for (size_t i = 0; i < input.length(); i++)
    {
        char at = input.at(i);
        if(at != '\n' && at != ' ' && at != '\t' && at != '\r'){
            out += at;
        }
    }
    return out;
}

string name_generator(){
	string out ;
	for (size_t i = 0; i < 8; i++)
	{
		int num = (rand()%26+97);
		char c = (char) num;
		out += c;
	}
	return out;
}

string snowman_from_name(string name){
	array<int ,27> map = {1, 3, 4, 4, 1, 1, 3, 2, 3, 1, 3, 4, 4, 3, 2, 3, 2, 2, 2, 4, 4, 4,2, 3, 2, 1, 4};
	int code =0 ;
	int code_len = 0;
	int i =0;
	while (code_len <8)
	{
		++i;
		i %= name.length();
		code *= 10;
		code += map.at(name.at(i)-97);
		++code_len;
	
	}
	return ariel::snowman(code);
}

class snowman{
	private:
	 int weapon_type;
	 int sol_type;
	 int str;
	 string name;
	 string look;

	void printhel(){
		string h;
		for (size_t i = 0; i < hel; i += 20)
		{
			h += '*';
		}
		print("health = "  + h);
	}

	 void printscrean(string action){
			print(" ");
			print(" ");
			print(look);
			print(" ");
			print(name);
			printhel();
			string line;
			for (size_t i = 0; i < 10; i++)
			{
				line += '_';
			}
			print(line);
			print(action);
			print(line);
			print(" ");
		}

	void take_dem(snowman* s , string action ){
		int def =0;
		if (action == " defend")
		{
			if(!sol_type)
				def = 4;
			def += 2;
		}
		int dem = s->str;
		if((s->weapon_type -1) % 3 == weapon_type)
			dem *= 2;
		hel -= dem;
		if(hel <1){
			hel = 0;
			return;
		}
		hel += def;
	}
	string act(){
		string actions[] = {"attack" , "defend"};
		int act;
		print("choose your action : ");
		print("attack : 0  ||  defend : 1 ");
		cin >> act;
		system("clear");
		return actions[act];
	}
	public:
		int hel;
		int counter;
		snowman(int wt,int st){
			sol_type = st;
			switch (st)
			{
			case 0:// tank
				hel = 200;
				str = 5;
				break;
			case 1: // fighter
				hel = 100;
				str = 10;
				break; 
			default:
				hel = 100;
				str = 5;
			}
			weapon_type = wt;
			name = name_generator();
			look = snowman_from_name(name); 
			counter = 0;
		}
		snowman(int wt,int st,string na){
			sol_type = st;
			switch (st)
			{
			case 0:// tank
				hel = 200;
				str = 5;
				break;
			case 1: // fighter
				hel = 100;
				str = 10;
				break;
			}
			weapon_type = wt;
			name = na;
			look = snowman_from_name(name); 
		}

		void fight(snowman* player){
			print("fight start");
			string actions[] = {"attack" , "defend"};
			string action1 , action2;
			while (player->hel && hel)
			{
				
				action1 = player->act();
				int act = 0;
				if(sol_type){
					act = (rand()%3)%2;
				}
				else{
					act = (rand()%3+1)%2;
				}
				action2 = actions[act];
				if (action1 == actions[0])
				{
					take_dem(player,action2);
				}
				if (action2 == actions[0])
				{
					player->take_dem(this,action1);
				}
				player->printscrean(action1);
				printscrean(action2);
			}
			player->counter++;
		}

		void heal(int amount){
			hel += amount;
		}
		void buff(int amount){
			str += amount;
		}	
};

class room{
	int type;
	public:
		int doors;
		room(){
			type = (rand()%4)%3;
			doors = 1 + rand()%3;
		}
		void interacte(snowman* player){
			int wt = rand()%3;
			int st = rand()%2;
			int gift_type = rand()%2;
			int amount = rand()%10;
			snowman s(wt,st);
			switch (type)
			{
			case 1:
				print("you found a gift");
				
				if(gift_type){
					player->heal(amount);
				}
				else{
					player->buff(amount);
				}
				break;
			case 2:
				print("an enemy approaching !");
				s.fight(player);
				break;
			default:
				print("this room is empty");
			}
		}
};

int main() {
	srand(time(0));
	string name;
	cout << "welcome to snowman slayer "<< endl; 
	cout << "here you can create your own snowman "<< endl; 
	cout << "you only need to give it a name we will do the rest "<< endl;
	cout << "if you want to use the name genrator enter : 0 "<< endl;
	cout << "if you want to enter your own name enter : 1 "<< endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 0 :
		name = name_generator();
		//print(name);
		break;
	case 1:
		cout << "enter the snowman name" << endl;
		cin >> name;
		break;
	}
	print("yout name is : " + name);
	print("this is you: " );
	print(snowman_from_name(nospace(name)));
	
	print("now lets build your character : ");
	print(" you can choose from three types of weapons");
	print("0 cav  |  1 sword  |  2 spear");
	print(" cav > sword , sword > spear , spear > cav");
	int wt;
	cin >> wt;

	print(" you can choose from two types of soldier");
	print("0 tank  |  1 fighter ");
	print(" tank has more health but does less damege");
	print(" fighter has less health but does more damege");
	int st;
	cin >> st;
	snowman player(wt,st,name);
	while (true)
	{
		system("clear");
		room r;
		r.interacte(&player);
		if(!player.hel)
			break;
		switch (r.doors)
		{
		case 2:
			print(" you can choose : ");
			print(" go to left : 0 | go to right : 1 ");
			cin >> st;
			break;
		case 3:
			print(" you can choose : ");
			print(" go to left : 0 | go to right : 1 | go forward : 2");
			cin >> st;	
			break;
		}
		print("you walk to the next room");
	}
	print(" ");
	print(" you killed :" << player.counter << " snowmans \n good job ");
	print("thanks for playing");
}
