/* Copyright (C) 2013 toine512 <toine512@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FAVCOMPLETER_H
#define FAVCOMPLETER_H

#include <QCompleter>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QStringListModel>

class FavCompleter : public QCompleter
{
    Q_OBJECT

public:
    explicit FavCompleter(QSettings *settings, QString settings_fav_path, QObject *parent = 0);
    bool isFavourited(const QString &s) const;
    bool toggleFavourite(const QString &s); /*Returns true  if favourite was added
                                                      false if favourite was removed*/

protected:
    QSettings *p_settings;
    QString fav_path;
    QStringList qsl_fav;
    QStringListModel *qslmodel;
};

#endif // FAVCOMPLETER_H
