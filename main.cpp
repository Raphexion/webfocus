#include <QApplication>
#include <QCommandLineParser>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("webfocus");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Webfocus");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("url", "url");

    parser.process(a);

    auto args = parser.positionalArguments();
    auto url = args.size() > 0 ? args.at(0) : "https://google.com";

    QWebEngineView* view = new QWebEngineView();
    view->load(QUrl(url));
    view->show();

    return a.exec();
}
