#include <gui/window/main-window.h>
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);
	Window::MainWindow window;
	window.show();
	return application.exec();
}
