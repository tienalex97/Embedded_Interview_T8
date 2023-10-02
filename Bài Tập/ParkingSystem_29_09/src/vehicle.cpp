#include"vehicle.h"

Vehicle::Vehicle(string bienso, string map_data, VehicleType type)
{
    sBienSo= bienso;
    sMapData= map_data;
    nType= type;
}

string Vehicle::getBienSo()
{
    return this->sBienSo;
}
string Vehicle::getMapData()
{
    return this->sMapData;
}
int Vehicle::getVehicleType()
{
    return nType;
}
void Vehicle::move(int slot)
{

}
void Vehicle::park()
{

}