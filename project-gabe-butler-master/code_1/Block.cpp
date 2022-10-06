#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // TODO
    string final;

    final = to_string(nonce);

    for(int i = 0; i < transactions.size(); i++){
        final += transactions[i].getSender() + transactions[i].getReceiver() + to_string(transactions[i].getAmount());
    }

    final += previousHash;

    final += to_string(timestamp);
    
    final = sha256(final);

    hash = final;

    return final;   
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    string beg;
    for(int i = 0; i < difficulty; i++){
        beg += "0";
    }

    while(hash.substr(0, difficulty) != beg){
        nonce++;
        calculateHash();
    }

}

string Block::toString() {
    // TODO
    cout << hash << " : ";
    for(int i = 0; i < transactions.size(); i++){
        cout << "(" << transactions[i].getSender() << ", " << transactions[i].getReceiver() << ", " << transactions[i].getAmount() << ") ";
    }
    cout << endl;
    return "";
}