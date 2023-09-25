#include"Table.h"   

Table::Table()
{
    ID= id++;
    nStatus= FREE;
    cout<<"Table "<<this->GetID()<< " da duoc tao.\n";
}

int Table::GetStatus()
{
    return this->nStatus;
}
int Table::GetID()
{
    return this->ID;
}
void Table::GoiThemMon(MonAn* mon, int soluong)
{

}
void Table::XoaBotMon(MonAn* mon, int soluong)
{

}
void Table::Display()
{

}
void Table::ThanhToan()
{

}

int Table::id = 0;