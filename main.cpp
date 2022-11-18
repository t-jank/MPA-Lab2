#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Product
{
public:
    string name;
    int quantity;
    float price;
private:
vector < float > history_prices;
    vector < int > history_quantities;
public:
    void Add(int qu, float pr){
        history_prices.push_back(price);
        price = pr;
        quantity += qu;
    }

    void Show(){
        cout << name << "; liczba sztuk: " << quantity << "; cena: " << price << endl;
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
        cout << "\n/// Menu glowne ///\n"
             << "1. Stan magazynu\n"
             << "2. Dodaj produkt\n"
             << "3. Zakoncz\n"
             << "Wybor: ";
        cin>>choice;
        cout << endl;
        switch(choice)
        {
        case 1:
            cout << "Stan magazynu:\n";
            for(int i=0; i<magazyn.size(); i++){
                cout << i+1 << ". ";
                magazyn[i].Show();
            }
            cout << endl;
            break;
        case 2:{
            int i=0;
            cout << "/// Dodawanie produktu ///\n";
            for(i=0; i<magazyn.size(); i++){
                cout << i+1 << ". " << magazyn[i].name << endl;
            }
            int product_number = -1, amount=-1; float price=-1;
            string name;
            cout << i+1 << ". Nowy produkt\n";
            cout << i+2 << ". Anuluj\n";
            cout << "Wybierz produkt: ";
            cin >> product_number;
            if(product_number == i+2) {cout<<endl; break;}
            if(product_number < 1 || product_number > i+1) {cout<<endl; break;}

            if(product_number==i+1){
                cout << "Podaj nazwe: ";
                cin >> name;
                cout << "Podaj ilosc: ";
                cin >> amount;
                cout << "Podaj cene: ";
                cin >> price;
                Product a;
                magazyn.push_back(a);
                magazyn[i].name = name;
                magazyn[i].quantity = amount;
                magazyn[i].price = price;
            }
            else{
                cout << "Podaj ilosc: ";
                cin >> amount;
                cout << "Podaj cene: ";
                cin >> price;
                magazyn[product_number-1].Add(amount,price);
            }
            cout << endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
