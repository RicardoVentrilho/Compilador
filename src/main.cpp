#include "tela/editordetextoview.h"

using tela::EditorDeTextoView;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorDeTextoView w;
    w.show();

    return a.exec();
}
