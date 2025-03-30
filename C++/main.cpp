#include <iostream>
#include <vector>
#include <memory>
#include "StandardRide.h"
#include "PremiumRide.h"
#include "Person.h"

using namespace std;

int main() {
    // === DEMONSTRATING INHERITANCE ===
    // StandardRide and PremiumRide inherit from Ride
    shared_ptr<Ride> r1 = make_shared<StandardRide>(1, "Home", "Mall", 10);
    shared_ptr<Ride> r2 = make_shared<PremiumRide>(2, "Office", "Airport", 15);

    // === CREATING DRIVER AND RIDER ===
    Rider rider1(101, "Alice");
    Driver driver1(201, "Bob", 4.9);

    // === ENCAPSULATION: Access rides only through methods ===
    rider1.requestRide(r1);
    rider1.requestRide(r2);

    driver1.addRide(r1);
    driver1.addRide(r2);

    // === POLYMORPHISM: Different ride types in a single collection ===
    vector<shared_ptr<Ride>> rideList = {r1, r2};

    cout << "\n--- All Rides (Polymorphism Demo) ---\n";
    for (const auto& ride : rideList) {
        // Virtual methods called on base class pointers
        ride->rideDetails();
        cout << "Fare: $" << ride->fare() << "\n\n";
    }

    cout << "\n--- Rider Info ---\n";
    rider1.viewRides();

    cout << "\n--- Driver Info ---\n";
    driver1.getDriverInfo();

    return 0;
}
