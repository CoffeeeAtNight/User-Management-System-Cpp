#include <iostream>
#include <string>
#include <filesystem>
#include "./ums/UmsInitializer.h"
#include "./ums/UmsMain.h"

using namespace std;
using namespace filesystem;

void startUMS(short* userMode) {
  cout << "--------------------------------------\n";
  cout << "Do you want to [1] Login or [2] Register, please enter your choice:" << endl;
  cin >> *userMode;
}

void startLoginProcess(UmsMain &umsMain) {
  string userName;
  string password;

  cout << endl << endl;
  cout << "--------------------------------------\n";
  cout << "Log-in" << endl;
  cout << "Enter a username: ";
  cin >> userName;
  cout << "Enter a password: ";
  cin >> password;

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  bool loginProcessState = umsMain.loginUser(userName, password);

  if(!loginProcessState) {
    startLoginProcess(umsMain);
  }
}

void startRegisterProcess(UmsMain &umsMain) {
  string userName;
  string password;

  cout << endl << endl;
  cout << "--------------------------------------\n";
  cout << "Register a new user" << endl;
  cout << "Enter a username: ";
  cin >> userName;
  cout << "Enter a password: ";
  cin >> password;

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  bool registerProcessState = umsMain.registerUser(userName, password);

  if(!registerProcessState) {
    startRegisterProcess(umsMain);
  }

  cout << "User successfully created!" << endl << endl;
}


int main() {
  string username;
  string password;
  short userMode;
  const string pathToUserCredFolder = R"(C:\UserManagementSystem\user_credentials)";

  UmsInitializer umsInitializer(pathToUserCredFolder);
  UmsMain umsMain(pathToUserCredFolder);

  try {
    umsInitializer.start();
  } catch (exception& err) {
    cerr << err.what() << endl;
    return 1;
  }

  cout << "Welcome to this User Management System\n";
  startUMS(&userMode);

  while (userMode != 1 && userMode != 2) {
    cout << userMode << " is an invalid choice, please try again..." << endl;
    startUMS(&userMode);
  }

  if (userMode == 1) {
      startLoginProcess(umsMain);
  } else {
      startRegisterProcess(umsMain);
  }

  main();
  return 0;
}