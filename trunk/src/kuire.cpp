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


#include "kuire.h"

#include <kmdimainfrm.h>
#include <klocale.h>
#include <kstatusbar.h>
#include <kpopupmenu.h>
#include <kmenubar.h>
#include <kfiledialog.h>
#include <kuser.h>
#include <qdom.h>
#include <qdatetime.h>


kuire::kuire()
    : KMdiMainFrm( 0, "Kuire", KMdi::IDEAlMode )
{
    KPopupMenu *menuFile = new KPopupMenu( this );
    KPopupMenu *menuEdit = new KPopupMenu( this );
    KPopupMenu *menuChapter = new KPopupMenu( this );

    // add drop-down menus to main menu bar
    menuBar()->insertItem( "&File", menuFile );
    menuBar()->insertItem( "&Edit", menuEdit );
    menuBar()->insertItem( "&Chapter", menuChapter );
    menuBar()->insertItem( "&Help", helpMenu() );

    setToolviewStyle(3);

    // set the shell's ui resource file
    // setXMLFile("kuireui.rc");
    KMdiChildView *mainView = new KMdiChildView( i18n( "Mainview" ), this );
    ( new QHBoxLayout( mainView ) )->setAutoAdd( true );
    texteditor = new editorsView( mainView, this );
    addWindow( mainView );

    actors = new actorsView(this, "Actors");
    actors->setCaption( i18n( "Actors" ) );
    addToolWindow( actors, KDockWidget::DockRight, getMainDockWidget() );

    // Create another tool box
    QLabel *events = new QLabel( i18n( "Yet to implement, sorry!" ), this, "Events" );
    events->setCaption( i18n( "Events" ) );
    addToolWindow( events, KDockWidget::DockBottom, getMainDockWidget() );

    // Create another tool box
    QLabel *locations = new QLabel( i18n( "Yet to implement, sorry!" ), this, "Locations" );
    locations->setCaption( i18n( "Locations" ) );
    addToolWindow( locations, KDockWidget::DockBottom, getMainDockWidget() );

    statusBar()->message("Kuire has started.");  

    KAction *actionSave = KStdAction::save(this, SLOT(fileSave()), 0);
    KAction *actionOpen = KStdAction::open(this, SLOT(fileOpen()), 0);

    KAction *actionAddChapter  = new KAction( "&Add", ALT+Key_A, this, SLOT(addChapter()), this, "addChapter");
    KAction *actionDelChapter  = new KAction( "&Del", ALT+Key_D, this, SLOT(delChapter()), this, "delChapter");
    KAction *actionNextChapter  = new KAction( "Next", ALT+Key_Right, this, SLOT(nextChapter()), this, "nextChapter");
    KAction *actionPrevChapter  = new KAction( "Prev", ALT+Key_Left, this, SLOT(prevChapter()), this, "prevChapter");

    // add actions to File menu
    actionOpen->plug( menuFile );
    actionSave->plug( menuFile );

    actionAddChapter->plug( menuChapter );
    actionDelChapter->plug( menuChapter );
    actionNextChapter->plug( menuChapter );
    actionPrevChapter->plug( menuChapter );

}

kuire::~kuire()
{
}

/******************************** fileSave *********************************/

bool kuire::fileSave()
{
  // get user to select filename and location
  QString fileName = KFileDialog::getSaveFileName();
  if (fileName.isEmpty()) return false;

  // start the XML document
  QDomDocument doc( "Kuire" );

  // create the main data element and station elements
  QDomElement data = doc.createElement( "book" );
  doc.appendChild( data );
  texteditor->saveText( &doc, &data );

  // open the file and check we can write to it
  QFile file(fileName);
  if (!file.open(IO_WriteOnly))
  {
    statusBar()->message(QString("Failed to save '%1'").arg(fileName));
    return false;
  }

  // output the XML document as a text stream to the file
  QTextStream ts(&file);
  ts << doc.toString();
  file.close();
  statusBar()->message(QString("Saved to '%1'").arg(fileName));
  return true;
}


/******************************** fileOpen **********************************/

bool kuire::fileOpen()
{
  // get user to select filename and location
  QString fileName = KFileDialog::getOpenFileName();
  if (fileName.isEmpty()) return false;

  // create an empty XML document
  QDomDocument doc( "Kuire" );

  // open the file and check we can read from it
  QFile file(fileName);
  if (!file.open(IO_ReadOnly))
  {
    statusBar()->message(QString("Failed to open '%1'").arg(fileName));
    return false;
  }

  // read the XML document from the file
  if (!doc.setContent(&file))
  {
    file.close();
    statusBar()->message(QString("Failed to read '%1'").arg(fileName));
    return false;
  }
  file.close();

  // check the document type is correct
  if (doc.doctype().name() != "Kuire")
  {
    statusBar()->message(QString("Invalid '%1'").arg(fileName));
    return false;
  }

  // read the XML elements to create the stations
  QDomElement data = doc.documentElement();
  texteditor->loadText( &data );
  statusBar()->message(QString("Loaded '%1'").arg(fileName));
  return true;
}

bool kuire::nextChapter()
{
  return texteditor->nextChapter();
}

bool kuire::prevChapter()
{
  return texteditor->prevChapter();
}


bool kuire::addChapter()
{
  return texteditor->addChapter();
}

bool kuire::delChapter()
{
  return texteditor->delChapter();
}

#include "kuire.moc"
