/***************************************************************************
    qgsmapstylepanel.cpp
    ---------------------
    begin                : June 2016
    copyright            : (C) 2016 by Nathan Woodrow
    email                : woodrow dot nathan at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "qgsmapstylepanel.h"

QgsMapStylePanel::QgsMapStylePanel( QgsMapLayer *layer, QgsMapCanvas *canvas, QWidget *parent )
    : QWidget( parent )
    , mLayer( layer )
    , mMapCanvas( canvas )
{

}

QgsMapStylePanelFactory::QgsMapStylePanelFactory()
{

}

QgsMapStylePanelFactory::~QgsMapStylePanelFactory()
{

}
