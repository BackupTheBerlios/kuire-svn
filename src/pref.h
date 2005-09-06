/***************************************************************************
 *   Copyright (C) 2005 by Carsten Nikiel   *
 *   carsten@nikiel.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef _KUIREPREF_H_
#define _KUIREPREF_H_

#include <kdialogbase.h>
#include <qframe.h>

class KuirePrefPageOne;
class KuirePrefPageTwo;

class KuirePreferences : public KDialogBase
{
    Q_OBJECT
public:
    KuirePreferences();

private:
    KuirePrefPageOne *m_pageOne;
    KuirePrefPageTwo *m_pageTwo;
};

class KuirePrefPageOne : public QFrame
{
    Q_OBJECT
public:
    KuirePrefPageOne(QWidget *parent = 0);
};

class KuirePrefPageTwo : public QFrame
{
    Q_OBJECT
public:
    KuirePrefPageTwo(QWidget *parent = 0);
};

#endif // _KUIREPREF_H_
