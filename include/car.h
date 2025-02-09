#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    double dailyRate;
    bool available;

public:
    Car(const std::string& make, const std::string& model, int year, double dailyRate);
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getDailyRate() const;
    bool isAvailable() const;
    void setAvailability(bool available);
};

#endif // CAR_H
