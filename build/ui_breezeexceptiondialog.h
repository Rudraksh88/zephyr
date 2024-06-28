#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'breezeexceptiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREEZEEXCEPTIONDIALOG_H
#define UI_BREEZEEXCEPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BreezeExceptionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *detectDialogButton;
    QLineEdit *exceptionEditor;
    QComboBox *exceptionType;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *borderSizeCheckBox;
    QComboBox *borderSizeComboBox;
    QCheckBox *isDialog;
    QSpacerItem *verticalSpacer;
    QCheckBox *hideTitleBar;
    QCheckBox *opaqueTitleBar;
    QCheckBox *flatTitleBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *opacityOverrideLabel;
    QSpinBox *opacityOverrideLabelSpinBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BreezeExceptionDialog)
    {
        if (BreezeExceptionDialog->objectName().isEmpty())
            BreezeExceptionDialog->setObjectName("BreezeExceptionDialog");
        BreezeExceptionDialog->resize(362, 321);
        verticalLayout = new QVBoxLayout(BreezeExceptionDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(BreezeExceptionDialog);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        detectDialogButton = new QPushButton(groupBox);
        detectDialogButton->setObjectName("detectDialogButton");

        gridLayout_2->addWidget(detectDialogButton, 2, 2, 1, 1);

        exceptionEditor = new QLineEdit(groupBox);
        exceptionEditor->setObjectName("exceptionEditor");
        exceptionEditor->setProperty("showClearButton", QVariant(true));

        gridLayout_2->addWidget(exceptionEditor, 1, 1, 1, 2);

        exceptionType = new QComboBox(groupBox);
        exceptionType->addItem(QString());
        exceptionType->addItem(QString());
        exceptionType->setObjectName("exceptionType");

        gridLayout_2->addWidget(exceptionType, 0, 1, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BreezeExceptionDialog);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        borderSizeCheckBox = new QCheckBox(groupBox_2);
        borderSizeCheckBox->setObjectName("borderSizeCheckBox");

        gridLayout_3->addWidget(borderSizeCheckBox, 0, 0, 1, 1);

        borderSizeComboBox = new QComboBox(groupBox_2);
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->addItem(QString());
        borderSizeComboBox->setObjectName("borderSizeComboBox");
        borderSizeComboBox->setEnabled(false);

        gridLayout_3->addWidget(borderSizeComboBox, 0, 1, 1, 1);

        isDialog = new QCheckBox(groupBox_2);
        isDialog->setObjectName("isDialog");

        gridLayout_3->addWidget(isDialog, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 6, 0, 1, 2);

        hideTitleBar = new QCheckBox(groupBox_2);
        hideTitleBar->setObjectName("hideTitleBar");

        gridLayout_3->addWidget(hideTitleBar, 1, 0, 1, 1);

        opaqueTitleBar = new QCheckBox(groupBox_2);
        opaqueTitleBar->setObjectName("opaqueTitleBar");

        gridLayout_3->addWidget(opaqueTitleBar, 2, 0, 1, 1);

        flatTitleBar = new QCheckBox(groupBox_2);
        flatTitleBar->setObjectName("flatTitleBar");

        gridLayout_3->addWidget(flatTitleBar, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(16, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        opacityOverrideLabel = new QLabel(groupBox_2);
        opacityOverrideLabel->setObjectName("opacityOverrideLabel");

        horizontalLayout->addWidget(opacityOverrideLabel);

        opacityOverrideLabelSpinBox = new QSpinBox(groupBox_2);
        opacityOverrideLabelSpinBox->setObjectName("opacityOverrideLabelSpinBox");
        opacityOverrideLabelSpinBox->setMinimum(-1);
        opacityOverrideLabelSpinBox->setMaximum(100);
        opacityOverrideLabelSpinBox->setValue(-1);

        horizontalLayout->addWidget(opacityOverrideLabelSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 3, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(BreezeExceptionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#if QT_CONFIG(shortcut)
        label->setBuddy(exceptionType);
        label_2->setBuddy(exceptionEditor);
#endif // QT_CONFIG(shortcut)

        retranslateUi(BreezeExceptionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BreezeExceptionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BreezeExceptionDialog, qOverload<>(&QDialog::reject));
        QObject::connect(borderSizeCheckBox, &QCheckBox::toggled, borderSizeComboBox, &QComboBox::setEnabled);
        QObject::connect(opaqueTitleBar, &QCheckBox::toggled, opacityOverrideLabel, &QLabel::setDisabled);
        QObject::connect(opaqueTitleBar, &QCheckBox::toggled, opacityOverrideLabelSpinBox, &QSpinBox::setDisabled);

        QMetaObject::connectSlotsByName(BreezeExceptionDialog);
    } // setupUi

    void retranslateUi(QDialog *BreezeExceptionDialog)
    {
        BreezeExceptionDialog->setWindowTitle(tr2i18n("Dialog", nullptr));
        groupBox->setTitle(tr2i18n("Window Identification", nullptr));
        label->setText(tr2i18n("&Matching window property: ", nullptr));
        label_2->setText(tr2i18n("Regular expression &to match: ", nullptr));
        detectDialogButton->setText(tr2i18n("Detect Window Properties\342\200\246", nullptr));
        exceptionType->setItemText(0, tr2i18n("Window Class Name", nullptr));
        exceptionType->setItemText(1, tr2i18n("Window Title", nullptr));

        groupBox_2->setTitle(tr2i18n("Decoration Options", nullptr));
        borderSizeCheckBox->setText(tr2i18n("Border size:", nullptr));
        borderSizeComboBox->setItemText(0, tr2i18n("No Border", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(1, tr2i18n("No Side Borders", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(2, tr2i18n("Tiny", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(3, tr2i18n("Normal", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(4, tr2i18n("Large", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(5, tr2i18n("Very Large", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(6, tr2i18n("Huge", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(7, tr2i18n("Very Huge", "@item:inlistbox Border size:"));
        borderSizeComboBox->setItemText(8, tr2i18n("Oversized", "@item:inlistbox Border size:"));

        isDialog->setText(tr2i18n("Only for dialogs", nullptr));
        hideTitleBar->setText(tr2i18n("Hide window title bar", nullptr));
        opaqueTitleBar->setText(tr2i18n("Opaque title bar", nullptr));
        flatTitleBar->setText(tr2i18n("Flat title bar", nullptr));
        opacityOverrideLabel->setText(tr2i18n("Override opacity:", nullptr));
        opacityOverrideLabelSpinBox->setSuffix(tr2i18n("%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BreezeExceptionDialog: public Ui_BreezeExceptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BREEZEEXCEPTIONDIALOG_H

