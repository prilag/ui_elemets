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
    m_prev = new QLabel("-", this);
    m_next = new QLabel("-", this);
    setButtonSymbols(QAbstractSpinBox::NoButtons);
    setAlignment(Qt::AlignCenter);
    m_prev->setAlignment(alignment());
    m_next->setAlignment(alignment());
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(changePrevNext(int)));
}

// -------------------------------------------------------------------------
SpinBox::SpinBox(QWidget *parent, const int min, const int max, const QString &suffix)
    : SpinBox(parent)
{
    setRange(min,max);
    setSuffix(suffix);
    changePrevNext(minimum());
}

// -------------------------------------------------------------------------
QString SpinBox::textFromValue(int value) const
{
    if(m_int2text_map.isEmpty())
    {
        return QString::number(value);
    }
    else
    {
        return m_int2text_map.key(value, "?");
    }
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
    if(m_int2text_map.isEmpty())
    {
        if ((value - 1) >= minimum())
        {
            m_prev->setText(QString::number(value - 1) + suffix());
        }
        else
        {
            m_prev->setText("-");
        }

        if ((value + 1) <= maximum())
        {
            m_next->setText(QString::number(value + 1) + suffix());
        }
        else
        {
            m_next->setText("-");
        }
    }
    else
    {
        m_prev->setText(m_int2text_map.key(value-1, "-"));
        m_next->setText(m_int2text_map.key(value+1, "-"));
    }
}
