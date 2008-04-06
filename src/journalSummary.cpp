#include <qwidget.h>
#include <qlayout.h>
#include <qlabel.h>

#include "journalSummary.h"
#include "journalTable.h"

JournalSummary::JournalSummary(QWidget *parent, const char *name, JournalTable *table)
    : QWidget(parent,name)
{
    int debitColWidth = table->debitColWidth();
    int creditColWidth = table->creditColWidth();
    int scrollBarWidth = (table->verticalScrollBar()->width() + 5);
    
    grid = new QGridLayout(this, 3, 5);
    
    debitLabel = new QLabel("Debit:", this);
    debitLabel->setAlignment(Qt::AlignRight);
    
    debitValue = new QLabel(tr("<tt>37263.34</tt>"), this);
    debitValue->setMaximumWidth(debitColWidth);
    debitValue->setMinimumWidth(debitColWidth);
    debitValue->setAlignment(Qt::AlignRight);
    
    creditLabel = new QLabel("Credit:", this);
    creditLabel->setAlignment(Qt::AlignRight);
    
    creditValue = new QLabel(tr("<tt>111.31</tt>"), this);
    creditValue->setMaximumWidth(creditColWidth);
    creditValue->setMinimumWidth(creditColWidth);
    creditValue->setAlignment(Qt::AlignRight);
    
    balanceLabel = new QLabel(tr("<b>Balance:</b>"), this);
    balanceLabel->setAlignment(Qt::AlignRight);
    
    balanceValue = new QLabel(tr("<b><tt>234.23</tt></b>"), this);
    balanceValue->setAlignment(Qt::AlignRight);
    
    debitWidth = new QSpacerItem(debitColWidth, 1);
    creditWidth = new QSpacerItem(creditColWidth, 1);
    scrollWidth = new QSpacerItem(scrollBarWidth, 1);
    
    grid->setColStretch(0, 1);
    
    grid->addWidget(debitLabel, 0, 1);
    grid->addWidget(debitValue, 0, 2);
    grid->addItem(creditWidth, 0, 3);
    
    grid->addItem(scrollWidth, 0, 4);
    
    grid->addWidget(creditLabel, 1, 1);
    grid->addItem(debitWidth, 1, 2);
    grid->addWidget(creditValue, 1, 3);
    
    grid->addWidget(balanceLabel, 2, 1);
    grid->addItem(debitWidth, 2, 2);
    grid->addWidget(balanceValue, 2, 3);
    
}

JournalSummary::~JournalSummary()
{
    grid->removeItem(scrollWidth);
    delete scrollWidth;
    grid->removeItem(creditWidth);
    delete creditWidth;
    grid->removeItem(debitWidth);
    delete debitWidth;
    grid->remove(balanceValue);
    delete balanceValue;
    grid->remove(balanceLabel);
    delete balanceLabel;
    grid->remove(creditValue);
    delete creditValue;
    grid->remove(creditLabel);
    delete creditLabel;
    grid->remove(debitValue);
    delete debitValue;
    grid->remove(debitLabel);
    delete debitLabel;
    delete grid;
}



