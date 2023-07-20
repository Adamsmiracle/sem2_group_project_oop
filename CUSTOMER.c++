#include "customer.hpp"
#include "AUTH.hpp"
#include "CART.hpp"
#include "PRODUCT.hpp"
#include <fstream>
#include <string>
#include <string.h>
// using namespace PRODUCT;
using namespace std;

typedef fstream file;

CUSTOMER::CUSTOMER(string first_name,  string last_name, string password)
{
        this->first_name = first_name;
        this->last_name =  last_name;
        this->password = password;
}

    void CUSTOMER::buy(){}

    void CUSTOMER::selectItem(PRODUCT item){
        CART * cart = CART::getinStance();
        cart->addToCart(item);
    }

    void CUSTOMER::removeFromCart(int _position){}

    void CUSTOMER::createAccount(){
        AUTH newCustomer(this->first_name,this->last_name, this->password);
        newCustomer.Register();
    }

    bool CUSTOMER::login(string first_name, string last_name, string password){
            AUTH authToken(first_name, last_name, password);
            bool isloggedin = authToken.Login();

            if (!isloggedin){
                cout << "credentials incorrect you have "<< authToken.trial_limit - authToken.number_of_trials << "left";
                return false;
            }
           
        //    char key;
        //    cout << " Do you enter you password agian?\n";
        //    cout << " type y for yes and any other key for no\n";
        // //    add a cout << ">> " here 
        //    cin >> key;
        //    if (key == 'y' || key == 'Y'){

        //    }
           
        
            return true;
    }

    void CUSTOMER::logout(){
        string details = this->first_name + this->last_name + this->password;
        AUTH authToken(this->first_name, this->last_name, this->password);
        authToken.Logout("auth.txt",details);
    }