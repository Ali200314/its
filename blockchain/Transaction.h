#include "sha256.h"
#include <string>

#include <sstream>
class Transaction {
public:
  Transaction(std::string prevHash, std::string ReceiverPublicKey,
              std::string SenderPrivateKey) {
    std::string sum = prevHash + ReceiverPublicKey;
    hash = sha256(sum);
    signature = sha256(hash + SenderPrivateKey);
  }
  std::string publicKey;
  std::string hash;
  std::string signature;
};
