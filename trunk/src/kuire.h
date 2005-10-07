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


#ifndef _KUIRE_H_
#define _KUIRE_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kmdimainfrm.h>

#include <editorsview.h>
#include <actorsview.h>

/**
 * @short Application Main Window
 * @author Carsten Nikiel <carsten@nikiel.de>
 * @version 0.1
 */
class kuire : public KMdiMainFrm
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    kuire();

    /**
     * Default Destructor
     */
    virtual ~kuire();

public slots:
    bool fileSave();                             // save current file
    bool fileOpen();                             // open previously saved file
    bool nextChapter();                          // go to the next Chapter
    bool prevChapter();                          // go to the previous Chapter
    bool addChapter();                          // add a new Chapter
    bool delChapter();                          // delete active Chapter

private:
  editorsView* texteditor;
  actorsView* actors;

};

#endif // _KUIRE_H_
