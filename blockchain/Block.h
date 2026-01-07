#include "Transaction.h"
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class Block {
public:
  string sPrevHash;

  Block(uint32_t nIndexIn, const string &sDataIn);

  string GetHash();
  void AddTransaction(std::string recieverPublicKey,
                      std::string senderPrivateKey);
  void MineBlock(uint32_t nDifficulty);

private:
  uint32_t _nIndex;
  int64_t _nNonce;
  string _sData;
  string _sHash;
  time_t _tTime;

  vector<Transaction> Transactions;
  string _CalculateHash() const;
};
