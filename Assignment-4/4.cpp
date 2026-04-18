#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

//vehicle base class
class Vehicle {
protected:
    char name[50];

public:
    virtual void input() {
        cout << "Enter vehicle name: ";
        cin >> name;
    }

    virtual void displayInfo() {
        cout << "Vehicle: " << name << endl;
    }

    virtual void start() {
        cout << name << " started\n";
    }

    virtual void stop() {
        cout << name << " stopped\n";
    }

    virtual void saveInfo(ofstream &out) = 0;
    virtual void loadInfo(ifstream &in) = 0;

    virtual ~Vehicle() {}
};

//car
class Car : public Vehicle {
    int seats;

public:
    void input() {
        Vehicle::input();
        cout << "Seats: ";
        cin >> seats;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }

    void saveInfo(ofstream &out) {
        out << "Car " << name << " " << seats << endl;
    }

    void loadInfo(ifstream &in) {
        in >> name >> seats;
    }
};

//truck
class Truck : public Vehicle {
    double loadCapacity;

public:
    void input() {
        Vehicle::input();
        cout << "Load Capacity: ";
        cin >> loadCapacity;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Capacity: " << loadCapacity << endl;
    }

    void saveInfo(ofstream &out) {
        out << "Truck " << name << " " << loadCapacity << endl;
    }

    void loadInfo(ifstream &in) {
        in >> name >> loadCapacity;
    }
};

//bus
class Bus : public Vehicle {
    int passengers;

public:
    void input() {
        Vehicle::input();
        cout << "Passengers: ";
        cin >> passengers;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout << "Passengers: " << passengers << endl;
    }

    void saveInfo(ofstream &out) {
        out << "Bus " << name << " " << passengers << endl;
    }

    void loadInfo(ifstream &in) {
        in >> name >> passengers;
    }
};

int main() {
    vector<Vehicle*> fleet;
    int choice;

    do {
        cout << "\n1.Add 2.Display 3.StartAll 4.StopAll 5.Save 6.Load 0.Exit\n";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "1.Car 2.Truck 3.Bus: ";
            cin >> type;

            Vehicle* v;

            if (type == 1) v = new Car();
            else if (type == 2) v = new Truck();
            else v = new Bus();

            v->input();
            fleet.push_back(v);
        }

        else if (choice == 2) {
            for (auto v : fleet) v->displayInfo();
        }

        else if (choice == 3) {
            for (auto v : fleet) v->start();
        }

        else if (choice == 4) {
            for (auto v : fleet) v->stop();
        }

        else if (choice == 5) {
            ofstream out("fleet.txt");
            for (auto v : fleet)
                v->saveInfo(out);
            out.close();
        }

        else if (choice == 6) {
            ifstream in("fleet.txt");
            char type[20];

            while (in >> type) {
                Vehicle* v;

                if (strcmp(type, "Car") == 0) v = new Car();
                else if (strcmp(type, "Truck") == 0) v = new Truck();
                else v = new Bus();

                v->loadInfo(in);
                fleet.push_back(v);
            }
            in.close();
        }

    } while (choice != 0);

    return 0;
}