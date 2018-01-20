// -------------------------------------------------------------------------
/// @file spinbox.cpp
/// @author Gyula Pinter <gyula.pinter@yahoo.com>
/// @date 20.01.2018
/// @brief PSpinBox is an customization of QSpinBox
/// using string values
// -------------------------------------------------------------------------

#include "spinbox.h"
#include <QDebug>

// -------------------------------------------------------------------------
SpinBox::SpinBox(QWidget *parent) : QSpinBox(parent)
{
  setButtonSymbols(QAbstractSpinBox::PlusMinus);
  setReadOnly(false);
  //setFocusPolicy(Qt::NoFocus);
  setMinimum(0);
  setMaximum(4);
  m_int2text_map.insert(1,"first");
  m_int2text_map.insert(2,"second");
  m_int2text_map.insert(3,"third");
}

// -------------------------------------------------------------------------
QString SpinBox::textFromValue(int value) const
{
  return m_int2text_map.value(value, "?");
}



