#include "User.h"
#include "UdataUtils.h"
#include <QDebug>
#include <QVector>
#include <stdlib.h>

using namespace udata;

User *User::thisInstance = new User(QVector<Commitment>{});

/**
 * @brief User::User
 * @param newCommitments
 */
User::User(QVector<Commitment> newCommitments) {
    commitments = newCommitments;
}

/**
 * @brief User::User
 */
User::User() {
}

/**
 * @brief User::User
 * @param newUsername
 */
User::User(QString &newUsername) : userName{ newUsername } {
}

/**
 * @brief User::~User
 */
User::~User() {
}

/**
 * @brief udata::User::getDefaultCommitment
 * @return
 */
const Commitment &udata::User::getDefaultCommitment() {
    return commitments.at(defaultCommitmentIndex);
}

/**
 * @brief User::getCommitments
 * @return
 */
QVector<Commitment> &User::getCommitments() {
    return commitments;
}

/**
 * @brief User::addCommitment
 * @param newCommitment
 */
void User::addCommitment(Commitment &newCommitment) {
    commitments.push_back(newCommitment);
    UdataUtils::saveUserData(*getInstance());
}

/**
 * @brief User::addSession
 * @param newSession
 */
void User::addSession(Session &newSession) {
    Commitment c = commitments.at(currentCommitment);
    c.getSessions().push_back(newSession);
    UdataUtils::saveUserData(*getInstance());
}

/**
 * @brief udata::User::setDefaultCommitment
 * @param c
 */
void udata::User::setDefaultCommitment(const Commitment &c) {
    int i = 0;
    bool found = false;

#define OUT
#ifndef OUT
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
#endif
}

/**
 * @brief User::setUsername
 * @param name
 */
void User::setUsername(QString &name) {
    userName = name;
}

/**
 * @brief User::getUsername
 * @return
 */
QString &User::getUsername() {
    return userName;
}

/**
 * @brief udata::operator <<
 * @param out
 * @param newUser
 * @return
 */
QDataStream &udata::operator<<(QDataStream &out, User &newUser) {
    out << newUser.commitments << newUser.defaultCommitmentIndex << newUser.userName;
    return out;
}

/**
 * @brief udata::operator >>
 * @param in
 * @param newUser
 * @return
 */
QDataStream &udata::operator>>(QDataStream &in, User &newUser) {
    in >> newUser.commitments >> newUser.defaultCommitmentIndex >> newUser.userName;
    return in;
}

/**
 * @brief User::getInstance
 * @return
 */
User *User::getInstance() {
    return thisInstance;
}
