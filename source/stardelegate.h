/* This class provides a delegate to style Month view dates
*/

#ifndef STARDELEGATE_H
#define STARDELEGATE_H

#include <QStyledItemDelegate>


class StarDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    StarDelegate(QWidget *parent = 0) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

};


#endif
