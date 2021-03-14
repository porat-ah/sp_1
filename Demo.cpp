
#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <array>
#include <stdlib.h>
using namespace std;
#define print(x) cout << x << endl

string name_generator(){
	string out ;
	for (size_t i = 0; i < 8; i++)
	{
		int num = (rand()%27+97);
		char c = (char) num;
		out += c;
	}
	return out;
}
int main() {
	
	array<int ,27> map = {1, 3, 4, 4, 1, 1, 3, 2, 3, 1, 3, 4, 4, 3, 2, 3, 2, 2, 2, 4, 4, 4,2, 3, 2, 1, 4};
	string name;
	cout << "welcome to snowman generator "<< endl; 
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
		print(name);
		break;
	case 1:
		cout << "enter the snowman name ( must be 8 letters)" << endl;
		cin >> name;
		break;
	}
	int code =0 ;
	for (size_t i = 0; i < 8; i++)
	{
		code *= 10;
		code += map.at(name.at(i)-97);
	}
	print("this is " + name);
	print("say hello to him");
	print(ariel::snowman(code));
	print(name +"'s id = " + to_string(code));
}
