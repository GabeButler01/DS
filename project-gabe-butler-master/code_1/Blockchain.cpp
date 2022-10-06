#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
    int balance = getBalanceOfAddress(src);
    if(balance >= coins){
        Transaction pay = Transaction(src, dst, coins);
        pending.push_back(pay);
    }
    else{
        cout << "Insufficient funds." << endl;
    }
}

bool Blockchain::isChainValid() { 
    // TODO
    bool flag = true;

    // validate previous hash
    int j = 1;
    for(int i = 0; i < int(chain.size()); i++){
        if(chain[i].getHash() != chain[j].getPreviousHash()){
            flag = false;
        }

        // validate difficulty
        for(int k = 0; k < difficulty; k++){
            if(chain[j].getHash()[k] != '0'){
                flag = false;
            }
        }
        j++;
    }
    return flag;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    Block pend(pending, time(nullptr), getLatestBlock().calculateHash());
    pend.mineBlock(difficulty);

    pending.clear();

    chain.push_back(pend);

    Transaction reward("BFC", minerAddress, miningReward);
    pending.push_back(reward);

    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int total = 0;

    for(int i = 0; i < int(chain.size()); i++){
        for(int j = 0; j < chain[i].transactions.size(); j++){
            if(chain[i].transactions[j].getSender() == address){
                total -= chain[i].transactions[j].getAmount();
                if(total < 0){
                    cout << "Error! Negative funds." << endl;
                    return total;
                }
            }
            if(chain[i].transactions[j].getReceiver() == address){
                total += chain[i].transactions[j].getAmount();
            }
        }
    }
    
    for(int k = 0; k < pending.size(); k++){
        if(pending[k].getSender() == address){
                total -= pending[k].getAmount();
                if(total < 0){
                    cout << "Error! Negative funds." << endl;
                    return total;
                }
        }
        if(pending[k].getReceiver() == address){
            total += pending[k].getAmount();
        }
    }
            
            

    return total;
}

void Blockchain::prettyPrint() {
    // TODO
    for(int i = 0; i < int(chain.size()); i++){
        cout << chain[i].toString() << endl;
    }
}