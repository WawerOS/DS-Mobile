/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once
#ifndef _DS_MOBILE_UPDATER_H
#define _DS_MOBILE_UPDATER_H

#include <QObject>
#include <QApplication>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "Settings.h"

class Updater : public QObject
{
    Q_OBJECT

public:
    explicit Updater();

signals:
    void updateAvailable (QString version,
                          QString downloadLink);

public slots:
    Q_INVOKABLE void checkForUpdates();

private slots:
    void showUpdateMessages();
    void onFinished (QNetworkReply* reply);
    void readDownloadLink (QByteArray data);
    void readApplicationVersion (QByteArray data);

    QString readKey (QString data, QString key);

private:
    bool m_updateAvailable;

    QString m_version;
    QString m_platform;
    QString m_downloadLink;

    Settings m_settings;

    QNetworkAccessManager m_accessManager;
};

#endif
