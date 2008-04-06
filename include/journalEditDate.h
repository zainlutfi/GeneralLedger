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

#ifndef JOURNAL_EDIT_DATE_H
#define JOURNAL_EDIT_DATE_H

#include <qtable.h>
#include <qwidget.h>
#include <qdatetime.h>

class JournalEditDate : public QTableItem
{
    public:
        JournalEditDate(QTable *table, const QDate newDate);
        QWidget* createEditor() const;
        QString text() const;
        void setContentFromEditor(QWidget *widget);
        QDate date() const;

    private:
        QDate recordDate;
};

#endif
