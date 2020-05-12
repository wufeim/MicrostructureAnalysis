#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include "featuredialog.h"

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private slots:
    void featuresButtonClicked();

private:
    QGroupBox *createFunctionGroup();
    QGroupBox *createInfoGroup();

    FeatureDialog *featureDialog;
};

#endif // WINDOW_H
