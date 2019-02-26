#include "FileWithUsers.h"


void FileWithUsers::addUserToFile(User user) {
    CMarkup fileXml;

    fileXml.Load(fileWithUsers);

    while(fileXml.FindElem("user"))
        fileXml.OutOfElem();

    fileXml.AddElem("user");
    fileXml.IntoElem();
    fileXml.AddElem("userId", user.getUserId());
    fileXml.AddElem("login", user.getLogin());
    fileXml.AddElem("password", user.getPassword());
    fileXml.AddElem("name", user.getName());
    fileXml.AddElem("surname", user.getSurname());
    fileXml.Save(fileWithUsers);
}

vector <User> FileWithUsers::loadUserFromFile() {
    vector <User> users;
    User user;
    CMarkup xml;

    xml.Load(fileWithUsers);

    while (xml.FindElem("user")) {
        xml.IntoElem();
        xml.FindElem("userId");
        user.setUserId( atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void FileWithUsers::saveAllUserToFile (vector <User> &users) {

    CMarkup fileXml;
    for (int i =0; i < users.size(); i++) {
        fileXml.AddElem("user");
        fileXml.IntoElem();
        fileXml.AddElem("userId", users[i].getUserId());
        fileXml.AddElem("login", users[i].getLogin());
        fileXml.AddElem("password", users[i].getPassword());
        fileXml.AddElem("name", users[i].getName());
        fileXml.AddElem("surname", users[i].getSurname());
        fileXml.OutOfElem();
    }

    fileXml.Save(fileWithUsers);

}
