#ifndef CODE_CAR_H
#define CODE_CAR_H

class Car{
public:
    static void beep();
    void drive();
    std::string destination = "school";
    int speed = 50;
};

#endif //CODE_CAR_H
