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
#include <QLabel>
// -------------------------------------------------------------------------

class SpinBox : public QSpinBox
{
  Q_OBJECT

public:
    explicit SpinBox(QWidget *parent);
    SpinBox(QWidget *parent, const QMap<QString, int> &elements);
    SpinBox(QWidget *parent, const int min, const int max, const QString &suffix);

protected:
    QString textFromValue(int value) const;
    virtual void resizeEvent(QResizeEvent *event);

private:
    QMap<QString, int> m_int2text_map;
    QLabel *m_prev;
    QLabel *m_next;

private slots:
    void changePrevNext(int value);
};

#endif // SPINBOX_H
