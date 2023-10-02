#include<iostream>
using namespace std;
 //date class
class date {
   private:
   int day;
   int month;
   int year;

   public:
   date()
   {
      this->day=0;
      this->month=0;
      this->year=0;
   }
   date(int day,int month,int year)
   {
       this->day=day;
       this->month=month;
       this->year=year;
   }

   
   
   void accept()
   { 
      cout<<"Enter the day =";
      cin>>this->day;
      cout<<"Enter the month =";
      cin>>this->month;
      cout<<"Enter the year =";
      cin>>this->year;

   }

   void display()
   {
    cout<<"*****************************"<<endl;
    cout<<"Date is ="<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
    if(isleepyear())
    {
      cout<<"Year is leap year"<<endl;
    }
    else
    {
      cout<<"Year is not leap year"<<endl;
    }
    cout<<"******************************"<<endl;
   }  
    bool isleepyear()
      {
         if(this->year%400==0)
         {
            if(this->year%4==0)
            {
               return true;
            }
            else
            {
               return false;
            }
         }
         else
         {
            return false;
         }
      }

      void set_day(int day)
      {
         this->day=day;
      }
      void set_month(int month)
      {
         this->month=month;
      }
      void set_year(int year)
      {
         this->year=year;
      }

      int get_day()
      {
         return this->day;
      }
      int get_month()
      {
         return this->month;
      }
      int get_year()
      {
         return this->year;
      }
};
  // employee class
 class employee{
   private:
   int id;
   int sal;
   string dept;
   date obj;


   public:

   employee()
   {
      this->dept="";
      this->id=0;
      this->sal=0;
   }
   employee(int id,int sal,string dept,int day ,int month,int year):obj(day,month,year)
    {
      this->id=id;
      this->dept=dept;
      this->sal=sal;
      
    }

    void acceptemp()
    {
      cout<<"--------------------"<<endl;
      cout<<"Enter The id =";
      cin>>this->id;
      cout<<"Enter the dept =";
      cin>>this->dept;
      cout<<"Enter the sal =";
      cin>>this->sal;
      obj.accept();
      cout<<"--------------------"<<endl;
    }
    void display()
    {
      cout<<"************************"<<endl;
      cout<<"id is = "<<this->id<<endl;
      cout<<"Dept is ="<<this->dept<<endl;
      cout<<"Sal is ="<<this->sal<<endl;
      obj.display();
      cout<<"************************"<<endl;
    }
    int  get_id()
    {
       return this->id;
    }
    int get_sal()
    {
      return this->sal;
    }
    string get_dept()
    {
      return this->dept;
    }
    void set_id(int id)
    {
      this->id=id;
    }
    void set_sal(int sal)
    {
       this->sal=sal;
    }
    void set_dept(string dept)
    {
      this->dept=dept;
    }
    date get_joing_date()
    {
       return obj;
    }
    void set_joing_date()
    {
      this->obj.accept();
    }

 };
  //people class
  class person{
      private:
      string name;
      string addr;
      date dob;

      public:
      person()
      {
         this->name="Mohit";
         this->addr="karad";
         
      }
      person(string name,string addr ,int day, int month ,int year):dob(day,month,year)
      {
         this->name=name;
         this->addr=addr;

      }
      void acceptPerson()
      {
         cout<<"Enter the name =";
         cin>>name;
         cout<<"enter the addres";
         cin>>addr;
         dob.accept();
      }
      void display()
      {   cout<<"**********************"<<endl;
         cout<<"Name is = "<<this->name<<endl;
         cout<<"Address is = "<<this->addr<<endl;
         dob.display();
         cout<<"************************"<<endl;
         
      }

     void set_name(string name)
     {
      this->name=name;
     }
     void set_addr(string addr)
     {
      this->addr=addr;
     }
     string get_name()
     {
      return this->name;
     }
     string get_addr()
     {
      return this->addr;
     }
     date get_birth_date()
     {
       return dob;
     }
     void get_birth_date(date dob)
     {
      this->dob.accept();
     }
  };
int main()
{
   date d;
   d.accept();
   d.display();
   employee e;
   e.acceptemp();
   e.display();
   person p;
   p.acceptPerson();
   p.display();

}