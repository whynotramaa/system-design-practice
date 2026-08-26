#include "iostream"
using namespace std;

class Enemy {
    public:
        virtual void attack() = 0;
        virtual ~Enemy() = default;
};

class Zombie : public Enemy {
    public:
    void attack() override {
        cout << "ZOMBIE ATTACK----------- \n";
    }
};
class Goblin : public Enemy {
    public:
    void attack() override {
        cout << "Goblin ATTACK----------- \n";
    }
};


class Game {
    public:
        virtual Enemy* createEnemy() = 0;
        virtual ~Game() = default;

        void start(){
            Enemy* enemy = createEnemy();

            enemy -> attack();

            delete enemy;
        }
};

class ZombieGame : public Game {
    public:
        Enemy* createEnemy() override{
            return new Zombie;
        }
};
class GoblinGame : public Game {
    public:
        Enemy* createEnemy() override{
            return new Goblin;
        }
};


int main () {
    Game* game = new ZombieGame();
    game -> start();
    delete game;

    game = new GoblinGame();
    game -> start();
    delete game;

    return 0;
}
