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

#ifndef JOURNAL_EDIT_ACCOUNT_LIST_H
#define JOURNAL_EDIT_ACCOUNT_LIST_H

#include <qcombobox.h>

class QStringList;
class QFocusEvent;
class QListBox;
class QLineEdit;
class QEvent;

class JournalEditAccountList : public QComboBox
{
    Q_OBJECT
    public:
        JournalEditAccountList(QWidget *parent, const QStringList newAccounts, const QString newText);
        QString currentText() const;
        void focusInEvent(QFocusEvent *event);
        void focusOutEvent(QFocusEvent *event);
        
    private slots:
        void changed(const QString&);
        
    private:
        QStringList accounts;
        QString curText;
        QListBox *list;
        QLineEdit *editor;
};

#endif

