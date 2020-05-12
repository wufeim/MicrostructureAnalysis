#include "featuredialog.h"

#include <QWidget>
#include <QGridLayout>
#include <QMenuBar>
#include <QGroupBox>
#include <QCheckBox>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>

FeatureDialog::FeatureDialog()
{
    QGridLayout *grid = new QGridLayout;

    QDialogButtonBox *dialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                             | QDialogButtonBox::Cancel);

    grid->addWidget(createConfigGroup(), 0, 0);
    grid->addWidget(createFeatureGroup(), 0, 1);
    grid->addWidget(createPathGroup(), 1, 0);
    grid->addWidget(createButtonGroup(), 1, 1);
    grid->addWidget(dialogButtonBox, 2, 1);
    setLayout(grid);

    setWindowTitle(tr("Collect features"));
    resize(600, 400);
}

QGroupBox *FeatureDialog::createConfigGroup() {
    QGroupBox *configGroupBox = new QGroupBox(tr("Basics"));

    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Output Prefix:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Image filename regex:")), new QLineEdit);
    configGroupBox->setLayout(layout);

    return configGroupBox;
}

QGroupBox *FeatureDialog::createFeatureGroup() {
    QGroupBox *featureGroupBox = new QGroupBox(tr("Features"));
    // featureGroupBox->setFlat(true);

    QCheckBox *checkBoxArea = new QCheckBox(tr("Area features"));
    QCheckBox *checkBoxSpatial = new QCheckBox(tr("Spatial features"));
    QCheckBox *checkBoxHaralick = new QCheckBox(tr("Haralick features"));
    QCheckBox *checkBoxLBP = new QCheckBox(tr("LBP features"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(checkBoxArea);
    vbox->addWidget(checkBoxSpatial);
    vbox->addWidget(checkBoxHaralick);
    vbox->addWidget(checkBoxLBP);
    vbox->addStretch(1);
    featureGroupBox->setLayout(vbox);

    return featureGroupBox;
}

QGroupBox *FeatureDialog::createPathGroup() {
    QGroupBox *pathGroupBox = new QGroupBox(tr("Path"));

    QGridLayout *grid = new QGridLayout;

    // Image path
    grid->addWidget(new QLabel(tr("Image path:")), 0, 0);
    grid->addWidget(new QLineEdit, 0, 1);
    grid->addWidget(new QPushButton(tr("load")), 0, 2);

    // Output path
    grid->addWidget(new QLabel(tr("Output path:")), 1, 0);
    grid->addWidget(new QLineEdit, 1, 1);
    grid->addWidget(new QPushButton(tr("load")), 1, 2);

    pathGroupBox->setLayout(grid);

    return pathGroupBox;
}

QGroupBox *FeatureDialog::createButtonGroup() {
    QGroupBox *buttonGroupBox = new QGroupBox(tr("Run"));

    QPushButton *runButton = new QPushButton(tr("Run"));
    QPushButton *documentationButton = new QPushButton(tr("Documentation"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(runButton);
    vbox->addWidget(documentationButton);
    vbox->addStretch(1);
    buttonGroupBox->setLayout(vbox);

    return buttonGroupBox;
}
