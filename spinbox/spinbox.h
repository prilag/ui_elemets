// -------------------------------------------------------------------------
/// @file spinbox.h
/// @author Gyula Pinter <gyula.pinter@yahoo.com>
/// @date 20.01.2018
/// @brief PSpinBox is an customization of QSpinBox
/// using string values
// -------------------------------------------------------------------------

#ifndef SPINBOX_H
#define SPINBOX_H

// -------------------------------------------------------------------------
#include <QSpinBox>
// -------------------------------------------------------------------------

class SpinBox : public QSpinBox
{
  Q_OBJECT

public:
  explicit SpinBox(QWidget *parent);

protected:
  QString textFromValue(int value) const;

private:
  QMap<int, QString> m_int2text_map;
};

#endif // SPINBOX_H
