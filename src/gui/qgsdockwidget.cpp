/***************************************************************************
                             qgsdockwidget.cpp
                             -----------------
    begin                : June 2016
    copyright            : (C) 2016 by Nyall Dawson
    email                : nyall dot dawson at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "qgsdockwidget.h"


QgsDockWidget::QgsDockWidget( QWidget* parent )
    : QDockWidget( parent )
    , mVisibleAndActive( false )
{
  connect( this, SIGNAL( visibilityChanged( bool ) ), this, SLOT( handleVisibilityChanged( bool ) ) );
}

void QgsDockWidget::setUserVisible( bool visible )
{
  if ( visible )
  {
    if ( mVisibleAndActive )
      return;

    show();
    raise();
  }
  else
  {
    if ( !mVisibleAndActive )
      return;

    hide();
  }
}

bool QgsDockWidget::isUserVisible() const
{
  return mVisibleAndActive;
}

void QgsDockWidget::closeEvent( QCloseEvent* e )
{
  emit closed( true );
  emit opened( false );
  QDockWidget::closeEvent( e );
}

void QgsDockWidget::showEvent( QShowEvent* e )
{
  emit closed( false );
  emit opened( true );
  QDockWidget::showEvent( e );
}

void QgsDockWidget::handleVisibilityChanged( bool visible )
{
  mVisibleAndActive = visible;
}
