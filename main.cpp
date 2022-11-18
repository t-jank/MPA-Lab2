#include <iostream>
#include <vector>

using namespace std;


class Product
{
public:
    string name;
    int quantity;
    float price;
    vector < float > history_prices;
    vector < int > history_quantities;

    void Add(int qu, float pr)
    {
        history_prices.push_back(price);
        price = pr;
        quantity += qu;
    }

    void Show(){
        cout << name << "; liczba sztuk w magazynie: " << quantity << "; cena: " << price << endl;
    }

    void Show_history(){
        cout << "Dostawa " << "Liczba sztuk " << "Cena" << endl;
        for(int i=0; i < history_prices.size(); i++){
            cout << i+1 << history_quantities[i] << history_prices[i] << endl;
        }
    }

};




int main()
{
    vector < Product > magazyn;
    int choice=0;
    while(choice!=3){
        //system("cls");
        cout << "1. Stan magazynu\n"
             << "2. Dodaj produkt\n"
             << "3. Zakoncz\n"
             << "Wybor: ";
        cin>>choice;
        cout << endl;
        switch(choice)
        {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
        }
    }

    return 0;
}
