#include<string>
using namespace std;
class Player
{
	private:int age;
		string name;
		string country;
	public:	Player();	
		Player(int ,string ,string );
		void Accept();
		void Display();
		static void Sort(Player *,int);		
};
