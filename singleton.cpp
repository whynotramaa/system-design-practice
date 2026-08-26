/*
 Singleton ensures that each class has only one instance and provides a
 common access point through which everyone gets the same instance !
 */

#include "iostream"
using namespace std;


class Logger {
    private:
        static Logger* instance; // we must have an empty instance as well - static ensures class level instance-creation

        Logger(){
            cout << "Logger created \n";
        }

    public:
        static Logger* getInstance(){
            if (instance == nullptr){
                instance = new Logger();
            }

            return instance;
        }
};

Logger* Logger::instance = nullptr;

int main(){
    Logger* l1 = Logger::getInstance();
    Logger* l2 = Logger::getInstance();

    cout << "l1 address: " << l1 <<endl;
    cout << "l2 address: " << l2 <<endl;

    cout << "Are they same ? " << (l1 == l2) << endl;

    return 0;
}
