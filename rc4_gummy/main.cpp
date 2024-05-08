#include <iostream>
#include <vector>
#include <fstream>
#include "rc4.h"

std::string code(std::string key,std::string cipher_text){
    
    std::string result;
    std::vector<unsigned char> key_vec(key.begin(), key.end());
    // Генерация ключа
    set_key(key_vec);

    // Кодирование текста
    std::vector<unsigned char> uncipher_text;
    for (unsigned char c : cipher_text) {
        //std::cout<<(static_cast<int>(c))<<" ";
        //std::cout<<static_cast<int>(g())<< " ";
        uncipher_text.push_back(static_cast<unsigned char >(c ^ g()));
    }
    for(unsigned char elem : uncipher_text)
    {
        result+=static_cast<char>(elem);
    }
    std::cout<<result<<std::endl;
    fin();
    return result;
}
std::string decode(std::string key, std::string plain_text){
    std::vector<unsigned char> key_vec(key.begin(), key.end());
    set_key(key_vec);
    std::string result="";
        // Кодирование текста
    std::vector<unsigned char> cipher_text;
    for (unsigned char c : plain_text) {
        //std::cout<<(static_cast<int>(c))<<" ";
        cipher_text.push_back(static_cast<unsigned char >(c ^ g()));
    }
    std::cout<<std::endl;
    // Вывод закодированного текста
    //std::cout << "Закодированный текст: " << cipher_text << std::endl;
    for(unsigned char elem : cipher_text)
    {
        //std::cout<<static_cast<unsigned char>(elem)<< " ";
        result+=static_cast<unsigned char>(elem);
    }
 
    fin();
    return result;
}


int main() {
    std::ofstream file("crypt.txt", std::ios::out | std::ios::trunc);
    std::string key = "Thisvhjvu";
    std::string plain_text = "fbyvbhs";
    std::string flag;
    std::cout<<"Введите ключ"<<std::endl;
    std::cin>>key;
    std::cout<<"Расшифровать из decrypt.txt или зашифровать в файл  crypt.txt? 1 or 0"<<std::endl;
    std::cin>>flag;
    if(flag=="1"){
        std::ifstream infile("decrypt.txt");
        if (infile.is_open()) {
            std::string line;
            std::getline(infile, line);
        std::cout<<decode(key, line);
        infile.close();
    }
    }
    if(flag=="0"){
        std::cout<<"Введите текст"<<std::endl;
        std::cin>>plain_text;
        file<<code(key,plain_text);
    }
    file.close();
    return 0;
}