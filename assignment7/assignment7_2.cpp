#include <iostream>
using namespace std;

class product
{
private:
    int id;
    string title;
    float price;
    char product_type;

public:
    product()
    {
        id = 1;
        title = "The Kite Runner";
        price = 399.0F;
        // product_type = 'B';
    }

    product(int id, string title, float price, char type)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->product_type = type;
    }

    void setProduct_Type(char product_type)
    {
        this->product_type = product_type;
    }

    virtual void accept()
    {
        cout << "enter id = " << endl;
        cin >> this->id;

        cout << "enter title = " << endl;
        cin >> this->title;

        cout << "enter price = " << endl;
        cin >> this->price;
    }

    void display()
    {
        cout << "-------------------------------------------" << endl;
        cout << "id = " << this->id << "|"
             << " title = " << this->title << "|"
             << " price = " << this->price << "|"
             << " product type = " << this->product_type << endl;
        cout << "-------------------------------------------" << endl;
    }

    int get_price()
    {
        return price;
    }

    void set_price(float price)
    {
        this->price = price;
    }
    friend void calculateDiscountedPrice(product *arr[], int index);
};

class book : public product
{
private:
    string author;

public:
    book()
    {
        product::setProduct_Type('B');
        author = "The Kite Runner";
    }
    book(string author)
    {
        this->author = author;
    }
    void accept()
    {
        product::accept();
        cout << "Enter book name = " << endl;
        cin >> this->author;
    }

    void diaplay()
    {
        product::display();
        cout << "author = " << this->author << endl;
    }
};

class tape : public product
{
private:
    string artist;

public:
    tape()
    {
        product::setProduct_Type('T');
        artist = "Khaled Hosseini";
    }
    tape(string artist)
    {
        this->artist = artist;
    }

    void accept()
    {
        product::accept();
        cout << "enter artist = " << endl;
        cin >> this->artist;
    }

    void display()
    {
        product::display();
        cout << "artist = " << this->artist;
    }
};

void calculateDiscountedPrice(product *arr[], int index)
{
    float bsum;
    float tsum;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->product_type == 'B')
            bsum += arr[i]->get_price() - (arr[i]->get_price() * 0.10);
    }
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->product_type == 'T')
            tsum += arr[i]->get_price() - (arr[i]->get_price() * 0.05);
    }

    cout << "total bill = " << bsum + tsum << endl;
}

int menu()
{
    int choice;
    cout << "--------------------------" << endl;
    cout << "0.EXIT" << endl;
    cout << "1.Purchase book" << endl;
    cout << "2.Purchase tape" << endl;
    cout << "3.Total bill" << endl;
    cout << "4.Display item" << endl;
    cout << "--------------------------" << endl;

    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    product *arr[3];
    int index = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new book();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Cart is full...Can't add" << endl;
            }
            break;
        case 2:
            if (index < 3)
            {
                arr[index] = new tape();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Cart is full...Can't add" << endl;
            }
            break;
        case 3:
            calculateDiscountedPrice(arr, index);
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
            break;
        default:
            cout << "wrong choice..." << endl;
        }
    }
    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }

    cout << "thanks for shopping..." << endl;
    return 0;
}
