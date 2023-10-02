#pragma once
#include<iostream>


using namespace std;

typedef enum{
    MOTORBIKE,
    CAR
} VehicleType;

class Vehicle
{
    private:
        string sBienSo;
        string sMapData;
        VehicleType nType;
    public:
        Vehicle(string bienso, string map_data, VehicleType type);
        string getBienSo();
        string getMapData();
        int getVehicleType();
        void move(int slot);
        void park();
        

};