// Online C++ compiler to run C++ program online
#include <iostream>
#include<list>
#include<vector>
#include<utility>

using namespace std;

// Prototypes

typedef enum{
    FREE,
    ORDER,
    PAY
} TableStatus;

class MonAn
{
    private: 
        int ID;
        float fPrice;
        string sName;
    public:
        MonAn(float price, string name)
        {
            ID= id++;
            fPrice= price;
            sName= name;
        }
        void UpdateMonAn(float price, string name)
        {
            sName= name;
            fPrice= price;
        }
        static int id;
        string GetName()
        {
            return this->sName;
        }
        float GetPrice()
        {
            return this->fPrice;
        }
        int GetID()
        {
            return this->ID;
        }
        
};
int MonAn::id= 100;

list<MonAn*> listMonAn;

class Table
{
    private:
        list<MonAn*> listGoiMon;
        int nStatus;
        int ID;
        int static id;
    public:
        Table()
        {
            ID= id++;
            nStatus= ORDER;
        }
};
int Table::id=0;
    


void DisplayMonAn(MonAn* mon)
{
    cout<<"ID"<<"\t"<<"|"<<"\t"<<"Gia"<<"\t"<<"|"<<"\t"<<"Ten Mon"<<endl;
    cout<<mon->GetID()-100<<"\t"<<"|"<<"\t"<<mon->GetPrice()<<"\t"<<"|"<<"\t"<<mon->GetName()<<endl;
}
void DisplayMenu(list<MonAn*> &list)
{
    cout<<"ID"<<"\t"<<"|"<<"\t"<<"Gia"<<"\t"<<"|"<<"\t"<<"Ten Mon"<<endl;
    for(auto &l : list)
    {
        cout<<l->GetID()-100<<"\t"<<"|"<<"\t"<<l->GetPrice()<<"\t"<<"|"<<"\t"<<l->GetName()<<endl;
    }
}

void ThemMonAn(list<MonAn*> &list)
{
    bool bExit=false;
    while(!bExit)
    {
        cout<<"Moi ban nhap mon an moi:\n";
        cout<<"Nhap exit de quay lai"<<endl;
        cout<<"______________________\n";
        string name;
        if(name=="exit") bExit= true;
        float price;
        cout<<"1. Nhap ten: ";
        cin>>name;
        for(auto &l:list)
        {
            if(l->GetName() == name)
            {
                cout<<"Mon an da ton tai. Vui long thu lai! \n";\
                return ;
            }
        }
        cout<<"2. Nhap gia: ";
        cin>>price;
        MonAn* monMoi= new MonAn(price, name);
        list.push_back(monMoi);
        cout<<"Mon an moi da duoc them vao danh sach."<<endl;
        DisplayMonAn(monMoi);
        cout<<"______________________\n";
        bExit= true;
    }
    
    
}

void SuaThongTin(list<MonAn*> &list)
{
    bool bExit= false;
    while(!bExit)
    {
        cout<<"Xin hay nhap ten mon an ban muon sua:\n";
        cout<<"Nhap exit de quay lai"<<endl;
        cout<<"______________________\n";
        string name;
        if(name=="exit") bExit= true;
        cin>>name;
        for(auto &l: list)
        {
            if(l->GetName()== name)
            {
                
                bool bExist= true;
                string n;
                do
                {
                    cout<<"Ten moi: ";
                    cin>>n;
                    for(auto &k: list)
                    {
                        if(k->GetName() == n && k->GetID()!= l->GetID())
                        {
                            cout<<"Ohh, ten mon an nay da ton tai trong menu. Vui long thu lai.\n";
                            cout<<"__________________________"<<endl;
                            bExist= true;
                        }
                        else bExist= false;
                    }
                } while(bExist);
                
                cout<<"Gia moi: ";
                float price;
                cin>>price;
                
                l->UpdateMonAn(price, n);
                cout<<"Mon an da duoc thay doi thong tin thanh cong!"<<endl;
                DisplayMonAn(l);
                
                bExit= true;
            }
            else 
            {
                cout<<"Ohh, khong tim thay ten mon an nay!! Xin vui long thu lai! "<<endl;
                cout<<"Nhap 0 de quay lai. "<<endl;
                int n;
                cin>>n;
                if(n==0) bExit= true;
            }
        }
    }
     cout<<"______________________\n";
}

void XoaMonKhoiMenu(list<MonAn*> &listMenu)
{   
    bool bExit= false;
    while(!bExit)
    {
        cout<<"Xin hay nhap ten mon an ban muon xoa:\n";
        cout<<"Nhap exit de quay lai"<<endl;
        cout<<"______________________\n";
        string name;
        cin>>name;
        if(name=="exit") bExit= true;
        list<MonAn*>::iterator it;
        for(it= listMenu.begin(); it!=listMenu.end(); ++it )
        {
            if((*it)->GetName()==name)
            {
                string confirm;
                cout<<"Ban co chac chan muon xoa mon an nay? y/n"<<endl;
                cin>>confirm;
                if(confirm=="y")
                {
                    listMenu.erase(it);
                    cout<<"Mon an '"<<name<<"' da duoc xoa khoi menu thanh cong!"<<endl;
                    bExit= true;
                }
                else cout<<"Mon an nay chua duoc xoa! "<<endl;
                
            }
            else
            {
                cout<<"Khong tim thay mon an. Vui long thu lai! "<<endl;
            }
        }
    
    }
     cout<<"______________________\n";
}
int main() {
    // Write C++ code here
    MonAn* mon1= new MonAn(90, "com");
    MonAn* mon2= new MonAn(100, "pho");
    listMonAn.push_back(mon1);
    listMonAn.push_back(mon2);
    
    while(1)
    {
        int input;
       
        cout<<"----------------------------"<<endl;
        cout<<"\t"<<"1. Manager"<<endl;
        cout<<"\t"<<"2. Staff"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Xin moi nhap lua chon: ";
        
        cin>>input;
        if(input==1)
        {
            cout<<"\t"<<"MANAGER"<<endl;
            cout<<"____________________"<<endl;
            cout<<"1. Set so ban.\n";
            cout<<"2. Them mon va menu. \n";
            cout<<"3. Sua thong tin mon. \n";
            cout<<"4. Xoa mon khoi menu. \n";
            cout<<"5. Danh sach mon. \n";
            cout<<"0. To get back to main menu.\n";
            cout<<"____________________"<<endl;

            bool bExit= false;
            while(!bExit)
            {
                 
                int n;
                cout<<"\t"<<"MANAGER"<<endl;
                cout<<"Xin moi nhap lua chon: ";
                cin>> n;

                switch (n)
                {
                case 0:
                    bExit= true;    
                    break;
                case 1:

                    break;
                case 2:
                    ThemMonAn(listMonAn);
                    break;
                case 3:
                    SuaThongTin(listMonAn);
                    break;
                case 4:
                    XoaMonKhoiMenu(listMonAn);
                    break;
                case 5:
                    DisplayMenu(listMonAn);
                    break;
                default:
                    break;
            }
        
            }
            
        }
        else if(input ==2)
        {
            cout<<"\t"<<"STAFF"<<endl;
            cout<<"____________________"<<endl;
            // in danh sach ban
            // nhap so ban
            cout<<"____________________"<<endl;
            switch(soban)
            {
                case 1:
                    cout<<"\t"<<"STAFF"<<endl;
                    cout<<"____________________"<<endl;
                    cout<<"\t"<<"BAN 1"<<endl;
                     cout<<"____________________"<<endl;
                    cout<<"1. Them mon. \n";
                    cout<<"2. Xoa mon \n";
                    cout<<"3. Danh sach cac mon da order. \n";
                    cout<<"4. Thanh toan. \n";
                    cout<<"0. To get back to main menu.\n";
                    cout<<"____________________"<<endl;
            }
        }
        else cout<<"Ban nhap sai roi, vui long thu lai di! "<<endl;
        
        
    }
   

    return 0;
}
