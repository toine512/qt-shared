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

#include "FavCompleter.h"

FavCompleter::FavCompleter(QSettings *settings, QString settings_fav_path, QObject *parent) :
    QCompleter(parent)
{
    p_settings = settings;
    fav_path = settings_fav_path;
    qsl_fav = p_settings->value(fav_path).toStringList();
    qslmodel = new QStringListModel(qsl_fav, this);
    setModel(qslmodel);
    setCaseSensitivity(Qt::CaseInsensitive);
    setCompletionMode(QCompleter::PopupCompletion);
}

bool FavCompleter::isFavourited(const QString &s) const
{
    return qsl_fav.contains(s, Qt::CaseInsensitive);
}

bool FavCompleter::toggleFavourite(const QString &s)
{
    int i = qsl_fav.indexOf(s.toLower());
    if(i > -1)
    {
        qsl_fav.removeAt(i);
        qslmodel->setStringList(qsl_fav);
        p_settings->setValue(fav_path, qsl_fav);
        return false;
    }
    else
    {
        qsl_fav.append(s.toLower());
        qslmodel->setStringList(qsl_fav);
        p_settings->setValue(fav_path, qsl_fav);
        return true;
    }
}
