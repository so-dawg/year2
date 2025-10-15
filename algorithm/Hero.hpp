#include <iostream>
#include <string>

using namespace std;

class Hero{

    private:
        // Define all the attributes here...
      int Hero_health ;
      string name;
      int armor;
      int power;
      string weapon;
        
    public:
        // Define the constructor and methods here ...
        Hero(string name, int health, int armor, int power, string weapon){
            // assign each attributes' value from constructor param here...
            this->name = name;
            this->Hero_health = health;
            this->armor = armor;
            this->power = power;
            this->weapon = weapon;
        }
    
        void info(){
            // process display hero info here...
            cout << "[--- Hero's info ---]" << "\n";
            cout << "Name: " << this->name << "\n";
            cout << "Health: " << this->Hero_health << "\n";
            cout << "Armor: " << this->armor << "\n";
            cout << "Weapon: " << this->weapon << "\n";
            cout << "Power: " << this->power << "\n";
            cout << "[-------------------]" << "\n";
        }

         void strike(Hero& enemy){
            cout << "*****striking******" << "\n";
            int damage = this->power;
            if (enemy.armor > 0) {
                if (damage > enemy.armor) {
                    damage -= enemy.armor;
                    enemy.armor = 0;
                } else {
                    enemy.armor -= damage;
                    damage = 0;
                }
            }
            enemy.Hero_health -= damage;
            cout << "Enemy damaged!" << "\n";
        }

         string getName() {
            return this->name;
        }

        // getter methods
        int getHealth() {
            return this->Hero_health;
        }

        int getArmor() {
            return this->armor;
        }

        int getPower() {
            return this->power;
        }
};
