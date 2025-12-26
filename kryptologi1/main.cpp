#include <cryptopp/eccrypto.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/oids.h>
#include <cryptopp/osrng.h>
#include <iostream>
#include <string>
using namespace CryptoPP;

int main() {
  // AutoSeededRandomPool prng;
  //
  // // 1. Generate Key Pair (secp256k1)
  // ECDSA<ECP, SHA256>::PrivateKey privateKey;
  // privateKey.Initialize(prng, ASN1::secp256k1());
  //
  // ECDSA<ECP, SHA256>::PublicKey publicKey;
  // privateKey.MakePublicKey(publicKey);
  //
  // // 2. Data to Sign
  // std::string message = "Do or do not. There is no try.";
  // std::string signature;
  //
  // // 3. Sign the message
  // ECDSA<ECP, SHA256>::Signer signer(privateKey);
  // StringSource ss1(message, true,
  //                  new SignerFilter(prng, signer, new
  //                  StringSink(signature)));
  //
  // // 4. Verify the signature
  // ECDSA<ECP, SHA256>::Verifier verifier(publicKey);
  // bool result = false;
  //
  // // Use SignatureVerificationFilter to verify
  // StringSource ss2(
  //     signature + message, true,
  //     new SignatureVerificationFilter(
  //         verifier, new ArraySink((byte *)&result, sizeof(result))));
  //
  // // 5. Output Result
  // if (result) {
  //   std::cout << "Signature Verified!" << std::endl;
  // } else {
  //   std::cout << "Signature Failed!" << std::endl;
  // }
  //
  // return 0;
  std::string source, value;
  SHA256 hash;

  source = "Yoda said, Do or do not. There is no try.";
  StringSource ss(
      source, true /* PumpAll */,
      new HashFilter(hash,
                     new HexEncoder(new StringSink(value)) // HexEncoder
                     )                                     // HashFilter
  );                                                       // StringSource

  std::cout << source << std::endl;
  std::cout << value << std::endl;
}
