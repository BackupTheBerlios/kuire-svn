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
#ifndef EDITORSVIEW_H
#define EDITORSVIEW_H

#include <chaptereditor.h>
#include <kmdimainfrm.h>
#include <kstatusbar.h>
#include <qwidgetstack.h>
#include <qvaluelist.h>

/**
@author Carsten Nikiel
*/
class editorsView : public QWidgetStack
{
public:
    editorsView(KMdiChildView *child, KMdiMainFrm *parent);

    ~editorsView();

    void saveText( QDomDocument*, QDomElement* );    // save Text to XML document
    void loadText( QDomElement* );                   // create Text from XML
    bool nextChapter();
    bool prevChapter();
    bool addChapter();
    bool delChapter();

private:
  KStatusBar* sbar;                       // shortcut to Kuires statusbar
  QValueList<int> chapterList;
};

#endif
