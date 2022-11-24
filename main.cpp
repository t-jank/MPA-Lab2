#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;


class Product
{
public:
    string name;
    int quantity;
    float price;
    vector < float > history_prices;
    vector < int > history_quantities;
    void Add(int qu, float pr){
        history_prices.push_back(price);
        price = pr;
        quantity += qu;
    }
    void Show(){
        cout << name << "; liczba sztuk: " << quantity << "; cena: " << price << endl;
    }
    void Show_history(){
        cout << "Nr dostawy\t" << "Liczba sztuk\t" << "Cena" << endl;
        for(int i=0; i < history_prices.size(); i++){
            cout << i+1 <<"\t\t"<< history_quantities[i] <<"\t\t"<< history_prices[i] << endl;
        }
    }
    float avg=-1,var=-1,sum=0,sumvar=0;
    void update_variance(){
        for(int i=0; i < history_prices.size(); i++){
            sum+=history_prices[i];
        }
        avg = sum / history_prices.size();
        for(int i=0; i < history_prices.size(); i++){
            sumvar+=pow((history_prices[i]-avg),2);
        }
        var = sumvar/history_prices.size();
    }
};



int main()
{
    srand( time( NULL ) );
    vector < Product > magazyn;

    // reczne wprowadzenie istniejacej bazy
    Product a;
    magazyn.push_back(a);
    magazyn[0].name = "Komputery";
    magazyn[0].quantity = 40;
    magazyn[0].price = 124;
    magazyn[0].history_prices.push_back(100.0);
    magazyn[0].history_quantities.push_back(40);
    for(int i=1;i<50;i++){
        magazyn[0].history_prices.push_back(round(100*(rand()/float((RAND_MAX))*25.0+100))/100.0);
        magazyn[0].history_quantities.push_back(rand()%21+30);
        int x=rand()%100; // pomylka brak przecinka z Pr=20%
        if(x<20){magazyn[0].history_prices[magazyn[0].history_prices.size()-1] *=100;}
    }
    magazyn[0].history_prices.push_back(124.0);
    magazyn[0].history_quantities.push_back(20);

    char choice='1';
    while(choice!='5'){
        //system("cls");
        cout << "\n/// Menu glowne ///\n"
             << "1. Stan magazynu\n"
             << "2. Dodaj produkt\n"
             << "3. Historia dostaw\n"
             << "4. Edycja stanu magazynu\n"
             << "5. Zakoncz\n"
             << "Wybor: ";
        cin>>choice;
        cout << endl;
        switch(choice)
        {
        case '1':
            cout << "Stan magazynu:\n";
            for(int i=0; i<magazyn.size(); i++){
                cout << i+1 << ". ";
                magazyn[i].Show();
            }
            cout << endl;
            break;
        case '2':{
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
            char chosen_product;
            cin >> chosen_product;
            product_number = chosen_product - '0';
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
        case '3':{
            int i=0;
            cout << "/// Historia dostaw ///\n";
            for(i=0; i<magazyn.size(); i++){
                cout << i+1 << ". " << magazyn[i].name << endl;
            }
            cout << i+1 << ". Anuluj\n";
            cout << "Wybierz produkt: ";
            char chosen_product;
            int product_number = -1;
            cin >> chosen_product;
            product_number = chosen_product - '0';
            if(product_number == i+1) {cout<<endl; break;}
            if(product_number < 1 || product_number > i+1) {cout<<endl; break;}
            cout << "\n/// " << magazyn[product_number-1].name << " - historia dostaw ///\n";
            magazyn[product_number-1].Show_history();
            cout<<"aktualnie:\n";
            cout << "liczba sztuk: " << magazyn[product_number-1].quantity << "; cena: " << magazyn[product_number-1].price << endl << endl;
            break;
        }
        case '4':{
            int product_number = -1, new_stan=-1, new_price=-1;
            cout << "Stan magazynu:\n";
            for(int i=0; i<magazyn.size(); i++){
                cout << i+1 << ". ";
                magazyn[i].Show();
            }
            cout << "Wybierz element do edycji: ";
            cin >> product_number;
            cout << "Wprowadz nowy stan ilosciowy: ";
            cin >> new_stan;
            cout << "Wprowadz nowa cene: ";
            cin >> new_price;
            magazyn[product_number-1].quantity = new_stan;
            magazyn[product_number-1].price = new_price;
            break;
        }
        default:
            break;
        }
    }


    return 0;
}
