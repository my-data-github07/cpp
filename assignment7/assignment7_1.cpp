#include<iostream>
using namespace std;


class date{
   int day;
   int month;
   int year;
   public:
   date()
   {
      this->day=0;
      this->year=0;
      this->month=0;
   }
   date(int day,int month,int year)
   {
      this->day=day;
      this->month=month;
      this->year=year;
   }
   // int get_date()
   //  {
   //    return this->day;
   //  }

   //  void set_date(int date)
   //  {
   //    this->day=day;
   //  }
   // int  get_month()
   // {
   //    return this->month;
   // }
   // void set_month(int month)
   // {
   //    this->month=month;
   // }
   // int get_year()
   // {
   //    return this->year;
   // }
   // void get_year(int year)
   // {
   //    this->year;
   // }

    
    void accept()
    {
      cout<<"Enter the day";
      cin>>this->day;
      cout<<"Enter the Month";
      cin>>this->month;
      cout<<"Enter The year";
      cin>>this->year;
    }
   void display()
   {
      cout<<"Date you ennter is = "<<this->day<<":"<<this->month<<":"<<this->year<<endl;
      
   
   }

   bool isleepyear()
   {
      if(this->year%400==0)
      {
         return true;
      }
      else
      if(this->year%4==0)
      {
         return true;
      }
      else
      if(this->year%100==0)
      {
         return false;
      }
      else
      {
         return false;
      }
   }
   
    
};


class person 
{
    string name;
    string addr;
    date dob;

    public:
    person()
    {
      this->name="";
      this->addr="";
       
    }
    person(string name ,string addr,int day,int month,int year):dob(day,month,year)
    {
       this->name=name;
       this->addr=addr;
      
    }


    
   //  string get_name()
   //  {
   //    return this->name;
   //  }
   //  void set_name(string name)
   //  {
   //    this->name=name;
   //  }
   //  string get_addr()
   //  {
   //    return this->addr;
   //  }
   //  void set_addr(string addr)
   //  {
   //    this->addr=addr;

   //  }
   //  date get_date()
   //  {
   //    return dob;
   //  }

   //  void set_date(date dob)
   //  {
   //    this->dob=dob;
   //  }

    void accept()
    {
     cout<<"Enter the name";
     cin>>this->name;
     cout<<"Enter the address =";
     cin>>this->addr;
      dob.accept();
     }
    
    void display()
    {
      cout<<"Name is ="<<this->name<<endl;
      cout<<"addres is ="<<this->addr<<endl;
      dob.display();
    }
};

class employee : public person
{
   int id;
   float sal;
   string dept;
   date join;
   public:
   employee()
   {
      this->id=0;
      this->sal=0;
      this->dept=" ";
    
   }
   employee(int id,int sal,int dept,int day,int month,int year): join(day,month,year)
   {
      this->id=id;
      this->sal=sal;
      this->dept=dept;
     
      }
   //  int get_id()
   //  {
   //    return this->id;
   //  }
   //  void set_id(int id)
   //  {
   //    this->id=id;
   //  }
   //  float get_addr()
   //  {
   //    return this->sal;
   //  }
   //  void set_addr(float sal)
   //  {
   //    this->sal=sal;

   //  }
   // void  set_dept(string dept)
   //   {
   //    this->dept=dept;
   //   }

   

   // string get_dept()
   // {
   //    this->dept=dept;
   // }

   //  date get_date()
   //  {
   //    return join;
   //  }

   //  void set_date(date dob)
   //  {
   //    this->join=join;
   //  }  

   //   date get_date()
   //  {
   //    return join;
   //  }

   //  void set_date(date dob)
   //  {
   //    this->join=dob;
   //  } 

     void display()
     { 
        person::display();
        cout<<"id is "<<this->id<<endl;
        cout<<"sal is "<<this->sal<<endl;
        cout<<"dept ="<<this->dept<<endl;
        join.display();
        
     }
     void accept()
     {
      person::accept();
       cout<<"Enter id ";
       cin>>this->id;
       cout<<"enter sal ";
       cin>>this->sal;
       cout<<"enter dept";
       cin>>this->dept;
       join.accept();
     }
}; 
int main()
{
   
   
   employee e1;
   // e1.accept();
   e1.display();

   
   
}