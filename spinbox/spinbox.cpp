// -------------------------------------------------------------------------
/// @file spinbox.cpp
/// @author Gyula Pinter <gyula.pinter@yahoo.com>
/// @date 20.01.2018
/// @brief PSpinBox is an customization of QSpinBox
/// using string values
// -------------------------------------------------------------------------

#include "spinbox.h"
#include <QDebug>
#include <QPainter>
#include <QEvent>

// -------------------------------------------------------------------------
SpinBox::SpinBox(QWidget *parent) : QSpinBox(parent)
{
    setButtonSymbols(QAbstractSpinBox::NoButtons);
    m_int2text_map.insert(1,"first");
    m_int2text_map.insert(2,"second");
    m_int2text_map.insert(3,"third");
    setRange(1,3);
    m_prev = new QLabel("-",this);
    m_next = new QLabel("-",this);
    setAlignment(Qt::AlignCenter);
    m_prev->setAlignment(alignment());
    m_next->setAlignment(alignment());
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(changePrevNext(int)));
}

// -------------------------------------------------------------------------
QString SpinBox::textFromValue(int value) const
{
    return m_int2text_map.value(value, "?");
}

// -------------------------------------------------------------------------
void SpinBox::resizeEvent(QResizeEvent *event)
{
    QSpinBox::resizeEvent(event);
    m_prev->setGeometry(0,0,width(),height()/3);
    m_next->setGeometry(0,2*height()/3,width(),height()/3);
}

// -------------------------------------------------------------------------
void SpinBox::changePrevNext(int value)
{
    m_prev->setText(m_int2text_map.value(value-1, "-"));
    m_next->setText(m_int2text_map.value(value+1, "-"));
}
