#ifndef RIDE_H
#define RIDE_H

#include <iostream>
#include <string>
using namespace std;

class Ride {
protected:
    int rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(int id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    virtual double fare() const = 0; // Pure virtual function
    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << ", From: " << pickupLocation
             << " To: " << dropoffLocation << ", Distance: " << distance << " miles\n";
    }

    virtual ~Ride() {}
};

#endif
