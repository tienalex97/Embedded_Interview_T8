#pragma once
#include<iostream>
#include"vehicle.h"
using namespace std;

class ParkingSlot
{
    private:
        int nID;
        static int id;
        bool bOccupied;
        VehicleType nType;
        Vehicle* parking_vehicle;
    public:
        ParkingSlot(VehicleType type);
        int getSlotID();
        bool getSlotStatus();
        void updateSlotStatus();
        Vehicle* getParkingVehicle();
        void setParkingVehicle(Vehicle* vehicle);
        VehicleType getSlotType();

};