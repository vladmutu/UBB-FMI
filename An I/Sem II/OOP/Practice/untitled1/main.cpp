#include <QCoreApplication>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>

QWidget*createWidget() {
    auto *widget = new QWidget();
    auto *layout = new QVBoxLayout(widget);
    auto *button = new QPushButton("Hello, World!", widget);
    layout->addWidget(button);
    return widget;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    createWidget()->show();
    return QCoreApplication::exec();
}
