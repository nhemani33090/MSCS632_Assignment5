#ifndef PERSON_H
#define PERSON_H

#include "Ride.h"
#include <vector>
#include <memory>

class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<shared_ptr<Ride>> assignedRides;

public:
    Driver(int id, string driverName, double rate)
        : driverID(id), name(driverName), rating(rate) {}

    void addRide(shared_ptr<Ride> ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() const {
        cout << "Driver ID: " << driverID << ", Name: " << name << ", Rating: " << rating << endl;
        cout << "Completed Rides:\n";
        for (const auto& ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

class Rider {
private:
    int riderID;
    string name;
    vector<shared_ptr<Ride>> requestedRides;

public:
    Rider(int id, string riderName)
        : riderID(id), name(riderName) {}

    void requestRide(shared_ptr<Ride> ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        cout << "Rider ID: " << riderID << ", Name: " << name << endl;
        cout << "Requested Rides:\n";
        for (const auto& ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

#endif
