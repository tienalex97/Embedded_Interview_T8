#include"Table.h"   

typedef enum{
    FREE,
    ORDER,
    PAY
} TableStatus;

Table::Table()
{
    ID= id++;
    nStatus= 0;
    cout<<"Table "<<this->GetID()<< " da duoc tao.\n";
}

int Table::GetStatus()
{
    return Table::nStatus;
}
void Table::SetStatus(int n)
{
    Table::nStatus= n;
}
int Table::GetID()
{
    return Table::ID;
}
void Table::GoiThemMon(MonAn* mon, int soluong)
{
    listGoiMon.push_back(make_pair(mon, soluong));
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