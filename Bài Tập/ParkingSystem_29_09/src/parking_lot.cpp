#include"parking_lot.h"

ParkingSlot::ParkingSlot(VehicleType type)
{
    this->nType= type;
    bOccupied= false;
    nID= id++;
    parking_vehicle= nullptr;
}
int ParkingSlot::id= 0;
int ParkingSlot::getSlotID()
{
    return this->nID;
}
bool ParkingSlot::getSlotStatus()
{
    return this->bOccupied;
}
void ParkingSlot::updateSlotStatus()
{
    this->bOccupied = !this->bOccupied;
}
void ParkingSlot::setParkingVehicle(Vehicle* vehicle)
{
    this->parking_vehicle= vehicle;
}
Vehicle* ParkingSlot::getParkingVehicle()
{
    return this->parking_vehicle;
} 
VehicleType ParkingSlot::getSlotType()
{
    return this->nType;
}