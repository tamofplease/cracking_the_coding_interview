#include <iostream>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class animal {
    protected: 
        int val;
    public:
        int id;
        animal(int val) : val(val), id(-1) {};

        virtual string call() const {
            return "";
        }
};

class cat : public animal {
    public:
        cat(int val) : animal(val) {};

        string call() const override {
            return "cat";
        }
};

class dog : public animal {
    public:
        dog(int val) : animal(val) {};

        string call() const override {
            return "dog";
        }
};


class pet_shop_queue {
    private:
        queue<dog> dog_queue;
        queue<cat> cat_queue;
        int animal_number = 0;

    public:
        void enqueue(animal a) {
            a.id = animal_number;
            animal_number++;
            cout << a.call() << endl;
            if(a.call() == "dog") {
                dog *d = (dog *) &a;
                dog_queue.push(*d);
            } else {
                cat *c = (cat *) &a;
                cat_queue.push(*c);
            }
        }

        animal dequeue_any() {
            if(dog_queue.front().id < cat_queue.front().id) {
                animal target = dog_queue.front();
                dog_queue.pop();
                return target;
            } else {
                animal target = cat_queue.front();
                cat_queue.pop();
                return target;
            }
        }

        cat dequeue_cat() {
            cat target =  cat_queue.front();
            cat_queue.pop();
            return target;
        }

        dog dequeue_dog() {
            dog target = dog_queue.front();
            dog_queue.pop();
            return target;
        }
};

int main() {
    pet_shop_queue queue;
    dog d = dog(0);
    dog d1 = dog(1);
    dog d2 = dog(2);
    cat c = cat(0);
    cat c1 = cat(1);
    cat c2 = cat(2);
    queue.enqueue(d);
    queue.enqueue(c);
    queue.enqueue(c2);
    queue.enqueue(d1);
    queue.enqueue(c1);
    queue.enqueue(d2);
    animal a = queue.dequeue_any();
    cout << a.call() << endl;
    return 0;
}