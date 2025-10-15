#include <iostream>
#include "utils/Hero.hpp" // this is custom include header file

using namespace std;

int main(){
    // implement your code to test the functional of Hero class here ..
    Hero Sekiro("Sekiro",0,0,20,"Katana");
    string name = Sekiro.getName();
    int health = Sekiro.getHealth();
    int power = Sekiro.getPower();
    int armor = Sekiro.getArmor();

    
    Hero Sekiro1(name,health,armor,power,"Katana");
    Sekiro1.info();
    Sekiro.strike(Sekiro1);
    Sekiro1.info();
    return 0;
}
