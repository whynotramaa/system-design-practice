#include <iostream>
#include <string>

using namespace std;

class Pizza {
    public:

        string size;
        bool cheese = false;
        bool pepperoni = false;
        bool sausages = false;

        void showPizza() {

            cout << "Size : " << size << endl;

            cout << "cheese : "
                << (cheese ? "Yes" : "No")
                << endl;

            cout << "pepperoni : "
                << (pepperoni ? "Yes" : "No")
                << endl;

            cout << "saussages : "
                << (sausages ? "Yes" : "No")
                << endl;

        }
};


class PizzaBuilder {
    private:
        Pizza pizza;

    public:
        PizzaBuilder& setSize(string size){
            pizza.size = size;
            return *this;
        }

        PizzaBuilder& addCheese(){
            pizza.cheese = true;
            return *this;
        }

        PizzaBuilder& addPepperoni(){
            pizza.pepperoni = true;
            return *this;
        }

        PizzaBuilder& addSausages(){
            pizza.sausages = true;
            return *this;
        }

        Pizza build(){
            return pizza;
        }
};


int main() {

    Pizza pizza = PizzaBuilder().setSize("Large").addPepperoni().addSausages().build();
    pizza.showPizza();

    return 0;

};
