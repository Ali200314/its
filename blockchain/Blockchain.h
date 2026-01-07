#include "Block.h"
#include <cstdint>
#include <vector>

using namespace std;
class Blockchain {
public:
  Blockchain();

  void AddBlock(Block bNew);

  vector<Block> _vChain;

private:
  uint32_t _nDifficulty;

  Block _GetLastBlock() const;
};
