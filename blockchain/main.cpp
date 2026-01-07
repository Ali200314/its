#include "Blockchain.h"

int main() {
  Blockchain bChain = Blockchain();
  std::string person1PrivateKey = "1234";
  std::string person1PublicKey = "453 ";

  std::string person2PrivateKey = "342";
  std::string person2PublicKey = "234";

  std::string person3PrivateKey = "942";
  std::string person3PublicKey = "284";

  Block b(Block(1, "Block 1 Data"));

  b.AddTransaction(person2PublicKey, person1PrivateKey);
  b.AddTransaction(person3PublicKey, person2PrivateKey);

  cout << "Mining block 1..." << endl;
  bChain.AddBlock(b);

  cout << "Mining block 2..." << endl;
  bChain.AddBlock(Block(2, "Block 2 Data"));

  cout << "Mining block 3..." << endl;
  bChain.AddBlock(Block(3, "Block 3 Data"));

  auto &block = bChain._vChain.back();

  return 0;
}
