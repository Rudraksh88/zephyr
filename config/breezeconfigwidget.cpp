//////////////////////////////////////////////////////////////////////////////
// breezeconfigurationui.cpp
// -------------------
//
// Copyright (c) 2009 Hugo Pereira Da Costa <hugo.pereira@free.fr>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//////////////////////////////////////////////////////////////////////////////

#include "breezeconfigwidget.h"
#include "breezeexceptionlist.h"

#include <KLocalizedString>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QFontDatabase>

namespace Breeze
{

    //_________________________________________________________
    ConfigWidget::ConfigWidget(QObject *parent, const KPluginMetaData &data, const QVariantList & /*args*/):
        KCModule(parent, data),
        m_configuration( KSharedConfig::openConfig( QStringLiteral( "breezerc" ) ) ),
        m_changed( false )
    {

        // configuration
        m_ui.setupUi(widget());

        // track ui changes
        connect( m_ui.titleAlignment, SIGNAL(currentIndexChanged(int)), SLOT(updateChanged()) );
        connect( m_ui.buttonSize, SIGNAL(currentIndexChanged(int)), SLOT(updateChanged()) );
        connect( m_ui.titleMarginSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int /*i*/){updateChanged();} );
        connect( m_ui.btnSpacingSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int /*i*/){updateChanged();} );
        connect( m_ui.drawBackgroundGradient, &QAbstractButton::clicked, this, &ConfigWidget::updateChanged );
        connect( m_ui.macOSButtons, SIGNAL(clicked()), SLOT(updateChanged()) );
        connect( m_ui.opacitySpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int /*i*/){updateChanged();} );
        connect( m_ui.gradientSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int /*i*/){updateChanged();} );

        connect( m_ui.fontComboBox, &QFontComboBox::currentFontChanged, [this] { updateChanged(); } );
        connect( m_ui.fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int /*i*/){updateChanged();} );
        connect(m_ui.weightComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [this] { updateChanged(); } );
        connect( m_ui.italicCheckBox, &QCheckBox::stateChanged, [this] { updateChanged(); } );

        // track animations changes
        connect( m_ui.animationsEnabled, &QAbstractButton::clicked, this, &ConfigWidget::updateChanged );
        connect( m_ui.animationsDuration, SIGNAL(valueChanged(int)), SLOT(updateChanged()) );

        // track shadows changes
        connect( m_ui.shadowSize, SIGNAL(currentIndexChanged(int)), SLOT(updateChanged()) );
        connect( m_ui.shadowStrength, SIGNAL(valueChanged(int)), SLOT(updateChanged()) );
        connect( m_ui.shadowColor, &KColorButton::changed, this, &ConfigWidget::updateChanged );

        // track exception changes
        connect( m_ui.exceptions, &ExceptionListWidget::changed, this, &ConfigWidget::updateChanged );

    }

    //_________________________________________________________
    void ConfigWidget::load()
    {

        // create internal settings and load from rc files
        m_internalSettings = InternalSettingsPtr( new InternalSettings() );
        m_internalSettings->load();

        // assign to ui
        m_ui.titleAlignment->setCurrentIndex( m_internalSettings->titleAlignment() );
        m_ui.buttonSize->setCurrentIndex( m_internalSettings->buttonSize() );
        m_ui.titleMarginSpinBox->setValue( m_internalSettings->extraTitleMargin() );
        m_ui.btnSpacingSpinBox->setValue( m_internalSettings->buttonSpacing() );
        m_ui.drawBackgroundGradient->setChecked( m_internalSettings->drawBackgroundGradient() );
        m_ui.animationsEnabled->setChecked( m_internalSettings->animationsEnabled() );
        m_ui.animationsDuration->setValue( m_internalSettings->animationsDuration() );
        m_ui.macOSButtons->setChecked( m_internalSettings->macOSButtons() );
        m_ui.opacitySpinBox->setValue( m_internalSettings->backgroundOpacity() );
        m_ui.gradientSpinBox->setValue( m_internalSettings->backgroundGradientIntensity() );

        QString fontStr = m_internalSettings->titleBarFont();
        if (fontStr.isEmpty())
            fontStr = QLatin1String("Sans,11,-1,5,50,0,0,0,0,0");
        QFont f; f.fromString( fontStr );
        m_ui.fontComboBox->setCurrentFont( f );
        m_ui.fontSizeSpinBox->setValue( f.pointSize() );
        int w = f.weight();
        switch (w) {
            case QFont::Medium:
                m_ui.weightComboBox->setCurrentIndex(1);
                break;
            case QFont::DemiBold:
                m_ui.weightComboBox->setCurrentIndex(2);
                break;
            case QFont::Bold:
                m_ui.weightComboBox->setCurrentIndex(3);
                break;
            case QFont::ExtraBold:
                m_ui.weightComboBox->setCurrentIndex(4);
                break;
            case QFont::Black:
                m_ui.weightComboBox->setCurrentIndex(5);
                break;
            default:
                m_ui.weightComboBox->setCurrentIndex(0);
                break;
        }
        m_ui.italicCheckBox->setChecked( f.italic() );

        // load shadows
        if( m_internalSettings->shadowSize() <= InternalSettings::ShadowVeryLarge )
            m_ui.shadowSize->setCurrentIndex(m_internalSettings->shadowSize());
        else
            m_ui.shadowSize->setCurrentIndex(InternalSettings::ShadowLarge);

        m_ui.shadowStrength->setValue( qRound(qreal(m_internalSettings->shadowStrength()*100)/255 ) );
        m_ui.shadowColor->setColor( m_internalSettings->shadowColor() );

        // load exceptions
        ExceptionList exceptions;
        exceptions.readConfig( m_configuration );
        m_ui.exceptions->setExceptions( exceptions.get() );
        setNeedsSave(false);

    }

    //_________________________________________________________
    void ConfigWidget::save()
    {

        // create internal settings and load from rc files
        m_internalSettings = InternalSettingsPtr( new InternalSettings() );
        m_internalSettings->load();

        // apply modifications from ui
        m_internalSettings->setTitleAlignment( m_ui.titleAlignment->currentIndex() );
        m_internalSettings->setButtonSize( m_ui.buttonSize->currentIndex() );
        m_internalSettings->setExtraTitleMargin( m_ui.titleMarginSpinBox->value() );
        m_internalSettings->setButtonSpacing( m_ui.btnSpacingSpinBox->value() );
        m_internalSettings->setDrawBackgroundGradient( m_ui.drawBackgroundGradient->isChecked() );
        m_internalSettings->setAnimationsEnabled( m_ui.animationsEnabled->isChecked() );
        m_internalSettings->setAnimationsDuration( m_ui.animationsDuration->value() );
        m_internalSettings->setMacOSButtons(m_ui.macOSButtons->isChecked());
        m_internalSettings->setBackgroundOpacity(m_ui.opacitySpinBox->value());
        m_internalSettings->setBackgroundGradientIntensity(m_ui.gradientSpinBox->value());

        QFont f = m_ui.fontComboBox->currentFont();
        f.setPointSize(m_ui.fontSizeSpinBox->value());
        int indx = m_ui.weightComboBox->currentIndex();
        switch (indx) {
            case 1:
                f.setWeight(QFont::Medium);
                break;
            case 2:
                f.setWeight(QFont::DemiBold);
                break;
            case 3:
                f.setWeight(QFont::Bold);
                break;
            case 4:
                f.setWeight(QFont::ExtraBold);
                break;
            case 5:
                f.setWeight(QFont::Black);
                break;
            default:
                f.setBold(false);
                break;
        }
        f.setItalic(m_ui.italicCheckBox->isChecked());
        m_internalSettings->setTitleBarFont(f.toString());

        m_internalSettings->setShadowSize( m_ui.shadowSize->currentIndex() );
        m_internalSettings->setShadowStrength( qRound( qreal(m_ui.shadowStrength->value()*255)/100 ) );
        m_internalSettings->setShadowColor( m_ui.shadowColor->color() );

        // save configuration
        m_internalSettings->save();

        // get list of exceptions and write
        InternalSettingsList exceptions( m_ui.exceptions->exceptions() );
        ExceptionList( exceptions ).writeConfig( m_configuration );

        // sync configuration
        m_configuration->sync();
        setNeedsSave(false);

        // needed to tell kwin to reload when running from external kcmshell
        {
            QDBusMessage message = QDBusMessage::createSignal(QStringLiteral("/KWin"),
                                                              QStringLiteral("org.kde.KWin"),
                                                              QStringLiteral("reloadConfig"));
            QDBusConnection::sessionBus().send(message);
        }

        // needed for breeze style to reload shadows
        {
            QDBusMessage message(QDBusMessage::createSignal(QStringLiteral("/BreezeDecoration"),
                                                            QStringLiteral("org.kde.Breeze.Style"),
                                                            QStringLiteral("reparseConfiguration")));
            QDBusConnection::sessionBus().send(message);
        }

    }

    //_________________________________________________________
    void ConfigWidget::defaults()
    {

        // create internal settings and load from rc files
        m_internalSettings = InternalSettingsPtr( new InternalSettings() );
        m_internalSettings->setDefaults();

        // assign to ui
        m_ui.titleAlignment->setCurrentIndex( m_internalSettings->titleAlignment() );
        m_ui.buttonSize->setCurrentIndex( m_internalSettings->buttonSize() );
        m_ui.titleMarginSpinBox->setValue( m_internalSettings->extraTitleMargin() );
        m_ui.btnSpacingSpinBox->setValue( m_internalSettings->buttonSpacing() );
        m_ui.drawBackgroundGradient->setChecked( m_internalSettings->drawBackgroundGradient() );
        m_ui.animationsEnabled->setChecked( m_internalSettings->animationsEnabled() );
        m_ui.animationsDuration->setValue( m_internalSettings->animationsDuration() );
        m_ui.macOSButtons->setChecked( m_internalSettings->macOSButtons() );
        m_ui.opacitySpinBox->setValue( m_internalSettings->backgroundOpacity() );
        m_ui.gradientSpinBox->setValue( m_internalSettings->backgroundGradientIntensity() );

        QFont f; f.fromString(QStringLiteral("Sans,11,-1,5,400,0,0,0,0,0,0,0,0,0,0,1"));
        m_ui.fontComboBox->setCurrentFont( f );
        m_ui.fontSizeSpinBox->setValue( f.pointSize() );
        int w = f.weight();
        switch (w) {
            case QFont::Medium:
                m_ui.weightComboBox->setCurrentIndex(1);
                break;
            case QFont::DemiBold:
                m_ui.weightComboBox->setCurrentIndex(2);
                break;
            case QFont::Bold:
                m_ui.weightComboBox->setCurrentIndex(3);
                break;
            case QFont::ExtraBold:
                m_ui.weightComboBox->setCurrentIndex(4);
                break;
            case QFont::Black:
                m_ui.weightComboBox->setCurrentIndex(5);
                break;
            default:
                m_ui.weightComboBox->setCurrentIndex(0);
                break;
        }
        m_ui.italicCheckBox->setChecked( f.italic() );

        m_ui.shadowSize->setCurrentIndex( m_internalSettings->shadowSize() );
        m_ui.shadowStrength->setValue( qRound(qreal(m_internalSettings->shadowStrength()*100)/255 ) );
        m_ui.shadowColor->setColor( m_internalSettings->shadowColor() );

    }

    //_______________________________________________
    void ConfigWidget::updateChanged()
    {

        // check configuration
        if(!m_internalSettings)
            return;

        // track modifications
        bool modified(false);
        QFont f; f.fromString( m_internalSettings->titleBarFont() );

        if (m_ui.macOSButtons->isChecked() != m_internalSettings->macOSButtons())
            modified = true;
        if (m_ui.titleAlignment->currentIndex() != m_internalSettings->titleAlignment())
            modified = true;
        else if (m_ui.buttonSize->currentIndex() != m_internalSettings->buttonSize())
            modified = true;
        else if (m_ui.titleMarginSpinBox->value() != m_internalSettings->extraTitleMargin())
            modified = true;
        else if (m_ui.btnSpacingSpinBox->value() != m_internalSettings->buttonSpacing())
            modified = true;
        else if (m_ui.drawBackgroundGradient->isChecked() !=  m_internalSettings->drawBackgroundGradient())
            modified = true;
        else if (m_ui.opacitySpinBox->value() != m_internalSettings->backgroundOpacity())
            modified = true;
        else if (m_ui.gradientSpinBox->value() != m_internalSettings->backgroundGradientIntensity())
            modified = true;

        // font (also see below)
        else if (m_ui.fontComboBox->currentFont().toString() != f.family())
            modified = true;
        else if (m_ui.fontSizeSpinBox->value() != f.pointSize())
            modified = true;
        else if (m_ui.italicCheckBox->isChecked() != f.italic())
            modified = true;

        // animations
        else if (m_ui.animationsEnabled->isChecked() !=  m_internalSettings->animationsEnabled())
            modified = true;
        else if (m_ui.animationsDuration->value() != m_internalSettings->animationsDuration())
            modified = true;

        // shadows
        else if (m_ui.shadowSize->currentIndex() !=  m_internalSettings->shadowSize())
            modified = true;
        else if (qRound(qreal(m_ui.shadowStrength->value()*255)/100) != m_internalSettings->shadowStrength())
            modified = true;
        else if (m_ui.shadowColor->color() != m_internalSettings->shadowColor())
            modified = true;

        // exceptions
        else if (m_ui.exceptions->isChanged())
            modified = true;
        else {
            int indx = m_ui.weightComboBox->currentIndex();
            switch (indx) {
                case 1:
                    if (f.weight() != QFont::Medium) modified = true;
                    break;
                case 2:
                    if (f.weight() != QFont::DemiBold) modified = true;
                    break;
                case 3:
                    if (f.weight() != QFont::Bold) modified = true;
                    break;
                case 4:
                    if (f.weight() != QFont::ExtraBold) modified = true;
                    break;
                case 5:
                    if (f.weight() != QFont::Black) modified = true;
                    break;
                default:
                    if (f.bold()) modified = true;
                    break;
            }
        }

        setNeedsSave(modified);

    }

}
