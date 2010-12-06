#include <QtGui>

#include "stardelegate.h"
#include "starrating.h"


void StarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (qVariantCanConvert<StarRating>(index.data())) {
        StarRating starRating = qVariantValue<StarRating>(index.data());

        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.highlight());

        starRating.paint(painter, option.rect, option.palette,
                         StarRating::ReadOnly);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }

}

