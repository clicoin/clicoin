// Copyright (c) 2011-2014 The Clicoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CLICOIN_QT_CLICOINADDRESSVALIDATOR_H
#define CLICOIN_QT_CLICOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ClicoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ClicoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Clicoin address widget validator, checks for a valid clicoin address.
 */
class ClicoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ClicoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CLICOIN_QT_CLICOINADDRESSVALIDATOR_H
