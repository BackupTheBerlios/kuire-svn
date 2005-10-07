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
#include "editorsview.h"
#include <qvaluelist.h>
#include <qlayout.h>
#include <klocale.h>

editorsView::editorsView(KMdiChildView *child, KMdiMainFrm *parent)
 : QWidgetStack(child)
{
  chapterList.append(1);
  // set statusbar shortcut
  sbar = parent->statusBar();
  this->addWidget(new ChapterEditor(),1);
}


editorsView::~editorsView()
{
}

/****************************** saveStations *******************************/

void editorsView::saveText(QDomDocument* doc, QDomElement* data)
{
  QDomElement chapters_dom = doc->createElement( "chapters" );
  QDomElement chapter_element = doc->createElement( "chapter");
  data->appendChild( chapters_dom );
}

/****************************** openStations *******************************/

void editorsView::loadText( QDomElement* data )
{
  QDomNode node = data->firstChild();
  QDomElement stn = node.toElement();
}

bool editorsView::nextChapter()
{
  int activeWidget = id( this->visibleWidget() );
  QValueList<int>::iterator it;
  it = chapterList.find(activeWidget);
  it++;
  raiseWidget(*it);
  sbar->message( QString( "Chapter %1 active" ).arg( id( this->visibleWidget() ) ) );
  this->visibleWidget()->setFocus();
  return TRUE;
}

bool editorsView::prevChapter()
{
  int activeWidget = id( this->visibleWidget() );
  QValueList<int>::iterator it;
  it = chapterList.find(activeWidget);
  it--;
  raiseWidget(*it);
  sbar->message( QString( "Chapter %1 active" ).arg( id( this->visibleWidget() ) ) );
  this->visibleWidget()->setFocus();
  return TRUE;
}

bool editorsView::addChapter()
{
  int lastWidgetId = chapterList.last();
  lastWidgetId++;
  chapterList.append(lastWidgetId);
  this->addWidget(new ChapterEditor(),lastWidgetId);
  raiseWidget(lastWidgetId);
  sbar->message( QString( "Add Chapter %1" ).arg( id( this->visibleWidget() ) ) );
  this->visibleWidget()->setFocus();
  return TRUE;
}

bool editorsView::delChapter()
{
  if (chapterList.count() > 1) {
    int WidgetId = id( this->visibleWidget() );
    QValueList<int>::iterator it;
    it = chapterList.find(WidgetId);
    it = chapterList.remove(it);
    this->removeWidget( this->visibleWidget() ) ;
    if (it == chapterList.end()) { raiseWidget(chapterList.last()); }
    else { raiseWidget(*it); }
    sbar->message( QString( "Removed Chapter %1, active Widget now %1" ).arg( WidgetId ).arg( id( this->visibleWidget() ) ) );
  } else {
    sbar->message( QString( "Last Chapter can't be removed" ) );
  }
  this->visibleWidget()->setFocus();
  return TRUE;
}

