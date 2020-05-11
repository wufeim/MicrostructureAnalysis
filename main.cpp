/**
 * @file main.cpp
 *
 * @brief: Main file for the desktop app.
 *
 * @author: Wufei Ma
 * Contact: maw3@rpi.edu
 */

#include <QApplication>

#include "window.h"
#include "featuredialog.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();
}
