//
// Created by aki-dev on 10.07.2023.
//

#include "UmsMain.h"
#include <iostream>
#include <fstream>
#include <filesystem>

UmsMain::UmsMain(const std::string &umsBaseDir) {
  baseDirOfUms = umsBaseDir;
}

bool UmsMain::loginUser(const std::string &userName, const std::string &password) {
  if(!checkIfUserExists(userName)) {
    std::cout << "Username does not exist" << std::endl;
    return false;
  }

  std::string userFilePath = baseDirOfUms + "\\" + userName + ".txt";
  std::ifstream userFile(userFilePath);
  std::string inputPassword;

  while (getline (userFile, inputPassword)) {
    // Output the text from the file
    if(inputPassword == password) {
      std::cout << "Welcome " << userName << std::endl;
      userFile.close();
      return true;
    }
  }

  userFile.close();
  std::cout << "Password was invalid, please try again..." << std::endl;
  return false;
}

bool UmsMain::registerUser(const std::string &userName, const std::string &password) {
  if(checkIfUserExists(userName)) {
    std::cout << "This Username is taken, please choose a different one." << std::endl;
    return false;
  }

  std::string userFilePath = baseDirOfUms + "\\" + userName + ".txt";
  std::ofstream userFile(userFilePath);
  userFile << password;
  return true;
}

bool UmsMain::checkIfUserExists(const std::string &userName) {
  return std::filesystem::exists(baseDirOfUms + "\\" + userName + ".txt");
}