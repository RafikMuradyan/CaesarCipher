#include "signature.hpp"

CaesarCipher::CaesarCipher()
{
    std::string message{};
    std::cout << "Please input the message\n-> ";
    std::getline(std::cin,message);
    ushort choice{};
    do
    {   
        std::cout << "Please enter [1] for encoding and [2] for decoding\n[-]\b\b";
        std::cin >> choice;
    }while(choice != 1 and choice != 2); 
     
    ushort key{};
    std::cout << "Please enter key that you want to use for encoding/decoding: ";
    std::cin >> key;
    this->message = message;
    switch (choice)
    {
    case 1:
        encodeTheMessage(this->message,key);
        break;
    
    case 2:
        decodeTheMessage(this->message,key);
        break;
    }  
}

void CaesarCipher::encodeTheMessage(std::string& message,const ushort& key)
{
    const ushort lattersCount = 26;
    for (size_t i = 0; i < message.size(); i++)
    {
        if (message[i] >= 'a' and message[i] <= 'z'){
            if (message[i] + key <= 'z'){
                message[i] += key;
            }
            else{
                message[i] += key - lattersCount;
            }    
        }
        else if (message[i] >= 'A' and message[i] <= 'Z'){
            {
                if (message[i] + key <= 'Z'){
                    message[i] += key;
                }
                else{
                message[i] += key - lattersCount;
                }    
            }  
        }
    }
}

void CaesarCipher::decodeTheMessage(std::string& message,const ushort& key)
{
    const ushort lattersCount = 26;
    for (size_t i = 0; i < message.size(); i++)
    {
        if (message[i] >= 'a' and message[i] <= 'z')
        {
            if (message[i] - key >= 'a'){
                message[i] -= key;
            }
            else{
                message[i] = message[i] - key + lattersCount;
            }    
        }
        else if(message[i] >= 'A' and message[i] <= 'Z')
        {
            if (message[i] - key >= 'A'){
                message[i] -= key;
            }
            else{
                message[i] = message[i] - key + lattersCount;
            }     
        }       
    }
}

std::string CaesarCipher::getMessage()
{
    return message;
}

std::string codeYourMessage()
{
    CaesarCipher epistle;
    std::string result{};
    result = epistle.getMessage();

    return result;
}