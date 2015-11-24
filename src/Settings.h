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
#ifndef _DS_MOBILE_SETTINGS_H
#define _DS_MOBILE_SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QApplication>

class Settings : public QObject {
    Q_OBJECT

  public:
    explicit Settings();
    ~Settings();

  public slots:
    /**
     * Saves the \a value to the input \a key
     */
    Q_INVOKABLE void set (QString key, QVariant value);

    /**
     * Returns the associated value with the \a key.
     * If the \a key is not found, the function will return
     * the \a defValue
     */
    Q_INVOKABLE QVariant get (QString key, QVariant defValue);

    /**
     * Returns the associated value with the \a key and converts
     * it into a \c boolean
     *
     * If the \a key is not found, the function will return
     * the \a defValue
     */
    Q_INVOKABLE bool getBool (QString key, QString defValue);

    /**
     * Returns the associated value with the \a key and converts
     * it into a \c double
     *
     * If the \a key is not found, the function will return
     * the \a defValue
     */
    Q_INVOKABLE double getNumber (QString key, double defValue);

    /**
     * Returns the associated value with the \a key and converts
     * it into a \c QString
     *
     * If the \a key is not found, the function will return
     * the \a defValue
     */
    Q_INVOKABLE QString getString (QString key, QString defValue);

  private:
    QSettings* m_settings;
};

#endif