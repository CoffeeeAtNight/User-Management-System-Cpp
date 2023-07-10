//
// Created by aki-dev on 10.07.2023.
//

#ifndef UMS_CPP_UMSMAIN_H
#define UMS_CPP_UMSMAIN_H

#include <string>

class UmsMain {
  public:
    UmsMain(const std::string &umsBaseDir);
    bool registerUser(const std::string& userName, const std::string& password);
    bool loginUser(const std::string& userName, const std::string& password);
  private:
    bool checkIfUserExists(const std::string& userName);
    std::string baseDirOfUms;

};


#endif //UMS_CPP_UMSMAIN_H
