Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance |

    Ride class >> newWithID: id pickup: pickup dropoff: dropoff distance: dist [
        ^ (self new)
            setID: id pickup: pickup dropoff: dropoff distance: dist;
            yourself
    ]

    setID: id pickup: pickup dropoff: dropoff distance: dist [
        rideID := id.
        pickupLocation := pickup.
        dropoffLocation := dropoff.
        distance := dist.
    ]

    fare [
        self subclassResponsibility
    ]

    rideDetails [
        ('Ride ID: ', rideID printString, ' From: ', pickupLocation, ' To: ', dropoffLocation, ' Distance: ', distance printString, ' miles') displayNl.
    ]
]

Ride subclass: StandardRide [

    fare [
        ^ distance * 1.5
    ]

    rideDetails [
        super rideDetails.
        ('Type: Standard, Fare: $', self fare printString) displayNl.
        '' displayNl.
    ]
]

Ride subclass: PremiumRide [

    fare [
        ^ distance * 3.0
    ]

    rideDetails [
        super rideDetails.
        ('Type: Premium, Fare: $', self fare printString) displayNl.
        '' displayNl.
    ]
]

Object subclass: Driver [
    | driverID name rating assignedRides |

    initializeWith: id name: driverName rating: r [
        driverID := id.
        name := driverName.
        rating := r.
        assignedRides := OrderedCollection new.
    ]

    addRide: aRide [
        assignedRides add: aRide.
    ]

    getDriverInfo [
        ('Driver ID: ', driverID printString, ', Name: ', name, ', Rating: 4.9') displayNl.
        'Completed Rides:' displayNl.
        assignedRides do: [:ride | ride rideDetails].
    ]
]

Object subclass: Rider [
    | riderID name requestedRides |

    initializeWith: id name: riderName [
        riderID := id.
        name := riderName.
        requestedRides := OrderedCollection new.
    ]

    requestRide: aRide [
        requestedRides add: aRide.
    ]

    viewRides [
        ('Rider ID: ', riderID printString, ', Name: ', name) displayNl.
        'Requested Rides:' displayNl.
        requestedRides do: [:ride | ride rideDetails].
    ]
]

r1 := StandardRide newWithID: 1 pickup: 'Home' dropoff: 'Mall' distance: 10.
r2 := PremiumRide newWithID: 2 pickup: 'Office' dropoff: 'Airport' distance: 15.

rider1 := Rider new.
rider1 initializeWith: 101 name: 'Alice'.
rider1 requestRide: r1.
rider1 requestRide: r2.

driver1 := Driver new.
driver1 initializeWith: 201 name: 'Bob' rating: 4.9.
driver1 addRide: r1.
driver1 addRide: r2.

'--- All Rides (Polymorphism Demo) ---' displayNl.
{r1. r2} do: [:ride |
    ride rideDetails.
    ('Fare: $', ride fare printString) displayNl.
    '' displayNl
].

'--- Rider Info ---' displayNl.
rider1 viewRides.

'--- Driver Info ---' displayNl.
driver1 getDriverInfo.
