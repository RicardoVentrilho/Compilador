#include "tela/editordetextoview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorDeTextoView w;
    w.show();

    return a.exec();
}
