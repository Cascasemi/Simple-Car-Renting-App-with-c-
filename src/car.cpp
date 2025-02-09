#include "car.h"

Car::Car(const std::string& make, const std::string& model, int year, double dailyRate)
    : make(make), model(model), year(year), dailyRate(dailyRate), available(true) {}

std::string Car::getMake() const {
    return make;
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getDailyRate() const {
    return dailyRate;
}

bool Car::isAvailable() const {
    return available;
}

void Car::setAvailability(bool available) {
    this->available = available;
}
