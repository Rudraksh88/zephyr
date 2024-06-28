#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'breezeconfigurationui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREEZECONFIGURATIONUI_H
#define UI_BREEZECONFIGURATIONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "config/breezeexceptionlistwidget.h"
#include "kcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_BreezeConfigurationUI
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QComboBox *titleAlignment;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QComboBox *buttonSize;
    QHBoxLayout *horizontalLayout;
    QLabel *titleMarginLabel;
    QSpinBox *titleMarginSpinBox;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *btnSpacingLabel;
    QSpinBox *btnSpacingSpinBox;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *drawBackgroundGradient;
    QLabel *label_7;
    QSpinBox *gradientSpinBox;
    QCheckBox *macOSButtons;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QSpinBox *opacitySpinBox;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QFontComboBox *fontComboBox;
    QSpinBox *fontSizeSpinBox;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_8;
    QComboBox *weightComboBox;
    QCheckBox *italicCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QLabel *animationsDurationLabel;
    QSpinBox *animationsDuration;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *animationsEnabled;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *shadowSize;
    QLabel *label_2;
    QSpinBox *shadowStrength;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    KColorButton *shadowColor;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    Breeze::ExceptionListWidget *exceptions;

    void setupUi(QWidget *BreezeConfigurationUI)
    {
        if (BreezeConfigurationUI->objectName().isEmpty())
            BreezeConfigurationUI->setObjectName("BreezeConfigurationUI");
        BreezeConfigurationUI->resize(428, 418);
        verticalLayout = new QVBoxLayout(BreezeConfigurationUI);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(BreezeConfigurationUI);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName("gridLayout_4");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        titleAlignment = new QComboBox(tab);
        titleAlignment->addItem(QString());
        titleAlignment->addItem(QString());
        titleAlignment->addItem(QString());
        titleAlignment->addItem(QString());
        titleAlignment->setObjectName("titleAlignment");

        gridLayout_4->addWidget(titleAlignment, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        buttonSize = new QComboBox(tab);
        buttonSize->addItem(QString());
        buttonSize->addItem(QString());
        buttonSize->addItem(QString());
        buttonSize->addItem(QString());
        buttonSize->addItem(QString());
        buttonSize->setObjectName("buttonSize");

        gridLayout_4->addWidget(buttonSize, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        titleMarginLabel = new QLabel(tab);
        titleMarginLabel->setObjectName("titleMarginLabel");

        horizontalLayout->addWidget(titleMarginLabel);

        titleMarginSpinBox = new QSpinBox(tab);
        titleMarginSpinBox->setObjectName("titleMarginSpinBox");

        horizontalLayout->addWidget(titleMarginSpinBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnSpacingLabel = new QLabel(tab);
        btnSpacingLabel->setObjectName("btnSpacingLabel");

        horizontalLayout_2->addWidget(btnSpacingLabel);

        btnSpacingSpinBox = new QSpinBox(tab);
        btnSpacingSpinBox->setObjectName("btnSpacingSpinBox");

        horizontalLayout_2->addWidget(btnSpacingSpinBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        gridLayout_4->addLayout(horizontalLayout_2, 3, 0, 1, 3);

        drawBackgroundGradient = new QCheckBox(tab);
        drawBackgroundGradient->setObjectName("drawBackgroundGradient");

        gridLayout_4->addWidget(drawBackgroundGradient, 4, 0, 1, 3);

        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setEnabled(false);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_7, 5, 0, 1, 1);

        gradientSpinBox = new QSpinBox(tab);
        gradientSpinBox->setObjectName("gradientSpinBox");
        gradientSpinBox->setEnabled(false);
        gradientSpinBox->setMaximum(100);

        gridLayout_4->addWidget(gradientSpinBox, 5, 1, 1, 1, Qt::AlignLeft);

        macOSButtons = new QCheckBox(tab);
        macOSButtons->setObjectName("macOSButtons");

        gridLayout_4->addWidget(macOSButtons, 6, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        opacitySpinBox = new QSpinBox(tab);
        opacitySpinBox->setObjectName("opacitySpinBox");
        opacitySpinBox->setMaximum(100);

        gridLayout_2->addWidget(opacitySpinBox, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(5, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        fontComboBox = new QFontComboBox(groupBox);
        fontComboBox->setObjectName("fontComboBox");

        gridLayout_3->addWidget(fontComboBox, 0, 0, 1, 5);

        fontSizeSpinBox = new QSpinBox(groupBox);
        fontSizeSpinBox->setObjectName("fontSizeSpinBox");
        fontSizeSpinBox->setMinimum(5);
        fontSizeSpinBox->setMaximum(50);

        gridLayout_3->addWidget(fontSizeSpinBox, 1, 1, 1, 1, Qt::AlignLeft);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        weightComboBox = new QComboBox(groupBox);
        weightComboBox->addItem(QString());
        weightComboBox->addItem(QString());
        weightComboBox->addItem(QString());
        weightComboBox->addItem(QString());
        weightComboBox->addItem(QString());
        weightComboBox->addItem(QString());
        weightComboBox->setObjectName("weightComboBox");

        gridLayout_3->addWidget(weightComboBox, 2, 1, 1, 1);

        italicCheckBox = new QCheckBox(groupBox);
        italicCheckBox->setObjectName("italicCheckBox");

        gridLayout_3->addWidget(italicCheckBox, 3, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        gridLayout_2->setColumnStretch(3, 1);

        gridLayout_4->addLayout(gridLayout_2, 7, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 8, 0, 1, 3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName("gridLayout_5");
        animationsDurationLabel = new QLabel(tab_2);
        animationsDurationLabel->setObjectName("animationsDurationLabel");
        animationsDurationLabel->setEnabled(false);
        animationsDurationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(animationsDurationLabel, 1, 0, 1, 1);

        animationsDuration = new QSpinBox(tab_2);
        animationsDuration->setObjectName("animationsDuration");
        animationsDuration->setEnabled(false);
        animationsDuration->setMaximum(500);

        gridLayout_5->addWidget(animationsDuration, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        animationsEnabled = new QCheckBox(tab_2);
        animationsEnabled->setObjectName("animationsEnabled");

        gridLayout_5->addWidget(animationsEnabled, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 2, 0, 1, 3);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout = new QGridLayout(tab_4);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(tab_4);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        shadowSize = new QComboBox(tab_4);
        shadowSize->addItem(QString());
        shadowSize->addItem(QString());
        shadowSize->addItem(QString());
        shadowSize->addItem(QString());
        shadowSize->addItem(QString());
        shadowSize->setObjectName("shadowSize");

        gridLayout->addWidget(shadowSize, 0, 1, 1, 1);

        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        shadowStrength = new QSpinBox(tab_4);
        shadowStrength->setObjectName("shadowStrength");
        shadowStrength->setMinimum(10);
        shadowStrength->setMaximum(100);

        gridLayout->addWidget(shadowStrength, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        label_5 = new QLabel(tab_4);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        shadowColor = new KColorButton(tab_4);
        shadowColor->setObjectName("shadowColor");

        gridLayout->addWidget(shadowColor, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 3);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        exceptions = new Breeze::ExceptionListWidget(tab_3);
        exceptions->setObjectName("exceptions");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exceptions->sizePolicy().hasHeightForWidth());
        exceptions->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(exceptions);

        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

#if QT_CONFIG(shortcut)
        label_3->setBuddy(titleAlignment);
        label_4->setBuddy(buttonSize);
        animationsDurationLabel->setBuddy(animationsDuration);
        label->setBuddy(shadowSize);
        label_2->setBuddy(shadowStrength);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(tabWidget, titleAlignment);
        QWidget::setTabOrder(titleAlignment, buttonSize);
        QWidget::setTabOrder(buttonSize, titleMarginSpinBox);
        QWidget::setTabOrder(titleMarginSpinBox, btnSpacingSpinBox);
        QWidget::setTabOrder(btnSpacingSpinBox, drawBackgroundGradient);
        QWidget::setTabOrder(drawBackgroundGradient, animationsEnabled);
        QWidget::setTabOrder(animationsEnabled, animationsDuration);
        QWidget::setTabOrder(animationsDuration, shadowSize);
        QWidget::setTabOrder(shadowSize, shadowStrength);
        QWidget::setTabOrder(shadowStrength, shadowColor);

        retranslateUi(BreezeConfigurationUI);
        QObject::connect(animationsEnabled, &QCheckBox::toggled, animationsDurationLabel, &QLabel::setEnabled);
        QObject::connect(animationsEnabled, &QCheckBox::toggled, animationsDuration, &QSpinBox::setEnabled);
        QObject::connect(drawBackgroundGradient, &QCheckBox::toggled, gradientSpinBox, &QSpinBox::setEnabled);
        QObject::connect(drawBackgroundGradient, &QCheckBox::toggled, label_7, &QLabel::setEnabled);

        tabWidget->setCurrentIndex(0);
        weightComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BreezeConfigurationUI);
    } // setupUi

    void retranslateUi(QWidget *BreezeConfigurationUI)
    {
        label_3->setText(tr2i18n("Tit&le alignment:", nullptr));
        titleAlignment->setItemText(0, tr2i18n("Left", nullptr));
        titleAlignment->setItemText(1, tr2i18n("Center", nullptr));
        titleAlignment->setItemText(2, tr2i18n("Center (Full Width)", nullptr));
        titleAlignment->setItemText(3, tr2i18n("Right", nullptr));

        label_4->setText(tr2i18n("B&utton size:", nullptr));
        buttonSize->setItemText(0, tr2i18n("Tiny", nullptr));
        buttonSize->setItemText(1, tr2i18n("Small", "@item:inlistbox Button size:"));
        buttonSize->setItemText(2, tr2i18n("Medium", "@item:inlistbox Button size:"));
        buttonSize->setItemText(3, tr2i18n("Large", "@item:inlistbox Button size:"));
        buttonSize->setItemText(4, tr2i18n("Very Large", "@item:inlistbox Button size:"));

        titleMarginLabel->setText(tr2i18n("Extra horizontal title margin:", nullptr));
        titleMarginSpinBox->setSuffix(tr2i18n(" px", nullptr));
        btnSpacingLabel->setText(tr2i18n("Button spacing:", nullptr));
        btnSpacingSpinBox->setSuffix(tr2i18n(" px", nullptr));
        btnSpacingSpinBox->setPrefix(QString());
        drawBackgroundGradient->setText(tr2i18n("Draw titlebar background gradient", nullptr));
        label_7->setText(tr2i18n("Gradient intensity:", nullptr));
        gradientSpinBox->setSuffix(tr2i18n(" %", nullptr));
        macOSButtons->setText(tr2i18n("macOS-like buttons", nullptr));
        label_6->setText(tr2i18n("Opacity:", nullptr));
        opacitySpinBox->setSuffix(tr2i18n(" %", nullptr));
        groupBox->setTitle(tr2i18n("Font:", nullptr));
        label_9->setText(tr2i18n("Size:", nullptr));
        label_8->setText(tr2i18n("Weight:", nullptr));
        weightComboBox->setItemText(0, tr2i18n("Normal", nullptr));
        weightComboBox->setItemText(1, tr2i18n("Medium", nullptr));
        weightComboBox->setItemText(2, tr2i18n("DemiBold", nullptr));
        weightComboBox->setItemText(3, tr2i18n("Bold", nullptr));
        weightComboBox->setItemText(4, tr2i18n("ExtraBold", nullptr));
        weightComboBox->setItemText(5, tr2i18n("Black", nullptr));

        italicCheckBox->setText(tr2i18n("Italic", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), tr2i18n("General", nullptr));
        animationsDurationLabel->setText(tr2i18n("Anima&tions duration:", nullptr));
        animationsDuration->setSuffix(tr2i18n(" ms", nullptr));
        animationsEnabled->setText(tr2i18n("Enable animations", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), tr2i18n("Animations", nullptr));
        label->setText(tr2i18n("Si&ze:", nullptr));
        shadowSize->setItemText(0, tr2i18n("None", "@item:inlistbox Button size:"));
        shadowSize->setItemText(1, tr2i18n("Small", "@item:inlistbox Button size:"));
        shadowSize->setItemText(2, tr2i18n("Medium", "@item:inlistbox Button size:"));
        shadowSize->setItemText(3, tr2i18n("Large", "@item:inlistbox Button size:"));
        shadowSize->setItemText(4, tr2i18n("Very Large", "@item:inlistbox Button size:"));

        label_2->setText(tr2i18n("S&trength:", "strength of the shadow (from transparent to opaque)"));
        shadowStrength->setSuffix(tr2i18n("%", nullptr));
        label_5->setText(tr2i18n("Color:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), tr2i18n("Shadows", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), tr2i18n("Window-Specific Overrides", nullptr));
        (void)BreezeConfigurationUI;
    } // retranslateUi

};

namespace Ui {
    class BreezeConfigurationUI: public Ui_BreezeConfigurationUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BREEZECONFIGURATIONUI_H

