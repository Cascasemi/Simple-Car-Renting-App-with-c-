#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "car.h"

// Function to display a loading screen
void showLoadingScreen() {
    std::cout << "Loading...";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\n\n";
}

// Function to simulate a login screen
bool performLogin() {
    std::string username, password;
    std::cout << "Welcome to Car Rental Shop\n";
    std::cout << "Please log in to continue.\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    return (username == "admin" && password == "admin1");
}

// Function to display available cars
void displayAvailableCars(const std::vector<Car>& cars) {
    std::cout << "Available Cars:\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].isAvailable()) {
            std::cout << i << ". " << cars[i].getMake() << " " << cars[i].getModel() << " (" << cars[i].getYear() << ")\n";
        }
    }
    std::cout << std::endl;
}

// Function to display rented cars
void displayRentedCars(const std::vector<Car>& cars) {
    std::cout << "Rented Cars:\n";
    for (size_t i = 0; i < cars.size(); ++i) {
        if (!cars[i].isAvailable()) {
            std::cout << i << ". " << cars[i].getMake() << " " << cars[i].getModel() << " (" << cars[i].getYear() << ")\n";
        }
    }
    std::cout << std::endl;
}

// Function to calculate rental price based on hours
double calculateRentalPrice(double dailyRate, int hours) {
    return dailyRate * (hours / 24.0);
}

int main() {
    showLoadingScreen();

    if (!performLogin()) {
        std::cout << "Login failed. Exiting the program.\n";
        return 0;
    }

    std::vector<Car> cars;
    cars.push_back(Car("Toyota", "Corolla", 2020, 50.0));
    cars.push_back(Car("Honda", "Civic", 2021, 55.0));
    cars.push_back(Car("Ford", "Fiesta", 2019, 45.0));

    std::cout << "Welcome, Admin!\n";

    while (true) {
        int choice;
        std::cout << "Select an option:\n";
        std::cout << "1. Rent a Car\n";
        std::cout << "2. Add a Car to the Fleet\n";
        std::cout << "3. View Available Cars\n";
        std::cout << "4. View Rented Cars\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            displayAvailableCars(cars);
            int carIndex;
            std::cout << "Enter the index of the car you want to rent: ";
            std::cin >> carIndex;

            if (carIndex >= 0 && carIndex < cars.size()) {
                if (cars[carIndex].isAvailable()) {
                    std::string renterName;
                    std::string telephoneNumber;
                    std::string nationalId;
                    int rentalHours;

                    std::cout << "Enter Renter's Name: ";
                    std::cin.ignore(); // To clear the newline character left in the input stream
                    std::getline(std::cin, renterName);

                    std::cout << "Enter Telephone Number: ";
                    std::getline(std::cin, telephoneNumber);

                    std::cout << "Enter National ID Number: ";
                    std::getline(std::cin, nationalId);

                    std::cout << "Enter Rental Duration (in hours): ";
                    std::cin >> rentalHours;

                    double rentalPrice = calculateRentalPrice(cars[carIndex].getDailyRate(), rentalHours);

                    // Rent the car and set its availability to false
                    cars[carIndex].setAvailability(false);

                    std::cout << "\nThank you, " << renterName << "! You have rented the "
                              << cars[carIndex].getMake() << " " << cars[carIndex].getModel()
                              << " (" << cars[carIndex].getYear() << ") for " << rentalHours << " hours.\n";
                    std::cout << "Your rental cost will be: $" << rentalPrice << "\n\n";
                } else {
                    std::cout << "Sorry, the selected car is not available for rent.\n\n";
                }
            } else {
                std::cout << "Invalid car index. Please try again.\n\n";
            }
        } else if (choice == 2) {
            std::string make, model;
            int year;
            double dailyRate;

            std::cout << "Enter Car Make: ";
            std::cin.ignore();
            std::getline(std::cin, make);

            std::cout << "Enter Car Model: ";
            std::getline(std::cin, model);

            std::cout << "Enter Car Year: ";
            std::cin >> year;

            std::cout << "Enter Daily Rental Rate: ";
            std::cin >> dailyRate;

            cars.push_back(Car(make, model, year, dailyRate));
            std::cout << "Car added to the fleet successfully.\n\n";
        } else if (choice == 3) {
            displayAvailableCars(cars);
        } else if (choice == 4) {
            displayRentedCars(cars);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n\n";
        }
    }

    return 0;
}
