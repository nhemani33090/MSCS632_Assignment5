#ifndef STANDARDRIDE_H
#define STANDARDRIDE_H

#include "Ride.h"

class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 1.5;
    }

    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Type: Standard, Fare: $" << fare() << endl;
    }
};

#endif
