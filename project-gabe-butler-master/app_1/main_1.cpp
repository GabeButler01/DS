#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    /* Blockchain buffCUoin;

    buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);

    cout << "ashutosh paid asa 15 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","asa", 15);
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa");
    buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    cout << "maciej mining third block ... " << endl;
    buffCUoin.minePendingTransactions("maciej");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();
    
    return 0; */

    Blockchain buffCUoin;
    buffCUoin.minePendingTransactions("A");
    buffCUoin.addTransaction("A", "B", 1);
    buffCUoin.addTransaction("B", "C", 1);
    buffCUoin.minePendingTransactions("C");
    buffCUoin.addTransaction("B", "A", 1);
    buffCUoin.addTransaction("A", "B", 2);
    buffCUoin.addTransaction("B", "A", 1);
    buffCUoin.minePendingTransactions("B");
    cout << buffCUoin.getBalanceOfAddress("A") << endl;
    cout << buffCUoin.getBalanceOfAddress("B") << endl;
    cout << buffCUoin.getBalanceOfAddress("C") << endl;

}