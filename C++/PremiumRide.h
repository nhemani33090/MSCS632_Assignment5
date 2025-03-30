#ifndef PREMIUMRIDE_H
#define PREMIUMRIDE_H

#include "Ride.h"

class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 3.0;
    }

    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Type: Premium, Fare: $" << fare() << endl;
    }
};

#endif
