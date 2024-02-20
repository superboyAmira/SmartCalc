#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observer.h"

class Observable {
public:
    void addObserver(Observer *observer) {
        observers_.push_back(observer);
    }
    void notifyUpdate() {
        int size = observers_.size();
        for (int i = 0; i < size; i++) {
            observers_[i]->update();
        }
    }
private:
    std::vector<Observer*> observers_;
};

#endif // OBSERVABLE_H
