#include<iostream>
#include<list>
#include<vector>

#include"parking_lot.h"
#include"vehicle.h"


using namespace std;

void DisplayParkingSystem(const vector<ParkingSlot*> vec_slot)
{
    cout<<"ID"<<"\t";
    for(auto &v: vec_slot)
    {
        cout<<v->getSlotID()<<"\t";
    }
    cout<<endl;
    cout<<"Stt"<<"\t";
    for(auto &v: vec_slot)
    {
        v->getSlotStatus() ? cout<<"V"<<"\t" : cout<<"X"<<"\t";
    } 
    cout<<endl;
}

bool bIsSystemFull(const vector<ParkingSlot*> vec_slot)
{
    int check=0;
    for(auto &v: vec_slot)
    {
        if(v->getSlotStatus()== false) check++;
    }
    return (check==0);
}
int FindOptimizeSlot(vector<ParkingSlot*> &vec_slot, Vehicle* &vehicle)
{
    cout<<"Finding the best position for parking\n";
    int ID;
    for(auto &v: vec_slot)
    {
        if(v->getSlotStatus()== false && v->getSlotType() == vehicle->getVehicleType())
        {
            ID= v->getSlotID();
            break;
        }
    }
    return ID;

}
void Park(vector<ParkingSlot*> &vec_slot, Vehicle* &vehicle)
{
    int ID= FindOptimizeSlot(vec_slot, vehicle);
    for(auto& v: vec_slot)
    {
        if(v->getSlotID()==ID)
        {
            v->setParkingVehicle(vehicle);
            v->updateSlotStatus();
            cout<<"Park successfully!\n";
        }
    }
}
int main()
{
    vector<ParkingSlot*> vecSlots;
    int input;


    // Create 10 slots for parking system
    for(int i=0; i<5; i++)
    {
        ParkingSlot* slot= new ParkingSlot(CAR);
        vecSlots.push_back(slot);
    }
    for(int i=0; i<5; i++)
    {
        ParkingSlot* slot = new ParkingSlot(MOTORBIKE);
        vecSlots.push_back(slot);
    }
    
    
    
    DisplayParkingSystem(vecSlots);
    if(bIsSystemFull(vecSlots)) cout<<"The system is full! Try again\n";
    
    cout<<"Input the vehilce_______________ "<<endl;
    string bienso;
    string map_data;
    int int_type;
    VehicleType type;
    cout<<"Input bienso: "; cin>>bienso;
    cout<<"Input mapdata: "; cin>>map_data;
    cout<<"Type of vehicle: "; cin>>int_type;
    if(int_type==0) type =CAR;
    else if(int_type==1) type = MOTORBIKE;

    Vehicle* new_vehicle= new Vehicle(bienso, map_data, type);
    Park(vecSlots, new_vehicle);

    DisplayParkingSystem(vecSlots);
    return 0;
}
