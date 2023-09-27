#include<iostream>
using namespace std;

class box
{
    private:
    int length;
    int width;
    int height;

    public:
    box()
    {
        this->length=0;
        this->width=0;
        this->height=0;
    }

    box(int length,int width,int height)
    {
        this->length=length;
        this->width=width;
        this->height=height;
    }

    void accept()
    {
        cout<<"Enter size of length :";
        cin>>this->length;

        cout<<"Enter size of width :";
        cin>>this->width;

        cout<<"Enter size of height :";
        cin>>this->height;
    }

    int volume()
    {
        int vol;
        vol=this->length * this->width * this->height;
        return vol;
    }

    void display()
    {
        cout<<"Volume of box :"<<this->volume()<<"sq.unit"<<endl;
    }
};

int menu()
{
    int choice;

    cout<<"------------------------------"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. ACCEPT VALUES"<<endl;
    cout<<"2. VOLUME OF BOX"<<endl;
    cout<<"3. DISPLAY VOLUME"<<endl;

    cin>>choice;
    return choice;
}

int main()
{
    box b;
    int choice;

    while((choice = menu()) !=0)
    {
        switch (choice)
        {
            case 1:
            b.accept();
            break;

            case 2:
            b.volume();
            break;

            case 3:
            b.display();
            break;

            default:
            cout<<"WRONG CHOICE NUMBER......"<<endl;
            cout<<"ENTER VALID CHOICE :-"<<endl;
        }
    } 
cout<<"THANKS FOR COMING OUR APP PLEASE VISIT AGAIN....."<<endl;
    return 0;
}
