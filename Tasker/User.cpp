#include "User.h"
#include "UdataUtils.h"
#include <stdlib.h>
using namespace udata;
User::User(QVector<Commitment>& newCommitments) {
    commitments = newCommitments;
}

User::~User() {
}

const Commitment &udata::User::getDefaultCommitment() {
    return commitments.at(defaultCommitmentIndex);
}
void udata::User::setDefaultCommitment(const Commitment &c) {
    int i = 0;
    bool found = false;

    /*
    for (i = 0; i < commitments.size(); i++) {
        if (c == commitments.at(i)) {
            found = true;
            defaultCommitmentIndex = i;
            break;
        }
    }

    if (found == false) {
        commitments.push_back(c);
        defaultCommitmentIndex = commitments.size() - 1;
    }
    */
}
QDataStream& udata::operator<<(QDataStream &out, User &newUser)
{
    out<<newUser.commitments<<newUser.defaultCommitmentIndex;
    return out;
}
QDataStream &udata::operator>>(QDataStream &in, User &newUser)
{
    in>>newUser.commitments>>newUser.defaultCommitmentIndex;
    return in;
}
User* User::getInstance()
{
    if(thisInstance == nullptr){
        thisInstance = std::make_unique<User>();
        if(UdataUtils::prepFiles()==0)
        {
            UdataUtils::loadUserData(thisInstance);
        }
    }
    return thisInstance;
}
