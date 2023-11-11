#include<stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class WeaponBehavior{
	protected:
		string Names;
	public:
	WeaponBehavior()
	{
	}
	 void virtual useWeapon() {
	 };
	string virtual Name()
	{
		return this->Names;
	}	
};

class character {
	protected:
		WeaponBehavior* Weapon;
		string Name;
		string Chara;
		
	public:
		character(string name, WeaponBehavior* we)
		{
			Name = name;
			Weapon = we;
	}
		virtual void fight(){
		} 
};

class knifeBehaver :public  WeaponBehavior{
	public :
	 knifeBehaver()
		{

		}
		virtual void useWeapon()
		{
			cout << "you use the "<<this->Names<<"kill a dog!"<<endl;
			return ;
		}
};
class Queen : public  character{
	public :
		Queen(string name,WeaponBehavior * weapon):character(name,weapon)
		{
			Chara = "Queen" ;
	
			
			
		}
		void setWeapon (WeaponBehavior * weapon)
		{
			Weapon = weapon;
		}
		void fight()
		{
	
			cout<<"name:"<<Name<<endl;
			cout<<"characher:"<<Chara<<endl;
			cout<<"Weapon:"<<Weapon->Name();
			
			Weapon->useWeapon();

			return ;
		}
};
int main() 
{

	WeaponBehavior *knif = new knifeBehaver();

	string na = "yuan";
		character * car = new Queen (na,knif);

	car->fight();

	return 0;
	
}
