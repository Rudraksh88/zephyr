/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 * Copyright 2014  Hugo Pereira Da Costa <hugo.pereira@free.fr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "breezebutton.h"

#include <KColorUtils>
#include <KDecoration2/DecoratedClient>
//#include <KIconLoader>

#include <QPainter>
#include <QPainterPath>
#include <QVariantAnimation>

namespace Breeze
{
    using KDecoration2::ColorGroup;
    using KDecoration2::ColorRole;
    using KDecoration2::DecorationButtonType;


    //__________________________________________________________________
    Button::Button(DecorationButtonType type, Decoration* decoration, QObject* parent)
        : DecorationButton(type, decoration, parent)
        , m_animation( new QVariantAnimation( this ) )
    {

        // setup animation
        // It is important start and end value are of the same type, hence 0.0 and not just 0
        m_animation->setStartValue( 0.0 );
        m_animation->setEndValue( 1.0 );
        m_animation->setEasingCurve( QEasingCurve::InOutQuad );
        connect(m_animation, &QVariantAnimation::valueChanged, this, [this](const QVariant &value) {
            setOpacity(value.toReal());
        });


        // setup default geometry
        const int height = decoration->buttonHeight();
        setGeometry(QRect(0, 0, height, height));
        setIconSize(QSize( height, height ));

        // connections
        connect(decoration->client(), SIGNAL(iconChanged(QIcon)), this, SLOT(update()));
        connect(decoration->settings().get(), &KDecoration2::DecorationSettings::reconfigured, this, &Button::reconfigure);
        connect( this, &KDecoration2::DecorationButton::hoveredChanged, this, &Button::updateAnimationState );

        reconfigure();

    }

    //__________________________________________________________________
    Button::Button(QObject *parent, const QVariantList &args)
        : Button(args.at(0).value<DecorationButtonType>(), args.at(1).value<Decoration*>(), parent)
    {
        m_flag = FlagStandalone;
        //! icon size must return to !valid because it was altered from the default constructor,
        //! in Standalone mode the button is not using the decoration metrics but its geometry
        m_iconSize = QSize(-1, -1);
    }

    //__________________________________________________________________
    Button *Button::create(DecorationButtonType type, KDecoration2::Decoration *decoration, QObject *parent)
    {
        if (auto d = qobject_cast<Decoration*>(decoration))
        {
            Button *b = new Button(type, d, parent);
            const auto c = d->client();
            switch( type )
            {

                case DecorationButtonType::Close:
                b->setVisible(c->isCloseable());
                QObject::connect(c, &KDecoration2::DecoratedClient::closeableChanged, b, &Breeze::Button::setVisible);
                break;

                case DecorationButtonType::Maximize:
                b->setVisible(c->isMaximizeable());
                QObject::connect(c, &KDecoration2::DecoratedClient::maximizeableChanged, b, &Breeze::Button::setVisible);
                break;

                case DecorationButtonType::Minimize:
                b->setVisible(c->isMinimizeable());
                QObject::connect(c, &KDecoration2::DecoratedClient::minimizeableChanged, b, &Breeze::Button::setVisible);
                break;

                case DecorationButtonType::ContextHelp:
                b->setVisible(c->providesContextHelp());
                QObject::connect(c, &KDecoration2::DecoratedClient::providesContextHelpChanged, b, &Breeze::Button::setVisible);
                break;

                case DecorationButtonType::Shade:
                b->setVisible(c->isShadeable());
                QObject::connect(c, &KDecoration2::DecoratedClient::shadeableChanged, b, &Breeze::Button::setVisible);
                break;

                case DecorationButtonType::Menu:
                QObject::connect(c, &KDecoration2::DecoratedClient::iconChanged, b, [b]() { b->update(); });
                break;

                default: break;

            }

            return b;
        }

        return nullptr;

    }

    //__________________________________________________________________
    void Button::paint(QPainter *painter, const QRect &repaintRegion)
    {
        Q_UNUSED(repaintRegion)

        if (!decoration()) return;

        painter->save();

        // translate from offset
        if( m_flag == FlagFirstInList ) painter->translate( m_offset );
        else painter->translate( 0, m_offset.y() );

        if( !m_iconSize.isValid() || isStandAlone() ) m_iconSize = geometry().size().toSize();

        // menu button
        if (type() == DecorationButtonType::Menu)
        {

            const QRectF iconRect( geometry().topLeft(), m_iconSize );
            const auto c = decoration()->client();
            /*if (auto deco =  qobject_cast<Decoration*>(decoration())) {
                const QPalette activePalette = KIconLoader::global()->customPalette();
                QPalette palette = c->palette();
                palette.setColor(QPalette::WindowText, deco->fontColor());
                KIconLoader::global()->setCustomPalette(palette);
                c->icon().paint(painter, iconRect.toRect());
                if (activePalette == QPalette()) {
                    KIconLoader::global()->resetPalette();
                }    else {
                    KIconLoader::global()->setCustomPalette(palette);
                }
            } else {*/
                c->icon().paint(painter, iconRect.toRect());
            //}


        } else {

            drawIcon( painter );

        }

        painter->restore();

    }

    //__________________________________________________________________
    void Button::drawIcon( QPainter *painter ) const
    {

        painter->setRenderHints( QPainter::Antialiasing );

        /*
        scale painter so that its window matches QRect( -1, -1, 20, 20 )
        this makes all further rendering and scaling simpler
        all further rendering is performed inside QRect( 0, 0, 18, 18 )
        */
        painter->translate( geometry().topLeft() );

        const qreal width( m_iconSize.width() );
        // painter->scale( width/21, width/21 );
        // painter->translate( 0, 0 );

        painter->scale( width/24, width/24 );
        painter->translate( 6, 7 );

        // render background
        const QColor backgroundColor( this->backgroundColor() );

        auto d = qobject_cast<Decoration*>( decoration() );
        bool isInactive(d && !d->client()->isActive()
                        && !isHovered() && !isPressed()
                        && m_animation->state() != QAbstractAnimation::Running);
        QColor inactiveCol(Qt::gray);
        if (isInactive)
        {
            int gray = qGray(d->titleBarColor().rgb());
            if (gray <= 200) {
                gray += 55;
                gray = qMax(gray, 115);
            }
            else gray -= 45;
            inactiveCol = QColor(gray, gray, gray);
        }

        // render mark
        const QColor foregroundColor( this->foregroundColor(inactiveCol) );
        if( foregroundColor.isValid() )
        {

            // setup painter
            QPen pen( foregroundColor );
            pen.setCapStyle( Qt::RoundCap );
            pen.setJoinStyle( Qt::MiterJoin );

            // setup pen width
            const double STROKE_WIDTH = 2;

            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );

            switch( type() )
            {

                case DecorationButtonType::Close:
                {
                    if (!d || d->internalSettings()->macOSButtons()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(255, 92, 87));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(233, 84, 79));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(250, 100, 102));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(230, 92, 94));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            qreal r = static_cast<qreal>(7)
                                      + (isPressed() ? 0.0
                                         : static_cast<qreal>(2) * m_animation->currentValue().toReal());
                            QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                            painter->drawEllipse( c, r, r );
                        }
                    }
                    else {
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( -5, -5, 28, 28 ) );
                        }
                        painter->setPen( pen );
                        if (isHovered())
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        painter->setBrush( Qt::NoBrush );

                        painter->drawLine( QPointF( 5, 5 ), QPointF( 13, 13 ) ); //
                        painter->drawLine( QPointF( 5, 13 ), QPointF( 13, 5 ) ); // /
                    }
                    break;
                }

                case DecorationButtonType::Maximize:
                {
                    if (!d || d->internalSettings()->macOSButtons()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        {
                            grad.setColorAt(0, isChecked() ? isInactive ? inactiveCol
                                                                        : QColor(67, 198, 176)
                                                           : isInactive ? inactiveCol
                                                                        : QColor(40, 211, 63));
                            grad.setColorAt(1, isChecked() ? isInactive ? inactiveCol
                                                                        : QColor(60, 178, 159)
                                                           : isInactive ? inactiveCol
                                                                        : QColor(36, 191, 57));
                        }
                        else
                        {
                            grad.setColorAt(0, isChecked() ? isInactive ? inactiveCol
                                                                        : QColor(67, 198, 176)
                                                           : isInactive ? inactiveCol
                                                                        : QColor(124, 198, 67));
                            grad.setColorAt(1, isChecked() ? isInactive ? inactiveCol
                                                                        : QColor(60, 178, 159)
                                                           : isInactive ? inactiveCol
                                                                        : QColor(111, 178, 60));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            qreal r = static_cast<qreal>(7)
                                      + (isPressed() ? 0.0
                                         : static_cast<qreal>(2) * m_animation->currentValue().toReal());
                            QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                            painter->drawEllipse( c, r, r );
                        }
                    }
                    else {
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( -5, -5, 28, 28 ) );
                        }

                        if (isHovered())
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        painter->setPen( pen );
                        pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        painter->setBrush( Qt::NoBrush );

                        // painter->drawPolyline(QPolygonF()
                        //                         << QPointF(5, 8) << QPointF(5, 13) << QPointF(10, 13));
                        // if (isChecked())
                        //     painter->drawRect(QRectF(8.0, 5.0, 5.0, 5.0));
                        // else {
                        //     painter->drawPolyline(QPolygonF()
                        //                           << QPointF(8, 5) << QPointF(13, 5) << QPointF(13, 10));
                        // }

                        // Just draw a square for now for maximize


                        if (isChecked()) {
                            painter->drawPolyline(QPolygonF()
                                                  << QPointF(8, 5) << QPointF(14, 5) << QPointF(14, 10));
                            painter->drawRect(QRectF(5.0, 7.0, 7.0, 7.0));
                        } else {
                            painter->drawRect(QRectF(5.0, 5.0, 8.0, 8.0));
                        }


                        if (isHovered())
                            pen.setWidthF( PenWidth::Symbol*qMax((qreal)1.0, 20/width ) );
                    }
                    break;
                }

                case DecorationButtonType::Minimize:
                {
                    if (!d || d->internalSettings()->macOSButtons()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(243, 176, 43));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(223, 162, 39));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(237, 198, 81));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(217, 181, 74));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            qreal r = static_cast<qreal>(7)
                                      + (isPressed() ? 0.0
                                         : static_cast<qreal>(2) * m_animation->currentValue().toReal());
                            QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                            painter->drawEllipse( c, r, r );
                        }
                    }
                    else {
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( -5, -5, 28, 28 ) );
                        }

                        if (isHovered())
                            pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        painter->setPen( pen );
                        pen.setWidthF( STROKE_WIDTH*qMax((qreal)1.0, 20/width ) );
                        painter->setBrush( Qt::NoBrush );

                        // painter->drawLine( QPointF( 4, 9 ), QPointF( 14, 9 ) );

                        // Draw a line at the base of the maximize square
                        painter->drawLine( QPointF( 4, 13 ), QPointF( 13, 13 ) );

                        if (isHovered())
                            pen.setWidthF( PenWidth::Symbol*qMax((qreal)1.0, 20/width ) );
                    }
                    break;
                }

                case DecorationButtonType::OnAllDesktops:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(103, 149, 210));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(93, 135, 190));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(135, 166, 220));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(122, 151, 200));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        if (isChecked())
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        else {
                            painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                            if( backgroundColor.isValid() )
                            {
                                painter->setPen( Qt::NoPen );
                                painter->setBrush( backgroundColor );
                                qreal r = static_cast<qreal>(7)
                                          + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                                QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                                painter->drawEllipse( c, r, r );
                            }
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered() || isChecked()) {
                        painter->setPen( Qt::NoPen );
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setBrush( foregroundColor );

                        if (macOSBtn)
                            painter->drawEllipse( QRectF( 6, 6, 6, 6 ) );
                        else {
                            if( isChecked()) {

                                // outer ring
                                painter->drawEllipse( QRectF( 3, 3, 12, 12 ) );

                                // center dot
                                QColor backgroundColor( this->backgroundColor() );
                                if( !backgroundColor.isValid() && d ) backgroundColor = d->titleBarColor();

                                if( backgroundColor.isValid() )
                                {
                                    painter->setBrush( backgroundColor );
                                    painter->drawEllipse( QRectF( 8, 8, 2, 2 ) );
                                }

                            } else {

                                painter->drawPolygon( QPolygonF()
                                    << QPointF( 6.5, 8.5 )
                                    << QPointF( 12, 3 )
                                    << QPointF( 15, 6 )
                                    << QPointF( 9.5, 11.5 ) );

                                painter->setPen( pen );
                                painter->drawLine( QPointF( 5.5, 7.5 ), QPointF( 10.5, 12.5 ) );
                                painter->drawLine( QPointF( 12, 6 ), QPointF( 4.5, 13.5 ) );
                            }
                        }
                    }
                    break;
                }

                case DecorationButtonType::Shade:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(103, 149, 210));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(93, 135, 190));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(135, 166, 220));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(122, 151, 200));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        if (isChecked())
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        else {
                            painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                            if( backgroundColor.isValid() )
                            {
                                painter->setPen( Qt::NoPen );
                                painter->setBrush( backgroundColor );
                                qreal r = static_cast<qreal>(7)
                                          + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                                QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                                painter->drawEllipse( c, r, r );
                            }
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered() || isChecked()) {
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setPen( pen );
                        painter->setBrush( Qt::NoBrush );

                        painter->drawLine( 5, 6, 13, 6 );
                        if (isChecked()) {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 9 )
                                << QPointF( 9, 13 )
                                << QPointF( 13, 9 ) );

                        } else {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 13 )
                                << QPointF( 9, 9 )
                                << QPointF( 13, 13 ) );
                        }
                    }

                    break;

                }

                case DecorationButtonType::KeepBelow:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons() || isChecked());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(103, 149, 210));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(93, 135, 190));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(135, 166, 220));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(122, 151, 200));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        if (isChecked())
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        else {
                            painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                            if( backgroundColor.isValid() )
                            {
                                painter->setPen( Qt::NoPen );
                                painter->setBrush( backgroundColor );
                                qreal r = static_cast<qreal>(7)
                                          + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                                QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                                painter->drawEllipse( c, r, r );
                            }
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered() || isChecked()) {
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setPen( pen );
                        painter->setBrush( Qt::NoBrush );

                        if (macOSBtn) {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 6, 6 )
                                << QPointF( 9, 9 )
                                << QPointF( 12, 6 ) );

                            painter->drawPolyline( QPolygonF()
                                << QPointF( 6, 10 )
                                << QPointF( 9, 13 )
                                << QPointF( 12, 10 ) );
                        }
                        else {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 5 )
                                << QPointF( 9, 9 )
                                << QPointF( 13, 5 ) );

                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 9 )
                                << QPointF( 9, 13 )
                                << QPointF( 13, 9 ) );
                        }
                    }
                    break;

                }

                case DecorationButtonType::KeepAbove:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(103, 149, 210));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(93, 135, 190));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(135, 166, 220));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(122, 151, 200));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        if (isChecked())
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        else {
                            painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                            if( backgroundColor.isValid() )
                            {
                                painter->setPen( Qt::NoPen );
                                painter->setBrush( backgroundColor );
                                qreal r = static_cast<qreal>(7)
                                          + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                                QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                                painter->drawEllipse( c, r, r );
                            }
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered() || isChecked()) {
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setPen( pen );
                        painter->setBrush( Qt::NoBrush );

                        if (macOSBtn) {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 6, 8 )
                                << QPointF( 9, 5 )
                                << QPointF( 12, 8 ) );

                            painter->drawPolyline( QPolygonF()
                                << QPointF( 6, 12 )
                                << QPointF( 9, 9 )
                                << QPointF( 12, 12 ) );
                        }
                        else {
                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 9 )
                                << QPointF( 9, 5 )
                                << QPointF( 13, 9 ) );

                            painter->drawPolyline( QPolygonF()
                                << QPointF( 5, 13 )
                                << QPointF( 9, 9 )
                                << QPointF( 13, 13 ) );
                        }
                    }
                    break;
                }


                case DecorationButtonType::ApplicationMenu:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(230, 129, 67));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(210, 118, 61));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(250, 145, 100));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(230, 131, 92));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            qreal r = static_cast<qreal>(7)
                                      + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                            QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                            painter->drawEllipse( c, r, r );
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered()) {
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setPen( pen );
                        painter->setBrush( Qt::NoBrush );

                        if (macOSBtn) {
                            painter->drawLine( QPointF( 4.5, 6 ), QPointF( 13.5, 6 ) );
                            painter->drawLine( QPointF( 4.5, 9 ), QPointF( 13.5, 9 ) );
                            painter->drawLine( QPointF( 4.5, 12 ), QPointF( 13.5, 12 ) );
                        }
                        else {
                            painter->drawLine( QPointF( 3.5, 5 ), QPointF( 14.5, 5 ) );
                            painter->drawLine( QPointF( 3.5, 9 ), QPointF( 14.5, 9 ) );
                            painter->drawLine( QPointF( 3.5, 13 ), QPointF( 14.5, 13 ) );
                        }
                    }
                    break;
                }

                case DecorationButtonType::ContextHelp:
                {
                    bool macOSBtn(!d || d->internalSettings()->macOSButtons());
                    if (macOSBtn && !isPressed()) {
                        QLinearGradient grad(QPointF(9, 2), QPointF(9, 16));
                        if (d && qGray(d->titleBarColor().rgb()) > 100)
                        { // yellow isn't good with light backgrounds
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(103, 149, 210));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(93, 135, 190));
                        }
                        else
                        {
                            grad.setColorAt(0, isInactive ? inactiveCol
                                                          : QColor(135, 166, 220));
                            grad.setColorAt(1, isInactive ? inactiveCol
                                                          : QColor(122, 151, 200));
                        }
                        painter->setBrush( QBrush(grad) );
                        painter->setPen( Qt::NoPen );
                        painter->drawEllipse( QRectF( 2, 2, 14, 14 ) );
                        if( backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            qreal r = static_cast<qreal>(7)
                                      + static_cast<qreal>(2) * m_animation->currentValue().toReal();
                            QPointF c(static_cast<qreal>(9), static_cast<qreal>(9));
                            painter->drawEllipse( c, r, r );
                        }
                    }
                    if (!macOSBtn || isPressed() || isHovered()) {
                        if( (!macOSBtn  || isPressed()) && backgroundColor.isValid() )
                        {
                            painter->setPen( Qt::NoPen );
                            painter->setBrush( backgroundColor );
                            painter->drawEllipse( QRectF( 0, 0, 18, 18 ) );
                        }
                        painter->setPen( pen );
                        painter->setBrush( Qt::NoBrush );

                        QPainterPath path;
                        path.moveTo( 5, 6 );
                        path.arcTo( QRectF( 5, 3.5, 8, 5 ), 180, -180 );
                        path.cubicTo( QPointF(12.5, 9.5), QPointF( 9, 7.5 ), QPointF( 9, 11.5 ) );
                        painter->drawPath( path );

                        painter->drawPoint( 9, 15 );
                    }

                    break;
                }

                default: break;

            }

        }

    }

    //__________________________________________________________________
    QColor Button::foregroundColor(const QColor& inactiveCol) const
    {
        auto d = qobject_cast<Decoration*>( decoration() );
        if(!d || d->internalSettings()->macOSButtons()) {
            QColor col;
            if (d && !d->client()->isActive()
                && !isHovered() && !isPressed()
                && m_animation->state() != QAbstractAnimation::Running)
            {
                int v = qGray(inactiveCol.rgb());
                if (v > 127) v = 200;
                else v = 200;
                col = QColor(v, v, v);
            }
            else
            {
                if (d && qGray(d->titleBarColor().rgb()) > 100)
                    col = QColor(200, 200, 200);
                else
                    col = QColor(200, 200, 200);
            }
            return col;
        }
        else if( !d ) {
            // Make colors white no matter what
            return QColor(200, 200, 200);

        } else if( isPressed() ) {

            // return d->titleBarColor();
            return QColor(200, 200, 200);

        /*} else if( type() == DecorationButtonType::Close && d->internalSettings()->outlineCloseButton() ) {

            return d->titleBarColor();*/

        } else if( ( type() == DecorationButtonType::KeepBelow || type() == DecorationButtonType::KeepAbove ) && isChecked() ) {

            // return d->titleBarColor();
            return QColor(200, 200, 200);

        } else if( m_animation->state() == QAbstractAnimation::Running ) {

            // return KColorUtils::mix( d->fontColor(), d->titleBarColor(), m_opacity );
            return QColor(200, 200, 200);

        } else if( isHovered() ) {

            // return d->titleBarColor();
            return QColor(200, 200, 200);

        } else {

            // return d->fontColor();
            return QColor(200, 200, 200);
        }

    }

    //__________________________________________________________________
    QColor Button::backgroundColor() const
    {
        auto d = qobject_cast<Decoration*>( decoration() );
        if( !d ) {

            return QColor();

        }

        if (d->internalSettings()->macOSButtons()) {
            if( isPressed() ) {

                QColor col;
                if( type() == DecorationButtonType::Close )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(254, 73, 66);
                    else
                        col = QColor(240, 77, 80);
                }
                else if( type() == DecorationButtonType::Maximize)
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = isChecked() ? QColor(0, 188, 154) : QColor(7, 201, 33);
                    else
                        col = isChecked() ? QColor(0, 188, 154) : QColor(101, 188, 34);
                }
                else if( type() == DecorationButtonType::Minimize )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(233, 160, 13);
                    else
                        col = QColor(227, 185, 59);
                }
                else if( type() == DecorationButtonType::ApplicationMenu ) {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(220, 124, 64);
                    else
                        col = QColor(240, 139, 96);
                }
                else {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(83, 121, 170);
                    else
                        col = QColor(110, 136, 180);
                }
                if (col.isValid())
                    return col;
                else return KColorUtils::mix( d->titleBarColor(), d->fontColor(), 0.3 );

            } else if( m_animation->state() == QAbstractAnimation::Running ) {

                QColor col;
                if( type() == DecorationButtonType::Close )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(254, 95, 87);
                    else
                        col = QColor(240, 96, 97);
                }
                else if( type() == DecorationButtonType::Maximize)
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = isChecked() ? QColor(64, 188, 168) : QColor(39, 201, 63);
                    else
                        col = isChecked() ? QColor(64, 188, 168) : QColor(116, 188, 64);
                }
                else if( type() == DecorationButtonType::Minimize )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(233, 172, 41);
                    else
                        col = QColor(227, 191, 78);
                }
                else if( type() == DecorationButtonType::ApplicationMenu ) {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(220, 124, 64);
                    else
                        col = QColor(240, 139, 96);
                }
                else {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(98, 141, 200);
                    else
                        col = QColor(128, 157, 210);
                }
                if (col.isValid())
                    return col;
                else {

                    col = d->fontColor();
                    col.setAlpha( col.alpha()*m_opacity );
                    return col;

                }

            } else if( isHovered() ) {

                QColor col;
                if( type() == DecorationButtonType::Close )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(254, 95, 87);
                    else
                        col = QColor(240, 96, 97);
                }
                else if( type() == DecorationButtonType::Maximize)
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = isChecked() ? QColor(64, 188, 168) : QColor(39, 201, 63);
                    else
                        col = isChecked() ? QColor(64, 188, 168) : QColor(116, 188, 64);
                }
                else if( type() == DecorationButtonType::Minimize )
                {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(233, 172, 41);
                    else
                        col = QColor(227, 191, 78);
                }
                else if( type() == DecorationButtonType::ApplicationMenu ) {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(220, 124, 64);
                    else
                        col = QColor(240, 139, 96);
                }
                else {
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(98, 141, 200);
                    else
                        col = QColor(128, 157, 210);
                }
                if (col.isValid())
                    return col;
                else return d->fontColor();

            } else {

                return QColor();

            }
        }
        else {
            auto c = d->client();
            if( isPressed() ) {

                // if( type() == DecorationButtonType::Close ) return c->color( ColorGroup::Warning, ColorRole::Foreground );
                if( type() == DecorationButtonType::Close ) return QColor(123, 48, 56);
                else
                {
                    QColor col;
                    // If the titlebar is light, the button should be dark
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(255, 255, 255, 65); // This is the color of the button when it is pressed
                    // If the titlebar is dark, the button should be light
                    else
                        col = QColor(64,64,64); // This is the color of the button when it is pressed
                    return col;
                }

            } else if( ( type() == DecorationButtonType::KeepBelow || type() == DecorationButtonType::KeepAbove ) && isChecked() ) {

                    QColor col;
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(255, 255, 255, 180);
                    else
                        // col = QColor(255, 255, 255, 180);
                        col = QColor(64,64,64);
                    return col;

            } else if( m_animation->state() == QAbstractAnimation::Running ) {

                if( type() == DecorationButtonType::Close )
                {

                    // QColor color( c->color( ColorGroup::Warning, ColorRole::Foreground ) );
                    QColor color(123, 48, 56);
                    color.setAlpha( color.alpha()*m_opacity );
                    return color;

                } else {

                    QColor col;
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(0, 0, 0, 165);
                    else
                        col = QColor(64,64,64);
                    col.setAlpha( col.alpha()*m_opacity );
                    return col;

                }

            } else if( isHovered() ) {

                // if( type() == DecorationButtonType::Close ) return c->color( ColorGroup::Warning, ColorRole::Foreground );
                if( type() == DecorationButtonType::Close ) return QColor(123, 48, 56);
                else
                {

                    QColor col;

                    // If the titlebar is light, the button should be dark
                    if (qGray(d->titleBarColor().rgb()) > 100)
                        col = QColor(0, 0, 0, 165); // This is the color of the button when it is hovered

                    // If the titlebar is dark, the button should be light
                    else
                        col = QColor(64,64,64); // This is the color of the button when it is hovered
                    return col;

                }

            } else {

                return QColor();
                // return QColor(64,64,64); // Gives permanent color to the button

            }
        }

    }

    //________________________________________________________________
    void Button::reconfigure()
    {

        // animation
        auto d = qobject_cast<Decoration*>(decoration());
        if( d )  m_animation->setDuration( d->internalSettings()->animationsDuration() );

    }

    //__________________________________________________________________
    void Button::updateAnimationState( bool hovered )
    {

        auto d = qobject_cast<Decoration*>(decoration());
        if( !(d && d->internalSettings()->animationsEnabled() ) ) return;

        QAbstractAnimation::Direction dir = hovered ? QAbstractAnimation::Forward : QAbstractAnimation::Backward;
        if( m_animation->state() == QAbstractAnimation::Running && m_animation->direction() != dir )
            m_animation->stop();
        m_animation->setDirection( dir );
        if( m_animation->state() != QAbstractAnimation::Running ) m_animation->start();

    }

} // namespace
