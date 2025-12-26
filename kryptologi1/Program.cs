// using System;
// using System.IO;
// using System.Security.Cryptography;
// string msgToEncrypt = "Hello, World!";
    
// Aes aes = Aes.Create();
// ICryptoTransform encryptor = aes.CreateEncryptor(aes.Key,aes.IV);
//  byte[] encrypted;
// using (MemoryStream msEncrypt = new MemoryStream())
// {
//       using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
//                     {
//                         using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
//                         {
//                             //Write all data to the stream.
//                             swEncrypt.Write(msgToEncrypt);
//                         }
//                     }
//                     encrypted = msEncrypt.ToArray();
// }
// string hex = BitConverter.ToString(encrypted);
// Console.WriteLine(hex); 

// string plaintext = null;

//  ICryptoTransform decryptor = aes.CreateDecryptor(aes.Key,aes.IV);
//   using (MemoryStream msDecrypt = new MemoryStream(encrypted))
//                 {
//                     using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
//                     {
//                         using (StreamReader srDecrypt = new StreamReader(csDecrypt))
//                         {

//                             // Read the decrypted bytes from the decrypting stream
//                             // and place them in a string.
//                             plaintext = srDecrypt.ReadToEnd();
//                         }
//                     }
//                 }

//         Console.WriteLine(plaintext);
// using System;
// using System.IO;
// using System.Security.Cryptography;
// byte[] secretkey = new Byte[64];
//
// string dataFile = @"text.txt";
// string signedFile = "signedFile.enc";
//
// using (RandomNumberGenerator rng = RandomNumberGenerator.Create())
//             {
//                 // The array is now filled with cryptographically strong random bytes.
//                 rng.GetBytes(secretkey);
//
//                 // Use the secret key to sign the message file.
//
//             }
//
// // string hex = BitConverter.ToString(secretkey);
// // Console.WriteLine(hex); 
//
//
// using (HMACSHA256 hmac = new HMACSHA256(secretkey))
//         {
//  using (FileStream inStream = new FileStream(dataFile, FileMode.Open))
//             {
//                 using (FileStream outStream = new FileStream(signedFile, FileMode.Create))
//                 {
//   byte[] hashValue = hmac.ComputeHash(inStream);
// Console.WriteLine(BitConverter.ToString(hashValue)); 
//                 }}}
//
//
using System;
using System.Security.Cryptography;
using System.Text;
 UnicodeEncoding ByteConverter = new UnicodeEncoding();
 byte[] dataToEncrypt = ByteConverter.GetBytes("Data to Encrypt");



byte[] encryptedData;
byte[] decryptedData;

RSACryptoServiceProvider RSA = new RSACryptoServiceProvider();
// string publicAndPrivateKey = RSA.ToXmlString(true);

encryptedData= RSA.Encrypt(dataToEncrypt,false);



 decryptedData=RSA.Decrypt(encryptedData,false);


// string hex = BitConverter.ToString(decryptedData);
// Console.WriteLine(hex); 
Console.WriteLine(ByteConverter.GetString(decryptedData));
