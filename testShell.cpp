#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
#include <chrono>
#include <thread>
//#include <standard.c>
std::string version = "0.0.2 -alpha tokenized build";
void credits() {
    std::cout << "made by Extreme-M" << std::endl;
    std::cout << "made for PointOS project" << std::endl;
    std::cout << "Manipur do not belong to Kuki!!" << std::endl;
    std::cout << "Kuki refugee leave Manipur!!";
    std::cout << "God forbid formation of Kukiland" << std::endl;
}
void cmd () {
    printf("switching to cmd");
    system("cmd.exe");
}
void powershell () {
    printf("switching to powershell");
    system("powershell");
}

bool permission(std::string question, bool value, bool inverted) {
    std::string permission;
    std::cout << question;
    getline(std::cin, permission);
    if (inverted == false){
        if (permission == "yes", permission == "Y", permission == "Yes", permission == "y") {
        value = true;
        std::cout << "granted" << std::endl;
        }
        else {
        value = false;
        std::cout << "aborted" << std::endl;
        }
    }
    if (inverted == true) {
        if (permission == "yes", permission == "Y", permission == "Yes", permission == "y") {
        value = false;
        std::cout << "granted" << std::endl;
        }
        else {
        value = true;
        std::cout << "aborted" << std::endl;
        }
    }
    return value;
}
void echo(std::string line) {
    std::cout << line << std::endl;
}
std::string logo = "! exclamation Shell, build- 0.0.2 -alpha Tokenized";
int main() {
    bool status = true;
    bool rootuser = false;
    std::string IO = "U$ ";
    std::string rootuserQuestion = "do you want to switch to root? Y/N: ";
    while (status) {
        std::string input;
        std::cout << IO;
        getline(std::cin, input);
        std::stringstream ss(input);
        std::string token;
        std::vector<std::string> args;
        while (ss >> token) {
            args.push_back(token);
        }
        if (args[0] == "superspace"){
            if (args[1] == "-S"){
                if (rootuser == false){
                    permission(rootuserQuestion, rootuser, false);
                    IO = "S$ ";
                }
                else {
                    std::cout << "already in root" << std::endl;
                }
            }
            if (args[1] == "-U"){
                if (rootuser == true){
                    permission("do want to revert back to normal", rootuser, true);
                    IO = "U$";
                }
                else {
                    std::cout << "already in normal" << std::endl;
                }
            }
            else {
                std::cout << "superstate state not specified!!" << std::endl;
            }
        }
        if (args[0] == "exit"){
            return 0;
        }
        if (args[0] == "version"){
            std::cout << version << std::endl;
        }
        if (args[0] == "credits", args[0] == "credit"){
            credits();
        }
        if (args[0] == "cmd"){
            cmd();
        }
        if (args[0] == "powershell"){
            powershell();
        }
        if (args[0] == "echo"){
            echo(args[1]);
        }
    }
    return 0;
}