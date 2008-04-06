/* General Ledger, Copyright (C) 2004  Joshua Eckroth <josh@eckroth.net>
 * http://www.eckroth.net/software/genledg
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  US
*/

#include <qhbox.h>
#include <qlabel.h>
#include <qpixmap.h>
#include <qcursor.h>

#include "config.h"
#include "globalGoBackLabel.h"

GlobalGoBackLabel::GlobalGoBackLabel(QWidget *parent, const char *name)
    : QHBox(parent,name)
{
    icon = new QLabel(this);
    icon->setPixmap( QPixmap::fromMimeSource(ICON_PATH + "/back.png") );
    label = new QLabel(" Back (ESC)", this);
    setCursor(Qt::PointingHandCursor);
}

void GlobalGoBackLabel::mousePressEvent(QMouseEvent*)
{
    emit goBack();
}

