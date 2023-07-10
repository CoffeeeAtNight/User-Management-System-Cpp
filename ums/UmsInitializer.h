//
// Created by aki-dev on 2023-07-10.
//
#include <string>

#ifndef UMS_CPP_USMINITIALIZER_H
#define UMS_CPP_USMINITIALIZER_H

class UmsInitializer {
  public:
    UmsInitializer(const std::string &userCredentialsFolderPath);
    void start();

  private:
    std::string userFolder;
    bool checkForExistingUserCredentialsFolder();
    void createUmsFolder();
    bool handleUmsFolderState();
};


#endif //UMS_CPP_USMINITIALIZER_H
