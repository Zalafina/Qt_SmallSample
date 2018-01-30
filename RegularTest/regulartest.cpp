#include "regulartest.h"
#include "ui_regulartest.h"

RegularTest::RegularTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegularTest)
{
    ui->setupUi(this);
}

RegularTest::~RegularTest()
{
    delete ui;
}

void RegularTest::on_pushButton_clicked()
{
    QString RegPattern = ui->lineEdit->text();

    QString l_str = ui->plainTextEdit->toPlainText();

    qDebug().noquote().nospace() << l_str;

    QRegularExpression rx(RegPattern);
    QRegularExpression::PatternOptions patternOptions = QRegularExpression::NoPatternOption;
    patternOptions |= QRegularExpression::InvertedGreedinessOption;
    rx.setPatternOptions(patternOptions);

    if (rx.isValid()) {
        const int capturingGroupsCount = rx.captureCount() + 1;

        QRegularExpressionMatchIterator iterator = rx.globalMatch(l_str);
        int i = 0;

        while (iterator.hasNext()) {
            QRegularExpressionMatch match = iterator.next();

            for (int captureGroupIndex = 0; captureGroupIndex < capturingGroupsCount; ++captureGroupIndex) {
                    ui->matchText->appendPlainText("Match" + QString::number(i+1) + ":" + "Group" + QString::number(captureGroupIndex) + "->");
                    ui->matchText->appendPlainText(match.captured(captureGroupIndex));
                    ui->matchText->appendPlainText("");
            }

            ++i;
            ui->matchText->appendPlainText("----------------------------------------");
            ui->matchText->appendPlainText("");
        }
    }
}
