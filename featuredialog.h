#ifndef FEATUREDIALOG_H
#define FEATUREDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QGroupBox;
QT_END_NAMESPACE

class FeatureDialog : public QDialog
{
    Q_OBJECT

public:
    FeatureDialog();

private:
    QGroupBox *createConfigGroup();
    QGroupBox *createFeatureGroup();
    QGroupBox *createPathGroup();
    QGroupBox *createButtonGroup();
};

#endif // FEATUREDIALOG_H
