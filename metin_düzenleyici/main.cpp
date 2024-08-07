#include <iostream>
#include <string>
#include <stack>
#include <fstream>

// karan berk kuthan 07.08.2024


enum ActionType { APPEND, DELETE };


struct Action {
    ActionType type;
    std::string text;
    int length;

    
    Action(ActionType t, const std::string &txt, int len)
        : type(t), text(txt), length(len) {}
};

int main() {
    std::string text;                  
    std::stack<Action> history;        
    std::string command;               

    while (true) {
        std::cout << "Komut girin (append, delete, print, undo, save): ";
        std::cin >> command;

        if (command == "append") {
            std::string appendText;
            std::cout << "Eklenecek metni girin: ";
            std::cin.ignore(); 
            std::getline(std::cin, appendText);
            text += appendText;

            
            history.push(Action(APPEND, appendText, 0));

        } else if (command == "delete") {
            int k;
            std::cout << "Silinecek karakter sayısını girin: ";
            std::cin >> k;

            if (k <= text.size()) {
                std::string deletedText = text.substr(text.size() - k, k);

                
                history.push(Action(DELETE, deletedText, k));

                
                text.erase(text.size() - k, k);
            } else {
                std::cout << "Silinecek karakter sayısı metinden fazla olamaz.\n";
            }

        } else if (command == "print") {
            int k;
            std::cout << "Yazdırılacak karakter sayısını girin: ";
            std::cin >> k;
            std::cout << text.substr(0, k) << std::endl;

        } else if (command == "undo") {
            if (!history.empty()) {
                Action lastAction = history.top();
                history.pop();

                if (lastAction.type == APPEND) {
                    
                    text.erase(text.size() - lastAction.text.size(), lastAction.text.size());
                } else if (lastAction.type == DELETE) {
                    
                    text += lastAction.text;
                }
            } else {
                std::cout << "Geri alınacak işlem yok.\n";
            }

        } else if (command == "save") {
            std::string filename;
            std::cout << "Kaydedilecek dosya adını girin: ";
            std::cin >> filename;

            std::ofstream file(filename);
            if (file.is_open()) {
                file << text;
                file.close();
                std::cout << "Metin " << filename << " dosyasına kaydedildi.\n";
            } else {
                std::cout << "Dosya açılamadı.\n";
            }
            break;

        } else {
            std::cout << "Geçersiz komut. Lütfen geçerli bir komut girin.\n";
        }
    }

    return 0;
}
