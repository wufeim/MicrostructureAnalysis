#include "window.h"
#include "featuredialog.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QMenu>
#include <QPushButton>
#include <QLabel>

Window::Window(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createFunctionGroup(), 0, 0);
    grid->addWidget(createInfoGroup(), 0, 1);
    setLayout(grid);

    setWindowTitle("Microstructure Analysis Toolbox");
    resize(480, 240);
}

QGroupBox *Window::createFunctionGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("Tools"));

    // Collect features button
    QPushButton *collectFeaturesButton = new QPushButton(tr("Collect features"));
    connect(collectFeaturesButton, SIGNAL (clicked()), this, SLOT (featuresButtonClicked()));

    // Train model button
    QPushButton *trainModelsButton = new QPushButton(tr("Train models"));

    // Plot outputs button
    QPushButton *plotOutputslButton = new QPushButton(tr("Plot outputs"));

    // Add layout
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(collectFeaturesButton);
    vbox->addWidget(trainModelsButton);
    vbox->addWidget(plotOutputslButton);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Window::createInfoGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("Info"));

    // About button
    QPushButton *aboutButton = new QPushButton(tr("About"));

    // Documentation button
    QPushButton *documentationButton = new QPushButton(tr("Documentation"));

    // Version label
    QLabel *versionLabel = new QLabel("v 0.1.0");

    // Add layout
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(aboutButton);
    vbox->addWidget(documentationButton);
    vbox->addWidget(versionLabel);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

void Window::featuresButtonClicked() {
    this->close();
    featureDialog = new FeatureDialog;
    featureDialog->setModal(true);
    featureDialog->exec();
}
