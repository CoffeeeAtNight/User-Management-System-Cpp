//
// Created by aki-dev on 2023-07-10.
//

#include "UmsInitializer.h"
#include "string"
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using namespace std;

// Constructor of class
UmsInitializer::UmsInitializer(
  const string& userCredentialsFolderPath
) {
  userFolder = userCredentialsFolderPath;
}

void UmsInitializer::start() {
  bool folderIsThere = handleUmsFolderState();

  if(!folderIsThere) {
    throw std::runtime_error("UMS folder does not exist.");
  }
}

bool UmsInitializer::handleUmsFolderState() {
  if(checkForExistingUserCredentialsFolder()) return true;

  try {
    createUmsFolder();
    return true;
  } catch(const std::exception& err) {
    cerr << "An exception occurred: " << err.what() << endl;
    return false;
  }
}

bool UmsInitializer::checkForExistingUserCredentialsFolder() {
  ifstream file(userFolder);
  return file.good();
}

void UmsInitializer::createUmsFolder() {
  fs::create_directories(userFolder);
}

