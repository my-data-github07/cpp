#include<iostream>
using namespace std;

class times
{
    private:
    int hr;
    int min;
    int sec;
    public:
    times(){
      
    }
     times(int hr,int min ,int sec)
     { 
          this->hr=hr;
          this->min=min;
          this->sec=sec;
     }
    int get_hr()
    {
        return this->hr;
    }
    int get_min()
    {
        return this->min;
    }
    int get_sec()
    {
        return this->sec;
    }

    void print()
    { 
        cout<<"you enter hr mins and sec =";
    cout<<this->hr<<":"<<this->min<<":"<<this->sec<<endl;
    }

    void set_hour(int hr)
    {
         this->hr=hr;
    }
     void set_mins(int min)
    {
        this->min=min;
    }

    void set_sec(int sec)
    {
       this->sec=sec;
    }
};

int main()
{
   times t;
  int hr,min, sec;
  times **arr = new times*[5];
   
   for(int i=0;i<2;i++)
   {
    cout<<"enter HOUR ,MINS ,SEC =";
    cin>>hr>>min>>sec;
    arr[i]=new times(hr,min,sec);

   }
   for(int i=0;i<2;i++)
   {
    arr[i]->print();
   }


}