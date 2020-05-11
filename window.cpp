#include "window.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QMenu>

Window::Window(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(createFunctionGroup(), 0, 0);
}
