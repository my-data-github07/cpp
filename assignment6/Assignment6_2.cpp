#include<iostream>
using namespace std;

class employee
{    
     private:
     int id;
     float sal;

     public: 
     employee()
     {
        cout<<"emp constr"<<endl;
        this->id=0;
        this->sal=0;
     }
     employee(int id,float sal)
     {
        this->id=id;
        this->sal=sal;
     }
     void accept()
     {
        cout<<"ID = ";
        cin>>this->id;
        cout<<"Sal = ";
        cin>>this->sal;
     }
     void display()
     {
        cout<<"id is "<<this->id<<endl;
        cout<<"sal is  "<<this->sal<<endl;
     }

}; 

class manager : virtual public  employee
{
     private:
     float bonus;

     public:
     manager()
     {
        cout<<"manager cnst"<<endl;
        this->bonus=0;

     }
     manager(float bonus)
     {
        this->bonus=bonus;
     }

     void accept()
     {
        cout<<"Enter the bonus";
        cin>>this->bonus;

     }
     void display()
     {
        cout<<"display bonus"<<this->bonus<<endl;
    
     }
};
class salesman : virtual public employee
{    
    private:
    float comm;

    public:
     salesman()
     {
        cout<<"slaesman cunst"<<endl;
       this->comm=0;
     }
     salesman(float comm)
     {
       this->comm=comm;

     }

     void accept()
     {
        cout<<" Enter Commission = ";
        cin>>this->comm;
     }

     void display()
     {
        cout<<"commission is = "<<this->comm<<endl;

     }
      
};

class sales_manager : public salesman ,public manager
{    public:
    sales_manager()
    {
        cout<<"const for salesmanager"<<endl;
    }
   void accept()
   {

   }
     void display()
     {
        
     }

};


int main()
{
   sales_manager b;

}